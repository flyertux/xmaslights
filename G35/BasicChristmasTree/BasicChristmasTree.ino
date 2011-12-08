#include <G35.h>

#define OUT_PIN 4 // String on pin 4
#define LIGHT_COUNT 50 // 50 light string
#define RUNS 500 // After 250 runs, the noise has necesitated a refresh, so we move on
#define DELAY 1000 // Delay for 420s between steps

// Total # of lights on string (usually 50, 48, or 36). Maximum is 63,
// because the protocol uses 6-bit addressing and bulb #63 is reserved
// for broadcast messages.
G35 lights(OUT_PIN, LIGHT_COUNT);  // Constructor for G35 lights

byte i, j, c = 0;
byte ornament[10]    =      { 0,0,0,0,0,0,0,0,0,0 };
byte ornamentrow[10] =      { 0,0,0,0,0,0,0,0,0,0 };
static byte top[5]  =      { 0,1,50,25,26 };
static byte tier[5] =      { 1,23,24,48 };
static byte bottom[2][4] = { { 12,13,14,15 }, { 36,37,38,39 } };
static byte column[4][10] = { 
  { 2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10,11 }, 
  { 16,17,18,19,20,21,22,23,24,24 },
  { 27,28,29,30,31,32,33,34,35,35 },
  { 40,41,42,43,44,45,46,47,48,49 }};

void SetupLights(){
  lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_GREEN); // Set everything Green first

  for(i=0;i<2;i++) { // rows 
    for(j=0;j<3;j++) { // lights
      lights.set_color(bottom[i][j],G35::MAX_INTENSITY, COLOR_WARMWHITE);
    }
  }
  
  for(i=0;i<5;i++){ // Top as Starlight, should twinkle
    lights.set_color(top[i],G35::MAX_INTENSITY, COLOR_YELLOW);
    lights.set_color(tier[i],G35::MAX_INTENSITY, COLOR_YELLOW);
  }
}

void FlickerOrnaments(){
  SetupLights(); // Every program starts by setting the lights up
  for(c=0;c<=RUNS;c++){ // Run for RUNS times
    for (i=0; i<5; i++) {
      lights.set_color(column[ornamentrow[i]][ornament[i]],G35::MAX_INTENSITY, COLOR_GREEN);
      delay(DELAY);
      
      ornament[i] = random(0,10);
      ornamentrow[i] = random(0,4);
      lights.set_color(column[ornamentrow[i]][ornament[i]],G35::MAX_INTENSITY, G35::max_color(rand()));
      delay(DELAY);
    }  
  }  
}

void setup() {
  lights.enumerate_forward(); // enumerate FORWARD to enable addressing
}

void loop() {
  FlickerOrnaments();
}  
