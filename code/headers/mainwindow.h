#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QTcpSocket>

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
    void setBlockBelt2();
    void setBlockBelt3();


public slots:
    void on_clicked();
    void on_lowP_clicked();
    void on_highP_clicked();
    void on_lowM_clicked();
    void on_highM_clicked();
    void onReadyRead();
    void checkBelt();

private:
    Ui::MainWindow *ui;
    cBelt *mBelt1;
    cBelt *mBelt2;
    cBelt *mBelt3;
    QUIBelt *mQUIbelt1;
    QUIBelt *mQUIbelt2;
    QUIBelt *mQUIbelt3;
    QCheckBox *lowP;
    QCheckBox *highP;
    QCheckBox *lowM;
    QCheckBox *highM;
    cblock *Block;
    cblock *noBlock;
    QTcpSocket  _socket;

};
#endif // MAINWINDOW_H
