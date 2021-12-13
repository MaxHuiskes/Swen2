#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString beltinfo ="Convayer Belt number " + QString::number(belt.belt);
    QString blockCount = "Block count on belt " + QString::number(belt.block);
    //QString sensorValue = "Sensor Value " + QString::number(sensor);


    ui->label->setText(beltinfo);
    ui->label_2->setText(blockCount);
    //ui->label_3->setText(sensorValue);
}

MainWindow::~MainWindow()
{
    delete ui;
}




