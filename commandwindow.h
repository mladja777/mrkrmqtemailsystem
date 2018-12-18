#ifndef COMMANDWINDOW_H
#define COMMANDWINDOW_H

#include <QMainWindow>

namespace Ui {
class CommandWindow;
}

class CommandWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CommandWindow(QWidget *parent = 0);
    ~CommandWindow();

private:
    Ui::CommandWindow *ui;
};

#endif // COMMANDWINDOW_H
