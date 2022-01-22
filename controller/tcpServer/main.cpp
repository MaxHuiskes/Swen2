#include "mainwindow.h"
#include <QTime>
#include <QApplication>

void delay(int);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    while (true){
    delay(5);
    w.askData();
    }
    w.show();
    return a.exec();
}
void delay(int secs)
{
    QTime dieTime= QTime::currentTime().addSecs(secs);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
