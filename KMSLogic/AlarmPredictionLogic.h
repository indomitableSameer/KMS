#ifndef ALARMPREDICTIONLOGIC_H
#define ALARMPREDICTIONLOGIC_H
#include <string>

using namespace std;

class AlarmPredictionLogic
{
public:
    AlarmPredictionLogic();
    int calculateBlockageProbablity(int ppmLevel);
};

#endif // ALARMPREDICTIONLOGIC_H
