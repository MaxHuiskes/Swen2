#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QHostAddress>
#include <QAbstractSocket>
#include <QTime>

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
    ask = true;
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
    QString s = "Server online!!\nConnected to client " + clientSocket->peerAddress().toString();
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
        QString s = "Server online!!\nDisconnected to client " + sender->peerAddress().toString();
        ui->label->setText(s);
    }
}

void MainWindow::onReadyRead()                                          // check data send by client
{
    QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
    datas = sender->readAll();
    qDebug() << datas;
    if (datas == "ok !\n"){
        ask = true;

    } else if(datas.contains("belt1Low:1")){
        ask = false;

    } else if(datas.contains("belt2Low:1")){
        ask = false;

    } else if(datas.contains("belt3Low:1")){
        ask = false;

    } else{
        ask = true;

    }
}

void MainWindow::askData(){
    QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
    if (ask == true){                                                   // ask for data
        for (QTcpSocket* socket : _sockets) {
            if (socket != sender)
                socket->write(QByteArray::fromStdString("ask"));
        }
    } else if(ask == false){                                            // checkBelt will activate
        for (QTcpSocket* socket : _sockets) {
            if (socket != sender)
                socket->write(QByteArray::fromStdString("checkBelt"));
        }
        ask = true;
    }
}

void MainWindow::delay(int secs)                                        // delay from xx seconds
{
    QTime dieTime= QTime::currentTime().addSecs(secs);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

bool MainWindow::getAsk(){                                             // returns bool ask
    return ask;
}
