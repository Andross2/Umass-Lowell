package com.example.vdc.tourapp;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.ListView;
import java.util.ArrayList;


/**
 * Created by ChuongVu on 10/2/2017.
 */

public class RestaurantActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_restaurant);

        final ArrayList<Word> words = new ArrayList<>();
        words.add(new Word("Cobblestones", "91 Dutton St, Lowell, MA 01852", "(978) 970-2282", R.drawable.resta_cobblestones));
        words.add(new Word("The Lowell Beer Works", "203 Cabot St, Lowell, MA 01854", "(978) 937-2337", R.drawable.resta_beerworks));
        words.add(new Word("Blue Taleh", "15 Kearney Square, Lowell, MA 01852", "(978) 453-1112", R.drawable.resta_bluetaleh));
        words.add(new Word("Bonchon Chicken", "1075 Westford St, Lowell, MA 01851", "(978) 970-1888", R.drawable.resta_bonchon));

        // debug
        Log.v("MAIN WORDS", words.toString());

        WordAdapter adapter = new WordAdapter(this, words);
        ListView listView = (ListView) findViewById(R.id.list_restaurant);
        listView.setAdapter(adapter);

    }
}
