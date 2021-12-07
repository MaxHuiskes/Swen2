#include "mainwindow.h"

#include <QApplication>
#include <qobject.h>
#include <QEvent>
#include <qevent.h>

class MyEvent;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


class MyEvent : public QEvent{
public:
    MyEvent();
    virtual ~MyEvent();

    void customEvent(QEvent *event);

    // function to register and save the custom event type for the application,
    static QEvent::Type type(){
        if (customEventType == QEvent::None){
            int generatedType = QEvent::registerEventType();
            customEventType = static_cast<QEvent::Type>(generatedType);
        }
        return customEventType;
    }

private:

};

void MyEvent::customEvent(QEvent *event){
    if(event->type() == MyEvent){
        MyEvent();
    }
    else{

    }
}

class EventHandler {

};
