#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>

// Obsługa urządzenia wykrywanego przez scan
#include <QSerialPort>

// zachowuje nazwe urządzenia do dalszej przeróbki
//#include "device.h"

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
    bool valConn;

    struct device_x {
        QString device_name_x;
    };
    struct device_x device_num = {"serial"};

private slots:
    void on_scanButton_clicked();
    void addToLogs(QString message);

    void on_connectButton_clicked();

    void on_disconnectButton_clicked();
    void readFromPort();

private:
    Ui::ConnectDialog *ui;
    // Obsługa urządzenia - stworzenie wskaźnika na urządzenie
};

#endif // CONNECTDIALOG_H
