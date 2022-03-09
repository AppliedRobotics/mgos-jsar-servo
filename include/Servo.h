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
    uint8_t attach(uint8_t pin);           // attach the given pin to the next free channel, sets pinMode, returns channel number or INVALID_SERVO if failure
    uint8_t attach(uint8_t pin, uint16_t min, uint16_t max); // as above but also sets min and max values for writes. 
    void detach();
    void write(int value);             // if value is < 200 its treated as an angle, otherwise as pulse width in microseconds 
    void writeMicroseconds(uint16_t value); // Write pulse width in microseconds 
    int read();                        // returns current pulse width as an angle between 0 and 180 degrees
    uint16_t readMicroseconds();            // returns current pulse width in microseconds for this servo (was read_us() in first release)
    bool attached();                   // return true if this servo is attached, otherwise false 
private:
    uint8_t servoIndex_;               // index into the channel data for this servo
    uint16_t us_;
    int8_t min_;                       // minimum is this value times 4 added to MIN_PULSE_WIDTH    
    int8_t max_;                       // maximum is this value times 4 added to MAX_PULSE_WIDTH   

};

#endif // SERVO_H