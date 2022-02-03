#include <kms.h>
#include <KmsLogic.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KMSLogic* logic = new KMSLogic();
    kms* w = new kms(logic);

    logic->startProcessing();
    w->show();
    return a.exec();
}
