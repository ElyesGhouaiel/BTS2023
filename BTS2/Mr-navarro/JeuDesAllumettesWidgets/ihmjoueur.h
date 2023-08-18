#ifndef IHMJOUEUR_H
#define IHMJOUEUR_H
#include <QMainWindow>
#include <iostream>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class IHMjoueur; }
QT_END_NAMESPACE

class IHMjoueur : public QMainWindow
{
    Q_OBJECT

private slots:
    void on_Jouer_clicked();

    void on_OK_clicked();

private:
    Ui::IHMjoueur *ui;
    class CUjeuAllumettes* addJeuAllumettes;

public:
    IHMjoueur(QWidget *parent = nullptr);
    ~IHMjoueur();
    void RecupAddJeu(class CUjeuAllumettes* UneAddCujeuAllumettes);
    void initIHM();
    QString saisirNom(int numerojoueur);
    void afficherJeuAllumettes(int NbreAllumettes) ;
    void afficherMessage(QString);
    void boutonOKonOff(bool okonoff);
    void boutonJOUERonOff(bool joueronoff);
    void nomsOnOff(bool nomsonoff);
    void NbAEnleverOnOff(bool nbaenleveronOff);


};
#endif // IHMJOUEUR_H
