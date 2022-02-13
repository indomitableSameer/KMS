#ifndef IDATARECEIVER_H
#define IDATARECEIVER_H

#include <QObject>

class IDataReceiver : public QObject
{
    Q_OBJECT
signals:
    void dataAvailable();
public:
    virtual bool start() = 0;
    virtual int getFromQueue() = 0;
};

#endif // IDATARECEIVER_H
