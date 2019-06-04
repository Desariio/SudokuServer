#include "myserver.h"

MyServer::MyServer()
{

}

MyServer::~MyServer()
{

}

void MyServer::startServer()
{
    if(this->listen(QHostAddress::Any, 5555)){
        qDebug() << "Waiting";
    }else{
        qDebug() << "Not waiting";
    }
}

void MyServer::incomingConnection(int socketDescriptor)
{
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, SIGNAL(readyRead()), this, SLOT(socketReady()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisconnect()));

    qDebug() << socketDescriptor << " Client connected";

    //JSON FORMAT
    socket->write("{\"type\":\"connect\", \"status\":\"yes\"}");
    qDebug() << "Send client connect status - YES";
}

void MyServer::socketReady()
{

}

void MyServer::socketDisconnect()
{
    qDebug() << "Disconnected";
    socket->deleteLater();
}
