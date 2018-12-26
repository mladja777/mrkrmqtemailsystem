#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    clientSocket = new QTcpSocket(this);
    ui->setupUi(this);
    ui->passwordEntry->setEchoMode(QLineEdit::Password);
    QObject::connect(ui->exitButton, SIGNAL(released()), this, SLOT(close_main_window()));
    QObject::connect(ui->loginButton, SIGNAL(pressed()), this, SLOT(on_loginButton_clicked()));
}

void MainWindow::on_loginButton_clicked(void)
{
    QString email = ui->emailEntry->text();
    QString password = ui->passwordEntry->text();
    qDebug() << "Input sa konzole: " << email << " sifra: " << password;
    user.append(email);
    bool loginSucces = false;

    qDebug()<<clientSocket->state();
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
        qDebug()<<line;
        QStringList splitLine = line.split("|");
        mailList.append(splitLine);
    }
    for(QList<QStringList>::iterator i = mailList.begin(); i != mailList.end(); i++)
    {
        qDebug() << "Provera emaila: " << i[0].first() << " vs " << email;
        qDebug() << "Provera sifre: " << i[1].first() << " vs " << email;
        if(QString::compare(i[0].first(), email, Qt::CaseSensitive) == 0)
        {
            if(QString::compare(i[1].first(), password, Qt::CaseSensitive))
                {
                    loginSucces = true;
                    on_runClientButton_released();
                    goto success;
                }
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
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), SLOT(newConnection()));
    if(server->listen(QHostAddress::Any, 27015))
    {
        ui->serverLabel->setText("Listening on port 27015...");
    }
    //ui->serverLabel->setText("Server is running...");
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
    QString host = ui->IPEntry->text();
    clientSocket->connectToHost(host, 27015);
    qDebug() << clientSocket->state();
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

void MainWindow::on_check()
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

void MainWindow::on_checkButton_released()
{
    QByteArray flag;
    flag.append("CCH");
    MainWindow::writeData(flag);
    QTcpServer *clientListen = new QTcpServer(this);
    connect(clientListen, SIGNAL(newConnection()), SLOT(newConnection()));
    clientListen->listen(QHostAddress::Any, 27015);
}

void MainWindow::on_send(QStringList qsl)
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
    messageList.append(qsl);
    file.close();
    file.open(QIODevice::WriteOnly | QIODevice::Text);
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
    ui->textBrowser->insertPlainText("Message written.");
}

void MainWindow::on_sendButton_released()
{
    QString tempMessage;
    tempMessage.append("CSE");
    tempMessage.append(user);
    tempMessage.append("|");
    tempMessage.append(ui->dstMailEntry->text());
    tempMessage.append("|");
    tempMessage.append(ui->messageEntry->toPlainText());
    tempMessage.append("|");
    tempMessage.append("NOTSEEN");
    QByteArray msg;
    msg.append(tempMessage);
    MainWindow::writeData(msg);
}

void MainWindow::on_statButton_released()
{

}

bool MainWindow::connectToHost(QString host)
{
    clientSocket->connectToHost(host, 1024);
    return clientSocket->waitForConnected();
}

bool MainWindow::writeData(QByteArray data)
{
    if(clientSocket->state() == QAbstractSocket::ConnectedState)
    {
        clientSocket->write(IntToArray(data.size()));
        clientSocket->write(data);
        return clientSocket->waitForBytesWritten();
    }
    else
    {
        return false;
    }
}

QByteArray MainWindow::IntToArray(qint32 source) //Use qint32 to ensure that the number have 4 bytes
{
    //Avoid use of cast, this is the Qt way to serialize objects
    QByteArray temp;
    QDataStream data(&temp, QIODevice::ReadWrite);
    data << source;
    return temp;
}

void MainWindow::newConnection()
{
    while(server->hasPendingConnections())
    {
        QTcpSocket *serverSocket = server->nextPendingConnection();
        connect(serverSocket, SIGNAL(readyRead()), SLOT(readyRead()));
        connect(serverSocket, SIGNAL(disconnected()), SLOT(disconnected()));
        QByteArray *buf = new QByteArray();
        qint32 *s = new qint32(0);
        buffer.insert(serverSocket, buf);
        sizes.insert(serverSocket, s);
        ui->serverLabel->setText("Client connected to server.");
    }
}

void MainWindow::disconnected()
{
    QTcpSocket *serverSocket = static_cast<QTcpSocket*>(sender());
    QByteArray *buf = buffer.value(serverSocket);
    qint32 *s = sizes.value(serverSocket);
    serverSocket->deleteLater();
    delete buf;
    delete s;
}

void MainWindow::readyRead()
{
    qDebug() << "readyRead()";
    QTcpSocket *serverSocket = static_cast<QTcpSocket*>(sender());
    qDebug() << "1";
    QByteArray *buf = buffer.value(serverSocket);
    qDebug() << buf;
    qDebug() << *buf;
    qDebug() << "2";
    qint32 *s = sizes.value(serverSocket);
    qDebug() << s;
    qDebug() << "3";
    qint32 size = *s;
    qDebug() << "4";
    while (serverSocket->bytesAvailable() > 0) {
        buf->append(serverSocket->readAll());
        while ((size == 0 && buf->size() >= 4) || (size > 0 && buf->size() >= size)) {
            if(size == 0 && buf->size() >= 4)
            {
                size = ArrayToInt(buf->mid(0, 4));
                *s = size;
                buf->remove(0, 4);
            }
            if(size > 0 && buf->size() >= size)
            {
                QByteArray serverData = buf->mid(0, 4);
                size = 0;
                *s = size;
                emit dataReceived(serverData);
            }
        }
        QString dataForRead = QString::fromUtf8(*buf);
        if (dataForRead[0] == 'C' && dataForRead[1] == 'C' && dataForRead[2] == 'H') {
            on_check();
            QByteArray tempCheck;
            tempCheck.append("SCH");
            tempCheck.append(QString::number(notSeenMessages));
            ui->textBrowser->insertPlainText(tempCheck);
            serverSocket->write(IntToArray(tempCheck.size()));
            serverSocket->write(tempCheck);
            serverSocket->waitForBytesWritten();
            /*
            if(MainWindow::writeDataToClient(tempCheck, serverSocket))
            {
                ui->serverLabel->setText("SCH sent.");
            }
            else
            {
                ui->serverLabel->setText("SCH failed.");
            }
            */
        }
        if(dataForRead[0] == 'S' && dataForRead[1] == 'C' && dataForRead[2] == 'H')
        {
            dataForRead.remove(0, 3);
            ui->textBrowser->insertPlainText("");
            ui->textBrowser->insertPlainText("You have ");
            ui->textBrowser->insertPlainText(dataForRead);
            ui->textBrowser->insertPlainText(" new messages.\n");
        }
        if(dataForRead[0] == 'C' && dataForRead[1] == 'S' && dataForRead[2] == 'E')
        {
            dataForRead.remove(0, 3);
            QStringList qsl = dataForRead.split("|");
            on_send(qsl);
        }
    }
}

qint32 MainWindow::ArrayToInt(QByteArray source)
{
    qint32 temp;
    QDataStream data(&source, QIODevice::ReadWrite);
    data >> temp;
    return temp;
}

void MainWindow::handleStateChange(QAbstractSocket::SocketState socketState)
{
    ui->serverLabel->setText("Client connected...");
}
