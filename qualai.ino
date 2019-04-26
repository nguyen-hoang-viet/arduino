void setup() {
  // put your setup code here, to run once:
  for (int i=5;i<=9;i++){
    pinMode(i,OUTPUT);
  }

}
void qualai(){
  for (int i=5;i<=9;i++){
    digitalWrite(i,HIGH);
    delay(100);
    digitalWrite(i,LOW);
    delay(100);
  }
   for (int i=9;i>=5;i--){
    digitalWrite(i,HIGH);
    delay(100);
    digitalWrite(i,LOW);
    delay(100);
  }
}

void nhapnhay(){
  for (int j=5;j<=9;j++)
    digitalWrite(j,HIGH);
  delay(100);
  for (int j=5;j<=9;j++)
    digitalWrite(j,LOW);
  delay(100);
    
}
void loop() {
  // put your main code here, to run repeatedly:
  for (int i=1;i<=3;i++)
  qualai();
  delay(1000);
  for (int i=1;i<=10;i++)
  nhapnhay();
  delay(1000);

}
