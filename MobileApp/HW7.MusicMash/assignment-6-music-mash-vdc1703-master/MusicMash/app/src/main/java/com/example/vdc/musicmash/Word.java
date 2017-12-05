package com.example.vdc.musicmash;

/**
 * Created by ChuongVu on 10/2/2017.
 */

public class Word {

    private String mSongName;
    private String mArtist;

    private int imageResourceID = NO_IMAGE_PROVIDED;

    private static final int NO_IMAGE_PROVIDED = -1;

    private String mYoutube;

    public void setImageResourceID(int imageResourceID) {
        this.imageResourceID = imageResourceID;
    }

    public Word(String SongName, String Artist, int imageResourceID, String audio){
        this.mSongName = SongName;
        this.mArtist = Artist;
        this.imageResourceID = imageResourceID;
        this.mYoutube = audio;
    }

    // Return song name
    public String getSongName() {
        return mSongName;
    }

    // return Artist
    public String getArtist() {
        return mArtist;
    }

    // return image
    public int getImageResourceID() {
        return imageResourceID;
    }

    // For image
    public boolean isImageProvided(){
        return !(imageResourceID == NO_IMAGE_PROVIDED);
    }

    public String getYoutubeID(){
        return mYoutube;
    }

}
