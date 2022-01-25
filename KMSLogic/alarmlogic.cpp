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
    //write main functions here : business logic
    return 0;
}

int main()
{
    //PlaySoundA("alarm_red.wav",NULL,SND_SYNC);
    return 0;
}
