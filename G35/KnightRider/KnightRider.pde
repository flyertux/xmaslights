#include <G35.h>

// Arduino pin number. Pin 4 will blink the on-board LED.
#define OUT_PIN 4

// Total # of lights on string (usually 50, 48, or 36). Maximum is 63,
// because the protocol uses 6-bit addressing and bulb #63 is reserved
// for broadcast messages.
#define LIGHT_COUNT 50

#define SIZE 20

G35 lights(OUT_PIN, LIGHT_COUNT);  // Constructor

void setup() {
  // Enumerate lights on string to enable individual bulb addressing
  lights.enumerate_forward();
}

void loop() {
  lights.fill_color(0, SIZE, G35::MAX_INTENSITY, COLOR_BLACK);
  // loop from the lowest pin to the highest
  for (int thisLed = 0; thisLed < SIZE; thisLed++) {
    int count = 1;
    lights.set_color(thisLed, G35::MAX_INTENSITY, COLOR_RED);
    while (count <= 5) {
      int omfg = thisLed + count;
      if (omfg > SIZE) {
        count++;
      } else {
        lights.set_color(omfg, G35::MAX_INTENSITY, COLOR_RED);
        count++;
      }
    }
    delay(80);
    lights.set_color(thisLed, G35::MAX_INTENSITY, COLOR_BLACK);
    lights.set_color(thisLed + 1, G35::MAX_INTENSITY, COLOR_BLACK);
  }
  
  // loop from the highest pin to the lowest
  for (int thisLed = SIZE; thisLed >= 0; thisLed--) {
    int count = 1;
    lights.set_color(thisLed, G35::MAX_INTENSITY, COLOR_RED);
    while (count <= 5) {
      lights.set_color(thisLed - count, G35::MAX_INTENSITY, COLOR_RED);
      count++;
    }
    delay(80);
    lights.set_color(thisLed, G35::MAX_INTENSITY, COLOR_BLACK);
    lights.set_color(thisLed - 1, G35::MAX_INTENSITY, COLOR_BLACK);
  }
}
