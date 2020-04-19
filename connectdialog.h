#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>
// Obsługa urządzenia wykrywanego przez scan
#include <QSerialPort>


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
    bool deviceSetUp = false;
    QString give_device_name();
    void addToLogs(QString message);

    QString readFromPort();
private slots:
    void on_scanButton_clicked();

    void on_connectButton_clicked();

    void on_disconnectButton_clicked();

private:
    Ui::ConnectDialog *ui;
    // Obsługa urządzenia - stworzenie wskaźnika na urządzenie
};

#endif // CONNECTDIALOG_H
