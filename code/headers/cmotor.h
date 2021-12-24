#ifndef CMOTOR_H
#define CMOTOR_H
#include  <QObject>
class cblock;
class cmotor : public QObject
{
   // Q_OBJECT
public:
    cmotor(cblock *);
    virtual ~cmotor() {}
    void moveMotor(); // bewegen van motor en richting

public slots:
    void endTimer();

private:
    cblock *blck;
};


#endif // CMOTOR_H
