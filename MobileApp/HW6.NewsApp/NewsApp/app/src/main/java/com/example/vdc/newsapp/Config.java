package com.example.vdc.newsapp;

/**
 * Created by vdc on 10/21/17.
 */

public class Config {

    public Config() {

    }

    private static final String API_URL =
         "https://content.guardianapis.com/search?q=\"computer\"&from-date=2014-01-01&api-key=3de648a2-7204-462d-bdbf-ea8734c1580f&show-tags=contributor";

    public static String getApiUrl(){
        return API_URL;
    }

}
