#ifndef CMOTOR_H
#define CMOTOR_H
#include <QWidget>
#include <QLabel>
class cblock;
class cmotor : public QWidget
{
     Q_OBJECT
public:
    cmotor(cblock *);
    virtual ~cmotor() {}
    void moveMotor(); // bewegen van motor en richting
    void printLabel();

public slots:


private:
    cblock *blck;
    QLabel mLabel;
};


#endif // CMOTOR_H
