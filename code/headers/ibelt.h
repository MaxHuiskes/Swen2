#ifndef IBELT_H
#define IBELT_H

class iBelt
{
public:
    iBelt(){}
     virtual ~iBelt(){}

public:

    virtual void move(int) = 0; //aan/uit van motor en richting

};

#endif // IBELT_H
