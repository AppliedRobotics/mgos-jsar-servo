#include <mgos.h>
#include <mgos_pwm.h>

#include "Servo.h"

uint8_t ServoCount = 0; // the total number of attached servos
uint8_t servos[MAX_SERVOS];

Servo::Servo()
{
    if (ServoCount < MAX_SERVOS)
    {
        servoIndex = ServoCount++;
    }
    else
    {
        servoIndex = INVALID_SERVO; // too many servos
    }
}

uint8_t Servo::attach(uint8_t pin)
{
    return attach(pin, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
}

uint8_t Servo::attach(uint8_t pin, uint16_t min, uint16_t max)
{
    servos[servoIndex] = pin;

    float duty = (float) DEFAULT_PULSE_WIDTH / PERIOD_US;
    mgos_pwm_set(pin, PWM_FREQ, duty);

    min = (MIN_PULSE_WIDTH - min);
    max = (MAX_PULSE_WIDTH - max);
    return servoIndex;
}

void Servo::detach()
{
    //delete servos[this->servoIndex];
    //servos[this->servoIndex] = NULL;
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

void Servo::writeMicroseconds(uint16_t value)
{
    if (value < MIN_PULSE_WIDTH) // ensure pulse width is valid
        value = MIN_PULSE_WIDTH;
    else if (value > MAX_PULSE_WIDTH)
        value = MAX_PULSE_WIDTH;

    float duty = (float) value / PERIOD_US;
    mgos_pwm_set(servos[servoIndex], PWM_FREQ, duty);
}

int Servo::read() // return the value as degrees
{
    return 0;
    //return map(readMicroseconds(), SERVO_MIN(), SERVO_MAX(), 0, 180);
}

int Servo::readMicroseconds()
{

    return 0;
}

bool Servo::attached()
{
    return 0;
}