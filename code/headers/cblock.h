#ifndef CBLOCK_H
#define CBLOCK_H
#include <QString>

class cblock
{
public:
    cblock(QString info);

public:

    bool high; // 0 is low, 1 high
    bool metal; // 0 is plastic 1 is metal
    QString print; // to write to CBelt
    bool noBlock; // 0 is block, 1 is no Block

private:
    const QString lowP  = "Low plastic";
    const QString highP = "High plastic";
    const QString lowM  = "Low metal";
    const QString highM = "High metal";
};

#endif // CBLOCK_H
