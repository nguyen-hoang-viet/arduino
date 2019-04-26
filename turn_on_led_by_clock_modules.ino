#include <virtuabotixRTC.h> //thư viện của clock modules 

virtuabotixRTC myRTC(A0, A1, A2);

#define BUTTON1 A5
#define BUTTON2 A4
#define LED_0 13
#define LED_1 9
#define LED_2 10
#define LED_3 11
#define LED_4 12

byte bat[10][7] = {
  // A,B,C,D,E,F,G
  0, 0, 0, 0, 0, 0, 1, //=0
  1, 0, 0, 1, 1, 1, 1, //=1
  0, 0, 1, 0, 0, 1, 0, //=2
  0, 0, 0, 0, 1, 1, 0, //=3
  1, 0, 0, 1, 1, 0, 0, //=4
  0, 1, 0, 0, 1, 0, 0, //=5
  0, 1, 0, 0, 0, 0, 0, //=6
  0, 0, 0, 1, 1, 0, 1, //=7
  0, 0, 0, 0, 0, 0, 0, //=8
  0, 0, 0, 0, 1, 0, 0 //=9
};

int value, n1, n2, n3, n4;
int a[6];
int j, m, n, l, t;

void turn_on(int LED, int digit) {
  for (int i = 9; i <= 12; i++)
    digitalWrite(i, LOW);
  digitalWrite(LED, HIGH);
  for (int i = 2; i <= 8; i++)
    digitalWrite(i, bat[digit][i - 2]);
}

void hien() {
  turn_on(LED_1, n1);
  delay(1);
  turn_on(LED_2, n2);
  delay(1);
  turn_on(LED_3, n3);
  delay(1);
  turn_on(LED_4, n4);
  delay(1);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 2; i <= 13; i++)
    pinMode(i, OUTPUT);
  pinMode (BUTTON1, INPUT);
  pinMode (BUTTON2, INPUT);
  j = 0;
  digitalWrite(LED_0, HIGH);
  l = 1; //xác định đèn đang bật hay tắt (1: bật || 0: tắt)
  m = 0; //xác định thời gian bật/tắt đèn
  n = 20;
  myRTC.updateTime();
  t = myRTC.seconds;
}

void loop() {
  // put your main code here, to run repeatedly:
  myRTC.updateTime();
  if (t == 59) t = -1;
  if (myRTC.seconds - t == 1) {
    t = myRTC.seconds;
    m++;
  }
  if (m == n && l == 1) {
    digitalWrite(LED_0, LOW);
    l = 0;
    m = 0;
    n = 30;
  }
  if (m == n && l == 0) {
    digitalWrite(LED_0, HIGH);
    l = 1;
    m = 0;
    n = 20;
  }
  a[0] = myRTC.dayofmonth;
  a[1] = myRTC.month;
  a[2] = myRTC.year;
  a[3] = myRTC.hours;
  a[4] = myRTC.minutes;
  a[5] = myRTC.seconds;
  value = a[j];
  n4 = value % 10;
  n3 = value % 100 / 10;
  n2 = value % 1000 / 100;
  n1 = value % 10000 / 1000;
  hien();
  if (digitalRead(BUTTON1) == 1) {
    j++;
    if (j == 6) j = 0;
    digitalWrite(LED_4, LOW);
    delay(200);
  }
  if (digitalRead(BUTTON2) == 1) {
    j--;
    if (j == -1) j = 5;
    digitalWrite(LED_4, LOW);
    delay(200);
  }
  Serial.print(t);
  Serial.print("\n");
  //Serial.print(m);
  //Serial.print("\n");
}
