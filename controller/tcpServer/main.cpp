#include "mainwindow.h"
#include <QApplication>

void delay(int);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    while (true){
        w.delay(5);
        w.askData();
    }
    w.show();
    return a.exec();
}

