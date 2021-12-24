#ifndef CBLOCK_H
#define CBLOCK_H
#include <QString>

class cblock
{
public:
    cblock(QString info);

public:

    int size; // 1 is laag 2 is middle 3 is hoog
    int materiaal; // 1 is plastic 2 is metaal
    QString print;
private:
   const QString lowP  = "Low plastic";
   const QString middleP = "Middle plastic";
   const QString highP = "High plastic";
   const QString lowM = "Low metal";
   const QString middleM = "Middle metal";
   const QString highM = "High metal";

};

#endif // CBLOCK_H
