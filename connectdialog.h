#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>
<<<<<<< HEAD

// Obsługa urządzenia wykrywanego przez scan
#include <QSerialPort>

// zachowuje nazwe urządzenia do dalszej przeróbki
//#include "device.h"
=======
// Obsługa urządzenia wykrywanego przez scan
#include <QSerialPort>

>>>>>>> e1a18cf145c2204eaae565638cb0d50a38580484

namespace Ui {
class ConnectDialog;
}

class ConnectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectDialog(QWidget *parent = nullptr);
    ~ConnectDialog();
    QSerialPort *device;
    QString device_name;
<<<<<<< HEAD
    bool valConn;

    struct device_x {
        QString device_name_x;
    };
    struct device_x device_num = {"serial"};

private slots:
    void on_scanButton_clicked();
    void addToLogs(QString message);
=======
    bool deviceSetUp = false;
    QString give_device_name();
    void addToLogs(QString message);

    QString readFromPort();
private slots:
    void on_scanButton_clicked();
>>>>>>> e1a18cf145c2204eaae565638cb0d50a38580484

    void on_connectButton_clicked();

    void on_disconnectButton_clicked();
<<<<<<< HEAD
    void readFromPort();
=======
>>>>>>> e1a18cf145c2204eaae565638cb0d50a38580484

private:
    Ui::ConnectDialog *ui;
    // Obsługa urządzenia - stworzenie wskaźnika na urządzenie
};

#endif // CONNECTDIALOG_H
