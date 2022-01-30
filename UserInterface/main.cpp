#include "widget.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a (argc, argv);
    Widget w;
    w.resize(400,300);
    w.show();
    return a.exec();
}
