// Digispark Mouse Jiggler
// Written by James Franklin for Air-Gap in 2019
// www.air-gap.com.au

#define Version "01.01"
#include <DigiMouse.h>
unsigned int LowerCycleTime = 10000;   //Minimum Time in milli-seconds between each mouse action  Default: 10000 (10 Seconds), Max 65535ms
unsigned int UpperCycleTime = 30000;   //Maximum Time in milli-seconds between each mouse action  Default: 30000 (30 Seconds), Max 65535ms
//A random() function will randomly execute a mouse move between these two values

void setup() {
   randomSeed(analogRead(0));          //Random Seed off background noise on analog pin
   pinMode(1, OUTPUT);                 // LED initialization 
   digitalWrite(1, LOW);               // LED OFF

   DigiMouse.begin();                  //start
}


void loop() {
//Moves mouse 1 pixel in a random direction (up/down/left/right)

   digitalWrite(1, HIGH);              // LED ON
   DigiMouse.moveX(random(-1, 1));     // X axix left or right
   DigiMouse.moveY(random(-1, 1));     // Y axis up ro down
   DigiMouse.delay(50);
   digitalWrite(1, LOW);               // LED OFF
   DigiMouse.delay(random(LowerCycleTime, UpperCycleTime));
  
}