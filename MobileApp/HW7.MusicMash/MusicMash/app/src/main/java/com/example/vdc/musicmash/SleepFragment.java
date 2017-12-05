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

public class SleepFragment extends Fragment{

    public SleepFragment() {
        super();
    }

    @Override
    public View onCreateView(final LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View lView = inflater.inflate(R.layout.activity_wordlist, container, false);

        // Create list songs

        final ArrayList<Word> songs = new ArrayList<>();

        // add songs
        songs.add(new Word("Photograph", "Ed Sheeran", R.drawable.photograph, "nSDgHBxUbVQ"));
        songs.add(new Word("Delispice", "Chau chau", R.drawable.deli, "Mt-TwxOw8Z0"));
        songs.add(new Word("I Lay My Love on You", "Westlife", R.drawable.ilaymylove, "ZnOAK04tJhc"));

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
