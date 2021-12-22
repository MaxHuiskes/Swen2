#include "headers/mainwindow.h"

#include <QApplication>
#include <QPushButton>
#include "quibelt.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     cBelt *belt1 = new cBelt;
    MainWindow w(nullptr, belt1);

    belt1->setBelt(1);
    cBelt *belt2 = new cBelt;
    belt2->setBelt(2);
    cBelt *belt3 = new cBelt;
    belt3->setBelt(3);

    QUIBelt* invoerband1;
    invoerband1 = new QUIBelt(&w, belt1);
    invoerband1->setGeometry(10,30,200,200);
    QUIBelt* invoerband2;
    invoerband2 = new QUIBelt(&w, belt2);
    invoerband2->setGeometry(150,30,200,200);
    QUIBelt* invoerband3;
    invoerband3 = new QUIBelt(&w, belt3);
    invoerband3->setGeometry(290,30,200,200);

    w.show();
    return a.exec();
}
