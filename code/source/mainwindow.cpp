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
    connect(&_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

    // start normal program
    ui->menubar->hide();
        
    cBelt *belt1 = new cBelt(1); //  create first belt
        
    cBelt *belt2 = new cBelt(2); // create second belt
        
    cBelt *belt3 = new cBelt(3); // creat third belt

    QUIBelt* invoerband1;  // create info for first belt
    invoerband1 = new QUIBelt(this);
    invoerband1->setBelt(belt1);
    invoerband1->setGeometry(10,30,200,200);
    mQUIbelt = invoerband1;
   
    QUIBelt* invoerband2; // create info for second belt
    invoerband2 = new QUIBelt(this);
    invoerband2->setBelt(belt2);
    invoerband2->setGeometry(150,30,200,200);
    
    QUIBelt* invoerband3; // create info for thirth belt
    invoerband3 = new QUIBelt(this);
    invoerband3->setBelt(belt3);
    invoerband3->setGeometry(290,30,200,200);

    QPushButton *button = new QPushButton("Set block on first belt", this);  // create push button for block on first belt
    button->connect(button, &QPushButton::pressed, this, &MainWindow::on_clicked);
    button->setGeometry(639,500,121,41);

    lowP = new QCheckBox("Low plastic", this); // create check box for plastic low
    lowP->setGeometry(439,500,121,19);
    lowP->connect(lowP, &QPushButton::pressed, this , &MainWindow::on_lowP_clicked);
    lowP->setCheckable(true);

    highP = new QCheckBox("High plastic", this); //  create check box for plastic high
    highP->setGeometry(439,530,121,19);
    highP->connect(highP, &QPushButton::pressed, this , &MainWindow::on_highP_clicked);
    highP->setCheckable(true);

    lowM = new QCheckBox("Low metal", this); // create check box for metal low
    lowM->setGeometry(539,500,121,19);
    lowM->connect(lowM, &QPushButton::pressed, this , &MainWindow::on_lowM_clicked);
    lowM->setCheckable(true);

    highM = new QCheckBox("High metal", this); // create check box for metal high
    highM->setGeometry(539,530,121,19);
    highM->connect(highM, &QPushButton::pressed, this , &MainWindow::on_highM_clicked);
    highM->setCheckable(true);

    QButtonGroup *check = new QButtonGroup(this); // create check box group
    check->addButton(lowP);
    check->addButton(highP);
    check->addButton(lowM);
    check->addButton(highM);
}
void MainWindow::onReadyRead() // gives status back to sever
{
    QByteArray datas = _socket.readAll();
    qDebug() << datas;
    _socket.write(QByteArray("ok !\n"));
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
    mQUIbelt->setLabel(Block);
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

