#ifndef KMSLOGIC_H
#define KMSLOGIC_H

#include <KmsResponse.h>
#include <QObject>

class KMSLogic : public QObject
{
public:
    explicit KMSLogic(QObject *parent = nullptr);
    void kmsLogicFunction(double ppmLevel);
    void KmsDataReceiverFunction();

    signals:
        void kmssignal();

   public slots:
        KmsResponse kmsQueueData();

};

#endif // KMSLOGIC_H
