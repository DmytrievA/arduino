void setup() {
  // put your setup code here, to run once:
  for(int i=1;i<11;i++)
  {
    pinMode(i, OUTPUT);
  }
}

void offAll()
{
  for(int i=1;i<11;i++)
  {
    digitalWrite(i, LOW);
    //delay(300);
  }
}

int turnedOn = 0;

void loop() {
  for(int i=1;i<11;i++)
  {
    if(i<=turnedOn)
    {
      digitalWrite(i, HIGH);
    }
    else
    {
      digitalWrite(i, LOW);
    }
  }
  delay(100);
  turnedOn= (turnedOn+1)%11;
  return;
  // put your main code here, to run repeatedly:
  for(int i=1;i<11;i++)
  {
    if(i%2==0)
    {
      digitalWrite(i, HIGH);
    }
  }
  delay(300);
  offAll();
  delay(300);
  for(int i=1;i<11;i++)
  {
    if(i%2==1)
    {
      digitalWrite(i, HIGH);
    }
  }
  delay(300);
  offAll();
  delay(300);
}
