#include "isensor.h"

ISensor::ISensor()
{
public:
    ISensor();

    virtual bool getSensorStatus() = 0;

private:
    bool waarde;
}
