int button = 4;
bool state = false;
bool ledState = false;

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool newState = digitalRead(button);
  if(newState == HIGH && state == LOW)
  {
    ledState = !ledState;
    digitalWrite(LED_BUILTIN, ledState);
    Serial.println("state changed");
  }
  state = newState;
}
