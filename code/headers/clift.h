#ifndef CLIFT_H
#define CLIFT_H
#include "cpushrot.h"
#include "cbelt.h"


class cLift
{
public:
    cLift();
public:
    void getBlock(int); //voor het krijgen van een blok van de vorige band, int voor welke het is
private:
    cBelt liftBelt;
    cpushrot pushrod;
    int liftPos; //status van de lift (omhoog/omlaag)
};

#endif // CLIFT_H
