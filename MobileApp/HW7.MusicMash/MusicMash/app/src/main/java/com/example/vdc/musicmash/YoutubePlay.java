package com.example.vdc.musicmash;

import android.os.Bundle;
import android.widget.TextView;

import com.google.android.youtube.player.YouTubeBaseActivity;
import com.google.android.youtube.player.YouTubeInitializationResult;
import com.google.android.youtube.player.YouTubePlayer;
import com.google.android.youtube.player.YouTubePlayerView;

import org.w3c.dom.Text;

/**
 * Created by VDC on 10/9/2017.
 */

public class YoutubePlay extends YouTubeBaseActivity {
    private YouTubePlayerView mYoutubeView;
    private YouTubePlayer.OnInitializedListener mOnInit;

    public Bundle getBundle = null;

    private String url;
    private String mName;
    private String mArtis;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_youtube);

        mYoutubeView = (YouTubePlayerView)findViewById(R.id.youtubeplayer_view);

        getBundle = this.getIntent().getExtras();

        if(getBundle != null){
            url = getBundle.getString("URL");
            mName = getBundle.getString("SongName");
            mArtis = getBundle.getString("Artist");
        }

		// get values from bundle and display to textview
        TextView songname = (TextView) findViewById(R.id.playing_songname);
        songname.setText(mName);
        TextView songartis = (TextView) findViewById(R.id.playing_artist);
        songartis.setText(mArtis);

		// Play the youtube video based on the API key
        mOnInit = new YouTubePlayer.OnInitializedListener() {
            @Override
            public void onInitializationSuccess(YouTubePlayer.Provider provider, YouTubePlayer youTubePlayer, boolean b) {
                youTubePlayer.loadVideo(url);
            }

            @Override
            public void onInitializationFailure(YouTubePlayer.Provider provider, YouTubeInitializationResult youTubeInitializationResult) {

            }
        };

        mYoutubeView.initialize(YoutubeConfig.getApiKey(), mOnInit);

    }
}
