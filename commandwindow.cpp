#include "commandwindow.h"
#include "ui_commandwindow.h"

CommandWindow::CommandWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CommandWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->logoutButton, SIGNAL(released()), this, SLOT(on_logoutButton_released()));
}

CommandWindow::~CommandWindow()
{
    delete ui;
}

void CommandWindow::on_logoutButton_released()
{
    QProcess *proc = new QProcess(this);
    proc->start("./Debug/EMailSystem.exe");
    this->setVisible(false);
    proc->close();
}

void CommandWindow::on_receiveButton_released()
{

}
