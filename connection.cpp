#include <QtNetwork>
#include "connection.h"

static const int TransferTimeout = 30 * 1000;
static const int PongTimeout = 60 * 1000;
static const int PingInterval = 5 * 1000;
static const char SeparatorToken = ' ';

Connection::Connection(QObject *parent)
    : QTcpSocket(parent)
{
    greetingMessage = tr("undefined");
    username = tr("unknown");
    state = WaitingForGreeting;
    currentDataType = Undefined;
    numBytesForCurrentDataType = -1;
    transferTimerId = 0;
    isGreetingMessageSent = false;
    pingTimer.setInterval(PingInterval);

    QObject::connect(this, SIGNAL(readyRead()), this, SLOT(processReadyRead()));
    QObject::connect(this, SIGNAL(disconnected()), &pingTimer, SLOT(stop()));
    QObject::connect(&pingTimer, SIGNAL(timeout()), this, SLOT(sendPing()));
    QObject::connect(this, SIGNAL(connected()),
                     this, SLOT(sendGreetingMessage()));
}

QString Connection::name() const
{
    return username;
}

void Connection::setGreetingMessage(const QString &message)
{
    greetingMessage = message;
}

bool Connection::sendMessage(const QString &message)
{
    if (message.isEmpty())
        return false;

    QByteArray msg = message.toUtf8();
    QByteArray data = "MESSAGE " + QByteArray::number(msg.size()) + ' ' + msg;
    return write(data) == data.size();
}

void Connection::timerEvent(QTimerEvent *timerEvent)
{
    if (timerEvent->timerId() == transferTimerId) {
        abort();
        killTimer(transferTimerId);
        transferTimerId = 0;
    }
}

void Connection::processReadyRead()
{
    if (state == WaitingForGreeting) {
        if (!readProtocolHeader())
            return;
        if (currentDataType != Greeting) {
            abort();
            return;
        }
        state = ReadingGreeting;
    }

    if (state == ReadingGreeting) {
        if (!hasEnoughData())
            return;

        buffer = read(numBytesForCurrentDataType);
        if (buffer.size() != numBytesForCurrentDataType) {
            abort();
            return;
        }

        username = QString(buffer) + '@' + peerAddress().toString() + ':'
                   + QString::number(peerPort());
        currentDataType = Undefined;
        numBytesForCurrentDataType = 0;
        buffer.clear();

        if (!isValid()) {
            abort();
            return;
        }

        if (!isGreetingMessageSent)
            sendGreetingMessage();

        pingTimer.start();
        pongTime.start();
        state = ReadyForUse;
        emit readyForUse();
    }

    do {
        if (currentDataType == Undefined) {
            if (!readProtocolHeader())
                return;
        }
        if (!hasEnoughData())
            return;
        processData();
    } while (bytesAvailable() > 0);
}

void Connection::sendPing()
{
    if (pongTime.elapsed() > PongTimeout) {
        abort();
        return;
    }

    write("PING 1 p");
}

void Connection::sendGreetingMessage()
{
    QByteArray greeting = greetingMessage.toUtf8();
    QByteArray data = "GREETING " + QByteArray::number(greeting.size()) + ' ' + greeting;
    if (write(data) == data.size())
        isGreetingMessageSent = true;
}

int Connection::readDataIntoBuffer(int maxSize)
{
    if (maxSize > MaxBufferSize)
        return 0;

    int numBytesBeforeRead = buffer.size();
    if (numBytesBeforeRead == MaxBufferSize) {
        abort();
        return 0;
    }

    while (bytesAvailable() > 0 && buffer.size() < maxSize) {
        buffer.append(read(1));
        if (buffer.endsWith(SeparatorToken))
            break;
    }
    return buffer.size() - numBytesBeforeRead;
}

int Connection::dataLengthForCurrentDataType()
{
    if (bytesAvailable() <= 0 || readDataIntoBuffer() <= 0
            || !buffer.endsWith(SeparatorToken))
        return 0;

    buffer.chop(1);
    int number = buffer.toInt();
    buffer.clear();
    return number;
}

bool Connection::readProtocolHeader()
{
    if (transferTimerId) {
        killTimer(transferTimerId);
        transferTimerId = 0;
    }

    if (readDataIntoBuffer() <= 0) {
        transferTimerId = startTimer(TransferTimeout);
        return false;
    }

    if (buffer == "PING ") {
        currentDataType = Ping;
    } else if (buffer == "PONG ") {
        currentDataType = Pong;
    } else if (buffer == "MESSAGE ") {
        currentDataType = PlainText;
    } else if (buffer == "GREETING ") {
        currentDataType = Greeting;
    } else {
        currentDataType = Undefined;
        abort();
        return false;
    }

    buffer.clear();
    numBytesForCurrentDataType = dataLengthForCurrentDataType();
    return true;
}

bool Connection::hasEnoughData()
{
    if (transferTimerId) {
        QObject::killTimer(transferTimerId);
        transferTimerId = 0;
    }

    if (numBytesForCurrentDataType <= 0)
        numBytesForCurrentDataType = dataLengthForCurrentDataType();

    if (bytesAvailable() < numBytesForCurrentDataType
            || numBytesForCurrentDataType <= 0) {
        transferTimerId = startTimer(TransferTimeout);
        return false;
    }

    return true;
}

void Connection::processData()
{
    buffer = read(numBytesForCurrentDataType);
    if (buffer.size() != numBytesForCurrentDataType) {
        abort();
        return;
    }

    switch (currentDataType) {
    case PlainText:
        emit newMessage(username, QString::fromUtf8(buffer));
        break;
    case Ping:
        write("PONG 1 p");
        break;
    case Pong:
        pongTime.restart();
        break;
    default:
        break;
    }

    currentDataType = Undefined;
    numBytesForCurrentDataType = 0;
    buffer.clear();
}
