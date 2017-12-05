package com.example.vdc.quizapp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.CheckBox;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity {
    int TotalScore = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    /** Calculate question 1 **/
    public void CalculateScoreQuest1(){
        RadioButton button = (RadioButton) findViewById(R.id.A1_2);

        if(button.isChecked()){
            updateScore(25);
        }

    }

    /** Calculate question 2 **/
    public void CalculateScoreQuest2(){
        RadioButton button = (RadioButton) findViewById(R.id.A2_1);

        if(button.isChecked()){
            updateScore(25);
        }

    }

    /** Calculate question 3 **/
    public void CalculateScoreQuest3(){
        CheckBox box1 = (CheckBox) findViewById(R.id.A3_1);
        CheckBox box2 = (CheckBox) findViewById(R.id.A3_2);
        CheckBox box3 = (CheckBox) findViewById(R.id.A3_3);

        if(box1.isChecked() && box3.isChecked() && box2.isChecked()==false){
            updateScore(25);
        } else if (box1.isChecked() && box3.isChecked()==false && box2.isChecked()==false){
            updateScore(12);
        } else if (box1.isChecked()==false && box3.isChecked() && box2.isChecked()==false) {
            updateScore(13);
        }

    }

    /** Calculate question 4 **/
    public void CalculateScoreQuest4(){
        RadioButton button = (RadioButton) findViewById(R.id.A4_2);

        if(button.isChecked()){
            updateScore(25);
        }

    }
    public void updateScore(int Score){
        TotalScore = TotalScore + Score;
    }

    /** Function for reset button **/
    public void b_reset(View view){

        /** Uncheck all ratiobutton in question 1,2,4 **/
        RadioGroup radioGroup;
        radioGroup = (RadioGroup)findViewById(R.id.RGQ1);
        radioGroup.clearCheck();
        radioGroup = (RadioGroup)findViewById(R.id.RGQ2);
        radioGroup.clearCheck();
        radioGroup = (RadioGroup)findViewById(R.id.RGQ4);
        radioGroup.clearCheck();

        /** Uncheck all checkbox in question 3 **/
        CheckBox box;
        box = (CheckBox) findViewById(R.id.A3_1);
        if(box.isChecked()){
            box.setChecked(false);
        }

        box = (CheckBox) findViewById(R.id.A3_2);

        if(box.isChecked()){
            box.setChecked(false);
        }

        box = (CheckBox) findViewById(R.id.A3_3);
        if(box.isChecked()){
            box.setChecked(false);
        }

        /** Set the TotalScore back to 0 **/
        TotalScore = 0;

        /** Call the function to display total score **/
        displayScore(TotalScore);
    }

    /** Submit button function **/
    public void b_submit(View view){
        /**  reset TotalScore everytime submit button click **/
        TotalScore = 0;

        CalculateScoreQuest1();
        CalculateScoreQuest2();
        CalculateScoreQuest3();
        CalculateScoreQuest4();
        displayScore(TotalScore);
    }
    /**
     * Displays the final score
     */
    public void displayScore(int score) {
        TextView scoreView = (TextView) findViewById(R.id.Score);
        scoreView.setText(String.valueOf(score));
    }
}
