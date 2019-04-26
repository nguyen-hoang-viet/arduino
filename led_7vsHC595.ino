/*#define SEGMENT 7 // so doan
  #define DIGIT 16  //so luong so hien thi

  byte bat[DIGIT][SEGMENT]={
   // A,B,C,D,E,F,G
      1,1,1,1,1,1,0, //=0
      0,1,1,0,0,0,0, //=1
      1,1,0,1,1,0,1, //=2
      1,1,1,1,0,0,1, //=3
      0,1,1,0,0,1,1, //=4
      1,0,1,1,0,1,1, //=5
      1,0,1,1,1,1,1, //=6
      1,1,1,0,0,1,0, //=7
      1,1,1,1,1,1,1, //=8
      1,1,1,1,0,1,1, //=9
  };*/
#define latchpin 9
#define datapin 8
#define clockpin 10
#define resetpin 11
#define button 4
byte turn_on[10] = {
  0b11111100, //=0
  0b01100000, //=1
  0b11011010, //=2
  0b11110010, //=3
  0b01100110, //=4
  0b10110110, //=5
  0b10111110, //=6
  0b11100100, //=7
  0b11111110, //=8
  0b11110110 //=9
};

void setup() {
  // put your setup code here, to run once:
  pinMode(datapin, OUTPUT);
  pinMode(latchpin, OUTPUT);
  pinMode(resetpin, OUTPUT);
  pinMode(clockpin, OUTPUT);
  digitalWrite(resetpin, HIGH);
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, LSBFIRST, turn_on[0]);
  shiftOut(datapin, clockpin, LSBFIRST, turn_on[0]);
  shiftOut(datapin, clockpin, LSBFIRST, turn_on[0]);
  digitalWrite(latchpin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(button) == 1) {
    for (byte i = 0; i <= 9; i++) {
      for (byte j = 0; j <= 9; j++) {
        for (byte k = 0; k <= 9; k++) {
          shiftOut(datapin, clockpin, LSBFIRST, turn_on[i]);
          shiftOut(datapin, clockpin, LSBFIRST, turn_on[j]);
          shiftOut(datapin, clockpin, LSBFIRST, turn_on[k]);
          digitalWrite(latchpin, HIGH);
          delay(100);
          digitalWrite(latchpin, LOW);
        }
      }
    }
  }
  /*for (byte i=0;i<=9;i++){
    shiftOut(datapin,clockpin,LSBFIRST,turn_on[i]);
    digitalWrite(latchpin,HIGH);
    delay(1000);
    digitalWrite(latchpin,LOW);
    }*/
}
