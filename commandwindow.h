#ifndef COMMANDWINDOW_H
#define COMMANDWINDOW_H

#include <QMainWindow>
#include <QProcess>

namespace Ui {
class CommandWindow;
}

class CommandWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CommandWindow(QWidget *parent = 0);
    ~CommandWindow();

private slots:
    void on_logoutButton_released();

    void on_receiveButton_released();

private:
    Ui::CommandWindow *ui;
};

#endif // COMMANDWINDOW_H
