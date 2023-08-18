#include "ihmpendu.h"
#include "CUjeuDuPendu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CUjeuDUPendu jeu;
    IHMPendu ihm;
    ihm.RecupAddJeu(&jeu);
    jeu.RecupAddIHM(&ihm);
    ihm.show();
    return a.exec();
}
