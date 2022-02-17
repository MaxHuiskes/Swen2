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
    order = "Low plastic; Low metal; High metal; High plastic; High plastic; Low metal; Low plastic; High metal;";
    intOrder = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNewConnection()
{
    // new client created
    QTcpSocket *clientSocket = _server.nextPendingConnection();
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));   // looks if connection read
    connect(clientSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onSocketStateChanged(QAbstractSocket::SocketState))); // looks if state of client changes
    QString s = "Server online!!\nConnected to client " + clientSocket->peerAddress().toString();
    ui->label->setText(s);

    _sockets.push_back(clientSocket); //checks client
    for (QTcpSocket* socket : _sockets) {
        socket->write(QByteArray::fromStdString(order.toStdString())); // data send to client
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
        intOrder = 0;
    }
}

void MainWindow::onReadyRead()                                          // check data send by client
{
    QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
    datas = sender->readAll();
    qDebug() << datas;
    if(datas.contains("liftMaxUp:4")){
        liftUp = 1;
    }else if(datas.contains("belt11Low:1") && datas.contains("liftStatus:0") && datas.contains("liftLow:0")){
        liftUp = 1;
    }else if (datas.contains("belt11Low:1") && datas.contains("liftStatus:1") && datas.contains("liftLow:0")){
        liftUp = 0;
    }else if(datas.contains("belt11Low:0")){
        liftUp = 0;
    }

    if (datas.contains("sortLow1:1")){
        print = sort();
        ask = false;
    } else if(datas.contains("belt1Low:1")){
        ask = false;
        print = 8;
    } else if(datas.contains("belt2Low:1")){
        ask = false;
        print = 8;
    } else if(datas.contains("belt3Low:1")){
        ask = false;
        print = 8;
    } else if(datas.contains("liftLow:1")){
        ask = false;
        print = 8;
    } else if(datas.contains("belt5Low:1")){
        ask = false;
        print = 8;
    } else if(datas.contains("sortLow1:1")){
        ask = false;
        print = 8;
    } else if(datas.contains("belt5Low:1")){
        ask = false;
        print = 8;
    } else if(datas.contains("storeLow:1")){
        ask = false;
        print = 8;
    } else if(datas.contains("belt8Low:1")){
        ask = false;
        print = 8;
    } else if(datas.contains("belt9Low:1")){
        ask = false;
        print = 8;
    } else if(datas.contains("belt10Low:1")){
        ask = false;
        print = 8;
    } else if(datas.contains("belt11Low:1")){
        ask = false;
        print = 8;
    } else if(datas.contains("liftMaxUp:4")){
            ask = false;
            print = 8;
            liftUp = 0;
        }else if(datas == "ok !\n"){
        ask = true;
        print = 8;
    }else{
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
                socket->write(QByteArray::fromStdString("checkBelt(" + QString::number(print).toStdString() + ")" + ";liftUp(" + QString::number(liftUp).toStdString())+")");
        }
        if (intOrder == 8){
            intOrder = 0;
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


int MainWindow::sort(){                                                // sort order
    if (datas.contains("sortLow1:1") && datas.contains("sortMetal:0") && datas.contains("sortHigh:0") && intOrder == 0 ){
        intOrder++;
        return 0;
    }else if(datas.contains("sortLow1:1") && datas.contains("sortMetal:1") && datas.contains("sortHigh:0") && intOrder == 1){
        intOrder++;
        return 1;
    }else if(datas.contains("sortLow1:1") && datas.contains("sortMetal:1") && datas.contains("sortHigh:1") && intOrder == 2){
        intOrder++;
        return 2;
    }else if(datas.contains("sortLow1:1") && datas.contains("sortMetal:0") && datas.contains("sortHigh:1") && intOrder == 3){
        intOrder++;
        return 3;
    }else if(datas.contains("sortLow1:1") && datas.contains("sortMetal:0") && datas.contains("sortHigh:1") && intOrder == 4){
        intOrder++;
        return 4;
    }else if(datas.contains("sortLow1:1") && datas.contains("sortMetal:1") && datas.contains("sortHigh:0") && intOrder == 5){
        intOrder++;
        return 5;
    }else if(datas.contains("sortLow1:1") && datas.contains("sortMetal:0") && datas.contains("sortHigh:0") && intOrder == 6){
        intOrder++;
        return 6;
    }else if(datas.contains("sortLow1:1") && datas.contains("sortMetal:1") && datas.contains("sortHigh:1") && intOrder == 7){
        intOrder++;
        return 7;
    }else{
        return 8;
    }
}
