package com.example.vdc.musicmash;

import android.content.Intent;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ListView;

import java.util.ArrayList;

/**
 * Created by VDC on 10/9/2017.
 */

public class GymFragment extends Fragment {

    public GymFragment() {
        super();
    }

    @Override
    public View onCreateView(final LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View lView = inflater.inflate(R.layout.activity_wordlist, container, false);

        // Create list songs

        final ArrayList<Word> songs = new ArrayList<>();

        // add songs
        songs.add(new Word("Touch By Touch", "Joy", R.drawable.touchbytouch, "_jiqSLsd-DE"));
        songs.add(new Word("Take On me", "a-ha", R.drawable.takeonme, "djV11Xbc914"));
        songs.add(new Word("GANGNAM STYLE", "PSY", R.drawable.gangman, "9bZkp7q19f0"));

        WordAdapter adapter = new WordAdapter(getActivity(), songs);

        // word_list in active_worldlist.xml
        ListView listView = (ListView) lView.findViewById(R.id.word_list);

        listView.setAdapter(adapter);

		// use for when click item on the list, it will call the youtube layout
        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                Bundle bundle = new Bundle();
                Word song = songs.get(i);

                bundle.putString("URL", song.getYoutubeID());
                bundle.putString("SongName", song.getSongName());
                bundle.putString("Artist", song.getArtist());


                Intent intent = new Intent(getActivity(), YoutubePlay.class);
                // intent.putExtra("URL", song.getYoutubeID());
                intent.putExtras(bundle);

                startActivity(intent);
            }
        });


        return lView;
    }
}

