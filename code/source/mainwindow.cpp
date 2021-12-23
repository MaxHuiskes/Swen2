#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent, cBelt *belt, QUIBelt *Uibelt) : QMainWindow(parent) , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    beltt1 = belt;
    uiBelt = Uibelt;
}

MainWindow::~MainWindow()
{
    delete ui;
}

