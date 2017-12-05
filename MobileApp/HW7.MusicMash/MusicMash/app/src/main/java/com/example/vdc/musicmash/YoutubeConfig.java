package com.example.vdc.musicmash;

/**
 * Created by VDC on 10/9/2017.
 */

 // Use to store the API key that already preconfig on the Google API Console website
 // The API key is based on my own google account, it should be different from other.
public class YoutubeConfig {
    public YoutubeConfig() {
    }

    private static final String API_KEY = "AIzaSyCtoO5bYv0SYkHufm8VitrVm2amjLHiGjI";

    public static String getApiKey() {
        return API_KEY;
    }
}
