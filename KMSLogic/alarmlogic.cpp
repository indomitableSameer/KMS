#include "alarmlogic.h"
#include "UIdata.h"
#include <string>
#include <QSound>

int ppmLevel = 600;
int red_flag_value = 1500;
int yellow_flag_value = 1000;
int result_value;

using namespace std;

alarmlogic::alarmlogic()
{

}

int alarmlogic::alarmCommand()
{
    if (ppmLevel > red_flag_value){
        result_value = 2;
    }if (ppmLevel > yellow_flag_value){
        result_value = 1;
    }else {
        result_value = 0;
    }
   return result_value;
}
