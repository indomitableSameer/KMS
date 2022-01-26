#ifndef IDBREADER_H
#define IDBREADER_H

#include <ISqlTableList.h>

class IDBReader
{
public:
    virtual void readSo2ValueRecords() = 0;
    virtual void readAlarmDataRecords() = 0;
    virtual void readNotificationDataRecords() = 0;
};

#endif // IDBREADER_H
