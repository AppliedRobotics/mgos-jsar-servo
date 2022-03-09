#include "mgos_jsar_servo.h"


/*
 creates a servo object using the settings defined in mos.yml
 */
Servo* mgos_servo_create()
{
    return new Servo();
}

/*
 creates a servo object 
 */
uint8_t mgos_servo_attach(Servo *obj, int pin)
{
    if (obj == nullptr) {
        return 0;
    }

    return obj->attach(pin);
}

/*
 creates a servo object using full settings
 */
uint8_t mgos_servo_attach_full(Servo *obj, int pin, uint16_t min, uint16_t max)
{
    if (obj == nullptr) {
        return 0;
    }

    return obj->attach(pin, min, max);
}


/*
 Write microseconds
 */
uint16_t mgos_servo_write_us(Servo *obj, uint16_t value)
{
    if (obj == nullptr) {
        return 0;
    }

    return obj->writeMicroseconds(value);
}

/*
 Read microseconds
 */
uint16_t mgos_servo_read_us(Servo *obj)
{
    if (obj == nullptr) {
        return 0;
    }

    return obj->readMicroseconds();
}