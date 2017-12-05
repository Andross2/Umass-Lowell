package com.example.vdc.newsapp;

/**
 * Created by vdc on 10/22/17.
 */

import java.io.*;
import java.net.*;
import javax.net.ssl.HttpsURLConnection;

import org.json.JSONArray;
import org.json.JSONObject;


public class MachineLearning {

    // ***********************************************
    // *** Update or verify the following values. ***
    // **********************************************

    // Replace the accessKey string value with your valid access key.
    private static final String accessKey = "5c6fbc40b49548aca863daacc489821d";

    // Replace or verify the region.

    // You must use the same region in your REST API call as you used to obtain your access keys.
    // For example, if you obtained your access keys from the westus region, replace
    // "westcentralus" in the URI below with "westus".

    // NOTE: Free trial access keys are generated in the westcentralus region, so if you are using
    // a free trial access key, you should not need to change this region.
    private static final String host = "https://westcentralus.api.cognitive.microsoft.com";

    private static final String path = "/text/analytics/v2.0/languages";


    public static String GetLanguage(String title) throws Exception {

        // Create json string
        String text1 = "{\"documents\":[{\"id\":\"1\",\"text\":\"" + title + "\"}]}";
        //Log.i("Test---", text1);

        byte[] encoded_text = text1.getBytes("UTF-8");

        URL url = new URL(host + path);
        HttpsURLConnection connection = (HttpsURLConnection) url.openConnection();
        connection.setRequestMethod("POST");
        connection.setRequestProperty("Content-Type", "text/json");
        connection.setRequestProperty("Ocp-Apim-Subscription-Key", accessKey);
        connection.setDoOutput(true);

        DataOutputStream wr = new DataOutputStream(connection.getOutputStream());
        wr.write(encoded_text, 0, encoded_text.length);
        wr.flush();
        wr.close();

        StringBuilder response = new StringBuilder();

        BufferedReader in = new BufferedReader(
                new InputStreamReader(connection.getInputStream()));
        String line;
        while ((line = in.readLine()) != null) {
            response.append(line);
        }

        in.close();


        // Get value from Json
        String lang = response.toString();

        JSONObject newsObject = new JSONObject(response.toString());
        JSONArray newsArray = newsObject.getJSONArray("documents");

        JSONObject objectInArray = newsArray.getJSONObject(0);
        JSONArray newsArray2 = objectInArray.getJSONArray("detectedLanguages");

        JSONObject langdect = newsArray2.getJSONObject(0);

        // String return languge
        String languagedetect = langdect.getString("name");

        return languagedetect;

    }

}

