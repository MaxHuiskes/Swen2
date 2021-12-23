#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include "quibelt.h"
#include "cbelt.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(nullptr);

    w.show();
    return a.exec();
}
