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
  // constantly read button value
  bool newState = debounce(state);
  if(newState == HIGH && state == LOW)
  {//if button was pressed
    ledState = !ledState;//reverce LED state
    digitalWrite(LED_BUILTIN, ledState);//set LED state
    Serial.println("state changed");//print for debug
  }
  state = newState;//save button state
}

//to read of noise
boolean debounce(boolean state) {
  boolean current = digitalRead(button);//get current value
  if(state != current) {//if button state was changed
    delay(5);//some wait to ensure that is intended
    current = digitalRead(button);//reread value
    return current;//return more accurate value
  }
}