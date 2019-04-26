#define latchpin 3
#define datapin 4
#define clockpin 2
#define resetpin 5

void setup() {
  // put your setup code here, to run once:
  pinMode (datapin,OUTPUT);
  pinMode (latchpin,OUTPUT);
  pinMode (clockpin,OUTPUT);
  digitalWrite(resetpin,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  shiftOut(datapin,clockpin,MSBFIRST,0b11001101);
  digitalWrite(latchpin,HIGH);
  do{
  }while(1);
  
}
