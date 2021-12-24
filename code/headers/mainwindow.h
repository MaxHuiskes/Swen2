#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cbelt.h"
//class cBelt;

class QUIBelt;

class QCheckBox;

class cblock;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent);
    ~MainWindow();
    cBelt *belt2 = new cBelt;
    QUIBelt* invoerband2 = new QUIBelt(this);

public slots:
     void on_clicked();
     void on_lowP_clicked();
     void on_middleP_clicked();
     void on_highP_clicked();
     void on_lowM_clicked();
     void on_middleM_clicked();
     void on_highM_clicked();


private slots:



private:
    Ui::MainWindow *ui;
    cBelt *mBelt;
    QUIBelt *mQUIbelt;
    QCheckBox *lowP;
    QCheckBox *middleP;
    QCheckBox *highP;
    QCheckBox *lowM;
    QCheckBox *middleM;
    QCheckBox *highM;
    cblock *door;

};
#endif // MAINWINDOW_H
