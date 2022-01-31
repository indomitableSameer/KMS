#ifndef KMSLOGIC_H
#define KMSLOGIC_H

#include <KmsResponse.h>
#include <QObject>

class KMSLogic : public QObject
{

Q_OBJECT

public:
    explicit KMSLogic(QObject *parent = nullptr);
    void kmsLogicFunction(double ppmLevel);
    void KmsDataReceiverFunction();

    signals:
        void kmssignal();

   public slots:
        KmsResponse kmsQueueData();
        void kmsLogicFunction(double ppmLevel);

};

#endif // KMSLOGIC_H
