package com.example.vdc.tourapp;

import android.app.Activity;
import android.widget.ArrayAdapter;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import android.view.LayoutInflater;

import java.util.ArrayList;

/**
 * Created by ChuongVu on 10/2/2017.
 */

public class WordAdapter extends ArrayAdapter<Word>{

    public WordAdapter(Activity context, ArrayList<Word> words){
        super(context, 0, words);
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent){

        View listItemView = convertView;

        if(listItemView == null){
            listItemView = LayoutInflater.from(getContext()).inflate(
                    R.layout.list_item, parent, false);
        }

        Word word = getItem(position);

        TextView tourname = (TextView) listItemView.findViewById(R.id.name);
        tourname.setText(word.getTourappName());
        TextView tourAddress = (TextView) listItemView.findViewById(R.id.address);
        tourAddress.setText(word.getTourappAddress());
        TextView tourphone = (TextView) listItemView.findViewById(R.id.phone);
        tourphone.setText(word.getTourappPhone());

        ImageView tourimage = (ImageView) listItemView.findViewById(R.id.pic);
        if(word.isImageProvided()) {
            tourimage.setImageResource(word.getImageResourceID());
        } else {
            tourimage.setVisibility(View.GONE);
        }

        return listItemView;

    }

    @Override
    public String toString() {
        return "WordAdapter{}";
    }



}
