#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void askData();

public slots:
    void onNewConnection();
    void onSocketStateChanged(QAbstractSocket::SocketState socketState);
    void onReadyRead();
    void delay(int);
    bool getAsk();
    int sort();

private:
    Ui::MainWindow *ui;
    QTcpServer  _server;
    QList<QTcpSocket*>  _sockets;
    QByteArray datas;
    bool ask;           // if ask is 1 asking sensor info
    QString order;
    int intOrder = 0;
    int print;
    int liftUp = 0;

};


// sites used to create server client connection
// https://riptutorial.com/qt/example/29874/tcp-server
// https://riptutorial.com/qt/example/29873/tcp-client

#endif // MAINWINDOW_H
