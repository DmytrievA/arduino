int buttonPins[] = {2,3,4,5};
int lastButtonStates[] = {0,0,0,0};
int currentButtonStates[] = {0,0,0,0};

int ledPins[] = {8,9,10};

void setup() {
  for(int i=0;i<4;i++)
  {
    pinMode(buttonPins[i], INPUT);
  }
  for(int i=0;i<3;i++)
  {
    pinMode(ledPins[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  for(int i=0;i<4;i++)
  {
    currentButtonStates[i] = debounce(lastButtonStates[i], buttonPins[i]);
    if(lastButtonStates[i] == 0 && currentButtonStates[i] == 1) {
      for(int j=0;j<4;j++)
      {
        Serial.print(j); Serial.print(": "); Serial.print(currentButtonStates[j]);
        Serial.println("\t");
      }
      doButtons(i);
      delay(400);
    }
    lastButtonStates[i] = currentButtonStates[i];
  }
}

void doButtons(int pressedButton) {
  switch (pressedButton) {
    case 0:
      digitalWrite(ledPins[0], HIGH);
      break;
    case 1:
      digitalWrite(ledPins[1], HIGH);
      break;
    case 2:
      digitalWrite(ledPins[2], HIGH);
      break;
    case 3: 
      for(int i=0;i<3;i++)
      {
        digitalWrite(ledPins[i], LOW);
      }
      break;
  }

  Serial.print("button pressed: ");
  Serial.println(pressedButton);
}

//to read of noise
boolean debounce(boolean state, int pin) {
  boolean current = digitalRead(pin);//get current value
  if(state != current) {//if button state was changed
    delay(5);//some wait to ensure that is intended
    current = digitalRead(pin);//reread value
    return current;//return more accurate value
  }
}