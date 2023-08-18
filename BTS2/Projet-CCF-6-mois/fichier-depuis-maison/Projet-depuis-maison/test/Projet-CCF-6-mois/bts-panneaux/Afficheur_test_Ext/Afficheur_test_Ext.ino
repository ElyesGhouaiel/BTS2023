// scrolltext demo for Adafruit RGBmatrixPanel library.
// Demonstrates double-buffered animation on our 16x32 RGB LED matrix:
// http://www.adafruit.com/products/420

// Written by Limor Fried/Ladyada & Phil Burgess/PaintYourDragon
// for Adafruit Industries.
// BSD license, all text above must be included in any redistribution.

#include "Adafruit_GFX.h"   // Core graphics library
#include "RGBmatrixPanel.h" // Hardware-specific library

// Similar to F(), but for PROGMEM string pointers rather than literals
#define F2(progmem_ptr) (const __FlashStringHelper *)progmem_ptr

#define CLK 11  // MUST be on PORTB! (Use pin 11 on Mega)
#define LAT A3
#define OE  9
#define A   A0
#define B   A1
#define C   A2
// Last parameter = 'true' enables double-buffering, for flicker-free,
// buttery smooth animation.  Note that NOTHING WILL SHOW ON THE DISPLAY
// until the first call to swapBuffers().  This is normal.
//RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, true);
#define NUMDISPLAYS 2
#define DOUBLEBUFFER true
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, DOUBLEBUFFER, NUMDISPLAYS);
// Double-buffered mode consumes nearly all the RAM available on the
// Arduino Uno -- only a handful of free bytes remain.  Even the
// following string needs to go in PROGMEM:

int commande = 0;
const char parking[] PROGMEM = "PARKING";
const char complet[] PROGMEM = "COMPLET";
const char places[]  PROGMEM = "PLACES";
const char libres[]  PROGMEM = "LIBRES";
const char libre[]  PROGMEM = "LIBRE";
const char ouvert[]  PROGMEM = "OUVERT";
const char ferme[]   PROGMEM = "FERME";
const char abonne[]   PROGMEM = "ABONNES";
const char pmr[]   PROGMEM = "PMR";
byte i = 0; //permet le comptage du nombre de defillement sevenpark au demarrage
static const uint16_t PROGMEM Color[5] = {
  0x0F00, // vert  =0
  0x00F0, // Bleu  =1
  0xF000, // Rouge =2
  0xFFFF, // Blanc =3
  0xFFA5 //  Ambre =4
};
int    textX         = matrix.width(),
       textX2        = 0,
       textMin       = sizeof(complet) * -50,
       hue     = 0;;
int pause=3000;

void setup() {
  matrix.begin();
  matrix.setTextWrap(false); // Allow text to run off right edge
  matrix.setTextSize(1);
}

void loop() {

Fct_libre2L();
delay(pause);
Fct_complet2L();
delay(pause);
Fct_ouvert2L();
delay(pause);
Fct_ferme2L();
delay(pause);
Fct_libreXl();
delay(pause);
}
void Fct_libre(){
  while (commande==15){
  matrix.setTextSize(2); 
  matrix.fillScreen(0);  
  matrix.setTextColor(pgm_read_word(&Color[0]));
  matrix.setCursor(textX, 1);
  matrix.print(F2(libre));  //F2(str)

  // Move text left (w/wrap), increase hue
  if((--textX) < textMin){ textX = matrix.width(); i++;}
  
  // Update display
  matrix.swapBuffers(false);
  //Fct_receptionRS485();

 
  }
}  

void Fct_complet(){
 
 while (commande==16){
  matrix.setTextSize(2); 
  matrix.fillScreen(0);  
  matrix.setTextColor(pgm_read_word(&Color[2]));
  matrix.setCursor(textX, 1);
  matrix.print(F2(complet));  //F2(str)

  // Move text left (w/wrap), increase hue
  if((--textX) < textMin){ textX = matrix.width(); i++;}
  
  // Update display
  matrix.swapBuffers(false);
  //Fct_receptionRS485();

 
  }
} 
void Fct_ferme2L(){
  matrix.fillScreen(0); //efface l ecran 
  //matrix.fillRect(0, 0, 17,16, pgm_read_word(&Color[3]));
  //matrix.fillCircle(8, 8, 7, pgm_read_word(&Color[3]));
  matrix.fillCircle(8, 8, 7, pgm_read_word(&Color[2]));
  matrix.fillRect(3, 7, 11,3, pgm_read_word(&Color[3]));
  //matrix.fillRect(1, 1, 14,14, pgm_read_word(&Color[1]));
  matrix.setTextSize(1);
       
  matrix.setTextColor(pgm_read_word(&Color[2]));
  matrix.setCursor(20, 0);
  matrix.print(F2(parking));  //F2(str)
   
  matrix.setTextColor(pgm_read_word(&Color[2]));
  matrix.setCursor(26, 9);
  matrix.print(F2(ferme));  //F2(str)
  
  matrix.swapBuffers(false); 
}
void Fct_ouvert2L(){
  
   matrix.fillScreen(0); //efface l ecran 
     
   matrix.fillRect(0, 0, 16,16, pgm_read_word(&Color[3]));
   matrix.fillRect(1, 1, 14,14, pgm_read_word(&Color[1]));
   matrix.setTextSize(2);  
   matrix.setTextColor(pgm_read_word(&Color[3]));
   matrix.setCursor(3, 2);
   matrix.print("P");  //F2(str)

  matrix.setTextSize(1);
      
  matrix.setTextColor(pgm_read_word(&Color[0]));
  matrix.setCursor(20, 0);
  matrix.print(F2(parking));  //F2(str)
   
  matrix.setTextColor(pgm_read_word(&Color[0]));
  matrix.setCursor(23, 9);
  matrix.print(F2(ouvert));  //F2(str)

  matrix.swapBuffers(false);  
}
void Fct_libre2L(){
  matrix.fillScreen(0); //efface l ecran 
  matrix.fillRect(0, 0, 16,16, pgm_read_word(&Color[3]));
  matrix.fillRect(1, 1, 14,14, pgm_read_word(&Color[1]));
  matrix.setTextSize(2);  
  matrix.setTextColor(pgm_read_word(&Color[3]));
  matrix.setCursor(3, 2);
  matrix.print("P");  //F2(str)
   
  matrix.setTextSize(1);
      
  matrix.setTextColor(pgm_read_word(&Color[0]));
  matrix.setCursor(20, 0);
  matrix.print(F2(parking));  //F2(str)
   
  matrix.setTextColor(pgm_read_word(&Color[0]));
  matrix.setCursor(26, 9);
  matrix.print(F2(libre));  //F2(str)

  matrix.swapBuffers(false);  
}
void Fct_complet2L(){
  matrix.fillScreen(0); //efface l ecran 
     
   matrix.fillRect(0, 0, 16,16, pgm_read_word(&Color[3]));
   matrix.fillRect(1, 1, 14,14, pgm_read_word(&Color[1]));
   matrix.setTextSize(2);  
   matrix.setTextColor(pgm_read_word(&Color[3]));
   matrix.setCursor(3, 2);
   matrix.print("P");  //F2(str)
   
  matrix.setTextSize(1);
      
  matrix.setTextColor(pgm_read_word(&Color[2]));
  matrix.setCursor(20, 0);
  matrix.print(F2(parking));  //F2(str)
   
  matrix.setTextColor(pgm_read_word(&Color[2]));
  matrix.setCursor(20, 9);
  matrix.print(F2(complet));  //F2(str)

  matrix.swapBuffers(false);  
}
void Fct_libreXl(){
  matrix.fillScreen(0); //efface l ecran 
     
   matrix.setTextSize(2);  
   matrix.setTextColor(pgm_read_word(&Color[3]));
   matrix.setCursor(3, 1);
   matrix.print("LIBRE");  //F2(str)
   

  matrix.swapBuffers(false);  
}
