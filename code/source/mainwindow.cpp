#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPushButton>
#include "quibelt.h"

MainWindow::MainWindow(QWidget *parent, cBelt *belt) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    beltt1 = belt;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    beltt1->setBlock();
}

