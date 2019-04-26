#define BUTTON1 3
#define BUTTON2 4
#define LED 11

int i = 25;

void setup() {
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void nhay(int n) {
  for (int j = 1; j <= n; j++) {
    digitalWrite(LED, HIGH);
    delay(100);
    digitalWrite(LED, LOW);
    delay(100);
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(digitalRead(BUTTON2));
  analogWrite(LED, i);
  if (digitalRead(BUTTON1) == 0 && i <= 225) {
    i = i + 25;
    delay(200);
    Serial.println(digitalRead(BUTTON1));
    if (i == 250) {
      nhay(3);
      return 0;
    }
  }
  if (digitalRead(BUTTON2) == 1 && i >= 25) {
    i = i - 25;
    delay(200);
    //Serial.println(digitalRead(BUTTON2));
    if (i == 0) {
      nhay(1);
      return 0;
    }
  }
}
