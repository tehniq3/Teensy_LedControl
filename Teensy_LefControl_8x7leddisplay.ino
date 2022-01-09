//We always have to include the library
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.

 adapted by Nicu FLORICA (niq_ro)
 */
LedControl lc=LedControl(12,11,10,1);

/* we always wait a bit between updates of the display */
unsigned long delaytime=50;
unsigned long delaytime2=400;
byte imin = 0;
byte imax = 8;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,0);
  /* and clear the display */
  lc.clearDisplay(imin);
}


void writeTeensy() {
  lc.setRow(0,7,B00001111);
  delay(delaytime);
  lc.setRow(0,6,B01101111);
  delay(delaytime);
  lc.setRow(0,5,B01101111);
  delay(delaytime);
  lc.setChar(0,4,'n',false);
  delay(delaytime);
  lc.setChar(0,3,'5',false);
  delay(delaytime);
  lc.setRow(0,2,B00111011);
  delay(delaytime2);
  lc.setDigit(0,1,4,true);
  delay(delaytime);
  lc.setDigit(0,0,0,false);
  delay(delaytime);
} 

void writetestby() {
  lc.setRow(0,7,B00001111);
  delay(delaytime);
  lc.setRow(0,6,B01101111);
  delay(delaytime);
  lc.setChar(0,5,'5',false);
  delay(delaytime);
  lc.setRow(0,4,B00001111);
  delay(delaytime);
  lc.setChar(0,3,' ',false);
  delay(delaytime);
  lc.setRow(0,2,B00011111);
  delay(delaytime);
  lc.setRow(0,1,B00111011);
  delay(delaytime);
  lc.setChar(0,0,' ',false);
  delay(delaytime);
} 

void writebyniq() {
  lc.setChar(0,7,' ',false);  // none
  delay(delaytime);  
  lc.setRow(0,6,B01100010);  // n
  delay(delaytime);
  lc.setRow(0,5,B00000010); // i
  delay(delaytime);
  lc.setRow(0,4,B01110011); // q
  delay(delaytime);
  lc.setRow(0,3,B00000001); // _
  delay(delaytime);
  lc.setRow(0,2,B01000010); // r
  delay(delaytime);
  lc.setRow(0,1,B01100011); // o
  delay(delaytime);
  lc.setChar(0,0,' ',false);
  delay(delaytime);
} 


void loop() { 
  writeTeensy();
  for (byte i = imin; i <= imax; i++) {
  delay(delaytime2);
  lc.setIntensity(0,i);
  }
  delay(delaytime2);
  lc.clearDisplay(0);
  writetestby();
  for (byte i = imax; i > imin; i--) {
  delay(delaytime2);
  lc.setIntensity(0,i);
  }
  delay(delaytime2);
  lc.clearDisplay(0);
  writebyniq();
  for (byte i = imin; i <= imax; i++) {
  delay(delaytime2);
  lc.setIntensity(0,i);
  }
  for (byte i = imax; i > imin; i--) {
  delay(delaytime2);
  lc.setIntensity(0,i);
  }
  delay(delaytime2);
  lc.clearDisplay(0);
}
