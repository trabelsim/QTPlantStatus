#include "mainwindow.h"
#include "connectdialog.h"
#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

struct deviceXX{
    QString device_name;
};




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    ConnectDialog as;

    w.show();
    return a.exec();
}
