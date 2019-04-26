#define qtro A1
#define btro A0
#define led 8

void setup() {
  // put your setup code here, to run once:
  pinMode(btro, INPUT);
  pinMode(qtro, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a, b;
  a = analogRead(btro);
  b = analogRead(qtro);
  if (a <= b) digitalWrite(led, HIGH);
  else digitalWrite(led, LOW);
}
