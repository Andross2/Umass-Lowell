package com.example.vdc.musicmash;

import android.content.Context;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentPagerAdapter;

/**
 * Created by VDC on 10/9/2017.
 */

public class CatAdapter extends FragmentPagerAdapter {

    private Context mContext;

    public CatAdapter(Context context, FragmentManager fm) {
        super(fm);
        mContext = context;
    }

	// Load tab
    @Override
    public Fragment getItem(int i) {
        switch(i) {
            case 0:
                return new StudyFragment();
            case 1:
                return new GymFragment();
            case 2:
                return new SleepFragment();
            case 3:
                return new BusFragment();
        }
        return null;
    }

	// Display tab name
    @Override
    public CharSequence getPageTitle(int i) {
        switch(i) {
            case 0:
                return mContext.getString(R.string.cat_study);
            case 1:
                return mContext.getString(R.string.cat_gym);
            case 2:
                return mContext.getString(R.string.cat_sleep);
            case 3:
                return mContext.getString(R.string.cat_bus);
        }
        return null;
    }

	// return how many tab in the app
    @Override
    public int getCount() {
        return 4;
    }

}