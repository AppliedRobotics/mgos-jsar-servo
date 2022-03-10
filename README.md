Servo library for Applied Robotics ESP-JS-AR board 

Using: 

   Servo* myservo1;
   
   myservo1 = mgos_servo_create();
   
   mgos_servo_attach(myservo1, 19);

Set angle: 

   mgos_servo_write(myservo1, value);
  
Set us:

   mgos_servo_write_us(myservo1, value);
