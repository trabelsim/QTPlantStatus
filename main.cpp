#include "mainwindow.h"
#include "connectdialog.h"
#include "mainwindow.h"
<<<<<<< HEAD
#include "device.h"
#include <QDebug>
#include <QApplication>
=======

#include <QApplication>
#include <QDebug>

struct deviceXX{
    QString device_name;
};



>>>>>>> e1a18cf145c2204eaae565638cb0d50a38580484

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
<<<<<<< HEAD
    QMainWindow window;
=======
    ConnectDialog as;

>>>>>>> e1a18cf145c2204eaae565638cb0d50a38580484
    w.show();
    return a.exec();
}
