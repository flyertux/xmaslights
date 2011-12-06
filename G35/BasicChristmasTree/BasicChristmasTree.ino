#include <G35.h>

// Arduino pin number. Pin 13 will blink the on-board LED.
#define OUT_PIN 4
#define STATUS_PIN 13

// Total # of lights on string (usually 50, 48, or 36). Maximum is 63,
// because the protocol uses 6-bit addressing and bulb #63 is reserved
// for broadcast messages.
#define LIGHT_COUNT 50

static uint8_t c;
static uint8_t top[2] = {1,50};
static uint8_t tier[4]= {1,23,24,48};

static uint8_t column[4][11]= {
  {2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10,11}, 
  {16,17,18,19,20,21,22,23,24,25},
  {26,27,28,29,30,31,32,33,34,35},
  {40,41,42,43,44,45,46,47,48,49}
};

static uint8_t row[2][4]= {{12,13,14,15},{36,37,38,39}};

G35 lights(OUT_PIN, LIGHT_COUNT);  // Constructor for G35 lights

void setup() {
  lights.enumerate_forward(); // enumerate FORWARD to enable addressing
  lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_GREEN); // Set everything Green first

  for(int i=0;i<2;i++){ // rows 
    for(int j=0;j<4;j++){ // lights
      lights.set_color(row[i][j],G35::MAX_INTENSITY, COLOR_WARMWHITE);
    }
  }
  for(int i=0;i<2;i++){ // Top as Starlight, should twinkle 
    lights.set_color(top[i],G35::MAX_INTENSITY, COLOR_YELLOW);
  }
}


void loop() {
  // fill_color makes all bulbs from 0 to LIGHT_COUNT the same brightness
  // and color
  
//  for(int i=0;i<2;i++){
 //   for(int j=0;j<10;j++){
//      lights.set_color(row[i][j],G35::MAX_INTENSITY, COLOR_WARMWHITE);
//    }
//  }

  //lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_GREEN);





  delay(1000);
}  
