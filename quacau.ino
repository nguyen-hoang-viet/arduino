#define buttonA 13
#define buttonB 1
#define greenA 6
#define greenB 5
#define yellowA 7
#define yellowB 4
#define redA 8
#define redB 3

bool kt=1;

void setup() {
  // put your setup code here, to run once:
  for (int i = 3; i <= 8; i++)
  pinMode (i, OUTPUT);
  Serial.begin(9600);
  pinMode (buttonA, INPUT); //thiet lap buttonA o che do input
  pinMode (buttonB, INPUT); //thiet lap buttonB o che do input
  digitalWrite(greenA,HIGH);
  digitalWrite(redB,HIGH);
  kt=false;
}

void nhay(int n, int a) {
  //hàm nháy n lần đèn a
  for (int i = 1; i <= n; i++) {
    digitalWrite(a, HIGH);
    delay(50);
    digitalWrite(a, LOW);
    delay(50);
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  
  if (digitalRead(buttonB)==0&&kt==false){
    digitalWrite(greenA,LOW);
    nhay(3,yellowA);
    digitalWrite(redA,HIGH);
    delay(6000);  
    digitalWrite(redB,LOW);
    nhay(3,yellowB);
    digitalWrite(greenB,HIGH);
    kt=true;
  }
  if (digitalRead(buttonA)==0&&kt==true){
    digitalWrite(greenB,LOW);
    nhay(3,yellowB);
    digitalWrite(redB,HIGH);
    delay(6000);  
    digitalWrite(redA,LOW);
    nhay(3,yellowA);
    digitalWrite(greenA,HIGH);
    kt=false;
  }
}
