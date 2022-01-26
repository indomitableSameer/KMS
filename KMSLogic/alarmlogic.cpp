#include "alarmlogic.h"
#include "UIdata.h"
#include <string>
#include <QSound>

double RED_FLAG_VALUE = 15000.00;
double YELLOW_FLAG_VALUE = 10000.00;
int alarm_command_value;

using namespace std;

AlarmLogic::AlarmLogic()
{

}

int AlarmLogic::alarmCommand(double ppmLevel)
{
    if (ppmLevel > RED_FLAG_VALUE){
        alarm_command_value = 2;
    }if (ppmLevel > YELLOW_FLAG_VALUE){
        alarm_command_value = 1;
    }else {
        alarm_command_value = 0;
    }
   return alarm_command_value;
}
