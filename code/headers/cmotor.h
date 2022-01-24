#ifndef CMOTOR_H
#define CMOTOR_H
#include <QWidget>
#include <QLabel>

class cmotor : public QWidget
{
     Q_OBJECT
public:
    cmotor();
    virtual ~cmotor();
    void toggleMotor();         // toggle motor
    bool getMotorStatus();      // get motor status, 0 if off, 1 if on

    void motorNotifySensor();   // if xx time has passed, send 1 to sensor, block has arrived at sensor

private:
    bool motorStatusOn;         // status of motor, 0 if off, 1 if on

signals:

};


#endif // CMOTOR_H
