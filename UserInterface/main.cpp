#include <kms.h>
#include <KmsLogic.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KMSLogic* logic = new KMSLogic();
    logic->startProcessing();
    kms w;
    w.show();
    return a.exec();
}
