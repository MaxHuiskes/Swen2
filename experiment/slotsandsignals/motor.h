#ifndef MOTOR_H
#define MOTOR_H


class motor
{
public:
    motor();

    void setMotor();
    bool getMotorStatus();

private:
    bool motorOn;
};

#endif // MOTOR_H
