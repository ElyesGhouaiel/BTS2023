// scrolltext demo for Adafruit RGBmatrixPanel library.
// Demonstrates double-buffered animation on our 16x32 RGB LED matrix:
// http://www.adafruit.com/products/420

// Written by Limor Fried/Ladyada & Phil Burgess/PaintYourDragon
// for Adafruit Industries.
// BSD license, all text above must be included in any redistribution.

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library
#include <EEPROM.h>  // pour utiliser la mémoire EEPROM







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
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, DOUBLEBUFFER, NUMDISPLAYS);

const char parking[] PROGMEM = "PARKING";
const char complet[] PROGMEM = "COMPLET";
const char places[]  PROGMEM = "PLACES";
const char libres[]  PROGMEM = "LIBRES";
const char libre[]  PROGMEM = "LIBRE";
const char ouvert[]  PROGMEM = "OUVERT";
const char ferme[]   PROGMEM = "FERME";
const char abonne[]   PROGMEM = "ABONNES";
const char pmr[]   PROGMEM = "PMR";
const char str[] PROGMEM = "SevenPark";

       
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
  String placeVisiteur="25";
  String placeAbonnes="10";
  String placePmr="2";
  String messageLive="";
  
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
/*const unsigned char Complet [] PROGMEM = {
  // 'COMPLET'
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x06, 0x18, 0x6f, 0x86, 0x07, 0xf7, 0xfe,
  0x3f, 0x0f, 0x18, 0x6f, 0xc6, 0x07, 0xf7, 0xfe, 0x33, 0x9f, 0x98, 0x6c, 0xe6, 0x06, 0x00, 0x60,
  0x71, 0x99, 0x98, 0x6c, 0x76, 0x06, 0x00, 0x60, 0x60, 0x30, 0xdc, 0xec, 0x36, 0x06, 0x00, 0x60,
  0x60, 0x30, 0xdf, 0xec, 0x76, 0x06, 0x00, 0x60, 0x60, 0x30, 0xdf, 0xec, 0xe6, 0x07, 0xc0, 0x60,
  0x60, 0x30, 0xdf, 0xef, 0xc6, 0x07, 0xc0, 0x60, 0x60, 0x30, 0xdb, 0x6f, 0x86, 0x06, 0x00, 0x60,
  0x60, 0x30, 0xd8, 0x6c, 0x06, 0x06, 0x00, 0x60, 0x71, 0x99, 0x98, 0x6c, 0x06, 0x06, 0x00, 0x60,
  0x33, 0x9f, 0x98, 0x6c, 0x06, 0x06, 0x00, 0x60, 0x3f, 0x0f, 0x18, 0x6c, 0x07, 0xf7, 0xf0, 0x60,
  0x1e, 0x06, 0x18, 0x6c, 0x07, 0xf7, 0xf0, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  };

  const unsigned char Full [] PROGMEM = {
  // 'FULL, 64x16px
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf8, 0xc1, 0x8c, 0x03, 0x00, 0x00,
  0x00, 0x07, 0xf8, 0xc1, 0x8c, 0x03, 0x00, 0x00, 0x00, 0x06, 0x00, 0xc1, 0x8c, 0x03, 0x00, 0x00,
  0x00, 0x06, 0x00, 0xc1, 0x8c, 0x03, 0x00, 0x00, 0x00, 0x06, 0x00, 0xc1, 0x8c, 0x03, 0x00, 0x00,
  0x00, 0x06, 0x00, 0xc1, 0x8c, 0x03, 0x00, 0x00, 0x00, 0x07, 0xe0, 0xc1, 0x8c, 0x03, 0x00, 0x00,
  0x00, 0x07, 0xe0, 0xc1, 0x8c, 0x03, 0x00, 0x00, 0x00, 0x06, 0x00, 0xc1, 0x8c, 0x03, 0x00, 0x00,
  0x00, 0x06, 0x00, 0xc1, 0x8c, 0x03, 0x00, 0x00, 0x00, 0x06, 0x00, 0xc1, 0x8c, 0x03, 0x00, 0x00,
  0x00, 0x06, 0x00, 0xe3, 0x8c, 0x03, 0x00, 0x00, 0x00, 0x06, 0x00, 0x7f, 0x0f, 0xe3, 0xf8, 0x00,
  0x00, 0x06, 0x00, 0x3e, 0x0f, 0xe3, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  };
*/


void setup() {  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


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

  Fct_receptionRS485();
  if (demarrage==0){
    Fct_jPietri();
    demarrage=1;
  }
}

/*
  ETAT_E1=digitalRead(E1);  // bouton poussoir choix couleur


  bufferRs485=Serial1.available();


  while (bufferRs485 > 0){

  int inChar = Serial1.read();// creation de la variable qui prendra la valeur de chaque octées recus
  if (inChar == '?'){
  int inChar = Serial1.read();
  if(inChar == '0') colorSet=0;
  if(inChar == '1') colorSet=1;
  if(inChar == '2') colorSet=2;
  if(inChar == '3') colorSet=3;
  if(inChar == '4') colorSet=4;
  }
  if (inChar == '#') debutTrame=1;

  if (isDigit(inChar)&&(debutTrame ==1)) { // si inChar est un nombre
  inString += (char)inChar; // on rajoute dans la chaine de caracteres inString la valeur de inChar a la suite
  }

  if  (inChar == '\n')  {compteur = (inString.toInt()); Serial.println(compteur); debutTrame=0; inString = ""; Serial1.print(comOK);}//remise a zero renvoie aprés chaques receptions un message com ok sur le bus

  bufferRs485=Serial1.available();// on verifie si il reste des données dans le buffer .

  }


  if(compteur==0) {

  matrix.fillScreen(0);//effacement dalle

  // Draw big scrolly text on top

  matrix.setTextColor(pgm_read_word(&Color[2]));
  matrix.setCursor(textX, 1);
  matrix.print(F2(str));  //F2(str)

  // Move text left (w/wrap), increase hue
  if((--textX) < textMin) textX = matrix.width();

  // Update display
  matrix.swapBuffers(false);

  }
  else {

  if ((ETAT_E1 == LOW) && (ETAT_E1 != memoireE1))    ReglageCouleur();

  matrix.fillScreen(0);//effacement dalle

  // Decalage compteur sur la dalle pour affichage au bonne endroit

  if (compteur < 10) textX2=52;
  if ((compteur >= 10)&(compteur < 100)) textX2=40;
  if ((compteur >= 100)&(compteur < 1000)) textX2=28;
  if ((compteur >= 1000)&(compteur < 10000)) textX2=16;
  if ((compteur >= 10000)&(compteur < 100000)) textX2=4;


  // Draw big scrolly text on top
  matrix.setTextColor(pgm_read_word(&Color[colorSet]));
  matrix.setCursor(textX2, 1);
  matrix.print(compteur);  //F2(str)


  // Update display
  matrix.swapBuffers(false);
  textX = matrix.width();//redemarrage du texte complet au debut de la ligne
  }
  memoireE1 = ETAT_E1;
  }
*/

void Fct_reglageCouleur() {
  colorSet++;
  if (colorSet >= 5) colorSet = 0; // si n supérieur à 5 on le repasse à zéro
  EEPROM.write(500, colorSet);
  digitalWrite(led, LOW); // flash de la led sur bouton "demande de ticket", opération prise en compte
  delay(200);
  digitalWrite(led, HIGH);
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
  char charTemp = "";
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
      
    case 2://CPT ABONNE 2 LIGNES
      placeAbonnes=dataRecu;
      break;
      
    case 3://CPT PMR 2 LIGNES
      placePmr=dataRecu;
      break;
      
   case 8://CPT PMR 2 LIGNES

      break;
      
    case 9://ACCUEIL
      while (commande==9){
         matrix.setTextSize(2); 
          matrix.fillScreen(0);  
          matrix.setTextColor(pgm_read_word(&Color[1]));
          matrix.setCursor(textX, 1);
          matrix.print("PARKING ");  //F2(str)
          matrix.setTextColor(pgm_read_word(&Color[3]));
          matrix.print("J.PIETRI");  //F2(str)
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
        matrix.print("J. PIETRI");  //F2(str)
      
        matrix.swapBuffers(false); 
      break;
      
    case 11://LIBRE 2 LIGNES
      //Serial1.println("LIBRE 2 LIGNES");
     Fct_libre2L();
      break;
      
    case 12://COMPLET 2 LIGNES
      //Serial1.println("COMPLET 2 LIGNES");
     Fct_complet2L();
      break;
      
    case 13://OUVERT 2 LIGNES
          //Serial1.println("OUVERT 2 LIGNES");
      Fct_ouvert2L();
      break;
      
    case 14://FERME 2 LIGNES
      //Serial1.println("FERME 2 LIGNES");
      Fct_ferme2L();
      break;
      
    case 15://LIBRE DEFILEMENT
      //Serial1.println("LIBRE DEFILEMENT");
      Fct_libre();
      break;
      
    case 16://COMPLET DEFILEMNT
      //Serial1.println("CPT PMR");
      Fct_complet();
      break;

    case 17://OUVERT DEFILEMENT
      //Serial1.println("LIBRE");
      Fct_ouvert();
      break;
      
    case 18://FERME DEFILEMENT
     //Serial1.println("COMPLET");
     Fct_ferme();
      break;
      
    case 19:

      break;
      
    case 20://PLACE VISITEUR 2 LIGNES
     // placeVisiteur=dataRecu;
     Fct_AfficheCompteurVisiteur2L();
      break;
      
    case 21://PLACE ABONNES 2 LIGNES
      //Serial1.println("CPT VISITEURS");
     // placeAbonnes=dataRecu;
      Fct_AfficheAbonne2L(); 
      break;
      
    case 22://PLACE PMR 2 LIGNES 
     // Serial1.println("CPT ABONNES");
      //placePmr=dataRecu;
      Fct_AffichePmr2L(); 
      break;
      
    case 23://PLACE VISITEURS DEFILEMENT
      //Serial1.println("CPT PMR");
     //placeVisiteur=dataRecu;
      Fct_AfficheCompteurVisiteur();
      break;

    case 24://PLACE ABONNES DEFILEMENT
      //Serial1.println("LIBRE");
      //placeAbonnes=dataRecu; 
      Fct_AfficheAbonne();          
      break;
      
    case 25://PLACE PMR DEFILEMENT
      //placePmr=dataRecu;
      Fct_AffichePMR();
      
      break;

      
      
    case 30://MESS 1 PROG
     // Serial1.println("OUVERT");
      Fct_afficheMessage(30);
      break;
      
    case 31://MESS 2 PROG
      //Serial1.println("FERME");
      Fct_afficheMessage(31);
      break;
      
    case 32://MESS 3 PROG
      //Serial1.println("CPT VISITEURS");
      Fct_afficheMessage(32);
      break;
      
    case 33://MESS 4 PROG
     // Serial1.println("CPT ABONNES");
     Fct_afficheMessage(33);
      break;
      
    case 34://MESS 5 PROG
     // Serial1.println("CPT PMR");
     Fct_afficheMessage(34);
      break;
      
    case 35://MESS 6 PROG
      //Serial1.println("OUVERT");
      Fct_afficheMessage(35);
      break;
          
    case 36://MESSAGE LIVE 
     // Serial1.println("CPT VISITEURS");
      //messageLive=dataRecu;
      Fct_afficheMessageLive();
      break;
      
    case 37://MESSAGE LIVE 2 LIGNES
     // Serial1.println("CPT VISITEURS");
     // messageLive=dataRecu;
      Fct_afficheMessageLive2L();
      break;
      
    case 38://CPT LIVE 1 LIGNE
     // Serial1.println("CPT VISITEURS");
     // messageLive=dataRecu;
      Fct_cptLive();
      break;
      
    case 39://CPT LIVE 2 LIGNES
     // Serial1.println("CPT VISITEURS");
     // messageLive=dataRecu;
      Fct_cptLive2L();
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

      
    case 60://J.PIETRI
     placeVisiteur=dataRecu;
     Fct_jPietri() ;
      break;
  }
 }
}

void Fct_lectureEeprom(int NumeroAffichage) {

  char charTemp = "";
  int decalageAdresse = NumeroAffichage * 100;
  String StrMessage = "";
  String StrOrdre = "";
  String StrType = "";
  String StrCouleur = "";
  String StrNbrCycle = "";
  String StrIntervalle = "";
  String StrTempo = "";
  i = 0;


  while (charTemp != char(0) ) {
    charTemp = EEPROM.read(MESSAGE + decalageAdresse + i);
    if (charTemp != char(0)) {
      StrMessage += charTemp;
    }
    i++;
  }
  affichage[NumeroAffichage].message = StrMessage;
  Serial1.print("message: "); Serial1.println(affichage[NumeroAffichage].message);
  i = 0;
  charTemp = '/';
  
  while (charTemp != char(0) ) {
    charTemp = EEPROM.read(ORDRE + decalageAdresse + i);
    int temp = ORDRE + decalageAdresse + i;
    //Serial1.print("temp: ");Serial1.print(temp);
    if (charTemp != char(0)) {
      StrOrdre += (char)charTemp;
      //Serial1.print(charTemp,HEX);
    }
    i++;
  }
  
  affichage[NumeroAffichage].ordre = StrOrdre.toInt();
  Serial1.print("ordre: "); Serial1.println( affichage[NumeroAffichage].ordre);
  i = 0;

  charTemp = '/';
  while (charTemp != char(0) ) {
    charTemp = EEPROM.read(TYPE + decalageAdresse + i);
    if (charTemp != char(0)) {
      StrType += charTemp; 
    }
    i++;
  }
  affichage[NumeroAffichage].type = StrType.toInt();
  Serial1.print("type: "); Serial1.println(affichage[NumeroAffichage].type);
  i = 0;
  charTemp = '/';
  while (charTemp != char(0) ) {
    charTemp = EEPROM.read(COULEUR + decalageAdresse + i);
    if (charTemp != char(0)) {
      StrCouleur += charTemp;
    }
    i++;
  }
  affichage[NumeroAffichage].couleur = StrCouleur.toInt();
   Serial1.print("couleur: "); Serial1.println(affichage[NumeroAffichage].couleur);
  i = 0;
  charTemp = '/';
  while (charTemp != char(0) ) {
    charTemp = EEPROM.read(NBRCYCLE + decalageAdresse + i);
    if (charTemp != char(0)) {
      StrNbrCycle += charTemp;
    }
    i++;
  }
  affichage[NumeroAffichage].nbrCycle = StrNbrCycle.toInt();
  Serial1.print("nbrCycle: "); Serial1.println(affichage[NumeroAffichage].nbrCycle);
  i = 0;
  charTemp = '/';
  while (charTemp != char(0) ) {
    charTemp = EEPROM.read(INTERVALLE + decalageAdresse + i);
    if (charTemp != char(0)) {
      StrIntervalle += charTemp;
    }
    i++;
  }
  affichage[NumeroAffichage].intervalle = StrIntervalle.toInt();
  Serial1.print("intervalle: "); Serial1.println(affichage[NumeroAffichage].intervalle);
  
  i = 0;
  charTemp = '/';
  while (charTemp != char(0) ) {
    charTemp = EEPROM.read(TEMPO + decalageAdresse + i);
    if (charTemp != char(0)) {
      StrTempo += charTemp;
    }
    i++;
  }
  affichage[NumeroAffichage].tempo = StrTempo.toInt();
  Serial1.print("tempo: "); Serial1.println(affichage[NumeroAffichage].tempo );
  i = 0;

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

void Fct_afficheMessageLive(){
  
 while (commande == 36){
  
  matrix.setTextSize(2); 
  matrix.fillScreen(0);  
  matrix.setTextColor(pgm_read_word(&Color[couleurMessProg]));
  matrix.setCursor(textX, 1);
  matrix.print(textMessL1);  //F2(str)

  // Move text left (w/wrap), increase hue
  if((--textX) < textMin){ textX = matrix.width(); i++;}
  //if((--textX) < -80){ textX = 64; i++;}
  
  // Update display
  matrix.swapBuffers(false);
  Fct_receptionRS485();

 
  }
}  

void Fct_afficheMessageLive2L(){
   
   matrix.setTextSize(1);
   matrix.fillScreen(0); //efface l ecran
   
    matrix.setTextColor(pgm_read_word(&Color[couleurL1]));
    matrix.setCursor(XL1, 0);
    matrix.print(textMessL1);  //F2(str)
    
    matrix.setTextColor(pgm_read_word(&Color[couleurL2]));
    matrix.setCursor(XL2, 8);
    matrix.print(textMessL2);  //F2(str)

  matrix.swapBuffers(false);
}

void Fct_cptLive(){
  
 while (commande==38){
  matrix.setTextSize(2); 
  matrix.fillScreen(0);  
  
  matrix.setTextColor(pgm_read_word(&Color[couleurL1]));
  matrix.setCursor(textX, 1);
  matrix.print(textMessL1);    
 
  matrix.setTextColor(pgm_read_word(&Color[couleurCpt]));
  matrix.print(placeVisiteur);  //F2(str)   

  // Move text left (w/wrap), increase hue
  if((--textX) < textMin){ textX = matrix.width(); i++;}
  //if((--textX) < -80){ textX = 64; i++;}
  // Update display
  matrix.swapBuffers(false);
  Fct_receptionRS485();

 }
}

void Fct_cptLive2L(){
  
 int compteur = placeVisiteur.toInt();
 
   matrix.fillScreen(0); //efface l ecran 
   matrix.setTextSize(1);
  
   matrix.setTextColor(pgm_read_word(&Color[couleurL1]));
   matrix.setCursor(XL1, 0);
   matrix.print(textMessL1);  //F2(str)
    
   matrix.setTextColor(pgm_read_word(&Color[couleurL2]));
   matrix.setCursor(XL2, 8);
   matrix.print(textMessL2);  //F2(str)

   matrix.setTextColor(pgm_read_word(&Color[couleurCpt]));
   matrix.setTextSize(2);
   matrix.setCursor(Xcpt, 1);
   matrix.print(placeVisiteur);  //F2(str)
   
   matrix.swapBuffers(false);
}
//------------------------------------- Defilement 1 ligne------------------------------------------------------

void Fct_AfficheCompteurVisiteur(){
  
  
 while (commande==23||commande==1){
  matrix.setTextSize(2); 
  matrix.fillScreen(0);  
  matrix.setTextColor(pgm_read_word(&Color[3]));
  if (placeVisiteur.toInt()>1){
  matrix.setCursor(textX, 1);
  matrix.print("PLACES LIBRES ");    
  }
  else{
  matrix.setCursor(textX, 1);
  matrix.print("PLACE LIBRE ");    
  }

 if (placeVisiteur.toInt()<10){
  matrix.setTextColor(pgm_read_word(&Color[2]));
  matrix.print(placeVisiteur);  //F2(str)   
  }
  else{
  matrix.setTextColor(pgm_read_word(&Color[0]));
  matrix.print(placeVisiteur);  //F2(str)  
  }
  


  // Move text left (w/wrap), increase hue
 // if((--textX) < textMin){ textX = matrix.width(); i++;}
 if((--textX) < -190){ textX = 64; i++;}
  
  // Update display
  matrix.swapBuffers(false);
  Fct_receptionRS485();

 
  }
}

void Fct_AfficheAbonne(){
  
 while (commande==24||commande==2){
  matrix.setTextSize(2); 
  matrix.fillScreen(0);  
  matrix.setTextColor(pgm_read_word(&Color[4]));
  if (placeAbonnes.toInt()>1){
  matrix.setCursor(textX, 1);
  matrix.print("PLACES ABONNES ");    
  }
  else{
  matrix.setCursor(textX, 1);
  matrix.print("PLACE ABONNES ");    
  }

  if (placeAbonnes.toInt()<10){
  matrix.setTextColor(pgm_read_word(&Color[2]));
  matrix.print(placeAbonnes);  //F2(str)   
  }
  else{
  matrix.setTextColor(pgm_read_word(&Color[0]));
  matrix.print(placeAbonnes);  //F2(str)  
  }

  // Move text left (w/wrap), increase hue
  //if((--textX) < textMin){ textX = matrix.width(); i++;}
  if((--textX) < -200){ textX = 64; i++;}
  
  // Update display
  matrix.swapBuffers(false);
  Fct_receptionRS485();

 
  }
}
void Fct_AffichePMR(){
  
 while (commande==25||commande==3){
  matrix.setTextSize(2); 
  matrix.fillScreen(0);  
  matrix.setTextColor(pgm_read_word(&Color[1]));
  if (placePmr.toInt()>1){
  matrix.setCursor(textX, 1);
  matrix.print("PLACES PMR ");    
  }
  else{
  matrix.setCursor(textX, 1);
  matrix.print("PLACE PMR ");    
  }

if (placePmr.toInt()<10){
  matrix.setTextColor(pgm_read_word(&Color[2]));
  matrix.print(placePmr);  //F2(str)   
  }
  else{
  matrix.setTextColor(pgm_read_word(&Color[0]));
  matrix.print(placePmr);  //F2(str)  
  }
  // Move text left (w/wrap), increase hue
  //if((--textX) < textMin){ textX = matrix.width(); i++;}
  if((--textX) < -190){ textX = 64; i++;}
  
  // Update display
  matrix.swapBuffers(false);
  Fct_receptionRS485();

 
  }
}
void Fct_ferme(){
  while (commande==18){
  matrix.setTextSize(2); 
  matrix.fillScreen(0);  
  matrix.setTextColor(pgm_read_word(&Color[2]));
  matrix.setCursor(textX, 1);
  matrix.print(F2(ferme));  //F2(str)

  // Move text left (w/wrap), increase hue
  if((--textX) < -80){ textX = 64; i++;}
  
  // Update display
  matrix.swapBuffers(false);
  Fct_receptionRS485();

 
  }
} 

void Fct_ouvert(){
  while (commande==17){
  matrix.setTextSize(2); 
  matrix.fillScreen(0);  
  matrix.setTextColor(pgm_read_word(&Color[0]));
  matrix.setCursor(textX, 1);
  matrix.print(F2(ouvert));  //F2(str)

  // Move text left (w/wrap), increase hue
  if((--textX) < -80){ textX = 64; i++;}
  
  // Update display
  matrix.swapBuffers(false);
  Fct_receptionRS485();

 
  }
}   

void Fct_libre(){
  int avance=160;
  int n = 0;
  while (commande==15){
     //matrix.fillScreen(0); //efface l ecran 
  
  //matrix.setTextSize(1);
  matrix.setTextSize(2); 
  matrix.fillScreen(0); 

//voiture(avance);
  matrix.fillRect(textX, 0, 16,16, pgm_read_word(&Color[3]));
  matrix.fillRect(textX+1, 1, 14,14, pgm_read_word(&Color[1]));
  matrix.setTextSize(2);  
  matrix.setTextColor(pgm_read_word(&Color[3]));
  matrix.setCursor(textX+3, 2);
  matrix.print("P");  //F2(str)

   
  matrix.setTextColor(pgm_read_word(&Color[0]));
  matrix.setCursor(textX+17, 1);
  matrix.print(F2(libre));  //F2(str)

 
  // Move text left (w/wrap), increase hue
 if((--textX) < -100){ textX = 64; i++;}
// avance-=1;
// if(avance==0){avance=160;}
  // Update display
  matrix.swapBuffers(false);
  Fct_receptionRS485();

 
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
  if((--textX) < -80){ textX = 64; i++;}
  
  // Update display
  matrix.swapBuffers(false);
  Fct_receptionRS485();

 
  }
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
void Fct_jPietri2(){
int compteur = placeVisiteur.toInt();
  
   
   matrix.fillScreen(0); //efface l ecran
   matrix.fillRect(0, 0, 16,16, pgm_read_word(&Color[3]));
   matrix.fillRect(1, 1, 14,14, pgm_read_word(&Color[1]));
   matrix.setTextSize(2);  
   matrix.setTextColor(pgm_read_word(&Color[3]));
   matrix.setCursor(3, 2);
   matrix.print("P");  //F2(str)
  // Move text left (w/wrap), increase hue
 // if((--textX) < textMin){ textX = matrix.width(); i++;}
  matrix.setCursor(17, 1);
   matrix.print("J.PIETRI");
  // Update display
  matrix.swapBuffers(false); 
}
//-------------------------------2 Lignes---------------------------------------------
void Fct_AfficheCompteurVisiteur2L(){
  int compteur = placeVisiteur.toInt();
  
   matrix.setTextSize(1);
   matrix.fillScreen(0); //efface l ecran
   matrix.setTextColor(pgm_read_word(&Color[0]));
   
  if (compteur ==1){
          
      matrix.setCursor(0, 0);
      matrix.print("PLACE");  //F2(str)

      matrix.setCursor(0, 8);
      matrix.print("LIBRE");  //F2(str)
    
  }
  else{
        matrix.setCursor(0, 0);
        matrix.print(F2(places));  //F2(str)
         
        matrix.setCursor(0, 8);
        matrix.print(F2(libres));  //F2(str) 
  }
  if (compteur < 10){   
      textX2=54;
      matrix.setTextColor(pgm_read_word(&Color[2]));
  }
  if ((compteur >= 10)&(compteur < 100)) {
      textX2=42;
      matrix.setTextColor(pgm_read_word(&Color[3]));
  }
  matrix.setTextSize(2);
  matrix.setCursor(textX2, 1);
  matrix.print(placeVisiteur);  //F2(str)
  // Move text left (w/wrap), increase hue
 // if((--textX) < textMin){ textX = matrix.width(); i++;}
  
  // Update display
  matrix.swapBuffers(false);
}
void Fct_AfficheAbonne2L(){
  
  int compteur = placeAbonnes.toInt();
  
   matrix.setTextSize(1);
   matrix.fillScreen(0); //efface l ecran
   matrix.setTextColor(pgm_read_word(&Color[4]));
   
  if (compteur ==1){
          
      matrix.setCursor(0, 0);
      matrix.print("PLACE");  //F2(str)

      matrix.setCursor(0, 8);
      matrix.print("ABONNES");  //F2(str)
    
  }
  else{
        matrix.setCursor(0, 0);
        matrix.print(F2(places));  //F2(str)
         
        matrix.setCursor(0, 8);
        matrix.print(F2(abonne));  //F2(str) 
  }
  if (compteur < 10){   
      textX2=54;
      matrix.setTextColor(pgm_read_word(&Color[2]));
  }
  if ((compteur >= 10)&(compteur < 100)) {
      textX2=42;
      matrix.setTextColor(pgm_read_word(&Color[3]));
  }
  matrix.setTextSize(2);
  matrix.setCursor(textX2, 1);
  matrix.print(placeAbonnes);  //F2(str)
  // Move text left (w/wrap), increase hue
 // if((--textX) < textMin){ textX = matrix.width(); i++;}
  
  // Update display
  matrix.swapBuffers(false);
  //----------------------
  
}
void Fct_AffichePmr2L(){
  
   int compteur = placePmr.toInt();
  
   matrix.setTextSize(1);
   matrix.fillScreen(0); //efface l ecran
   matrix.setTextColor(pgm_read_word(&Color[1]));
   
  if (compteur ==1){
          
      matrix.setCursor(0, 0);
      matrix.print("PLACE");  //F2(str)

      matrix.setCursor(0, 8);
      matrix.print("Pmr");  //F2(str)
    
  }
  else{
        matrix.setCursor(0, 0);
        matrix.print(F2(places));  //F2(str)
         
        matrix.setCursor(0, 8);
        matrix.print(F2(pmr));  //F2(str) 
  }
  if (compteur < 10){   
      textX2=54;
      matrix.setTextColor(pgm_read_word(&Color[2]));
  }
  if ((compteur >= 10)&(compteur < 100)) {
      textX2=42;
      matrix.setTextColor(pgm_read_word(&Color[3]));
  }
  matrix.setTextSize(2);
  matrix.setCursor(textX2, 1);
  matrix.print(placePmr);  //F2(str)
  // Move text left (w/wrap), increase hue
 // if((--textX) < textMin){ textX = matrix.width(); i++;}
  
  // Update display
  matrix.swapBuffers(false);
 
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
  matrix.setTextColor(matrix.ColorHSV(hue, 255, 255, true));
  matrix.setCursor(textX, 1);
  matrix.print(F2(str));

  // Move text left (w/wrap), increase hue
  if((--textX) < textMin) textX = matrix.width();
  hue += 7;
  if(hue >= 1536) hue -= 1536;

  // Update display
  matrix.swapBuffers(false);
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
