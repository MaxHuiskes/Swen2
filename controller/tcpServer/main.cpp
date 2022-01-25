#include "mainwindow.h"
#include <QApplication>

void delay(int);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    while (true){
        if (w.getAsk() == true)
            w.delay(1);
        w.askData();
    }
    w.show();
    return a.exec();
}

