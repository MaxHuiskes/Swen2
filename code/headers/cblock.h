#ifndef CBLOCK_H
#define CBLOCK_H


class cblock
{
public:
    cblock();

public:
    int blockCount;
    int materiaal;

    void block(int,int);
    int order();
};

#endif // CBLOCK_H
