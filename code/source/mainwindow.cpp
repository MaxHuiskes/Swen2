#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPushButton>
#include <QCheckBox>
#include <QGroupBox>
#include "quibelt.h"
#include "cbelt.h"
#include "cblock.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
        
    cBelt *belt1 = new cBelt(this); //  create first belt
    belt1->setBelt(1);
    mBelt =  belt1;
        
    cBelt *belt2 = new cBelt(this); // create second belt
    belt2->setBelt(2);
        
    cBelt *belt3 = new cBelt(this); // creat thirth belt
    belt3->setBelt(3);

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

    middleP = new QCheckBox("Middle plastic", this); // create check box for plastic middle
    middleP->setGeometry(439,515,121,19);
    middleP->connect(middleP, &QPushButton::pressed, this , &MainWindow::on_middleP_clicked);
    middleP->setCheckable(true);

    highP = new QCheckBox("High plastic", this); //  create check box for plastic high
    highP->setGeometry(439,530,121,19);
    highP->connect(highP, &QPushButton::pressed, this , &MainWindow::on_highP_clicked);
    highP->setCheckable(true);

    lowM = new QCheckBox("Low metal", this); // create check box for metal low
    lowM->setGeometry(539,500,121,19);
    lowM->connect(lowM, &QPushButton::pressed, this , &MainWindow::on_lowM_clicked);
    lowM->setCheckable(true);

    middleM = new QCheckBox("Middle metal", this); // create check box for metal middle
    middleM->setGeometry(539,515,121,19);
    middleM->connect(middleM, &QPushButton::pressed, this , &MainWindow::on_middleM_clicked);
    middleM->setCheckable(true);

    highM = new QCheckBox("High metal", this); // create check box for metal high
    highM->setGeometry(539,530,121,19);
    highM->connect(highM, &QPushButton::pressed, this , &MainWindow::on_highM_clicked);
    highM->setCheckable(true);

    QButtonGroup *check = new QButtonGroup(this); // create check box group
    check->addButton(lowP);
    check->addButton(middleP);
    check->addButton(highP);
    check->addButton(lowM);
    check->addButton(middleM);
    check->addButton(highM);
}

MainWindow::~MainWindow()
{
    delete lowP;
    delete middleP;
    delete highP;
    delete lowM;
    delete middleM;
    delete highM;
    delete ui;
}

void MainWindow::on_clicked()  // click on button
{
    mQUIbelt->setButton(Block);
}

void MainWindow::on_lowP_clicked() // select block
{
    Block = new cblock("Low plastic");
}

void MainWindow::on_middleP_clicked() // select block
{
    Block = new cblock("Middle plastic");
}
void MainWindow::on_highP_clicked() // select block
{
    Block = new cblock("High plastic");
}
void MainWindow::on_lowM_clicked() // select block
{
    Block = new cblock("Low metal");
}

void MainWindow::on_middleM_clicked() // select block
{
    Block = new cblock("Middle metal");
}

void MainWindow::on_highM_clicked() // select block
{
    Block = new cblock("High metal");
}

