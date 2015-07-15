#ifndef NEWCONTACTWINDOW_H
#define NEWCONTACTWINDOW_H

#include <QMainWindow>
#include "deviceselectionwindow.h"
#include "client.h"

namespace Ui {
class NewContactWindow;
}

class NewContactWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewContactWindow(QWidget *parent = 0);
    ~NewContactWindow();
    void setClient(Client *_client);
    void openDeviceSelectionView();

private slots:
    void on_pushButton_createContact_clicked();
    void on_pushButton_sync_clicked();

private:
    Ui::NewContactWindow *ui;
    DeviceSelectionWindow *deviceSelectionWindow;
    Client *client;
};

#endif // NEWCONTACTWINDOW_H
