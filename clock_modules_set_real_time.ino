#include <virtuabotixRTC.h> //thư viện của clock modules 

virtuabotixRTC myRTC(A0, A1, A2);

void setup() {
  // put your setup code here, to run once:
  myRTC.setDS1302Time(30, 11, 8, 1, 22, 4, 2019);
}

void loop() {
  // put your main code here, to run repeatedly:
  myRTC.updateTime();
}
