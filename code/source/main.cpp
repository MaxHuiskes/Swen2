#include "headers/mainwindow.h"

#include <QApplication>
#include "quibelt.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QUIBelt* invoerband;
    invoerband = new QUIBelt(&w);
    invoerband->setGeometry(100,100,200,200);

    w.show();
    return a.exec();
}
