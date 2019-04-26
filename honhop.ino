#define BUTTON 2

int value;
void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
  for (int i = 4; i <= 13; i++)
    pinMode(i, OUTPUT);
}

void qualai() {
  for (int i = 4; i < 13; i++) {
    digitalWrite(i, HIGH);
    delay(50);
    digitalWrite(i, LOW);
    delay(50);
  }
  for (int i = 13; i > 4; i--) {
    digitalWrite(i, HIGH);
    delay(50);
    digitalWrite(i, LOW);
    delay(50);
  }
}

void nhapnhay1() {
  for (int i = 4; i <= 13; i++)
    digitalWrite(i, HIGH);
  delay(100);
  for (int i = 4; i <= 13; i++)
    digitalWrite(i, LOW);
  delay(100);
}

void nhapnhay2() {
  for (int i = 4; i <= 12; i += 2)
    digitalWrite(i, HIGH);
  delay(100);
  for (int i = 4; i <= 12; i += 2)
    digitalWrite(i, LOW);
  delay(100);
}

void nhapnhay3() {
  for (int i = 5; i <= 13; i += 2)
    digitalWrite(i, HIGH);
  delay(100);
  for (int i = 5; i <= 13; i += 2)
    digitalWrite(i, LOW);
  delay(100);
}

void sangmo() {
  for (int i = 0; i <= 255; i++) {
    analogWrite(9, i);
    delay(20);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(9, i);
    delay(20);
  }
  for (int i = 0; i <= 255; i++) {
    analogWrite(10, i);
    delay(20);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(10, i);
    delay(20);
  }
  for (int i = 0; i <= 255; i++) {
    analogWrite(11, i);
    delay(20);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(11, i);
    delay(20);
  }
}

void haiben1() {
  int i, j;
  for ( i = 4, j = 13; i < 8, j > 9; i++, j--) {
    digitalWrite(i, HIGH);
    digitalWrite(j, HIGH);
    delay(50);
    digitalWrite(i, LOW);
    digitalWrite(j, LOW);
    delay(50);
  }
  for ( i = 8, j = 9; i > 4, j < 13; i--, j++) {
    digitalWrite(i, HIGH);
    digitalWrite(j, HIGH);
    delay(50);
    digitalWrite(i, LOW);
    digitalWrite(j, LOW);
    delay(50);
  }
}

void haiben2() {
  int i, j;
  for ( i = 4, j = 13; i <= 8, j >= 9; i++, j--) {
    digitalWrite(i, HIGH);
    digitalWrite(j, HIGH);
    delay(50);
  }
  for ( i = 4, j = 13; i <= 8, j >= 9; i++, j--) {
    digitalWrite(i, LOW);
    digitalWrite(j, LOW);
    delay(50);
  }
  for ( i = 8, j = 9; i >= 4, j <= 13; i--, j++) {
    digitalWrite(i, HIGH);
    digitalWrite(j, HIGH);
    delay(50);
  }
  for ( i = 8, j = 9; i >= 4, j <= 13; i--, j++) {
    digitalWrite(i, LOW);
    digitalWrite(j, LOW);
    delay(50);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  value =  digitalRead(BUTTON);
  Serial.println(value);
  if (value == 0) {
    sangmo();
    for (int i = 1; i <= 5; i++)
      qualai();
    for (int i = 1; i <= 10; i++)
      nhapnhay1();
    for (int i = 1; i <= 10; i++)
    {
      nhapnhay2();
      nhapnhay3();
    }
    for (int i = 1; i <= 5; i++)
      haiben1();
    for (int i = 1; i <= 10; i++)
      haiben2();

  }
}
