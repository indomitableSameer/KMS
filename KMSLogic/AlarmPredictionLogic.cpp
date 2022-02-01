#include "AlarmPredictionLogic.h"
#include <string>
#include <iostream>

double RED_FLAG_VALUE_P = 15000.00;
double YELLOW_FLAG_VALUE_P = 10000.00;
//double alarm_command_value_p;
string alarm_predicted_value;

AlarmPredictionLogic::AlarmPredictionLogic()
{

}

string AlarmPredictionLogic::alarmPrediction(double ppmLevel)
{

    //mathematical calculation for probability
    if (ppmLevel > RED_FLAG_VALUE_P){
        alarm_predicted_value = "80% Probability in Cyclone Blockage in next 3 days :Red Alarm !!";
    }if (ppmLevel > YELLOW_FLAG_VALUE_P){
        alarm_predicted_value = "70% Probability in Cyclone Blockage in next 3 days :Red Alarm !!";
    }else {
        alarm_predicted_value = "Safe State : Green Alarm !!";
    }
   return alarm_predicted_value;
}
