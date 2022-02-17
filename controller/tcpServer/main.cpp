#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    while (true){
        if (w.getAsk() == true)
            w.delay(2);
        w.askData();
    }
    w.show();
    return a.exec();
}

