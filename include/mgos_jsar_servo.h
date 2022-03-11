#ifndef MGOS_SERVO_H
#define MGOS_SERVO_H

#ifdef __cplusplus
#include "Servo.h"
#else
typedef struct ServoTag Servo;
#endif

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/*
 creates a servo object using the settings defined in mos.yml
 */
Servo* mgos_servo_create();

/*
 creates a servo object
 */
uint8_t mgos_servo_attach(Servo * obj, int pin);

/*
 creates a servo object using full settings
 */
uint8_t mgos_servo_attach_full(Servo *obj, int pin, uint16_t min, uint16_t max);

/*
 Write microseconds
 */
uint16_t mgos_servo_write_us(Servo *obj, uint16_t value);

/*
 Read microseconds
 */
uint16_t mgos_servo_read_us(Servo *obj);

/*
 Write angle  
 */
uint16_t mgos_servo_write(Servo *obj, uint16_t value);

/*
 Read angle
 */
uint16_t mgos_servo_read(Servo *obj);



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // MGOS_SERVO_H