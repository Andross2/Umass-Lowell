package com.example.vdc.newsapp;


import android.content.Context;
import android.support.annotation.NonNull;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;


import java.util.ArrayList;


/**
 * Created by vdc on 10/21/17.
 */

public class NewsAdapter extends ArrayAdapter<News> {


    public NewsAdapter(Context context, ArrayList<News> newsArrayList) {
        super(context, 0, newsArrayList);
    }

    @NonNull
    @Override
    public View getView(int position, View convertView, ViewGroup parent) {

        News currentNews = getItem(position);

        if(convertView == null) {
            convertView = LayoutInflater.from(getContext()).inflate(R.layout.list_item, parent, false);
        }

        TextView nTitle = (TextView) convertView.findViewById(R.id.news_title);
        TextView nAuthor = (TextView) convertView.findViewById(R.id.news_author);
        TextView nDate = (TextView) convertView.findViewById(R.id.news_date);
        TextView nLang = (TextView) convertView.findViewById(R.id.news_lang);

        nTitle.setText(currentNews.getmTitle());
        nAuthor.setText(currentNews.getmAuthor());
        nDate.setText(currentNews.getmDate());
        nLang.setText(currentNews.getmLang());

        return convertView;
    }


}
