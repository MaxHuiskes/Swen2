#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qlabel.h>
#include <qpushbutton.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLabel* label = new QLabel(this->statusBar());
    this->statusBar()->addWidget(label);
    label->setText("status");

    /* use ui button and connect slots */
    QPushButton* uibutton = this->ui->mPushDynamic;
    QPushButton::connect(uibutton, &QPushButton::pressed, this, &MainWindow::on_clicked);


    /* create dynamic button programmatically */
    QPushButton* button = new QPushButton(this);
    button->setText("Dynamic push button");
    button->setGeometry(40,150,171,21);

    QPushButton::connect(button, &QPushButton::pressed, this, &MainWindow::on_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_mPushStatic_clicked()
{
    static int seq = 0;
    seq++;
    static_cast<QLabel*>(this->statusBar()->children().at(1))->
            setText(QString("static ") + QString::number(seq));
    //static_cast<QLabel*>((this->statusBar()->children()[0])->setText(QString("clicked ") + QString::number(seq));
}

void MainWindow::on_clicked()
{
    static int seq = 0;
    seq++;

//    QStatusBar* wid = this->statusBar();
//    QObjectList lst = wid->children();
//    QObject*    obj = lst.at(1);
//    QLabel*     lbl = static_cast<QLabel*>(obj);

//    lbl->setText("skljf");
//    lbl->setText(QString("dynamic ") + QString::number(seq));

    static_cast<QLabel*>(this->statusBar()->children().at(1))->
            setText(QString("dynamic ") + QString::number(seq));
    //static_cast<QLabel*>((this->statusBar()->children()[0])->setText(QString("clicked ") + QString::number(seq));
}



