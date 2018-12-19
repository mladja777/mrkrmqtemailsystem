#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->passwordEntry->setEchoMode(QLineEdit::Password);
    QObject::connect(ui->exitButton, SIGNAL(released()), this, SLOT(close_main_window()));
    QObject::connect(ui->loginButton, SIGNAL(released()), this, SLOT(on_loginButton_clicked()));
}

void MainWindow::on_loginButton_clicked(void)
{
    QString email = ui->emailEntry->text();
    QString password = ui->passwordEntry->text();
    user.append(email);
    bool loginSucces = false;

    QFile file("users.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, "Error: ", "No user files.");
        close_main_window();
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
            loginSucces = true;
            on_runClientButton_released();
            goto success;
        }
    }
    if(!loginSucces) QMessageBox::warning(this, "Error: ", "Wrong username or password.");
success:
    //commandWindow.show();
    //this->setVisible(false);
    if(loginSucces)
    {
        ui->logoutButton->setEnabled(true);
        ui->sendButton->setEnabled(true);
        ui->checkButton->setEnabled(true);
        ui->statButton->setEnabled(true);
        ui->deleteButton->setEnabled(true);
        ui->cleanButton->setEnabled(true);
        ui->receiveButton->setEnabled(true);
        ui->textBrowser->setEnabled(true);
        ui->runServerButton->setEnabled(false);
        ui->runClientButton->setEnabled(false);
        ui->serverLabel->setText(user);
        ui->emailEntry->setText("");
        ui->emailEntry->setEnabled(false);
        ui->passwordEntry->setText("");
        ui->passwordEntry->setEnabled(false);
        ui->loginButton->setEnabled(false);
        ui->dstMailEntry->setEnabled(true);
        ui->messageEntry->setEnabled(true);
    }
    file.close();
    mailList.clear();
}

void MainWindow::close_main_window()
{
    QApplication::quit();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_runServerButton_released()
{
    ui->serverLabel->setText("Server is running...");
    ui->runServerButton->setEnabled(false);
    ui->runClientButton->setEnabled(true);
    ui->loginButton->setEnabled(false);
    ui->emailEntry->setEnabled(false);
    ui->passwordEntry->setEnabled(false);
    ui->logoutButton->setEnabled(false);
    ui->sendButton->setEnabled(false);
    ui->checkButton->setEnabled(false);
    ui->statButton->setEnabled(false);
    ui->deleteButton->setEnabled(false);
    ui->cleanButton->setEnabled(false);
    ui->receiveButton->setEnabled(false);
    ui->textBrowser->setEnabled(false);
    ui->dstMailEntry->setEnabled(false);
    ui->messageEntry->setEnabled(false);
}

void MainWindow::on_runClientButton_released()
{
    ui->serverLabel->setText("Client is running...");
    ui->runClientButton->setEnabled(false);
    ui->runServerButton->setEnabled(true);
    ui->loginButton->setEnabled(true);
    ui->emailEntry->setEnabled(true);
    ui->passwordEntry->setEnabled(true);
    ui->logoutButton->setEnabled(false);
    ui->sendButton->setEnabled(false);
    ui->checkButton->setEnabled(false);
    ui->statButton->setEnabled(false);
    ui->deleteButton->setEnabled(false);
    ui->cleanButton->setEnabled(false);
    ui->receiveButton->setEnabled(false);
    ui->textBrowser->setEnabled(false);
    ui->dstMailEntry->setEnabled(false);
    ui->messageEntry->setEnabled(false);
}

void MainWindow::on_logoutButton_released()
{
    ui->serverLabel->setText("Client is running...");
    ui->runClientButton->setEnabled(false);
    ui->runServerButton->setEnabled(true);
    ui->loginButton->setEnabled(true);
    ui->emailEntry->setEnabled(true);
    ui->passwordEntry->setEnabled(true);
    ui->logoutButton->setEnabled(false);
    ui->sendButton->setEnabled(false);
    ui->checkButton->setEnabled(false);
    ui->statButton->setEnabled(false);
    ui->deleteButton->setEnabled(false);
    ui->cleanButton->setEnabled(false);
    ui->receiveButton->setEnabled(false);
    ui->textBrowser->setEnabled(false);
    ui->emailEntry->setText("");
    ui->passwordEntry->setText("");
    user = "";
    ui->textBrowser->setText("");
    ui->dstMailEntry->setEnabled(false);
    ui->messageEntry->setEnabled(false);
    ui->dstMailEntry->setText("");
    ui->messageEntry->setText("");
}

void MainWindow::on_receiveButton_released()
{
    ui->textBrowser->setText("");
    QFile file("messages.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, "Error: ", "No messages.");
        file.close();
        return;
    }

    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList splitLine = line.split("|");
        messageList.append(splitLine);
    }
    for(QList<QStringList>::iterator it = messageList.begin(); it != messageList.end(); it++)
    {
        if(QString::compare(it[0].at(3), "NOTSEEN") == 0)
        {
            ui->textBrowser->insertPlainText("\nFrom: ");
            ui->textBrowser->insertPlainText(it[0].at(0));
            ui->textBrowser->insertPlainText("\nTo: ");
            ui->textBrowser->insertPlainText(it[0].at(1));
            ui->textBrowser->insertPlainText("\nMessage: \n");
            ui->textBrowser->insertPlainText(it[0].at(2));
            ui->textBrowser->insertPlainText("\n----------------------");
        }
    }
    file.close();
    messageList.clear();
}

void MainWindow::on_checkButton_released()
{
    ui->textBrowser->setText("");
    QFile file("messages.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, "Error: ", "No messages.");
        file.close();
        return;
    }

    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList splitLine = line.split("|");
        messageList.append(splitLine);
    }
    notSeenMessages = 0;
    for(QList<QStringList>::iterator it = messageList.begin(); it != messageList.end(); it++)
    {
        if(QString::compare(it[0].at(3), "NOTSEEN") == 0)
        {
            notSeenMessages++;
        }
    }
    ui->textBrowser->insertPlainText("You have ");
    ui->textBrowser->insertPlainText(QStringLiteral("%1").arg(notSeenMessages));
    ui->textBrowser->insertPlainText(" new messages.\n");
    file.close();
    messageList.clear();
}

void MainWindow::on_sendButton_released()
{
    QFile file("messages.txt");
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error: ", "No messages.");
        file.close();
        return;
    }

    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList splitLine = line.split("|");
        messageList.append(splitLine);
    }
    file.close();
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QStringList tempMessage;
    tempMessage.append(user);
    tempMessage.append(ui->dstMailEntry->text());
    tempMessage.append(ui->messageEntry->toPlainText());
    tempMessage.append("NOTSEEN");
    messageList.append(tempMessage);
    for(QList<QStringList>::iterator it = messageList.begin(); it != messageList.end(); it++)
    {
        for(qint16 i = 0; i < 4; i++)
        {
            in << it[0].at(i);
            if(i < 3)
            {
                in << "|";
            }
        }
        in << '\n';
    }
    file.close();
    messageList.clear();
}

void MainWindow::on_statButton_released()
{

}
