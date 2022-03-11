let Servo = {
    _create: ffi('void* mgos_servo_create()'),
    _attach: ffi('int mgos_servo_attach(void*, int)'),
    _attach_full: ffi('int mgos_servo_attach_full(void*, int, int, int)'),
    _write_us: ffi('int mgos_servo_write_us(void*, int)'),
    _read_us: ffi('int mgos_servo_read_us(void*)'),
    _write: ffi('int mgos_servo_write(void*, int)'),
    _read: ffi('int mgos_servo_read(void*)'),

    create: function () {
        let obj = Object.create(Servo._proto);
        obj.servo = Servo._create();
        return obj;
    },

    _proto: {
        attach: function (pin) {
           return Servo._attach(this.servo, pin);
        },

        attach_full: function (pin, min, max) {
            return Servo._attach_full(this.servo, pin, min, max);
        },

        write_us: function (us) {
            return Servo._write_us(this.servo, us);
        },

        read_us: function () {
            return Servo._read_us(this.servo);
        },

        write: function (angle) {
            return Servo._write(this.servo, angle);
        },

        read: function () {
            return Servo._read(this.servo);
        }
    }
};
