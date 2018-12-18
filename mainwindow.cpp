#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->passwordEntry->setEchoMode(QLineEdit::Password);
    QObject::connect(ui->exitButton, SIGNAL(released()), this, SLOT(close_main_window()));
}

void MainWindow::on_loginButton_clicked(void)
{
    QString email = ui->emailEntry->text();
    QString password = ui->passwordEntry->text();

    QFile file("users.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        return;
    }

    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList splitLine = line.split("|");
        mailList.append(splitLine);
    }
    for(QList<QStringList>::iterator i = mailList.begin(); i != mailList.end(); i++)
    {
        if(QString::compare(i[0].first(), email, Qt::CaseSensitive) == 0 && QString::compare(i[1].first(), password, Qt::CaseSensitive))
        {
            goto success;
        }
    }
    QMessageBox::warning(this, "Error: ", "Wrong username or password.");
    return;
success:
    commandWindow->show();
    this->hide();
}

void MainWindow::close_main_window()
{
    QApplication::quit();
}

MainWindow::~MainWindow()
{
    delete ui;
}
