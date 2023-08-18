#ifndef CUJEUDUPENDU_H
#define CUJEUDUPENDU_H
#include <QPushButton>
#include <iostream>
#include <QLineEdit>
#include <QMainWindow>
#include <QString>

class CUjeuDUPendu {

private:

    QString nomJoueur;
    QString nomFichierDeMots;
    int nombreDeMotsDisponibles;
    QString motChoisi;
    QString motEnCours;
    int nombreErreur;
    class IHMPendu* addIHMPendu;

public:

    CUjeuDUPendu();
    ~CUjeuDUPendu();
    void RecupAddIHM(class IHMPendu*);
    QString getnomFichierDeMots();
    void setnomFichierDeMots(QString);
    int getnombreErreur();
    void setnombreErreur(int);
    QString getmotEnCours();
    void setmotEnCours(QString);
    QString getmotChoisi();
    int tirageAleatoire(int maxi,int mini);
    void miseAJourFichierDeMots();
    int getnombredemotsdisponibles();
    void lireNombresdeMotsAJour();
    void commencerunePartie();
    void setnombredemotsdisponibles(int nbrdemotdispo);
    void setMotPointilles(QString a);
};

#endif // CUJEUDUPENDU_H
