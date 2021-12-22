#ifndef PUSHROD_H
#define PUSHROD_H


class pushRod
{
public:
    pushRod();

    void setPushRod(bool _status);
    bool getPushRodStatus();

private:
    bool pushRodActive;
};

#endif // PUSHROD_H
