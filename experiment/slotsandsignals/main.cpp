#include "mainwindow.h"

#include <QApplication>
#include <qobject.h>
#include <QEvent>
#include <qevent.h>

#include "belt.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    belt belt2;
    belt belt3;

    MainWindow w;
    w.show();
    return a.exec();
}


