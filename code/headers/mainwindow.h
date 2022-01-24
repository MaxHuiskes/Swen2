#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTcpSocket>
#include <QMainWindow>

class cBelt;

class QUIBelt;

class QCheckBox;

class cblock;

class cLift;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent);
    ~MainWindow();
    void checkSorteer();

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
    cLift *mLift;
    cBelt *mBelt5;
    cBelt *mSort;
    cBelt *mStore;
    cBelt *mBelt8;
    cBelt *mBelt9;
    cBelt *mBelt10;
    cBelt *mBelt11;
    QUIBelt *mQUIbelt1;
    QUIBelt *mQUIbelt2;
    QUIBelt *mQUIbelt3;
    QUIBelt *mQUILift;
    QUIBelt *mQUIbelt5;
    QUIBelt *mQUISort;
    QUIBelt *mQUIStore;
    QUIBelt *mQUIbelt8;
    QUIBelt *mQUIbelt9;
    QUIBelt *mQUIbelt10;
    QUIBelt *mQUIbelt11;
    QCheckBox *lowP;
    QCheckBox *highP;
    QCheckBox *lowM;
    QCheckBox *highM;
    cblock *Block;
    cblock *noBlock;
    QTcpSocket  _socket;
    std::string order;

};
#endif // MAINWINDOW_H
