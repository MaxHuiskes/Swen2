#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTcpSocket>
#include <QMainWindow>
#include <QElapsedTimer>
#include <QTime>

class cBelt;
class QUIBelt;
class QCheckBox;
class cblock;
class cLift;
class QUILift;
class QLabel;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent);
    ~MainWindow();
    void checkSorteer(int);

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
    QUILift *mQUILift;
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
    QString order;
    int checkB;
    bool wait = 0;
    int lowPMax = 0;
    int lowMMax = 0;
    int highPMax = 0;
    int highMMax = 0;
    QLabel *mLabel;
    QLabel *rightOrder;
    QString strRightOrder;
    QLabel *timerPrint;
    bool clickedLowP = 0;
    bool clickedHighP = 0;
    bool clickedLowM = 0;
    bool clickedHighM = 0;
    bool reset = 0; // resets block out

};
#endif // MAINWINDOW_H
