#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QHostAddress>
#include <QAbstractSocket>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _server(this)
{
    ui->setupUi(this);

    ui->label->setText("Server online!!");
    //create connection
    _server.listen(QHostAddress::Any, 4242);
    connect(&_server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNewConnection()
{
    // new client created
    QTcpSocket *clientSocket = _server.nextPendingConnection();
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));   // looks if connection ready
    //connect(clientSocket, SIGNAL(readyRead()), this, SLOT(askData()));
    connect(clientSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onSocketStateChanged(QAbstractSocket::SocketState))); // looks if state of client changes

    QString s = "Server online!!\nConnectet to client " + clientSocket->peerAddress().toString();
    ui->label->setText(s);

    _sockets.push_back(clientSocket); //checks client
    for (QTcpSocket* socket : _sockets) {
        socket->write(QByteArray::fromStdString(clientSocket->peerAddress().toString().toStdString() + " connected to server !")); // data send to client
    }
}

void MainWindow::onSocketStateChanged(QAbstractSocket::SocketState socketState) // checks of client is still connected
{
    if (socketState == QAbstractSocket::UnconnectedState)
    {
        QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
        qDebug() << "Client disconected " + sender->peerAddress().toString() << endl;
        _sockets.removeOne(sender);
    }
}

void MainWindow::onReadyRead() // send data to client
{
    QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
    datas = sender->readAll();
    qDebug() << datas;
    if (datas == "ok !\n"){
        for (QTcpSocket* socket : _sockets) {
            if (socket != sender)
                socket->write(QByteArray::fromStdString("ask"));
        }
    }else{
        datas = "\n";
        for (QTcpSocket* socket : _sockets) {
            if (socket != sender)
                socket->write(QByteArray::fromStdString(sender->peerAddress().toString().toStdString() + ": " + datas.toStdString()));
        }
    }
}

void MainWindow::askData(){
    QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
    for (QTcpSocket* socket : _sockets) {
        if (socket != sender)
            socket->write(QByteArray::fromStdString("ask"));
    }
}

