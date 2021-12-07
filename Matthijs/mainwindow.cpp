#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

class MyEvent : public QEvent{
public:
    MyEvent();
    virtual ~MyEvent();

    static QEvent::Type type(){
        if (customEventType == QEvent::None){
            int generatedType = QEvent::registerEventType()
            customEventType = static_cast<QEvent::Type>(generatedType);
        }
        return customEventType;
    }

private:

};
