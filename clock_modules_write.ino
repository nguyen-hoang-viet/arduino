#include <virtuabotixRTC.h> //thư viện của clock modules 

virtuabotixRTC myRTC(A0, A1, A2);

int m;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  m = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  myRTC.updateTime();
  if (myRTC.seconds % 2 == 0) m++;
  if (myRTC.seconds % 2 == 1) m++;
  Serial.print(myRTC.dayofweek);
  Serial.print(" ");
  Serial.print(myRTC.dayofmonth);
  Serial.print("/");
  Serial.print(myRTC.month);
  Serial.print("/");
  Serial.print(myRTC.year);
  Serial.print(" ");
  Serial.print(myRTC.hours);
  Serial.print(":");
  Serial.print(myRTC.minutes);
  Serial.print(":");
  Serial.print(myRTC.seconds);
  Serial.print("\n");
  Serial.print(m);
  Serial.print("\n");
  delay(1000);
}
