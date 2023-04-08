#include <Servo.h>
#include <SoftwareSerial.h>

Servo tap_servo;
int sensor_pin = 4;
int tap_servo_pin = 5;
int handCount = 0;  // counter for the number of times hand is detected
int val;

void setup() {
  Serial.begin(9600);
  pinMode(sensor_pin, INPUT);
  tap_servo.attach(tap_servo_pin);
}

void loop() {
  val = digitalRead(sensor_pin);

  if (val == 0) {

    Serial.println(handCount);

    // increment hand count

    if (handCount % 2 == 1) {  // odd number of hand detections
      tap_servo.write(90);
    }
    else if (handCount % 2 == 0) {
      tap_servo.write(0);

    }
    handCount++;
    delay(1500);

  }
}
