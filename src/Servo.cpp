#include <mgos.h>
#include <mgos_pwm.h>

#include "Servo.h"

uint8_t ServoCount = 0; // the total number of attached servos
uint8_t servos[MAX_SERVOS];

Servo::Servo()
{
    if (ServoCount < MAX_SERVOS) 
    {
        servoIndex_ = ServoCount++;
    } 
    else 
    {
        servoIndex_ = INVALID_SERVO; // too many servos
    }
}

uint8_t Servo::attach(uint8_t pin)
{
    return attach(pin, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
}

uint8_t Servo::attach(uint8_t pin, uint16_t min, uint16_t max)
{
    servos[servoIndex_] = pin;

    float duty = (float) DEFAULT_PULSE_WIDTH / PERIOD_US;
    mgos_pwm_set(pin, PWM_FREQ, duty);

    us_ = DEFAULT_PULSE_WIDTH;
    min_pulse_ = min;
    max_pulse_ = max;
    return servoIndex_;
}

void Servo::detach()
{
    //delete servos[this->servoIndex_];
    //servos[this->servoIndex_] = NULL;
}

void Servo::write(int value)
{/*
    // treat values less than 544 as angles in degrees (valid values in microseconds are handled as microseconds)
    if (value < MIN_PULSE_WIDTH)
    {
        if (value < 0)
            value = 0;
        else if (value > 180)
            value = 180;

        value = map(value, 0, 180, SERVO_MIN(), SERVO_MAX());
    }
    writeMicroseconds(value);*/
}

uint16_t Servo::writeMicroseconds(uint16_t value)
{
    /*
    if (value < min_pulse_) // ensure pulse width is valid
        value = min_pulse_;
    else if (value > max_pulse_)
        value = max_pulse_;
*/
    float duty = (float) value / PERIOD_US;
    if (mgos_pwm_set(servos[servoIndex_], PWM_FREQ, duty) == true) {
        us_ = value;
        return value;
    }
    return 0;
}

int Servo::read() // return the value as degrees
{
    return 0;
    //return map(readMicroseconds(), SERVO_MIN(), SERVO_MAX(), 0, 180);
}

uint16_t Servo::readMicroseconds()
{
    return us_;
}

bool Servo::attached()
{
    return 0;
}