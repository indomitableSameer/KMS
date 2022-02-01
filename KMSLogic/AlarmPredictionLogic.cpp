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

int AlarmPredictionLogic::calculateBlockageProbablity(int ppmLevel)
{
    // probabilty is calcauted with function which is dependent on so2 value
    // currently - used-> p(x) = 0.007 * so2ppm - 25
    // currently formula generated from graph
    float probablity = (0.007 * ppmLevel) - 25;
    probablity = probablity < 0 ? 0 : probablity;
    return probablity;
}
