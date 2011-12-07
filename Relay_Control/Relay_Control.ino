/* Relay Control */

int serIn;
int status[] = { 0,0,0,0,0,0,0,0,0,0 };

void setup() {
  digitalWrite(4, HIGH); // Prevents power cycle at start
  pinMode(4, OUTPUT);    // But it must be before pin is set to output
  digitalWrite(9, HIGH);  
  pinMode(9, OUTPUT); 
  Serial.begin(115200);

}

void loop () {
  // only if there are bytes in the serial buffer execute the following code
  if(Serial.available()) {
    
    //keep reading and printing from serial untill there are bytes in the serial buffer
     int serIn = Serial.read(); //read Serial data as integer
     Serial.print(serIn); //prints the bytes received for the characters just read
     
      
     if (serIn >= 48 && serIn <= 58){    //  ASCII Byte equivalent of 0 through 9?
       int usePin = serIn- 48; // Subtract 48 to get the correct pin number
        
       if (status[usePin] < 1) {
         digitalWrite(usePin, LOW); //make that pin output LOW to turn it on
         status[usePin] = 1;
         Serial.print(status[usePin]);
       } else {
         digitalWrite(usePin, HIGH); //make that pin output HIGH to turn it off
         status[usePin] = 0;
         Serial.write(status[usePin]);
       }
   }
              
    //the serial buffer is over just go to the line (or pass your favorite stop char)
    Serial.println();
  }
  
  //slows down the visualization in the terminal
  delay(100);
}


