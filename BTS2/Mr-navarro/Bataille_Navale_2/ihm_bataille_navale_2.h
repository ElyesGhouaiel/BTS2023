#ifndef IHM_BATAILLE_NAVALE_2_H
#define IHM_BATAILLE_NAVALE_2_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class IHM_Bataille_Navale_2; }
QT_END_NAMESPACE

class IHM_Bataille_Navale_2 : public QMainWindow
{
    Q_OBJECT

public:
    IHM_Bataille_Navale_2(QWidget *parent = nullptr);
    ~IHM_Bataille_Navale_2();
    void constructiondutableau_joueur1();
    void constructiondutableau_joueur2();
    void boutonsAllieOnOff();
  //void boutonsAdverseOnOff();
    int VerificationDesBoutons[10][10];
    void Start();



private slots:
    void boutonclic0();
    void boutonclic1();

private:
    Ui::IHM_Bataille_Navale_2 *ui;
    QPushButton* bouton_joueur1[10][10];
    QPushButton* bouton_joueur2[10][10];
    QPushButton* RecupPointeurs[10][10];
};
#endif // IHM_BATAILLE_NAVALE_2_H
