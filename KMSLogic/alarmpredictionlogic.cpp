#include "alarmpredictionlogic.h"
#include <string>
#include <iostream>

int ppmLevel = 600;
int red_flag_value = 1500;
int yellow_flag_value = 1000;
int result_value;

AlarmPredictionLogic::AlarmPredictionLogic()
{

}

string AlarmPredictionLogic::alarmPrediction()
{
    //write main functions here : business logic
    return "Result";
}

int main()
{
    if (ppmLevel > red_flag_value){
        cout << "80% Probability in Cyclone Blockage in next 3 days :Red Alarm !!";
        result_value = 2;
    }if (ppmLevel > yellow_flag_value){
        cout << "70% Probability in Cyclone Blockage in next 3 days : Yellow Alarm !!";
        result_value = 1;
    }else {
        cout << "Safe State : Green Alarm !!";
        result_value = 0;
    }
   return result_value;

    return 0;
}
