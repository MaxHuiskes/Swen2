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

    virtual void toggleMotor() = 0;
    virtual void setBlock(cblock * blck) = 0;
    virtual int  getBeltNr() = 0;


};

#endif // IBELT_H
