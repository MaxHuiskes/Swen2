#ifndef IBELT_H
#define IBELT_H
#include <QString>
#include <QObject>
class cblock;
class iBelt : public QObject
{
public:
    iBelt(){}
    virtual ~iBelt(){}

public:

    virtual void    toggleMotor()                  = 0;
    virtual void    setBlock(cblock * blck)        = 0;
    virtual int     getBeltNr()                    = 0;
    virtual int     getLowSensorValue()            = 0;
    virtual void    setNoBlock(cblock *blck)       = 0;
    virtual bool    getOccupiedStatus()            = 0;
    virtual void    setOccupiedStatus(bool)        = 0;
    virtual int     getMotorStatus()               = 0;
    virtual void    resetSensor()                  = 0;

};

#endif // IBELT_H
