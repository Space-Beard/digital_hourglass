// Switch pin
const int switchPin = 8;

// variable to hold the last time an LED was changed
unsigned long previousTime = 0;

//variables to check the state of the switch
int switchState = 0;
int prevSwitchState = 0;

//variable used to tell which LED pin is the next to turn on
int led = 2;

//used to set the interval between lighting each LED
long interval = 6000;

void setup() {
  // set pins 2-7 for output
  for( int x = 2; x < 8; x++){
    pinMode(x, OUTPUT);
  }

  // set pin switch is connected to for input
  pinMode(switchPin, INPUT);

}

void loop() {
  // get how long the arduino has been running and store the value
  unsigned long currentTime = millis();

  // check to see if enough time has elapsed, if it's the case
  // sets the previousTime variable, turns on the next LED and increments
  // the led variable to the next pin to be set HIGH.
  if (currentTime - previousTime > interval) {
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    led++;
  }

  // checks to see if the final LED is lit
  if (led > 8) {
    // flashes the LEDS once they are all lit
    for (int x = 7; x > 1; x--) {
      digitalWrite(x, LOW);
      delay(20);
    }

    delay(125);
    
    for (int x = 2; x < 8; x++) {
      digitalWrite(x, HIGH);
      delay(20);
    }

    delay(125);
    
  }

  // gets the state of the switch
  switchState = digitalRead(switchPin);

  // Checks to see if the switch state has changed since the loop last ran
  // If it has, it resets the LEDs and the previousTime variable
  if (switchState != prevSwitchState) {
    for (int x = 2; x < 8; x++) {
      digitalWrite(x, LOW);
    }

    led =2;
    previousTime = currentTime;
  }

  // sets the prevSwitchState so it can be checked the next time the loop is run
  prevSwitchState = switchState;

}
