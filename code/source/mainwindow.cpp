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
#include "clift.h"
#include "QUILift.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _socket(this)

{
    ui->setupUi(this);
    rightOrder = new QLabel(this);
    rightOrder->setText("The right order to come out:\n" + strRightOrder);
    rightOrder->setGeometry(10,140,600,100);


    // create connection to server
    _socket.connectToHost(QHostAddress("127.0.0.1"), 4242);
    connect(&_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead())); // creates connection with server/controller to recieve data

    // start normal program
    ui->menubar->hide();

    lowMMax = 0;
    lowPMax = 0;
    highPMax = 0;
    highMMax = 0;

    noBlock = new cblock("No Block");

    cBelt *belt1 = new cBelt(1); //  create first belt
    mBelt1 = belt1;
    belt1->setNoBlock(noBlock);

    cBelt *belt2 = new cBelt(2); // create second belt
    mBelt2  = belt2;
    belt2->setNoBlock(noBlock);

    cBelt *belt3 = new cBelt(3); // creat third belt
    mBelt3 = belt3;
    belt3->setNoBlock(noBlock);

    cLift *belt4 = new cLift(4); // creat third belt
    mLift = belt4;
    belt4->setNoBlock(noBlock);

    cBelt *belt5 = new cBelt(5); // creat third belt
    mBelt5 = belt5;
    belt5->setNoBlock(noBlock);

    cBelt *belt6 = new cBelt(6); // creat sort belt
    mSort = belt6;
    belt6->setNoBlock(noBlock);

    cBelt *belt7 = new cBelt(7); // creat third belt
    mStore = belt7;
    belt7->setNoBlock(noBlock);

    cBelt *belt8 = new cBelt(8); // creat third belt
    mBelt8 = belt8;
    belt8->setNoBlock(noBlock);

    cBelt *belt9 = new cBelt(9); // creat third belt
    mBelt9 = belt9;
    belt9->setNoBlock(noBlock);

    cBelt *belt10 = new cBelt(10); // creat third belt
    mBelt10 = belt10;
    belt10->setNoBlock(noBlock);

    cBelt *belt11 = new cBelt(11); // creat third belt
    mBelt11 = belt11;
    belt11->setNoBlock(noBlock);

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

    QUILift* invoerband4; // create info for thirth belt
    invoerband4 = new QUILift(this);
    invoerband4->setLift(belt4);
    invoerband4->setGeometry(430,30,200,200);
    mQUILift = invoerband4;

    QUIBelt* invoerband5; // create info for thirth belt
    invoerband5 = new QUIBelt(this,belt5);
    invoerband5->setBelt(belt5);
    invoerband5->setGeometry(10,80,200,200);
    mQUIbelt5 = invoerband5;

    QUIBelt* invoerband6; // create info for thirth belt
    invoerband6 = new QUIBelt(this,belt6);
    invoerband6->setBelt(belt6);
    invoerband6->setGeometry(150,80,200,200);
    mQUISort = invoerband6;

    QUIBelt* invoerband7; // create info for thirth belt
    invoerband7 = new QUIBelt(this,belt7);
    invoerband7->setBelt(belt7);
    invoerband7->setGeometry(290,80,200,200);
    mQUIStore = invoerband7;

    QUIBelt* invoerband8; // create info for thirth belt
    invoerband8 = new QUIBelt(this,belt8);
    invoerband8->setBelt(belt8);
    invoerband8->setGeometry(10,130,200,200);
    mQUIbelt8 = invoerband8;

    QUIBelt* invoerband9; // create info for thirth belt
    invoerband9 = new QUIBelt(this,belt9);
    invoerband9->setBelt(belt9);
    invoerband9->setGeometry(150,130,200,200);
    mQUIbelt9 = invoerband9;

    QUIBelt* invoerband10; // create info for thirth belt
    invoerband10 = new QUIBelt(this,belt10);
    invoerband10->setBelt(belt10);
    invoerband10->setGeometry(290,130,200,200);
    mQUIbelt10 = invoerband10;

    QUIBelt* invoerband11; // create info for thirth belt
    invoerband11 = new QUIBelt(this,belt11);
    invoerband11->setBelt(belt11);
    invoerband11->setGeometry(430,130,200,200);
    mQUIbelt11 = invoerband11;

    QPushButton *button = new QPushButton("Set block on first belt", this);  // create push button for block on first belt
    button->connect(button, &QPushButton::pressed, this, &MainWindow::on_clicked);
    button->setGeometry(639,500,121,41);

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


    mLabel = new QLabel(this);
    order += "Blocks out of belt:\n";
    mLabel->setText(order);
    mLabel->setGeometry(10,180,600,100);

}
void MainWindow::onReadyRead() // gives status back to sever
{
    QByteArray datas = _socket.readAll(); //recieved data from server
    qDebug() << datas;
    if (datas.contains("Low plastic; Low metal; High metal; High plastic; High plastic; Low metal; Low plastic; High metal;")){

        strRightOrder = QString::fromStdString(datas.toStdString());
        strRightOrder.remove("ask");
        rightOrder->setText("The right order to come out:\n" + strRightOrder );
    }

    if(datas.contains("liftUp(0)")){
        mLift->liftDown();
        mQUILift->updateLiftStatus(mLift->bl);
    }else if(datas.contains("liftUp(1)")){
        mLift->liftUp();
        mQUILift->updateLiftStatus(mLift->bl);
    }

    if (datas == "ask"){
        QString s = "belt1Low:"    + QString::number(mBelt1->getLowSensorValue())           // low sensor value to controller/server
                +   ";belt1Metal:" + QString::number(mBelt1->getMetalSensorValue())         // metal sensor value to controller
                +   ";belt1High:"  + QString::number(mBelt1->getHighSensorValue())          // high sensor value to controller
                +   ";belt2Low:"   + QString::number(mBelt2->getLowSensorValue())           // low sensor value to controller
                +   ";belt3Low:"   + QString::number(mBelt3->getLowSensorValue())           // low sensor value to controller
                +   ";liftLow:"    + QString::number(mLift->getLowSensorValue())            // low sensor value to controller
                +   ";liftStatus:" + QString::number(mLift->getLiftStatus())                // pushrod sensor value to controller
                +   ";belt5Low:"   + QString::number(mBelt5->getLowSensorValue())           // low sensor value to controller
                +   ";sortLow1:"   + QString::number(mSort->getLowSensorValue())            // low sensor value to controller
                +   ";sortLow2:"   + QString::number(mSort->getLow2SensorValue())           // low sensor value to controller
                +   ";sortLow3:"   + QString::number(mSort->getLow3SensorValue())           // low sensor value to controller
                +   ";sortMetal:"  + QString::number(mSort->getMetalSensorValue())          // metal sensor value to controller
                +   ";sortHigh:"   + QString::number(mSort->getHighSensorValue())           // high sensor value to controller
                +   ";storeLow:"   + QString::number(mStore->getLowSensorValue())           // low sensor value to controller
                +   ";belt8Low:"   + QString::number(mBelt8->getLowSensorValue())           // low sensor value to controller
                +   ";belt9Low:"   + QString::number(mBelt9->getLowSensorValue())           // low sensor value to controller
                +   ";belt10Low:"  + QString::number(mBelt10->getLowSensorValue())          // low sensor value to controller
                +   ";liftMaxUP:"  + QString::number(mLift->getMaxUp())                     // max belt up
                +   ";belt11Low:"  + QString::number(mBelt11->getLowSensorValue());         // low sensor value to controller
        _socket.write(QByteArray::fromStdString(s.toStdString()));
    } else if (datas == "Low plastic; Low metal; High metal; High plastic; High plastic; Low metal; Low plastic; High metal;" ) {
        _socket.write(QByteArray("ok !\n")); // sends status client to server
    } else if (datas.contains( "checkBelt(0)")){
        checkB = 0;
        checkBelt();                          // checks belt to next belt
    } else if (datas.contains( "checkBelt(1)")){
        checkB = 1;
        checkBelt();                         // checks belt to next belt
    } else if (datas .contains( "checkBelt(2)")){
        checkB = 2;
        checkBelt();                         // checks belt to next belt
    } else if (datas .contains( "checkBelt(3)")){
        checkB = 3;
        checkBelt();                         // checks belt to next belt
    } else if (datas .contains( "checkBelt(4)")){
        checkB = 4;
        checkBelt();                         // checks belt to next belt
    } else if (datas .contains( "checkBelt(5)")){
        checkB = 5;
        checkBelt();                         // checks belt to next belt
    } else if (datas .contains( "checkBelt(6)")){
        checkB = 6;
        checkBelt();                         // checks belt to next belt
    } else if (datas .contains( "checkBelt(7)")){
        checkB = 7;
        checkBelt();                         // checks belt to next belt
    } else if (datas .contains( "checkBelt(8)")){
        checkB = 8;
        checkBelt();                         // checks belt to next belt
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
    if (reset == 1){
        reset = 0;
        order = "Blocks out of belt:\n";
        mLabel->setText(order);
    }
    if(mBelt1->getBlockCount() < 8){
        if(lowPMax !=2 && clickedLowP == 1){
            lowPMax++;
            mQUIbelt1->setLabel(Block);
        }
        if(highPMax !=2 && clickedHighP == 1){
            highPMax++;
            mQUIbelt1->setLabel(Block);
        }
        if(lowMMax !=2 && clickedLowM == 1){
            lowMMax++;
            mQUIbelt1->setLabel(Block);
        }
        if(highMMax !=2 && clickedHighM == 1){
            highMMax++;
            mQUIbelt1->setLabel(Block);
        }
    }
}
void MainWindow::on_lowP_clicked() // select block
{
    clickedLowP = 1;
    clickedHighP = 0;
    clickedLowM = 0;
    clickedHighM = 0;
    Block = new cblock("Low plastic");
}
void MainWindow::on_highP_clicked() // select block
{
    clickedLowP = 0;
    clickedHighP = 1;
    clickedLowM = 0;
    clickedHighM = 0;
    Block = new cblock("High plastic");
}
void MainWindow::on_lowM_clicked() // select block
{
    clickedLowP = 0;
    clickedHighP = 0;
    clickedLowM = 1;
    clickedHighM = 0;
    Block = new cblock("Low metal");
}
void MainWindow::on_highM_clicked() // select block
{
    clickedLowP = 0;
    clickedHighP = 0;
    clickedLowM = 0;
    clickedHighM = 1;
    Block = new cblock("High metal");
}
void MainWindow::checkBelt(){
    wait2 = 0;

    if (mBelt11->getOccupiedStatus() == 1 && mLift->getOccupiedStatus() == 0 && mLift->getLiftStatus() == 1 && mLift->getMaxUp() < 4){ // looks if belt is occupied
        wait = 1;
        mQUILift->setLiftLabel(mBelt11->bl);
        mQUIbelt11->setNoBlock(noBlock);     // set belt to no block
        mBelt11->resetSensor();              // reset sensor value
        mBelt11->setOccupiedStatus(0);       // set occupied to 0
    }

    if (mBelt10->getOccupiedStatus() == 1 && mBelt11->getOccupiedStatus() == 0){ // looks if belt is occupied
        mQUIbelt11->setLabel(mBelt10->bl);
        mQUIbelt10->setNoBlock(noBlock);     // set belt to no block
        mBelt10->setOccupiedStatus(0);       // set occupied to 0
        mBelt10->resetSensor();              // reset sensor value
    }

    if (mBelt9->getOccupiedStatus() == 1 && mBelt10->getOccupiedStatus() == 0 ){ // looks if belt is occupied
        mQUIbelt10->setLabel(mBelt9->bl);
        mQUIbelt9->setNoBlock(noBlock);     // set belt to no block
        mBelt9->setOccupiedStatus(0);       // set occupied to 0
        mBelt9->resetSensor();              // reset sensor value
    }
    if (mBelt8->getOccupiedStatus() == 1 && mBelt9->getOccupiedStatus() == 0 ){ // looks if belt is occupied
        mQUIbelt9->setLabel(mBelt8->bl);
        mQUIbelt8->setNoBlock(noBlock);     // set belt to no block
        mBelt8->setOccupiedStatus(0);       // set occupied to 0
        mBelt8->resetSensor();              // reset sensor value
    }

    if (mStore->getOccupiedStatus() == 1 && mBelt2->getOccupiedStatus() == 0){ // looks if belt is occupied
        wait2 = 1;
        mQUIbelt2->setLabel(mStore->bl);
        mQUIStore->setNoBlock(noBlock);     // set belt to no block
        mStore->setOccupiedStatus(0);       // set occupied to 0
        mStore->resetSensor();              // reset sensor value
    }

    checkSorteer(checkB);

    if (mBelt5->getOccupiedStatus() == 1 && mSort->getOccupiedStatus() == 0 ){ // looks if belt is occupied
        mQUISort->setLabel(mBelt5->bl);
        mQUIbelt5->setNoBlock(noBlock);     // set belt to no block
        mBelt5->setOccupiedStatus(0);       // set occupied to 0
        mBelt5->resetSensor();              // reset sensor value
    }

    if (mLift->getOccupiedStatus() == 1 && mBelt5->getOccupiedStatus() == 0 && wait == 0){ // looks if belt is occupied
        mQUIbelt5->setLabel(mLift->bl);
        mQUILift->setNoBlock(noBlock);     // set belt to no block
        mLift->setOccupiedStatus(0);       // set occupied to 0
        mLift->resetSensor();              // reset sensor value
    }

    if (mBelt3->getOccupiedStatus() == 1 && mLift->getOccupiedStatus() == 0 && mLift->getLiftStatus() == 0){ // looks if belt is occupied
        mQUILift->setLiftLabel(mBelt3->bl);
        mQUIbelt3->setNoBlock(noBlock);     // set belt to no block
        mBelt3->setOccupiedStatus(0);       // set occupied to 0
        mBelt3->resetSensor();              // reset sensor value
    }

    if(mBelt2->getOccupiedStatus() == 1 && mBelt3->getOccupiedStatus() == 0 && wait2 == 0){
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
    wait = 0;
    wait2 = 0;
}

void MainWindow::checkSorteer(int sort){
    cblock *blk = mSort->bl;
    if(sort < 8){
        if(mSort->getOccupiedStatus() == 1){
            if (sort != 0 && sort < 8){
                order += ", ";
            }
            order += mSort->block;             // block is out
            mLabel->setText(order);            // set label block out of belt
            mQUISort->setNoBlock(noBlock);     // set no block on belt
            mSort->setOccupiedStatus(0);       // set occupied to 0
            mSort->resetSensor();              // reset sensor
            mBelt1->blockOut();                // takes block from belt
            if (sort == 7){
                highMMax = 0;
                highPMax = 0;
                lowMMax = 0;
                lowPMax = 0;
                reset = 1;
            }
        }
    }else if(sort == 8){
        if (mSort->getOccupiedStatus() == 1 && mBelt8->getOccupiedStatus() == 0){
            mSort->setLow23SensorValue(1,1);
            mQUIbelt8->setLabel(blk);    // set block on next belt
            mQUISort->setNoBlock(noBlock);     // set no block on belt
            mSort->setOccupiedStatus(0);       // set occupied to 0
            mSort->resetSensor();              // reset sensor
        }else if(mSort->getOccupiedStatus() == 1 && mStore->getOccupiedStatus() == 0){
            mSort->setLow23SensorValue(0,1);
            mQUIStore->setLabel(blk);    // set block on next belt
            mQUISort->setNoBlock(noBlock);     // set no block on belt
            mSort->setOccupiedStatus(0);       // set occupied to 0
            mSort->resetSensor();              // reset sensor
        }
    }
}
