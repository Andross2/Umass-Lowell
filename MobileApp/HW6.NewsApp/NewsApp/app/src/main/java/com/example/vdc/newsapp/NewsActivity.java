package com.example.vdc.newsapp;

import android.content.Context;
import android.content.Intent;
import android.databinding.DataBindingUtil;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.Uri;
import android.support.v4.app.LoaderManager;
import android.support.v4.content.Loader;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Toast;

import com.example.vdc.newsapp.databinding.ActivityMainBinding;

import java.util.ArrayList;
import java.util.List;

public class NewsActivity extends AppCompatActivity
    implements LoaderManager.LoaderCallbacks<List<News>> {

    private static final String LOG_TAG = NewsAdapter.class.getSimpleName();
    private static final int NEWS_LOADER_ID = 1;
    private NewsAdapter mNewsAdapter;

    ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = DataBindingUtil.setContentView(this, R.layout.activity_main);

        binding.emptyView.setText(getResources().getText(R.string.no_stores));
        binding.newslistView.setEmptyView(binding.emptyView);

        mNewsAdapter = new NewsAdapter(this, new ArrayList<News>());

        binding.newslistView.setAdapter(mNewsAdapter);

        binding.newslistView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                News currentNews = mNewsAdapter.getItem(i);

                Uri NewsUri = Uri.parse(currentNews.getmUrl());

                //Log.d(LOG_TAG, NewsUri.toString());

                if(currentNews.getmUrl() == null || TextUtils.isEmpty(currentNews.getmUrl())) {
                    Toast.makeText(NewsActivity.this,
                            NewsActivity.this.getResources().getString(R.string.no_link_found),
                            Toast.LENGTH_SHORT).show();
                } else {
                    Intent websiteIntent = new Intent(Intent.ACTION_VIEW, NewsUri);
                    startActivity(websiteIntent);
                }
            }
        });


        ConnectivityManager connMgr = (ConnectivityManager)
                getSystemService(Context.CONNECTIVITY_SERVICE);

        NetworkInfo networkInfo = connMgr.getActiveNetworkInfo();

        if (networkInfo != null && networkInfo.isConnected()) {
            LoaderManager loaderManager = getSupportLoaderManager();

            loaderManager.initLoader(NEWS_LOADER_ID, null, this);
        } else {
            View loadingProgress = findViewById(R.id.loading_progressBar);
            loadingProgress.setVisibility(View.GONE);

            binding.emptyView.setText(R.string.no_internet);
        }
    }

    @Override
    public Loader<List<News>> onCreateLoader(int id, Bundle args) {
        return new NewsLoader(this, Config.getApiUrl());
    }

    @Override
    public void onLoadFinished(Loader<List<News>> loader, List<News> data) {
        binding.loadingProgressBar.setVisibility(View.GONE);

        binding.emptyView.setText(R.string.no_stores);

        mNewsAdapter.clear();

        if(data != null && !data.isEmpty()) {
            mNewsAdapter.addAll(data);
        }
    }

    @Override
    public void onLoaderReset(Loader<List<News>> loader) {
        mNewsAdapter.clear();
    }
}
