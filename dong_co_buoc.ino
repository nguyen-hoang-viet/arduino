// Công thức tính số bước thật của động cơ
//Số bước thật = Số bước lý thuyết * tỉ lệ bánh răng(=64)

#include <Stepper.h>

unsigned int  tyle= 64; // tỷ lệ bánh răng

const int  b = tyle * 64; // số bước thực tế

Stepper myStepper(tyle, 8, 10, 9, 11);

char button;

void setup() {
  // Stepper library sets pins as output

  myStepper.setSpeed(500); // Thiết đặt tốc độ của động cơ
  Serial.begin(9600);

}

void loop() {

  // quay ngược
  //Serial.println("clockwise");
  //myStepper.step(b);
  //delay(500);

  // quay xuôi
  /*Serial.println("counterclockwise");
    myStepper.step(-b);
    delay(500);*/

  if (Serial.available() > 1)
    button = Serial.read();
  Serial.println(Serial.available());
  if (button == '1')
  {
    myStepper.step(b);
  }

}
