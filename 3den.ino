#define BUTTON_1 3 
#define BUTTON_2 4
#define BUTTON_3 5
#define LED_1 10
#define LED_2 11
#define LED_3 12

void setup() {
  // put your setup code here, to run once:
  for (int i=10;i<=12;i++)
    pinMode(i,OUTPUT);
  for (int i=3;i<=5;i++)
    pinMode(i,INPUT);
}

void turnon(int n){
  //bật đèn n

  digitalWrite(n,HIGH);
  do
  {}while(1);
  //turnon(n);
}
void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(BUTTON_1)==0) turnon(LED_1);
  if (digitalRead(BUTTON_2)==0) turnon(LED_2);
  if (digitalRead(BUTTON_3)==0) turnon(LED_3);
}
