#include "mgos_jsar_servo.h"


/*
 creates a servo object using the settings defined in mos.yml
 */
Servo* mgos_servo_create()
{
    return new Servo();
}

/*
 creates a servo object using full settings
 */
uint8_t mgos_servo_attach(Servo *obj, int pin)
{
    if (obj == nullptr) {
        return 0;
    }

    return obj->attach(pin);
}

