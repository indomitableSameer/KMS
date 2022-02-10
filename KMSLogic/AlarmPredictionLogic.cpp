#include "AlarmPredictionLogic.h"
#include <string>
#include <iostream>

AlarmPredictionLogic::AlarmPredictionLogic()
{

}

/*
 * Hazard Id : _H4.1_blockage_prediction_
*/
int AlarmPredictionLogic::calculateBlockageProbablity(int ppmLevel)
{
    // probabilty is calcauted with function which is dependent on so2 value
    // currently - used-> p(x) = 0.007 * so2ppm - 25
    // currently formula generated from graph
    float probablity = (0.007 * ppmLevel) - 25;
    probablity = probablity < 0 ? 0 : probablity;
    return probablity;
}
