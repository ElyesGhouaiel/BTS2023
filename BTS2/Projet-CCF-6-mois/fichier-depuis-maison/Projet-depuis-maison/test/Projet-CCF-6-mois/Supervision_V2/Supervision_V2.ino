// scrolltext demo for Adafruit RGBmatrixPanel library.
// Demonstrates double-buffered animation on our 16x32 RGB LED matrix:
// http://www.adafruit.com/products/420

// Written by Limor Fried/Ladyada & Phil Burgess/PaintYourDragon
// for Adafruit Industries.
// BSD license, all text above must be included in any redistribution.

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library
#include <EEPROM.h>  // pour utiliser la mémoire EEPROM
#include <SoftwareSerial.h>

#define RX_PIN 2
#define TX_PIN 3
#define RS485_CONTROL_PIN 4

// Similar to F(), but for PROGMEM string pointers rather than literals
#define F2(progmem_ptr) (const __FlashStringHelper *)progmem_ptr

#define CLK 11  // MUST be on PORTB! (Use pin 11 on Mega)
#define LAT A3
#define OE  9
#define A   A0
#define B   A1
#define C   A2

unsigned int MESSAGE    = 0;     // message a afficher
unsigned int ORDRE      = 50;    // odre 0-inactif 1-afiché en premier 2-affiché en second etc....
unsigned int TYPE       = 55;    // 0-fixe  1-defilement
unsigned int COULEUR    = 60;    // 0-vert 1-bleu 2-rouge 3-blanc 4-ambre
unsigned int NBRCYCLE   = 65;    // nombre de defilement du message
unsigned int INTERVALLE = 70;    // temps entre chaque nouveau defilement du meme message
unsigned int TEMPO      = 75;    // tempo entre chaque affichage

// Last parameter = 'true' enables double-buffering, for flicker-free,
// buttery smooth animation.  Note that NOTHING WILL SHOW ON THE DISPLAY
// until the first call to swapBuffers().  This is normal.
#define NUMDISPLAYS 2
#define DOUBLEBUFFER true
SoftwareSerial rs485Serial(RX_PIN, TX_PIN);
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, DOUBLEBUFFER, NUMDISPLAYS);

const char parking[] PROGMEM = "PARKING";
const char complet[] PROGMEM = "COMPLET";
const char places[]  PROGMEM = "PLACES";
const char place[]  PROGMEM = "PLACE";
const char libres[]  PROGMEM = "LIBRES";
const char libre[]  PROGMEM = "LIBRE";
const char ouvert[]  PROGMEM = "OUVERT";
const char ferme[]   PROGMEM = "FERME";
const char abonne[]   PROGMEM = "ABONNES";
const char pmr[]   PROGMEM = "PMR";

const char str[] PROGMEM = "SevenPark_G";

       
int    textX         = matrix.width(),
       textX2        = 0,
       textMin       = sizeof(complet) * -50,
       hue     = 0;;

String comOK = "Com OK\n";
String inString = "";
String color = "0x07E0";
int bufferRs485 ;
long int compteur = 0;
byte colorSet;
byte n = 10; //nombre de passage de sevenpark au demarrage
byte i = 0; //permet le comptage du nombre de defillement sevenpark au demarrage
const int E1 = 58; // bouton poussoir impression ticket
int ETAT_E1;
int memoireE1 = LOW;
bool debutTrame;//detection du diese
const int led = 60; //sortie led

static const uint16_t PROGMEM Color[5] = {
  0x0F00, // vert  =0
  0x00F0, // Bleu  =1
  0xF000, // Rouge =2
  0xFFFF, // Blanc =3
  0xFFA5 //  Ambre =4
};

int8_t ball[3][4] = {
  {  3,  0,  1,  1 }, // Initial X,Y pos & velocity for 3 bouncy balls
  { 17, 15,  1, -1 },
  { 27,  4, -1,  1 }
};
static const uint16_t PROGMEM ballcolor[3] = {
  0x0080, // Green=1
  0x0002, // Blue=1
  0x1000  // Red=1
};

int tailleTrame = 80;
char bfr[80];
String StrCommande = "";
int commande = 0;

struct configMess {
  String message;
  int ordre;
  int type;
  int couleur;
  int nbrCycle;
  int intervalle;
  int tempo;
};

configMess affichage[6];

  String dataRecu="";
  String placeAbonnes="10";
  String placePmr="2";
  String Mess="";


  String placeVisiteur1="99";
  String placeVisiteur2="100";
  int intPlaceVisiteur1 = placeVisiteur1.toInt();
  int intPlaceVisiteur2 = placeVisiteur2.toInt();
  int TotalPlaceVisiteur= intPlaceVisiteur1 + intPlaceVisiteur2;
  String placeVisiteur= String(TotalPlaceVisiteur);
  
  int x=0;

  String textMessL1="Lignes1";
  String textMessL2="Lignes2";
  int couleurL1=3;
  int couleurL2=3;
  int couleurCpt=3;
  int XL1=0;
  int XL2=0;
  int Xcpt=42;
  int couleurMessProg=3;

  bool demarrage=0;
  bool z =false;
  int avance = 64;
  int y =0;

  int compteurJpietri = 0;
  bool sensEntree = false;
  

void setup() {  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
  rs485Serial.begin(9600);
  pinMode(RS485_CONTROL_PIN, OUTPUT);
  digitalWrite(RS485_CONTROL_PIN, HIGH); 
  
  Serial.begin(9600);

  Serial.begin(9600);
  Serial1.begin(9600);

  pinMode(E1, INPUT);         // bouton changement couleur
  digitalWrite(E1, HIGH) ;    // pull up

  pinMode(led, OUTPUT);        // relais ouverture barrière
  digitalWrite(led, HIGH) ;

  for (int i = 0; i < 6; i++) {
    Serial1.print("-------------------message: "); Serial1.print(i); Serial1.println(" -------------------");
    //Fct_lectureEeprom(i);
    
    delay(100);
  }


  
    colorSet=EEPROM.read(500);
    if ( colorSet>4 || colorSet<0 )                    //  si "n" n'a pas une valeur comprise entre 0 et 4 ( respectivement tempo 1 à 5 ! )
    {
     colorSet=0 ;                                    // on lui donne valeur 0
     EEPROM.write(500, colorSet);                    // et on met "n" en EEprom
    }
    matrix.begin();
    matrix.setTextWrap(false); // Allow text to run off right edge
    matrix.setTextSize(2);
  
   for ( int i=0;i<300;i++) { 
   Fct_start();
   }
  matrix.fillScreen(0);
  matrix.swapBuffers(false);
  commande=60;


}
void loop() { //----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
if (rs485Serial.available()) {
    int receivedByte = rs485Serial.read();
    if (receivedByte == '4') {
      Fct_receptionRS485();  // Exécuter la commande sur l'afficheur
    }
  }
  
  receiveCommand();
  receiveFromPython();
  
  Fct_receptionRS485();
  if (demarrage==0){
    Fct_jPietri();
    demarrage=1;
  }


}

void receiveCommand() {
  if (rs485Serial.available()) {
    int receivedByte = rs485Serial.read();
    if (receivedByte == '4') {
      Fct_receptionRS485();   // Exécuter la commande sur l'afficheur
    }
  }
}

void receiveFromPython() {
  if (Serial.available()) {
    String receivedMessage = Serial.readStringUntil('\n');
    receivedMessage.trim();
    if (receivedMessage == "4") {
      rs485Serial.write('4');  // Envoyer la commande "4" à l'afficheur via RS485
    }
  }
}

void Fct_receptionRS485() {

  byte etape = 0;
  int j = 0;
  int i = 0;

  bufferRs485 = Serial1.available();
  StrCommande = "";
  dataRecu ="";
  
  if (bufferRs485 > 0) {
    memset(bfr, 0, tailleTrame);
    Serial1.readBytesUntil('\n', bfr, (tailleTrame - 1));
    Serial1.print("bfr :"); Serial1.println(bfr);
    
  
/*
    while ((char)bfr[i] != '/' || i < 10) {
      StrCommande += bfr[i];
      i++;
    }

    commande = StrCommande.toInt();
    //Serial1.print("commande :");Serial1.println(commande);
*/
    
    for (int i = 0; i < tailleTrame; i++) {

    if (((char)bfr[i] != '/') && (etape == 0)) {
       StrCommande += bfr[i];
    }
    if (((char)bfr[i] != '/') && (etape == 1)) {
       dataRecu += bfr[i];
    }
    if ((char)bfr[i] == '/') {
        etape++;
    }
  }

  commande = StrCommande.toInt();
  Serial1.print("commande :");Serial1.println(commande);
  Serial1.print("PlacesLibre:");Serial1.println(dataRecu);
    
  switch (commande) {
    
    case 0://Reboot

      delay(100);
      asm volatile ("jmp 0");//reset carte spb2
      break;
      
    case 1://CPT VISITEUR 2 LIGNES
    {
     sensEntree = false;
     placeVisiteur=dataRecu;
     z=false;
     y=0;
       if (compteurJpietri >= placeVisiteur.toInt()){
           avance = 64;
           textX=0;
           sensEntree = true;
           voitureEntreeParking();
       }
       else{
        avance =0;
        textX = 0;
        sensEntree = false;
        voitureSortieParking();
       }
     }
      break;
      
    case 2://CPT VISITEUR P1 2 LIGNES
      placeVisiteur1=dataRecu;
      break;
      
    case 3://CPT VISITEUR P2 2 LIGNES
      placeVisiteur2=dataRecu;
      break;
      
     case 4:
            matrix.fillScreen(0);
            matrix.setTextColor(matrix.Color333(7, 7, 7));
            matrix.setCursor(0, 0);
            matrix.print("Travaux");
            matrix.swapBuffers(false);
            Fct_receptionRS485();
      break;
      
     case 5:
            matrix.fillScreen(0);
            matrix.setTextColor(matrix.Color333(7, 7, 7));
            matrix.setCursor(0, 0);
            matrix.print("PUB");
            matrix.swapBuffers(false);
            Fct_receptionRS485();
      break;
      
     case 6:
     afficherMessage(Mess);
      break;
      case 7:
      Mess=dataRecu;
      break;
      
    case 9://ACCUEIL
      while (commande==9){
         matrix.setTextSize(2); 
          matrix.fillScreen(0);  
          matrix.setTextColor(pgm_read_word(&Color[1]));
          matrix.setCursor(textX, 1);
          matrix.print("PARKING ");  //F2(str)
          matrix.setTextColor(pgm_read_word(&Color[3]));
          matrix.print("SEVEN PARK");  //F2(str)
          // Move text left (w/wrap), increase hue
          if((--textX) < textMin){ textX = matrix.width(); i++;}
          
          // Update display
          matrix.swapBuffers(false);
          Fct_receptionRS485();

 
  }
  
      break;
    case 10://ACCUEIL
      //Serial1.println("ACCUEIL");
        matrix.fillScreen(0); //efface l ecran 
      
        matrix.setTextSize(1);
            
        matrix.setTextColor(pgm_read_word(&Color[1]));
        matrix.setCursor(12, 0);
        matrix.print(F2(parking));  //F2(str)
         
        matrix.setTextColor(pgm_read_word(&Color[3]));
        matrix.setCursor(6, 9);
        matrix.print("Seven Park");  //F2(str)
      
        matrix.swapBuffers(false); 
      break;
      
    case 11://LIBRE 2 LIGNES
      //Serial1.println("LIBRE 2 LIGNES");

      break;
      
    case 12://COMPLET 2 LIGNES
      //Serial1.println("COMPLET 2 LIGNES");

      break;
      
    case 13://OUVERT 2 LIGNES
          //Serial1.println("OUVERT 2 LIGNES");

      break;
      
    case 14://FERME 2 LIGNES
      //Serial1.println("FERME 2 LIGNES");

      break;
      
    case 15://LIBRE DEFILEMENT
      //Serial1.println("LIBRE DEFILEMENT");

      break;
      
    case 16://COMPLET DEFILEMNT
      //Serial1.println("CPT PMR");

      break;

    case 17://OUVERT DEFILEMENT
      //Serial1.println("LIBRE");

      break;
      
    case 18://FERME DEFILEMENT
     //Serial1.println("COMPLET");

      break;
      
    case 19:

      break;
      
    case 20://PLACE VISITEUR 2 LIGNES
     // placeVisiteur=dataRecu;

      break;
      
    case 21://PLACE ABONNES 2 LIGNES
      //Serial1.println("CPT VISITEURS");
     // placeAbonnes=dataRecu;

      break;
      
    case 22://PLACE PMR 2 LIGNES 
     // Serial1.println("CPT ABONNES");
      //placePmr=dataRecu;

      break;
      
    case 23://PLACE VISITEURS DEFILEMENT
      //Serial1.println("CPT PMR");
     //placeVisiteur=dataRecu;

      break;

    case 24://PLACE ABONNES DEFILEMENT
      //Serial1.println("LIBRE");
      //placeAbonnes=dataRecu; 
         
      break;
      
    case 25://PLACE PMR DEFILEMENT
      //placePmr=dataRecu;
      
      
      break;

      
      
    case 30://MESS 1 PROG
     // Serial1.println("OUVERT");
      
      break;
      
    case 31://MESS 2 PROG
      //Serial1.println("FERME");
     
      break;
      
    case 32://MESS 3 PROG
      //Serial1.println("CPT VISITEURS");
    
      break;
      
    case 33://MESS 4 PROG
     // Serial1.println("CPT ABONNES");
     
      break;
      
    case 34://MESS 5 PROG
     // Serial1.println("CPT PMR");
     
      break;
      
    case 35://MESS 6 PROG
      //Serial1.println("OUVERT");
    
      break;
          
    case 36://MESSAGE LIVE 
     // Serial1.println("CPT VISITEURS");
      //messageLive=dataRecu;
      
      break;
      
    case 37://MESSAGE LIVE 2 LIGNES
     // Serial1.println("CPT VISITEURS");
     // messageLive=dataRecu;
      
      break;
      
    case 38://CPT LIVE 1 LIGNE
     // Serial1.println("CPT VISITEURS");
     // messageLive=dataRecu;
      
      break;
      

    case 40://TEXT MESS LIGNE 1
      textMessL1=dataRecu;
      break;
    case 41://TEXT MESS LIGNE 2
      textMessL2=dataRecu;
      break;    
    case 42://COULEUR LIGNE 1
     couleurL1=dataRecu.toInt();
      break;     
    case 43://COULEUR LIGNE 1
     couleurL2=dataRecu.toInt();
      break;
    case 44://COULEUR CPT
     couleurCpt=dataRecu.toInt(); 
      break;
    case 45://COORDONNE X TEXT 1
     XL1=dataRecu.toInt();
      break;
    case 46://COORDONNE X TEXT 2
     XL2=dataRecu.toInt();
      break;
    case 47://COORDONNE X CPT
      Xcpt=dataRecu.toInt();
      break;
    case 48://COULEUR MESS PROG
      couleurMessProg=dataRecu.toInt();
      break;
    case 49://
     afficherParking1();
      break;

            

    case 50://Config Mess1
      Fct_SaveConfig(commande);
      break;
    case 51://Config Mess2
      Fct_SaveConfig(commande);
      break;
    case 52://Config Mess3
      Fct_SaveConfig(commande);
      break;
    case 53://Config Cpt1
      Fct_SaveConfig(commande);
      break;
    case 54://Config Cpt2
      Fct_SaveConfig(commande);
      break;
    case 55://Config Cpt3
      Fct_SaveConfig(commande) ;
      break;
    case 56:// Affichage Parking2
    afficherParking2();
    break;      
    case 57:
    afficherParkingPlacesLibresGeneral2L();
    break;
    case 58:
    afficherP1P2Libres2L();
    break;
    case 59:
    afficherP1P2Libres2LMove();
    break;
    
    case 60://J.PIETRI
     placeVisiteur=dataRecu;
     Fct_jPietri() ;
      break;
  }
 }
}
void Fct_SaveConfig(int decalageAdresse) {

  byte etape = 0;
  int j = 0;
  decalageAdresse = (decalageAdresse - 50) * 100;

  //Serial1.println(bfr);
  Serial1.print("decalageAdresse :"); Serial1.println(decalageAdresse);

  for (int i = 0; i < tailleTrame; i++) {

    if (((char)bfr[i] != '/') && (etape == 0)) {
      j++;
    }

    if (((char)bfr[i] != '/') && (etape == 1)) {
      EEPROM.write((MESSAGE + decalageAdresse + j), (char)bfr[i]);
      j++;
    }


    if (((char)bfr[i] != '/') && (etape == 2)) {
      EEPROM.write((ORDRE + decalageAdresse + j),(char)bfr[i]);
      j++;
    }

    if (((char)bfr[i] != '/') && (etape == 3)) {
      EEPROM.write((TYPE + decalageAdresse + j), (char)bfr[i]);
      j++;
    }


    if (((char)bfr[i] != '/') && (etape == 4)) {
      EEPROM.write((COULEUR + decalageAdresse + j), (char)bfr[i]);
      j++;
    }

    if (((char)bfr[i] != '/') && (etape == 5)) {
      EEPROM.write((NBRCYCLE + decalageAdresse + j),(char)bfr[i]);
      j++;
    }

    if (((char)bfr[i] != '/') && (etape == 6)) {
      EEPROM.write((INTERVALLE + decalageAdresse + j),(char)bfr[i]);
      j++;
    }

    if (((char)bfr[i] != '/') && (etape == 7)) {
      EEPROM.write((TEMPO + decalageAdresse + j), (char)bfr[i]);
      j++;
    }

    if ((char)bfr[i] == '/') {

      switch (etape) {
        case 0:
          // DISK3.write(MESSAGE_RECEPTION_MQTT+j,char(0));
          break;
        case 1:
          EEPROM.write((MESSAGE + decalageAdresse + j), char(0));
          break;
        case 2:
          EEPROM.write((ORDRE + decalageAdresse + j), char(0));
          break;
        case 3:
          EEPROM.write((TYPE + decalageAdresse + j), char(0));
          break;
        case 4:
          EEPROM.write((COULEUR + decalageAdresse + j), char(0));
          break;
        case 5:
          EEPROM.write((NBRCYCLE + decalageAdresse + j), char(0));
          break;
        case 6:
          EEPROM.write((INTERVALLE + decalageAdresse + j), char(0));
          break;
        case 7:
          EEPROM.write((TEMPO + decalageAdresse + j), char(0));
          break;
      }
      etape++;
      j = 0;
    }
  }
  //Serial1.print("decalageAdresse :");Serial1.println(decalageAdresse);


  Serial1.print("message :");
char charTemp = ' ';
  i = 0;
  while (charTemp != char(0) ) {
    charTemp = EEPROM.read(MESSAGE + decalageAdresse + i); //  + addressLangue[langue])
    if (charTemp != char(0)) Serial1.print( charTemp );
    i++;
  }

  Serial1.println("");
  Serial1.print("ordre :"); Serial1.println( EEPROM.read (ORDRE + decalageAdresse));
  Serial1.print("type :"); Serial1.println(EEPROM.read (TYPE + decalageAdresse));
  Serial1.print("couleur :"); Serial1.println(EEPROM.read (COULEUR + decalageAdresse));
  Serial1.print("nbrCycle :"); Serial1.println(EEPROM.read (NBRCYCLE + decalageAdresse));
  Serial1.print("intervalle :"); Serial1.println(EEPROM.read (INTERVALLE + decalageAdresse));
  Serial1.print("tempo :"); Serial1.println(EEPROM.read (TEMPO + decalageAdresse));


}
void Fct_afficheMessage(int mess){
  int index = mess-30;
 while (commande == mess){
  
  matrix.setTextSize(2); 
  matrix.fillScreen(0);  
  matrix.setTextColor(pgm_read_word(&Color[affichage[index].couleur]));
  matrix.setCursor(textX, 1);
  matrix.print(affichage[index].message);  //F2(str)

  // Move text left (w/wrap), increase hue
  if((--textX) < textMin){ textX = matrix.width(); i++;}
 //if((--textX) < -100){ textX = 64; i++;}
  
  // Update display
  matrix.swapBuffers(false);
  Fct_receptionRS485();

 
  }
}  

void Fct_start() {
  byte i;

  // Clear background
  matrix.fillScreen(0);

  // Bounce three balls around
  for(i=0; i<3; i++) {
    // Draw 'ball'
   // matrix.fillCircle(ball[i][0], ball[i][1], 5, pgm_read_word(&ballcolor[i]));
   matrix.fillRect(ball[i][0], ball[i][1], 5,5, pgm_read_word(&ballcolor[i]));
    // Update X, Y position
    ball[i][0] += ball[i][2];
    ball[i][1] += ball[i][3];
    // Bounce off edges
    if((ball[i][0] == 0) || (ball[i][0] == (matrix.width() - 1)))
      ball[i][2] *= -1;
    if((ball[i][1] == 0) || (ball[i][1] == (matrix.height() - 1)))
      ball[i][3] *= -1;
  }

  // Draw big scrolly text on top
  matrix.setTextColor(matrix.ColorHSV(hue, 160, 255, true));
  matrix.setCursor(textX, 1);
  matrix.print(F2(str));

  // Move text left (w/wrap), increase hue
  if((--textX) < textMin) textX = matrix.width();
  hue += 7;
  if(hue >= 1536) hue -= 1536;

  // Update display
  matrix.swapBuffers(false);
}
void Fct_jPietri(){
  
   compteurJpietri = placeVisiteur.toInt();
  
   while (commande==60||commande==1){

    if (compteurJpietri!=1){
    //textX=64;
    for ( int i=0;i<300;i++) {
          matrix.setTextSize(2); 
          matrix.fillScreen(0);  
          matrix.setTextColor(pgm_read_word(&Color[1]));
          matrix.setCursor(textX, 1);
          matrix.print("PARKING ");  //F2(str)
          matrix.setTextColor(pgm_read_word(&Color[3]));
          matrix.print("J.PIETRI");  //F2(str)
          // Move text left (w/wrap), increase hue
          if((--textX) < textMin){ textX = 15; i++;}
          
          // Update display
          matrix.swapBuffers(false);
          Fct_receptionRS485();
        if (commande!=60 && commande!=1){return;}
      }
    }
   // voitureEntreeParking();
   
   if (sensEntree){
    Serial1.println("voiture entre");
   voitureEntreeParking();
   }
   else{
    Serial1.println("voiture sort");
    voitureSortieParking();
   }
   
  }
}
void voitureEntree(int avance){
   matrix.fillRect(textX+avance+9, 4, 16,1, pgm_read_word(&Color[3]));//89
  matrix.fillRect(textX+avance+8, 5, 16,4, pgm_read_word(&Color[3]));//88
  matrix.fillRect(textX+avance+10, 5, 5,2, pgm_read_word(&Color[1]));//90
  //matrix.fillRect(textX+95, 5, 3,2, pgm_read_word(&Color[1]));
  
  matrix.fillRect(textX+avance+1, 8, 24,1, pgm_read_word(&Color[1]));//81
  matrix.fillRect(textX+avance, 9, 25,4, pgm_read_word(&Color[1]));//80
  matrix.fillCircle(textX+avance+5, 13, 2, pgm_read_word(&Color[2]));//85
  matrix.fillCircle(textX+avance+20, 13, 2, pgm_read_word(&Color[2]));//100
  matrix.setTextSize(2);  
  matrix.setTextColor(pgm_read_word(&Color[3]));
  matrix.setCursor(textX+79, 2);
  /*matrix.fillRect(textX+76, 0, 16,16, pgm_read_word(&Color[3]));
  matrix.fillRect(textX+77, 1, 14,14, pgm_read_word(&Color[1]));
  matrix.setTextSize(2);  
  matrix.setTextColor(pgm_read_word(&Color[3]));
  matrix.setCursor(textX+79, 2);
  matrix.print("P");  //F2(str)*/
  
}
void voitureSortie(int avance){
  matrix.fillRect(textX+avance, 4, 16,1, pgm_read_word(&Color[3]));//89 SPOILER
  matrix.fillRect(textX+avance+1, 5, 16,4, pgm_read_word(&Color[3]));//88 HAUT VOITURE
  matrix.fillRect(textX+avance+10, 5, 5,2, pgm_read_word(&Color[1]));//90 FENETRE
  //matrix.fillRect(textX+95, 5, 3,2, pgm_read_word(&Color[1]));
  
  matrix.fillRect(textX+avance, 8, 24,1, pgm_read_word(&Color[1]));//81 HAUT CARCASSE POUR ARRONDI
  matrix.fillRect(textX+avance, 9, 25,4, pgm_read_word(&Color[1]));//80 CARCASSE
  matrix.fillCircle(textX+avance+5, 13, 2, pgm_read_word(&Color[2]));//85 ROUE
  matrix.fillCircle(textX+avance+20, 13, 2, pgm_read_word(&Color[2]));//100 ROUE
  matrix.setTextSize(2);  
  matrix.setTextColor(pgm_read_word(&Color[3]));
  matrix.setCursor(textX+79, 2);
  /*matrix.fillRect(textX+76, 0, 16,16, pgm_read_word(&Color[3]));
  matrix.fillRect(textX+77, 1, 14,14, pgm_read_word(&Color[1]));
  matrix.setTextSize(2);  
  matrix.setTextColor(pgm_read_word(&Color[3]));
  matrix.setCursor(textX+79, 2);
  matrix.print("P");  //F2(str)*/
    
}
void voitureEntreeParking(){
 for ( y=0;y<2000;y++) {
   int compteur = compteurJpietri;//placeVisiteur.toInt();
   if((textX <= -65)||z){compteurJpietri=placeVisiteur.toInt();}
   matrix.fillScreen(0); //efface l ecran
   if(!z){voitureEntree(avance);}
   matrix.fillRect(0, 0, 16,16, pgm_read_word(&Color[3]));
   matrix.fillRect(1, 1, 14,14, pgm_read_word(&Color[1]));
   matrix.setTextSize(2);  
   matrix.setTextColor(pgm_read_word(&Color[3]));
   matrix.setCursor(3, 2);
   matrix.print("P");  //F2(str)
  // Move text left (w/wrap), increase hue
  if((--textX) < -70){ textX = 30;}//matrix.width()

  avance-=2;
  //if(i>(i%1000))
  if(avance <= 0){z=true;}
  // matrix.setCursor(17, 1);
  // matrix.print("J.PIETRI");
  // Update display
 //matrix.swapBuffers(false); 

      /*
         int compteur = placeVisiteur.toInt();
         matrix.setTextSize(1);
         matrix.fillScreen(0); //efface l ecran
         matrix.setTextColor(pgm_read_word(&Color[1]));
         
        if (compteur ==1){
                
            matrix.setCursor(0, 0);
            matrix.print("PLACE");  //F2(str)          
        }
        else{
              matrix.setCursor(0, 0);
              matrix.print(F2(places));  //F2(str)
        }
*/
        
        if (compteur < 10){   
            textX2=36;
            matrix.setTextColor(pgm_read_word(&Color[2]));
        }
        if ((compteur >= 10)&(compteur < 100)) {
            textX2=29;
            matrix.setTextColor(pgm_read_word(&Color[3]));
        }
        if ((compteur >= 100)&(compteur < 1000)) {
            textX2=22;
            matrix.setTextColor(pgm_read_word(&Color[3]));
        }
        matrix.setTextSize(2);
        matrix.setCursor(textX2, 1);
        if(((textX<=-65)||z)){matrix.print(compteurJpietri); } //F2(str)
        else{matrix.print(compteur);}
       
        // Move text left (w/wrap), increase hue
       // if((--textX) < textMin){ textX = matrix.width(); i++;}
        
        // Update display
        matrix.swapBuffers(false);
        Fct_receptionRS485();
        if (commande!=60 && commande!=1){return;}
    
    } 
}
void voitureSortieParking(){
for ( y=0;y<2000;y++) {
   int compteur = compteurJpietri;//placeVisiteur.toInt();
   if((textX >= 65)||z){compteurJpietri=placeVisiteur.toInt();}
   matrix.fillScreen(0); //efface l ecran
   if(!z){voitureSortie(avance);}
   matrix.fillRect(0, 0, 16,16, pgm_read_word(&Color[3]));
   matrix.fillRect(1, 1, 14,14, pgm_read_word(&Color[1]));
   matrix.setTextSize(2);  
   matrix.setTextColor(pgm_read_word(&Color[3]));
   matrix.setCursor(3, 2);
   matrix.print("P");  //F2(str)
  // Move text left (w/wrap), increase hue
  if((++textX) > 70){ textX = 30;}//matrix.width()

  avance+=2;
  //if(i>(i%1000))
  if(avance >= 65){z=true;}
  // matrix.setCursor(17, 1);
  // matrix.print("J.PIETRI");
  // Update display
 //matrix.swapBuffers(false); 

      /*
         int compteur = placeVisiteur.toInt();
         matrix.setTextSize(1);
         matrix.fillScreen(0); //efface l ecran
         matrix.setTextColor(pgm_read_word(&Color[1]));
         
        if (compteur ==1){
                
            matrix.setCursor(0, 0);
            matrix.print("PLACE");  //F2(str)          
        }
        else{
              matrix.setCursor(0, 0);
              matrix.print(F2(places));  //F2(str)
        }
*/
        
        if (compteur < 10){   
            textX2=36;
            matrix.setTextColor(pgm_read_word(&Color[2]));
        }
        if ((compteur >= 10)&(compteur < 100)) {
            textX2=29;
            matrix.setTextColor(pgm_read_word(&Color[3]));
        }
        if ((compteur >= 100)&(compteur < 1000)) {
            textX2=22;
            matrix.setTextColor(pgm_read_word(&Color[3]));
        }
        matrix.setTextSize(2);
        matrix.setCursor(textX2, 1);
        if(((textX>=65)||z)){matrix.print(compteurJpietri); } //F2(str)
        else{matrix.print(compteur);}
       
        // Move text left (w/wrap), increase hue
       // if((--textX) < textMin){ textX = matrix.width(); i++;}
        
        // Update display
        matrix.swapBuffers(false);
        Fct_receptionRS485();
        if (commande!=60 && commande!=1){return;}
    
    } 
  
}
void afficherParking1() {
 while(commande == 49){
  for (int i = 0; i < 300; i++) {
    matrix.setTextSize(2);
    matrix.fillScreen(0);
    matrix.setTextColor(pgm_read_word(&Color[1]));
    matrix.setCursor(textX, 1);
    matrix.print("Parking 1 : ");
    matrix.setTextColor(pgm_read_word(&Color[4]));
    matrix.print(placeVisiteur);
    
    // Move text left (w/wrap), increase hue
    if((--textX) < textMin){textX = matrix.width(); i++;}
    
    matrix.swapBuffers(false);
    Fct_receptionRS485();

  }
 }
}

void afficherParking2() {
 while(commande == 56){
  for (int i = 0; i < 300; i++) {
    matrix.setTextSize(2);
    matrix.fillScreen(0);
    matrix.setTextColor(pgm_read_word(&Color[2]));
    matrix.setCursor(textX, 1);
    matrix.print("PARKING 2 : ");
    matrix.setTextColor(pgm_read_word(&Color[1]));
    matrix.print(placeVisiteur);
    
    // Move text left (w/wrap), increase hue
    if((--textX) < textMin){textX = matrix.width(); i++;}
    
    matrix.swapBuffers(false);
    Fct_receptionRS485();

  }
 }
}

void afficherParkingPlacesLibresGeneral2L(){
      
int compteur = placeVisiteur.toInt();
      
while(commande == 57){
      matrix.setTextSize(1);
      matrix.fillScreen(0); //efface l ecran
      matrix.setTextColor(pgm_read_word(&Color[1]));
      
      if (compteur <= 1){
      
      matrix.setCursor(0, 0);
      matrix.print(F2(place));  //F2(str)
      
      matrix.setCursor(0, 8);
      matrix.print(F2(libre));  //F2(str)
      
      }
      else{
      matrix.setCursor(0, 0);
      matrix.print(F2(places));  //F2(str)
      
      matrix.setCursor(0, 8);
      matrix.print(F2(libres));  //F2(str) 
      }
      if (compteur < 10){   
      textX2=59;
      matrix.setTextColor(pgm_read_word(&Color[2]));
      }
      if ((compteur >= 10)&(compteur < 100)) {
      textX2=53;
      matrix.setTextColor(pgm_read_word(&Color[0]));
      }if (compteur >= 100){   
      textX2=47;
      matrix.setTextColor(pgm_read_word(&Color[4]));
      }
      matrix.setTextSize(1);
      matrix.setCursor(textX2, 1);
      matrix.print(placeVisiteur);  //F2(str)
      
      // Update display
      matrix.swapBuffers(false);
      Fct_receptionRS485();
      }
    }

    
void afficherP1P2Libres2L(){  
while(commande == 58){
int compteur1 = placeVisiteur1.toInt();
int compteur2 = placeVisiteur2.toInt();
int y1=0 , y2=9;

      matrix.setTextSize(1);
      matrix.fillScreen(0); //efface l ecran
      matrix.setTextColor(pgm_read_word(&Color[1]));
      
      matrix.setCursor(0, y1);
      matrix.print("P1 : ");  //F2(str)
      matrix.setTextColor(pgm_read_word(&Color[3]));
      
      matrix.setCursor(0, y2);
      matrix.print("P2 : ");  //F2(str)
      matrix.setTextColor(pgm_read_word(&Color[3]));
      
      matrix.setTextSize(1);
      
      if (compteur1 < 10){   
      textX2=59;
      matrix.setTextColor(pgm_read_word(&Color[2]));
      }
      if ( compteur1 >= 10 && compteur1 < 100 ) {
      textX2=53;
      matrix.setTextColor(pgm_read_word(&Color[0]));
      }
      if (compteur1 >= 100){   
      textX2=47;
      matrix.setTextColor(pgm_read_word(&Color[4]));
      }
      
      matrix.setCursor(textX2, y1);
      
      matrix.print(placeVisiteur1);  //F2(str)

      
      if (compteur2 < 10){   
      textX2=59;
      matrix.setTextColor(pgm_read_word(&Color[2]));
      }
      if (compteur2 >= 10 && compteur2 < 100) {
      textX2=53;
      matrix.setTextColor(pgm_read_word(&Color[0]));
      }
      if (compteur2 >= 100){   
      textX2=47;
      matrix.setTextColor(pgm_read_word(&Color[4]));
      }
          
      
      matrix.setCursor(textX2, y2);
      
      matrix.print(placeVisiteur2);  //F2(str)
      
      // Update display
      matrix.swapBuffers(false);
      Fct_receptionRS485();
      }
}
    
void afficherP1P2Libres2LMove(){
        
int compteur1 = placeVisiteur1.toInt();
int compteur2 = placeVisiteur2.toInt();
int y1=0 , y2=9;
      
while(commande == 59){

for (int i = 0; i < 300; i++) {
      
      matrix.setTextSize(1);
      matrix.fillScreen(0); //efface l ecran
      matrix.setTextColor(pgm_read_word(&Color[1]));
      
      matrix.setCursor(textX, y1);
      matrix.print("P1 : ");  //F2(str)
     
      matrix.setCursor(textX, y2);
      matrix.print("P2 : ");  //F2(str)

            
      if (compteur1 < 10){   
      textX2=64;
      matrix.setTextColor(pgm_read_word(&Color[2]));
      }
      if ( compteur1 >= 10 && compteur1 < 100 ) {
      textX2=55;
      matrix.setTextColor(pgm_read_word(&Color[0]));
      }
      if (compteur1 >= 100){   
      textX2=50;
      matrix.setTextColor(pgm_read_word(&Color[4]));
      }
      
      matrix.setCursor(textX+25, y1);
      matrix.print(placeVisiteur1);  //F2(str)

      
      if (compteur2 < 10){   
      textX2=64;
      matrix.setTextColor(pgm_read_word(&Color[2]));
      }
      if (compteur2 >= 10 && compteur2 < 100) {
      textX2=55;
      matrix.setTextColor(pgm_read_word(&Color[0]));
      }
      if (compteur2 >= 100){   
      textX2=50;
      matrix.setTextColor(pgm_read_word(&Color[4]));
      }
          
      matrix.setCursor(textX+25, y2);
      
      matrix.print(placeVisiteur2);  //F2(str)
      
          // Move text left (w/wrap), increase hue
    if((--textX) < textMin){textX = matrix.width(); i++;}
    
      // Update display
      matrix.swapBuffers(false);
      Fct_receptionRS485();
      }
    }
}

void afficherMessage(String Mess) {

while(commande == 6){
  
  for (int i = 0; i < 300; i++) {
    
    matrix.fillScreen(0); // Efface l'écran
    matrix.setCursor(textX, 0);
    matrix.print(Mess);
             
    // Move text left (w/wrap), increase hue
    if((--textX) < textMin){textX = matrix.width(); i++;}
    
      // Update display
      matrix.swapBuffers(false);
      Fct_receptionRS485();
    }
}
}
