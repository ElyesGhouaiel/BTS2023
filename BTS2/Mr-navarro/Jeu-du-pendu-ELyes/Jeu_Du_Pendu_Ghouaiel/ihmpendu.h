#ifndef IHMPENDU_H
#define IHMPENDU_H
#include <QPushButton>
#include <iostream>
#include <QLineEdit>
#include <QMainWindow>
#include <QString>
#include <QSignalMapper>
QT_BEGIN_NAMESPACE
namespace Ui { class IHMPendu; }
QT_END_NAMESPACE

class IHMPendu : public QMainWindow
{
    Q_OBJECT
private:
    Ui::IHMPendu *ui;
    class CUjeuDUPendu* addJeuDuPendu;
    QPushButton *Bouton[26];
    QWidget* addFenetreConfig;
    QLineEdit* addLineEdit;
    int nbrcorrespondantpourlependu;

private slots:
    void on_Bonton_Jouer_clicked();
    void on_Bonton_Config_clicked();
    void boutonclic0();
    void boutonclic1();
    void boutonclic2();


public:
    QString NomDuFichierSelectionner;
    IHMPendu(QWidget *parent = nullptr);
    ~IHMPendu();
    void initIHMWIDGETS();
    void inintIHMreset();
    void RecupAddJeu(class CUjeuDUPendu* );
    void RecupAddFenetreConfig(QWidget*);
    void RecupAddLineEdit(QLineEdit*);
    void LabelMotATrouverVisible(bool);
    void boutonJOUEROnOff(bool);
    void boutonCONFIGOnOff(bool);
    void NomsOnOff(bool);
    void Afficher(QString);
    void AfficherPendu(int);
    void AfficherNomFichierMots(QString);
    void AfficherNombreDeMots(int);
    QString saisirNom();
    void slotBouton();
};
#endif // IHMPENDU_H
