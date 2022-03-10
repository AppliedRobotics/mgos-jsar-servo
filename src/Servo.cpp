#include <mgos.h>
#include <mgos_pwm.h>

#include "Servo.h"

uint8_t ServoCount = 0;     // the total number of attached servos
uint8_t servos[MAX_SERVOS]; // servo - pin

Servo::Servo()
{
    if (ServoCount < MAX_SERVOS) 
    {
        servoIndex_ = ServoCount++;
        servos[servoIndex_] = 0;
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
    servos[servoIndex_] = 0;
}

uint16_t Servo::write(uint16_t value)
{
    if (0 == servos[servoIndex_])
        return 0;

    if (value > 180)
      value = 180;

    float degree;

    if (value < 90) {
        degree = (float)(DEFAULT_PULSE_WIDTH - min_pulse_) / 90;
        return writeMicroseconds(DEFAULT_PULSE_WIDTH - (uint16_t)(degree * (90 - value)));
    }
    else if (value > 90) {
        degree = (float)(max_pulse_ - DEFAULT_PULSE_WIDTH) / 90;
        return writeMicroseconds(DEFAULT_PULSE_WIDTH + (uint16_t)(degree * (value - 90)));
    }
    else {
        return writeMicroseconds(DEFAULT_PULSE_WIDTH);
    }
     
    return 0; 

}

uint16_t Servo::writeMicroseconds(uint16_t value)
{
    if (0 == servos[servoIndex_])
        return 0;

    if (value < min_pulse_) // ensure pulse width is valid
        value = min_pulse_;
    else if (value > max_pulse_)
        value = max_pulse_;

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