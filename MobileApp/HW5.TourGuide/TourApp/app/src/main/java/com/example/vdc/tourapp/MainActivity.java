package com.example.vdc.tourapp;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        // Find the View that shows the parks category
        TextView parks = (TextView) findViewById(R.id.park);

        parks.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent parksIntent = new Intent(MainActivity.this, ParksActivity.class);

                // Start the new activity
                startActivity(parksIntent);
            }
        });


        // Find the View that shows the restaurant category
        TextView restaurant = (TextView) findViewById(R.id.restaurant);

        restaurant.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent restIntent = new Intent(MainActivity.this, RestaurantActivity.class);

                // Start the new activity
                startActivity(restIntent);
            }
        });

        // Find the View that shows the museums category
        TextView muse = (TextView) findViewById(R.id.museums);

        muse.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent museIntent = new Intent(MainActivity.this, MusesumsActivity.class);

                // Start the new activity
                startActivity(museIntent);
            }
        });


    }
}
