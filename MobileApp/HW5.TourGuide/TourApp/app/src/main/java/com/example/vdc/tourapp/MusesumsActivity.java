package com.example.vdc.tourapp;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.ListView;

import java.util.ArrayList;

/**
 * Created by ChuongVu on 10/2/2017.
 */

public class MusesumsActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_museums);

        final ArrayList<Word> words = new ArrayList<>();
        words.add(new Word("Boott Cotton Mills Museum", "115 John St, Lowell, MA 01852", "(978) 970-5000", R.drawable.muse_boottmill));
        words.add(new Word("Whistler House Museum Of Art", "243 Worthen St, Lowell, MA 01852", "(978) 452-7641", R.drawable.muse_whistlerhouse));
        words.add(new Word("National Streetcar Museum", "25 Shattuck St, Lowell, MA 01852", "(978) 458-5835", R.drawable.muse_streetcar));
        words.add(new Word("Brush Art Gallery & Studios", "256 Market St, Lowell, MA 01852", "(978) 459-7819", R.drawable.muse_brushart));

        // debug
        Log.v("MAIN WORDS", words.toString());

        WordAdapter adapter = new WordAdapter(this, words);
        ListView listView = (ListView) findViewById(R.id.list_museums);
        listView.setAdapter(adapter);

    }
}
