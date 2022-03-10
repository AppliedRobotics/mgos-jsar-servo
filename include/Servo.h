#ifndef SERVO_H
#define SERVO_H

#include <stdint.h>

#define MAX_SERVOS      8
#define MIN_PULSE_WIDTH       500     // the shortest pulse sent to a servo  
#define MAX_PULSE_WIDTH      2500     // the longest pulse sent to a servo 
#define DEFAULT_PULSE_WIDTH  1500     // default pulse width when servo is attached
#define PWM_FREQ             50       //  
#define PERIOD_US            (1000000UL / PWM_FREQ)       //  

#define INVALID_SERVO         255     // flag indicating an invalid servo index

class Servo
{
public:
    Servo();
    uint8_t attach(uint8_t pin);           
    uint8_t attach(uint8_t pin, uint16_t min, uint16_t max); 
    void detach();
    uint16_t write(uint16_t value);           
    uint16_t writeMicroseconds(uint16_t value);  
    int read();                       
    uint16_t readMicroseconds();            
    bool attached();                   
private:
    uint8_t servoIndex_;               
    uint16_t us_;
    uint16_t min_pulse_;                         
    uint16_t max_pulse_;                         

};

#endif // SERVO_H