#ifndef ICONFIGMANAGER_H
#define ICONFIGMANAGER_H

#include <QString>

class IConfigManager
{
public:
    QString getSensorLocation();
    QString getDatabaseLocation();
};

#endif // ICONFIGMANAGER_H
