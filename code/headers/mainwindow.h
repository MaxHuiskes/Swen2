#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cbelt.h"
#include "quibelt.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, cBelt *belt = nullptr, QUIBelt *Uibelt =nullptr);
    ~MainWindow();
    int i = 0;


private:
    Ui::MainWindow *ui;
    cBelt *beltt1;
    QUIBelt *uiBelt;

};
#endif // MAINWINDOW_H
