#include <Servo.h>

Servo servo;
int angle = 270;
const int trigPin = 8;
const int echoPin = 7;
long duration;
int distance;

void setup() {
  servo.attach(5);
  servo.write(angle);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600); 
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;

  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);

  if(distance<20)
  {
    servo.write(180);
    delay(2000);
  }
  else
  {
      servo.write(70);
  }
}
