const int apiPin = 2;
const int toolPin = 4;
const int webPin = 7;
const int resetPin = 8;

int apiState = 0, toolState = 0, webState = 0, resetState = 0,
    lastApiState = 0, lastToolState = 0, lastWebState = 0, lastResetState = 0;

void setup() {
    // initialize input buttons
    pinMode(apiPin, INPUT);
    pinMode(toolPin, INPUT);
    pinMode(webPin, INPUT);
    pinMode(resetPin, INPUT);

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

    resetState = digitalRead(resetPin);
    if (resetState != lastResetState) {
        if (resetState == HIGH) {
            output = "0";
        }
    }
    lastResetState = resetState;

    if (output.length() != 0) {
        Serial.println(output);
    }
    delay(100);
}
// /dev/tty.usbmodem1421
