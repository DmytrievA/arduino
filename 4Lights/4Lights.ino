void setup() {
  // setting used pits to output mode
  //so there will be curent that light diods
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

int t=500;
int max = 500;
int min = 25;
int add = 25;

void loop() {
  if(t == min || t == max)
  {
    add = -add;
  }
  digitalWrite(8, HIGH);
  delay(t);
  digitalWrite(9, HIGH);
  delay(t);
  digitalWrite(10, HIGH);
  digitalWrite(8, LOW);
  delay(t);
  digitalWrite(11, HIGH);
  digitalWrite(9, LOW);
  delay(t);
  digitalWrite(10, LOW);
  delay(t);
  digitalWrite(11, LOW);
  delay(t);
  t+=add;
  // digitalWrite(8, LOW);
  // digitalWrite(9, LOW);
  // digitalWrite(10, LOW);
  // digitalWrite(11, LOW);
  // delay(1000);
}
