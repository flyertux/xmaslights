#include <G35.h>

#define OUT_PIN 4 // String on pin 4
#define STATUS_PIN 13 // Light on pin 13
#define LIGHT_COUNT 50 // 50 light string

// Total # of lights on string (usually 50, 48, or 36). Maximum is 63,
// because the protocol uses 6-bit addressing and bulb #63 is reserved
// for broadcast messages.

int cleanup, changeme, ornament, row, i, j, c = 0;
static uint8_t top[5] = {0,1,50,25,26};
static uint8_t tier[5] = {1,23,24,48};

static uint8_t column[4][10] = 
{ {2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10,11}, 
  {16,17,18,19,20,21,22,23,24,24},
  {27,28,29,30,31,32,33,34,35,35},
  {40,41,42,43,44,45,46,47,48,49}};

static uint8_t bottom[2][4] = { {12,13,14,15}, {36,37,38,39} };

int ornaments[5] = { 0,0,0,0,0 };
int ornamentrow[5] = { 0,0,0,0,0 };



G35 lights(OUT_PIN, LIGHT_COUNT);  // Constructor for G35 lights

void setup() {
  lights.enumerate_forward(); // enumerate FORWARD to enable addressing
  lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_GREEN); // Set everything Green first

  for(i=0;i<1;i++){ // rows 
    for(j=0;j<3;j++){ // lights
      lights.set_color(bottom[i][j],G35::MAX_INTENSITY, COLOR_WARMWHITE);
    }
  }
  
  for(int i=0;i<4;i++){ // Top as Starlight, should twinkle
    lights.set_color(top[i],G35::MAX_INTENSITY, COLOR_YELLOW);
  }
}

void loop() {
  for (i=0; i<5; i++) {
    row=random(0,4);
    ornament=random(0,10);
    changeme = column[ornamentrow[i]][ornaments[i]];
    
   lights.set_color(changeme,G35::MAX_INTENSITY, COLOR_GREEN);
    delay(420);
    ornamentrow[i]= row;
    ornaments[i]=ornament;

    
    changeme = column[ornamentrow[row]][ornaments[ornament]];
    lights.set_color(changeme,G35::MAX_INTENSITY, COLOR_RED);
    delay(420);
  }
  
  ++cleanup;
  if (cleanup >= 250) {
    setup(); // reset string
    cleanup=0; // reset counter
  }
  
}  
