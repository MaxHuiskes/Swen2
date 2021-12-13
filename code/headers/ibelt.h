#ifndef IBELT_H
#define IBELT_H

class iBelt
{
public:
    iBelt(){}
     virtual ~iBelt(){}

public:
    virtual void move(int) = 0;
};

#endif // IBELT_H
