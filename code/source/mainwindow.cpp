#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPushButton>
#include <QCheckBox>
#include <QGroupBox>
#include "quibelt.h"
#include "cbelt.h"
#include "cblock.h"
#include <qbuttongroup.h>
#include <QDebug>
#include <QHostAddress>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _socket(this)

{
    ui->setupUi(this);

    // create connection to server
    _socket.connectToHost(QHostAddress("127.0.0.1"), 4242);
    connect(&_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead())); // creates connection with server/controller to recieve data

    // start normal program
    ui->menubar->hide();

    cBelt *belt1 = new cBelt(1); //  create first belt
    mBelt1 = belt1;

    cBelt *belt2 = new cBelt(2); // create second belt
    mBelt2  = belt2;

    cBelt *belt3 = new cBelt(3); // creat third belt
    mBelt3 = belt3;

    cBelt *belt4 = new cBelt(4); // creat third belt
    mLift = belt4;

    cBelt *belt5 = new cBelt(5); // creat third belt
    mBelt5 = belt5;

    cBelt *belt6 = new cBelt(6); // creat third belt
    mSort = belt6;

    cBelt *belt7 = new cBelt(7); // creat third belt
    mStore = belt7;

    cBelt *belt8 = new cBelt(8); // creat third belt
    mBelt8 = belt8;

    cBelt *belt9 = new cBelt(9); // creat third belt
    mBelt9 = belt9;

    cBelt *belt10 = new cBelt(10); // creat third belt
    mBelt10 = belt10;

    cBelt *belt11 = new cBelt(11); // creat third belt
    mBelt11 = belt11;

    QUIBelt* invoerband1;  // create info for first belt
    invoerband1 = new QUIBelt(this,belt1);
    invoerband1->setBelt(belt1);
    invoerband1->setGeometry(10,30,200,200);
    mQUIbelt1 = invoerband1;

    QUIBelt* invoerband2; // create info for second belt
    invoerband2 = new QUIBelt(this,belt2);
    invoerband2->setBelt(belt2);
    invoerband2->setGeometry(150,30,200,200);
    mQUIbelt2 = invoerband2;

    QUIBelt* invoerband3; // create info for thirth belt
    invoerband3 = new QUIBelt(this,belt3);
    invoerband3->setBelt(belt3);
    invoerband3->setGeometry(290,30,200,200);
    mQUIbelt3 = invoerband3;

    QUIBelt* invoerband4; // create info for thirth belt
    invoerband4 = new QUIBelt(this,belt4);
    invoerband4->setBelt(belt4);
    invoerband4->setGeometry(430,30,200,200);
    mQUILift = invoerband4;

    QUIBelt* invoerband5; // create info for thirth belt
    invoerband5 = new QUIBelt(this,belt5);
    invoerband5->setBelt(belt5);
    invoerband5->setGeometry(10,80,200,200);
    mQUILift = invoerband5;

    QUIBelt* invoerband6; // create info for thirth belt
    invoerband6 = new QUIBelt(this,belt6);
    invoerband6->setBelt(belt6);
    invoerband6->setGeometry(150,80,200,200);
    mQUILift = invoerband6;

    QUIBelt* invoerband7; // create info for thirth belt
    invoerband7 = new QUIBelt(this,belt7);
    invoerband7->setBelt(belt7);
    invoerband7->setGeometry(290,80,200,200);
    mQUILift = invoerband7;

    QUIBelt* invoerband8; // create info for thirth belt
    invoerband8 = new QUIBelt(this,belt8);
    invoerband8->setBelt(belt8);
    invoerband8->setGeometry(10,130,200,200);
    mQUILift = invoerband8;

    QUIBelt* invoerband9; // create info for thirth belt
    invoerband9 = new QUIBelt(this,belt9);
    invoerband9->setBelt(belt9);
    invoerband9->setGeometry(150,130,200,200);
    mQUILift = invoerband9;

    QUIBelt* invoerband10; // create info for thirth belt
    invoerband10 = new QUIBelt(this,belt10);
    invoerband10->setBelt(belt10);
    invoerband10->setGeometry(290,130,200,200);
    mQUILift = invoerband10;

    QUIBelt* invoerband11; // create info for thirth belt
    invoerband11 = new QUIBelt(this,belt11);
    invoerband11->setBelt(belt11);
    invoerband11->setGeometry(430,130,200,200);
    mQUILift = invoerband11;

    QPushButton *button = new QPushButton("Set block on first belt", this);  // create push button for block on first belt
    button->connect(button, &QPushButton::pressed, this, &MainWindow::on_clicked);
    button->setGeometry(639,500,121,41);

    QPushButton *buttonCheck = new QPushButton("check", this);
    buttonCheck->connect(buttonCheck, &QPushButton::pressed, this, &MainWindow::checkBelt);
    buttonCheck->setGeometry(300,500,121,41);

    lowP = new QCheckBox("Low plastic", this); // create check box for plastic low
    lowP->setGeometry(439,500,121,19);
    lowP->connect(lowP, &QPushButton::pressed, this , &MainWindow::on_lowP_clicked);
    lowP->setCheckable(true);

    highP = new QCheckBox("High plastic", this); //  create check box for plastic high
    highP->setGeometry(439,515,121,19);
    highP->connect(highP, &QPushButton::pressed, this , &MainWindow::on_highP_clicked);
    highP->setCheckable(true);

    lowM = new QCheckBox("Low metal", this); // create check box for metal low
    lowM->setGeometry(539,500,121,19);
    lowM->connect(lowM, &QPushButton::pressed, this , &MainWindow::on_lowM_clicked);
    lowM->setCheckable(true);

    highM = new QCheckBox("High metal", this); // create check box for metal high
    highM->setGeometry(539,515,121,19);
    highM->connect(highM, &QPushButton::pressed, this , &MainWindow::on_highM_clicked);
    highM->setCheckable(true);

    QButtonGroup *check = new QButtonGroup(this); // create check box group
    check->addButton(lowP);
    check->addButton(highP);
    check->addButton(lowM);
    check->addButton(highM);

    noBlock = new cblock("No Block");
}
void MainWindow::onReadyRead() // gives status back to sever
{
    QByteArray datas = _socket.readAll(); //recieved data from server
    qDebug() << datas;
    if (datas == "ask"){
        QString s = "belt1Low:" + QString::number(mBelt1->getLowSensorValue())          // low sensor value to controller/server
                +   ";belt1Metal:" + QString::number(mBelt1->getMetalSensorValue())     // metal sensor value to controller
                +   ";belt1High:" + QString::number(mBelt1->getHighSensorValue())       // high sensor value to controller
                +   ";belt2Low:" + QString::number(mBelt2->getLowSensorValue())         // low sensor value to controller
                +   ";belt3Low:" + QString::number(mBelt3->getLowSensorValue());        // low sensor value to controller

        _socket.write(QByteArray::fromStdString(s.toStdString()));
    } else if (datas == "::ffff:127.0.0.1 connected to server !" ) {
        _socket.write(QByteArray("ok !\n")); // sends status client to server
    } else if (datas == "checkBelt"){
        checkBelt();                        // checks belt to next belt
    }
}

MainWindow::~MainWindow()
{
    delete lowP;
    delete highP;
    delete lowM;
    delete highM;
    delete ui;
}

void MainWindow::on_clicked()  // click on button
{
    if (mBelt1->getBlockCount() < 8)
        mQUIbelt1->setLabel(Block);
}
void MainWindow::on_lowP_clicked() // select block
{
    Block = new cblock("Low plastic");
}
void MainWindow::on_highP_clicked() // select block
{
    Block = new cblock("High plastic");
}
void MainWindow::on_lowM_clicked() // select block
{
    Block = new cblock("Low metal");
}
void MainWindow::on_highM_clicked() // select block
{
    Block = new cblock("High metal");
}
void MainWindow::checkBelt(){

    if (mBelt3->getOccupiedStatus() == 1 ){ // looks if belt is occupied
        mQUIbelt3->setNoBlock(noBlock);     // set belt to no block
        mBelt3->setOccupiedStatus(0);       // set occupied to 0
        mBelt3->resetSensor();              // reset sensor value
        mBelt1->blockOut();                 // block out
    }

    if(mBelt2->getOccupiedStatus() == 1 && mBelt3->getOccupiedStatus() == 0 ){
        mQUIbelt3->setLabel(mBelt2->bl);    // set new block on next belt
        mQUIbelt2->setNoBlock(noBlock);     // set no block on belt
        mBelt2->setOccupiedStatus(0);       // set occupied to 0
        mBelt2->resetSensor();              // reset sensor value
    }

    if (mBelt1->getOccupiedStatus() == 1 && mBelt2->getOccupiedStatus() == 0){
        mQUIbelt2->setLabel(mBelt1->bl);    // set new block on next belt
        mQUIbelt1->setNoBlock(noBlock);     // set no block on belt
        mBelt1->resetSensor();              // reset sensor value
        mBelt1->setOccupiedStatus(0);       // set occupied to 0

    }
}

