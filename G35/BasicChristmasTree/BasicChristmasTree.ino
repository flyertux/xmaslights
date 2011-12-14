#include <G35.h>

#define PINSTRING1     4    // String on pin 4
#define PINSTRING2     12   // String on pin 4
#define LIGHT_COUNT    50   // 50 light string
#define RUNS           500  // After this many runs, move on
#define DELAY          100  // Delay between steps
#define ORNAMENTS      16   // Number of ornaments to place on the line

// Total # of lights on string (usually 50, 48, or 36). Maximum is 63,
// because the protocol uses 6-bit addressing and bulb #63 is reserved
// for broadcast messages.

byte h, i, k, j, c          =        0;
byte ornament[ORNAMENTS]    =      { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

static byte top[4]          =      { 0,1,49,25 };
static byte bottom[2][4]    =      { { 12,13,14,15 }, { 36,37,38,39 } };
static byte branches[4][10] =      { 
  { 2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10,11 }, 
  { 16,17,18,19,20,21,22,23,24,24 },
  { 27,28,29,30,31,32,33,34,35,35 },
  { 40,41,42,43,44,45,46,47,48,48 }
};

G35 lights_1(PINSTRING1, LIGHT_COUNT);  // Constructor for light control
// G35 lights_2(PINSTRING2, LIGHT_COUNT);  // Constructor for light control

void SetupLights(){
  lights_1.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_GREEN); // Set everything Green first


    for(i=0;i<4;i++) { // lights
    lights_1.set_color(bottom[0][i],G35::MAX_INTENSITY, COLOR_WARMWHITE);
    lights_1.set_color(bottom[1][i],G35::MAX_INTENSITY, COLOR_WARMWHITE);
  }
  
  for(i=0;i<5;i++){ // Top as Starlight, should twinkle
    lights_1.set_color(top[i],G35::MAX_INTENSITY, COLOR_YELLOW);
  }
}

void FlickerOrnaments(){
  SetupLights(); // Every program starts by setting the lights up
  for(c=0;c<RUNS;c++){ // Run for RUNS times
    for (i=0; i<ORNAMENTS; i++) {
      if (i % 4 == 0) { 
          k = 0;
      } else if  ( i % 4 == 1 ) {
        k = 1;
      } else if ( i % 4  == 2 ) {
        k = 2;
      } else {
        k = 3; 
      };
      
      lights_1.set_color(branches[k][ornament[i]],G35::MAX_INTENSITY, COLOR_GREEN);
      delay(DELAY);
      
      ornament[i] = random(0,10);
      lights_1.set_color(branches[k][ornament[i]],G35::MAX_INTENSITY, G35::max_color(rand()));
      delay(DELAY);
    }  
  }  
}

void KnightRiderBranches(){
  for(c=0;c<RUNS/20;c++){ // Run for RUNS times
    lights_1.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_BLACK);
    // loop from the lowest pin to the highest
    for (i = 0; i < 10; i++) {
      k = 1;
      lights_1.set_color(branches[0][i], G35::MAX_INTENSITY, COLOR_RED);
      lights_1.set_color(branches[1][i], G35::MAX_INTENSITY, COLOR_RED);
      lights_1.set_color(branches[2][i], G35::MAX_INTENSITY, COLOR_RED);
      lights_1.set_color(branches[3][i], G35::MAX_INTENSITY, COLOR_RED);
      while (k <= 5) {
        j = i + k;
        if (j > 10) {
          k++;
        } else {
          lights_1.set_color(branches[0][j], G35::MAX_INTENSITY, COLOR_RED);
          lights_1.set_color(branches[1][j], G35::MAX_INTENSITY, COLOR_RED);
          lights_1.set_color(branches[2][j], G35::MAX_INTENSITY, COLOR_RED);
          lights_1.set_color(branches[3][j], G35::MAX_INTENSITY, COLOR_RED);
          k++;
        }
      }
      delay(80);
      lights_1.set_color(branches[0][i], G35::MAX_INTENSITY, COLOR_BLACK);
      lights_1.set_color(branches[1][i], G35::MAX_INTENSITY, COLOR_BLACK);
      lights_1.set_color(branches[2][i], G35::MAX_INTENSITY, COLOR_BLACK);
      lights_1.set_color(branches[3][i], G35::MAX_INTENSITY, COLOR_BLACK);
                        
      lights_1.set_color(branches[0][i + 1], G35::MAX_INTENSITY, COLOR_BLACK);
      lights_1.set_color(branches[1][i + 1], G35::MAX_INTENSITY, COLOR_BLACK);
      lights_1.set_color(branches[2][i + 1], G35::MAX_INTENSITY, COLOR_BLACK);
      lights_1.set_color(branches[3][i + 1], G35::MAX_INTENSITY, COLOR_BLACK);
    }
  
    // loop from the highest pin to the lowest
    for (i = 10; i >= 0; i--) {
      k = 1;
      lights_1.set_color(branches[0][i], G35::MAX_INTENSITY, COLOR_RED);
      lights_1.set_color(branches[1][i], G35::MAX_INTENSITY, COLOR_RED);
      lights_1.set_color(branches[2][i], G35::MAX_INTENSITY, COLOR_RED);
      lights_1.set_color(branches[3][i], G35::MAX_INTENSITY, COLOR_RED);
      while (k <= 5) {
        lights_1.set_color(branches[0][i - k], G35::MAX_INTENSITY, COLOR_RED);
        lights_1.set_color(branches[1][i - k], G35::MAX_INTENSITY, COLOR_RED);
        lights_1.set_color(branches[2][i - k], G35::MAX_INTENSITY, COLOR_RED);
        lights_1.set_color(branches[3][i - k], G35::MAX_INTENSITY, COLOR_RED);
        
        k++;
      }
      delay(80);
      lights_1.set_color(branches[0][i], G35::MAX_INTENSITY, COLOR_BLACK);
      lights_1.set_color(branches[1][i], G35::MAX_INTENSITY, COLOR_BLACK);
      lights_1.set_color(branches[2][i], G35::MAX_INTENSITY, COLOR_BLACK);
      lights_1.set_color(branches[3][i], G35::MAX_INTENSITY, COLOR_BLACK);
      lights_1.set_color(branches[0][i - 1], G35::MAX_INTENSITY, COLOR_BLACK);
      lights_1.set_color(branches[1][i - 1], G35::MAX_INTENSITY, COLOR_BLACK);
      lights_1.set_color(branches[2][i - 1], G35::MAX_INTENSITY, COLOR_BLACK);
      lights_1.set_color(branches[3][i - 1], G35::MAX_INTENSITY, COLOR_BLACK);
    }
  }
}

void KnightRider(){
  for(c=0;c<RUNS/50;c++){ // Run for RUNS times
    lights_1.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_BLACK);
    // loop from the lowest pin to the highest
    for (i = 0; i < LIGHT_COUNT; i++) {
      k = 1;
      lights_1.set_color(i, G35::MAX_INTENSITY, COLOR_RED);
      while (k <= 5) {
        j = i + k;
        if (j > LIGHT_COUNT) {
          k++;
        } else {
          lights_1.set_color(j, G35::MAX_INTENSITY, COLOR_RED);
          k++;
        }
      }
      delay(DELAY);
      lights_1.set_color(i, G35::MAX_INTENSITY, COLOR_BLACK);
      lights_1.set_color(i + 1, G35::MAX_INTENSITY, COLOR_BLACK);
    }
  
    // loop from the highest pin to the lowest
    for (i = LIGHT_COUNT; i >= 0; i--) {
      k = 1;
      lights_1.set_color(i, G35::MAX_INTENSITY, COLOR_RED);
      while (k <= 5) {
        lights_1.set_color(i - k, G35::MAX_INTENSITY, COLOR_RED);
        k++;
      }
      delay(DELAY);
      lights_1.set_color(i, G35::MAX_INTENSITY, COLOR_BLACK);
      lights_1.set_color(i - 1, G35::MAX_INTENSITY, COLOR_BLACK);
    }
  }
}

void setup() {
  lights_1.enumerate_forward(); // enumerate FORWARD to enable addressing
  // lights_2.enumerate_forward(); // enumerate FORWARD to enable addressing
}

void loop() {
  FlickerOrnaments();
 // KnightRiderBranches();
  KnightRider();
}  
