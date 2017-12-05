package com.example.vdc.tourapp;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.ListView;

import java.util.ArrayList;

/**
 * Created by VDC on 10/1/2017.
 */

public class ParksActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_parks);

        final ArrayList<Word> words = new ArrayList<>();
        words.add(new Word("Jack Kerouac Park", "75 Bridge St, Lowell, MA 01852", "(978) 970-5000", R.drawable.park_jackkouac));
        words.add(new Word("Lowell National Historic Park", "67 Kirk St, Lowell, MA 01852", "(978) 970-5000", R.drawable.park_boottmills));
        words.add(new Word("Boarding House Park", "40 French St, Lowell, MA 01852", "N/A", R.drawable.park_boardinghouse));
        words.add(new Word("Shedd Park", "453 Rogers St, Lowell, MA 01852", "N/A", R.drawable.park_sheddpark));

        // debug
        Log.v("MAIN WORDS", words.toString());

        WordAdapter adapter = new WordAdapter(this, words);
        ListView listView = (ListView) findViewById(R.id.list_park);
        listView.setAdapter(adapter);

    }
}
