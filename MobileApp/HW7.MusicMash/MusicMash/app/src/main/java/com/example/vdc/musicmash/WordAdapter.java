package com.example.vdc.musicmash;

import android.app.Activity;
import android.widget.ArrayAdapter;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import android.view.LayoutInflater;

import com.example.vdc.musicmash.R;

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

        Word currentsong = getItem(position);

        TextView songname = (TextView) listItemView.findViewById(R.id.song_name);
        songname.setText(currentsong.getSongName());
        TextView singername = (TextView) listItemView.findViewById(R.id.singer_name);
        singername.setText(currentsong.getArtist());


        ImageView songimage = (ImageView) listItemView.findViewById(R.id.pic);
        if(currentsong.isImageProvided()) {
            songimage.setImageResource(currentsong.getImageResourceID());
        } else {
            songimage.setVisibility(View.GONE);
        }

        return listItemView;

    }

    @Override
    public String toString() {
        return "WordAdapter{}";
    }



}
