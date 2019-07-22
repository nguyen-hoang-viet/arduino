#include <Servo.h>

#define servoPin 9

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  pinMode (8,INPUT);
  pinMode (A0, INPUT);
  pinMode (A1,INPUT);
  myservo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(analogRead(A0));
  Serial.print("\t");
  Serial.print(analogRead(A1));
   Serial.print("\t");
  Serial.println(digitalRead(8));
  int value = analogRead(A0);
  int servoPos = map(value, 0, 1023, 0, 180);
  myservo.write(servoPos);
}
