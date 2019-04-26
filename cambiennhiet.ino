#define LM35 A0
#define RED 10
#define YELLOW 9
#define GREEN 8

float temp;

void setup() {
  // put your setup code here, to run once:
  pinMode(LM35, INPUT);
  for (int i = 8; i <= 10; i++)
    pinMode(i, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  temp=((5.0*analogRead(LM35))/1024.0)*100.0;
  Serial.println(temp,2);
  delay(500);
  
}
