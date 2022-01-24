#ifndef CPUSHROT_H
#define CPUSHROT_H


class cpushrot
{
public:
    cpushrot();
    virtual ~cpushrot();
public:
    void togglePushrod();       // switches pushrod from high to low or low to high
    bool getStatusPushrod();    // returns pushrod status, returns 0 if low, 1 if high

private:
    bool pushrodHigh;           // 0 if low, 1 if high
};

#endif // CPUSHROT_H
