#ifndef KMSRESPONSE_H
#define KMSRESPONSE_H
#include <string>

using namespace std;

class KmsResponse
{
private:
    int alarmCommand;
    string alarmPrediction;
public:

    void setAlarmCommand(int data){
        alarmCommand = data;
    }

    void setAlarmPrediction(string value){
        alarmPrediction = value;
    }

    int getAlarmCommand(){
        return alarmCommand;
    }

    string getAlarmPrediction(){
        return alarmPrediction;
    }

    KmsResponse();

    KmsResponse(int alarmCommand, string alarmPrediction){
        this->alarmCommand=alarmCommand;
        this->alarmPrediction=alarmPrediction;
    };
};

#endif // KMSRESPONSE_H
