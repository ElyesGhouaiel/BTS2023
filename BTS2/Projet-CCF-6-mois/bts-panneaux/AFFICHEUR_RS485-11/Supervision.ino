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
  String placeVisiteur="150";
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

      
    case 60://J.PIETRI
     placeVisiteur=dataRecu;
     Fct_jPietri() ;
      break;
  }
 }
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


void afficherParking1() {
  matrix.setTextSize(2);
  matrix.fillScreen(0);
  matrix.setTextColor(matrix.ColorHSV(96, 255, 255, true)); // Couleur turquoise
  matrix.setCursor(0, 1);
  matrix.print("Parking 1 : ",placeVisiteur);
  matrix.swapBuffers(false);
}