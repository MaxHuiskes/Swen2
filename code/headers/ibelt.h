#ifndef IBELT_H
#define IBELT_H
#include <QString>

class iBelt
{
public:
    iBelt(){}
     virtual ~iBelt(){}

public:


    virtual void toggleMotor() = 0;
    virtual void setBlock(QString) = 0;
    virtual void setBelt(int nr) = 0;


};

#endif // IBELT_H
