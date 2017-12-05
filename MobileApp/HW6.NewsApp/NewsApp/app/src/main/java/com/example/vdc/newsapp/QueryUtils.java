package com.example.vdc.newsapp;

import android.text.TextUtils;
import android.util.Log;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.nio.charset.Charset;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by vdc on 10/21/17.
 */

public final class QueryUtils {
    private static final String LOG_TAG = QueryUtils.class.getSimpleName();

    private QueryUtils() {}


    public static List<News> fetchNewsData(String requestUrl) {

        URL url = createUrl(requestUrl);
        String jsonResponse = null;

        try {
            jsonResponse = makeHttpRequest(url);
        } catch (IOException e){
            Log.e(LOG_TAG, "Problem making the HTTP request.", e);
        }

        List<News> newsList = extractFeatureFromJson(jsonResponse);

        return newsList;
    }

    private static URL createUrl(String stringUrl) {
        URL url = null;
        try {
            url = new URL(stringUrl);
        } catch (MalformedURLException e) {
            Log.e(LOG_TAG, "Problem building the URL ", e);
        }

        return url;
    }

    private static String makeHttpRequest(URL url) throws IOException {
        String jsonRespone = "";

        if(url == null) {
            return jsonRespone;
        }

        HttpURLConnection urlConnection = null;
        InputStream inputStream = null;
        try {
            urlConnection = (HttpURLConnection) url.openConnection();
            urlConnection.setReadTimeout(10000);
            urlConnection.setConnectTimeout(15000);
            urlConnection.setRequestMethod("GET");
            urlConnection.connect();

            // if request was successful
            if(urlConnection.getResponseCode() == 200) {
                inputStream = urlConnection.getInputStream();
                jsonRespone = readFromStream(inputStream);
            } else {
                Log.e(LOG_TAG, "Error response code: " + urlConnection.getResponseCode());
            }
        } catch (IOException e) {
            Log.e(LOG_TAG, "Problem retrieving the earthquak JSON results.", e);
        } finally {
            if (urlConnection != null) {
                urlConnection.disconnect();
            }

            if (inputStream != null) {
                inputStream.close();
            }
        }
        return jsonRespone;
    }

    private static String readFromStream(InputStream inputStream) throws IOException {

        StringBuilder output = new StringBuilder();

        if (inputStream != null) {
            InputStreamReader inputStreamReader = new InputStreamReader(inputStream, Charset.forName("UTF-8"));

            BufferedReader reader = new BufferedReader(inputStreamReader);

            String line = reader.readLine();

            while (line != null) {
                output.append(line);
                line = reader.readLine();
            }
        }
        return output.toString();
    }


    private static List<News> extractFeatureFromJson(String NewsJSON) {

        // if the json is empty, return early
        if(TextUtils.isEmpty(NewsJSON)){
            return null;
        }

        List<News> newsList = new ArrayList<>();

        try {
            // create json object based on input string
            JSONObject baseJsonObject = new JSONObject(NewsJSON);

            JSONObject response = baseJsonObject.getJSONObject("response");

            JSONArray result = response.getJSONArray("results");

            for(int i = 0; i < result.length(); i++) {
                JSONObject newsObject = result.getJSONObject(i);
                String title = newsObject.getString("webTitle");
                String date = newsObject.getString("webPublicationDate");
                String webUrl = newsObject.getString("webUrl");

                String lang = "N/A";

                try {
                    lang = MachineLearning.GetLanguage(title);
                    lang = "News is written in: " + lang;

                } catch (Exception e) {
                    Log.e(LOG_TAG, "Language Cant detect", e);
                }


                String author = "N/A";
                String[] authorArray = new String[]{};
                List<String> authorList = new ArrayList<>();

                JSONArray tagArray = newsObject.getJSONArray("tags");

                for(int j = 0; j < tagArray.length(); j++){
                    JSONObject tagsObject = tagArray.getJSONObject(j);
                    String fName = tagsObject.optString("firstName");
                    String lName = tagsObject.optString("lastName");
                    String authorName;
                    if(TextUtils.isEmpty(fName)) {
                        authorName = "Author: " + lName;
                    } else {
                        authorName = "Author: " + fName + " " + lName;
                    }
                    authorList.add(authorName);
                }

                if (authorList.size() == 0) {
                    author = "Author: N/A";
                } else {
                    author = TextUtils.join(", ", authorList);
                }

                //author = "Author: " + author;
                date = "Date: " + date.substring(0,10);

                News news = new News(title, author, date, webUrl, lang);
                newsList.add(news);
            }

        } catch (JSONException e) {
            Log.e("QueryUtils", "Problem parsing the news JSON results", e);
        }

        return newsList;
    }

}
