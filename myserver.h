#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    MyServer();
    ~MyServer();

public slots:
    void startServer();
    void incomingConnection(int socketDescriptor);
    void socketReady();
    void socketDisconnect();

private:
    QTcpSocket *socket;
    QByteArray data;
};

#endif // MYSERVER_H
