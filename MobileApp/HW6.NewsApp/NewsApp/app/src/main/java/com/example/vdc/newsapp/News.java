package com.example.vdc.newsapp;

/**
 * Created by vdc on 10/21/17.
 */

public class News {
    private String mTitle;
    private String mAuthor;
    private String mDate;
    private String mUrl;
    private String mLang;

    public News(String title, String author, String date, String url, String lang){
        this.mTitle = title;
        this.mAuthor = author;
        this.mDate = date;
        this.mUrl = url;
        this.mLang = lang;
    }


    public String getmAuthor() {
        return mAuthor;
    }

    public String getmDate() {
        return mDate;
    }

    public String getmTitle() {
        return mTitle;
    }

    public String getmUrl() {
        return mUrl;
    }

    public String getmLang() {
        return mLang;
    }

    @Override
    public String toString() {
        return "News {" +
                "title='" + mTitle + '\'' +
                ", author='" + mAuthor + '\'' +
                ", date='" + mDate + '\'' +
                ", mUrl='" + mUrl + '\'' +
                ", mLang='" + mLang + '\'' +
                '}';
    }
}
