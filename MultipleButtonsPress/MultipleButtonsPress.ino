//made using tutorial at https://playground.arduino.cc/Main/KeypadTutorial/
//utilizes Keypad.h library https://playground.arduino.cc/Code/Keypad/
//lights LED when certain buttons are pressed

#include <Keypad.h>

int ledPins[] = {2,3,4};//LED pins
bool ledPinsState[] = {false, false, false}; //current LED states

const byte ROWS = 4; // four rows
const byte COLS = 4; // four columns

// Map the buttons to an array for the Keymap instance
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte colPins[ROWS] = {8, 7, 6, 5}; // Pins used for the rows of the keypad
byte rowPins[COLS] = {12,11,10,9}; // Pins used for the columns of the keypad

// Initialise the Keypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  for(int i=0;i<3;i++)
  {
    pinMode(ledPins[i], OUTPUT);
  }
  Serial.begin(9600);   // Initialise the serial monitor
}

void loop() {
  // Read the pushed button
  char button = customKeypad.getKey();

  if (button) {
    Serial.println(button);
  }

  switch(button) {
    case '1':
      ledPinsState[0] = !ledPinsState[0];
      digitalWrite(ledPins[0], ledPinsState[0]);
      break;
    case '2':
      ledPinsState[1] = !ledPinsState[1];
      digitalWrite(ledPins[1], ledPinsState[1]);
      break;
    case '3':
      ledPinsState[2] = !ledPinsState[2];
      digitalWrite(ledPins[2], ledPinsState[2]);
      break;
  }
}