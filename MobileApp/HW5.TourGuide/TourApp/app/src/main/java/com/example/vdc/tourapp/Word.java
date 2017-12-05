package com.example.vdc.tourapp;

/**
 * Created by ChuongVu on 10/2/2017.
 */

public class Word {

    private String tourappName;
    private String tourappAddress;
    private String tourappPhone;

    private int imageResourceID = NO_IMAGE_PROVIDED;

    private static final int NO_IMAGE_PROVIDED = -1;

    public int getImageResourceID() {
        return imageResourceID;
    }

    public void setImageResourceID(int imageResourceID) {
        this.imageResourceID = imageResourceID;
    }

    public Word(String tourappName, String tourappAddress, String tourappPhone, int imageResourceID){
        this.tourappName = tourappName;
        this.tourappAddress = tourappAddress;
        this.tourappPhone = tourappPhone;
        this.imageResourceID = imageResourceID;
    }

    // For the name
    public String getTourappName() {
        return tourappName;
    }

    public void setTourappName(String tourappName) {
        this.tourappName = tourappName;
    }

    // For the address

    public String getTourappAddress() {
        return tourappAddress;
    }

    public void setTourappAddress(String tourappAddress) {
        this.tourappAddress = tourappAddress;
    }

    // For the phone

    public String getTourappPhone() {
        return tourappPhone;
    }

    public void setTourappPhone(String tourappPhone) {
        this.tourappPhone = tourappPhone;
    }

    // For image
    public boolean isImageProvided(){
        return !(imageResourceID == NO_IMAGE_PROVIDED);
    }



}
