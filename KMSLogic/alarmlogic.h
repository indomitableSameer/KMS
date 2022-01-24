#ifndef ALARMLOGIC_H
#define ALARMLOGIC_H

#include <string>

using namespace std;

class alarmlogic
{
public:
    alarmlogic();

    string alarmPrediction(float ppmLevel);
};

#endif // ALARMLOGIC_H
