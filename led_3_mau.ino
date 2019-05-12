#define RED 3
#define GREEN 4
#define BLUE 5
void setup() {
  // put your setup code here, to run once:
  for (int i = 3; i <= 6; i++)
    pinMode(i, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //for (int i = 3; i <= 5; i++) {
  for (int j = 255; j >= 0; j--) {
    analogWrite(3, j);
    delay(10);
  }
  for (int j = 255; j >= 0; j--) {
    analogWrite(5, j);
    delay(10);
  }
  for (int j = 255; j >= 0; j--) {
    analogWrite(6, j);
    delay(10);
  }
  for (int j = 0; j <= 255; j++) {
    analogWrite(3, j);
    delay(10);
  }
  analogWrite(3, 0);
  for (int j = 0; j <= 255; j++) {
    analogWrite(5, j);
    delay(10);
  }
  analogWrite(5, 0);
  for (int j = 0; j <= 255; j++) {
    analogWrite(6, j);
    delay(10);
  }
  analogWrite(6, 0);
  
}
