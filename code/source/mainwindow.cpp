#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPushButton>
#include <QCheckBox>
#include <QGroupBox>
#include "quibelt.h"
#include "cbelt.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    cBelt *belt1 = new cBelt;
    belt1->setBelt(1);
    mBelt =  belt1;
    cBelt *belt2 = new cBelt;
    belt2->setBelt(2);
    cBelt *belt3 = new cBelt;
    belt3->setBelt(3);

    QUIBelt* invoerband1;
    invoerband1 = new QUIBelt(this, belt1);
    invoerband1->setGeometry(10,30,200,200);
    mQUIbelt = invoerband1;
    QUIBelt* invoerband2;
    invoerband2 = new QUIBelt(this, belt2);
    invoerband2->setGeometry(150,30,200,200);
    QUIBelt* invoerband3;
    invoerband3 = new QUIBelt(this, belt3);
    invoerband3->setGeometry(290,30,200,200);


    QPushButton *button = new QPushButton("Set block on first belt", this);
    button->connect(button, &QPushButton::pressed, this, &MainWindow::on_clicked);
    button->setGeometry(639,500,121,41);


    checkbox = new QCheckBox("Low plastic", this);
    checkbox->setGeometry(439,500,121,19);
    checkbox->connect(checkbox, &QPushButton::pressed, this , &MainWindow::on_checkBox_clicked);
    checkbox->setCheckable(true);

    checkbox1 = new QCheckBox("Middle plastic", this);
    checkbox1->setGeometry(439,515,121,19);
    checkbox1->connect(checkbox1, &QPushButton::pressed, this , &MainWindow::on_checkBox1_clicked);
    checkbox1->setCheckable(true);

    checkbox2 = new QCheckBox("High plastic", this);
    checkbox2->setGeometry(439,530,121,19);
    checkbox2->connect(checkbox2, &QPushButton::pressed, this , &MainWindow::on_checkBox2_clicked);
    checkbox2->setCheckable(true);

    checkbox3 = new QCheckBox("Low metal", this);
    checkbox3->setGeometry(539,500,121,19);
    checkbox3->connect(checkbox3, &QPushButton::pressed, this , &MainWindow::on_checkBox3_clicked);
    checkbox3->setCheckable(true);

    checkbox4 = new QCheckBox("Middle metal", this);
    checkbox4->setGeometry(539,515,121,19);
    checkbox4->connect(checkbox4, &QPushButton::pressed, this , &MainWindow::on_checkBox4_clicked);
    checkbox4->setCheckable(true);

    checkbox5 = new QCheckBox("High metal", this);
    checkbox5->setGeometry(539,530,121,19);
    checkbox5->connect(checkbox5, &QPushButton::pressed, this , &MainWindow::on_checkBox5_clicked);
    checkbox5->setCheckable(true);

    QButtonGroup *check = new QButtonGroup(this);
    check->addButton(checkbox);
    check->addButton(checkbox1);
    check->addButton(checkbox2);
    check->addButton(checkbox3);
    check->addButton(checkbox4);
    check->addButton(checkbox5);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_clicked()
{
   mQUIbelt->setButton(blck);
}

void MainWindow::on_checkBox_clicked()
{
    blck = "Low plastic";
}

void MainWindow::on_checkBox1_clicked()
{
        blck = "Middle plastic";
}
void MainWindow::on_checkBox2_clicked()
{
        blck = "High plastic";
}
void MainWindow::on_checkBox3_clicked()
{
    blck = "Low metal";
}

void MainWindow::on_checkBox4_clicked()
{
        blck = "Middle metal";
}

void MainWindow::on_checkBox5_clicked()
{
        blck = "High metal";
}
