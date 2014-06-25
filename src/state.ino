#include <stdlib.h>

const int apiPin = 2;
const int toolPin = 4;
const int webPin = 7;
int apiState = 0, toolState = 0, webState = 0,
lastApiState = 0, lastToolState = 0, lastWebState = 0;
boolean anyState = false;

void setup() {
  // initialize the button pin as a input:
  pinMode(apiPin, INPUT);
  pinMode(toolPin, INPUT);
  pinMode(webPin, INPUT);
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
  String output = "";
  apiState = digitalRead(apiPin);
  if (apiState != lastApiState) {
    if (apiState == HIGH) {
      output += "2";
    }
  }
  lastApiState = apiState;
  
  toolState = digitalRead(toolPin);
  if (toolState != lastToolState) {
    if (toolState == HIGH) {
      output += "4";
    }
  }
  lastToolState = toolState;
  
  webState = digitalRead(webPin);
  if (webState != lastWebState) {
    if (webState == HIGH) {
      output += "7";
    }
  }
  lastWebState = webState;
  
  if (output.length() != 0) {
      Serial.println(output);
  }
  delay(100);
}
// /dev/tty.usbmodem1421
