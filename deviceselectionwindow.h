#ifndef DEVICESELECTIONWINDOW_H
#define DEVICESELECTIONWINDOW_H

#include <QMainWindow>

namespace Ui {
class DeviceSelectionWindow;
}

class DeviceSelectionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeviceSelectionWindow(QWidget *parent = 0);
    ~DeviceSelectionWindow();

private:
    Ui::DeviceSelectionWindow *ui;
};

#endif // DEVICESELECTIONWINDOW_H