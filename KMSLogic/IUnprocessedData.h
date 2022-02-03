#ifndef IUNPROCESSEDDATA_H
#define IUNPROCESSEDDATA_H

#include <QDateTime>

struct raw_data
{
    QDateTime dateTime;
    int so2PpmValue;
};

#endif // IUNPROCESSEDDATA_H
