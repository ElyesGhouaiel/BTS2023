#ifndef _CDATE_H
#define _CDATE_H


class CDate {
  private:
    int jour;

    int mois;

    int annee;


  public: 
    //constructeur par defaut : donne aux donnée valeurs par defaut 11/01/2000
    CDate();

    CDate(int leJour, int lemois, int lannee);

    //affiche la date selon le format: jj/m/an
    
    void afficher();

    //retourne l'attribut Jour
    
    int ReturnJour();

    //retourne l'attribut mois
    
    int RetourMois();

   // retourne l'attribut annee
    
    int RetourAnnee();

    void setJour(int unJour);

    void setMois(int Mois);

    void setAnnee(int Annee);

};
#endif
