#ifndef ALARMPREDICTIONLOGIC_H
#define ALARMPREDICTIONLOGIC_H
#include <string>

using namespace std;

class AlarmPredictionLogic
{
public:
    AlarmPredictionLogic();
    string alarmPrediction(double ppmLevel);
};

#endif // ALARMPREDICTIONLOGIC_H