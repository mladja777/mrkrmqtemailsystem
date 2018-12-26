#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QtNetwork>
#include <QAbstractSocket>
#include <commandwindow.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void MainWindow::on_check();
    void MainWindow::on_send(QStringList qsl);
    QByteArray IntToArray(qint32 source);
    qint32 ArrayToInt(QByteArray source);

signals:
    void dataReceived(QByteArray qbArray);

private slots:
    void on_loginButton_clicked();
    void close_main_window();
    void on_runServerButton_released();
    void on_runClientButton_released();
    void on_logoutButton_released();
    void on_receiveButton_released();
    void on_checkButton_released();
    void on_sendButton_released();
    void on_statButton_released();
    bool connectToHost(QString host);
    bool writeData(QByteArray data);
    void newConnection();
    void disconnected();
    void readyRead();
    void handleStateChange(QAbstractSocket::SocketState socketState);

private:
    Ui::MainWindow *ui;
    QList<QStringList> mailList;
    QList<QStringList> messageList;
    qint16 notSeenMessages;
    CommandWindow commandWindow;
    QString user;

    QTcpSocket *clientSocket;
    QTcpServer *server;
    QHash<QTcpSocket*, QByteArray*> buffer;
    QHash<QTcpSocket*, qint32*> sizes;
};

#endif // MAINWINDOW_H
