#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class cBelt;


class QUIBelt;

class QCheckBox;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent);
    ~MainWindow();


public slots:
     void on_clicked();
     void on_checkBox_clicked();
     void on_checkBox1_clicked();
     void on_checkBox2_clicked();
     void on_checkBox3_clicked();
     void on_checkBox4_clicked();
     void on_checkBox5_clicked();

private slots:



private:
    Ui::MainWindow *ui;
    cBelt *mBelt;
    QUIBelt *mQUIbelt;
    QCheckBox *checkbox;
    QCheckBox *checkbox1;
    QCheckBox *checkbox2;
    QCheckBox *checkbox3;
    QCheckBox *checkbox4;
    QCheckBox *checkbox5;
    QString blck;

};
#endif // MAINWINDOW_H
