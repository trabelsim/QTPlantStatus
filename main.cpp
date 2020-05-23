#include "mainwindow.h"
#include "connectdialog.h"
#include "mainwindow.h"
#include "device.h"
#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QMainWindow window;
    w.show();
    return a.exec();
}
