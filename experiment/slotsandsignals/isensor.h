#ifndef ISENSOR_H
#define ISENSOR_H


class ISensor
{
public:
    ISensor();

    virtual bool getSensorStatus() = 0;

private:
    bool waarde;
};

#endif // ISENSOR_H
