/*
let Servo = {
    _create: ffi('void* mgos_servo_create()'),
    _create_full: ffi('void* mgos_servo_create_full(int, int, int)'),
    _close: ffi('void mgos_servo_delete(void*)'),
    _do_time: ffi('int mgos_servo_doTime(void*, int)'),
    _do_time_timer: ffi('int mgos_servo_doTimeWithTimer(void*, int, int)'),
    _do_angle: ffi('int mgos_servo_doAngle(void* , int)'),
    _do_angle_timer: ffi('int mgos_servo_doAngleWithTimer(void*, int, int)'),
    _stop: ffi('void mgos_servo_stop(void*)'),

    // ## **`Servo.create()`**
    // Create and return an instance of a Servo object
    // using the settings defined in mos.yml:
    //   - ["Servo.pin", "i", {title: "The GPIO pin"}]
    //   - ["Servo.tmin", "i", 1000, {title: "Pulse width for 0 degrees in microseconds (default 1000)"}]
    //   - ["Servo.tmax", "i", 2000, {title: "Pulse width for 180 degrees in microseconds (default 2000)"}]
    //
    // Example:
    // ```javascript
    // let servo = Servo.create();
    // ```
    create: function () {
        let obj = Object.create(Servo._proto);
        // Initialize Servo library.
        // Return value: handle opaque pointer.
        obj.servo = Servo._create();
        return obj;
    },

    // ## **`Servo.create()`**
    // Create and return an instance of a Servo object
    // using the `pin`, `tmin` and `tmax`
    // See above.
    //
    // Example:
    // ```javascript
    // let servo = Servo.createFull(pin, tmin, tmax);
    // ```
    createFull: function (pin, tmin, tmax) {
        let obj = Object.create(Servo._proto);
        // Initialize Servo library.
        // Return value: handle opaque pointer.
        obj.servo = Servo._create_full(pin, tmin, tmax);
        return obj;
    },
    _proto: {
        // ## **`servo.close()`**
        // Close Servo handle. Return value: none.
        close: function () {
            Servo._close(this.servo);
        },

        // ## **`Servo.doTime(onTime)`**
        // Generates pwm with "on" `onTime` microseconds
        // The library constrains the `onTime` between `tmin` and `tmax` defined at object creation
        // Returns onTime if `this.servo` is not null, -1 otherwise
        doTime: function (onTime) {
            return Servo._do_time(this.servo, onTime);
        },

        // ## **`Servo.doTimeWithTimer(onTime, timer)`**
        // Generates pwm with "on" `onTime` microseconds
        // and stops after `timer` milliseconds
        // The library constrains the `onTime` between `tmin` and `tmax` defined at object creation
        // Returns onTime if `this.servo` is not null, -1 otherwise
        doTimeWithTimer: function (onTime, timer) {
            return Servo._do_time_timer(this.servo, onTime, timer);
        },

        // ## **`Servo.doAngle(angle)`**
        // Generates pwm to move the servo to the specified `angle`
        // The library constrains the angle between 0 and 180 degrees.
        // Returns onTime if `this.servo` is not null, -1 otherwise
        doAngle: function (angle) {
            return Servo._do_angle(this.servo, angle);
        },

        // ## **`Servo.doAngleWithTimer(angle, timer)`**
        // Generates pwm to move the servo to the specified `angle`
        // and stops after `timer` milliseconds
        // The library constrains the angle between 0 and 180 degrees.
        // Returns onTime if `this.servo` is not null, -1 otherwise
        doAngleWithTimer: function (angle, timer) {
            return Servo._do_angle_timer(this.servo, angle, timer);
        },

        // ## **`servo.stop()`**
        // Stops the pwm. Return value: none.
        stop: function () {
            Servo._stop(this.servo);
        },
    }
};
*/