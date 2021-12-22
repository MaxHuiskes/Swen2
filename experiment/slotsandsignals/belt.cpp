#include "belt.h"

belt::belt()
{
public:
    belt();


    bool getBeltOccupied();
    void setBeltOccupied(bool _occupied);


private:
    int beltLength;
    bool motor;
    bool occupied;
}
