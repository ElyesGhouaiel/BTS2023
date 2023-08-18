/********************************************************************************
** Form generated from reading UI file 'ihmjoueur.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IHMJOUEUR_H
#define UI_IHMJOUEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IHMjoueur
{
public:
    QWidget *centralwidget;
    QLabel *TITRE;
    QLabel *Joueur1NomLabel;
    QLabel *Joueur2NomLabel;
    QLineEdit *Joueur1Nom;
    QLineEdit *Joueur2Nom;
    QLabel *zoneMessage;
    QLabel *Allumettes;
    QPushButton *OK;
    QLineEdit *NbAEnlever;
    QPushButton *Jouer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *IHMjoueur)
    {
        if (IHMjoueur->objectName().isEmpty())
            IHMjoueur->setObjectName(QString::fromUtf8("IHMjoueur"));
        IHMjoueur->resize(800, 600);
        centralwidget = new QWidget(IHMjoueur);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        TITRE = new QLabel(centralwidget);
        TITRE->setObjectName(QString::fromUtf8("TITRE"));
        TITRE->setGeometry(QRect(270, 70, 181, 17));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        TITRE->setFont(font);
        Joueur1NomLabel = new QLabel(centralwidget);
        Joueur1NomLabel->setObjectName(QString::fromUtf8("Joueur1NomLabel"));
        Joueur1NomLabel->setGeometry(QRect(180, 120, 111, 17));
        Joueur2NomLabel = new QLabel(centralwidget);
        Joueur2NomLabel->setObjectName(QString::fromUtf8("Joueur2NomLabel"));
        Joueur2NomLabel->setGeometry(QRect(390, 120, 111, 17));
        Joueur1Nom = new QLineEdit(centralwidget);
        Joueur1Nom->setObjectName(QString::fromUtf8("Joueur1Nom"));
        Joueur1Nom->setGeometry(QRect(170, 160, 113, 25));
        Joueur2Nom = new QLineEdit(centralwidget);
        Joueur2Nom->setObjectName(QString::fromUtf8("Joueur2Nom"));
        Joueur2Nom->setGeometry(QRect(380, 160, 113, 25));
        zoneMessage = new QLabel(centralwidget);
        zoneMessage->setObjectName(QString::fromUtf8("zoneMessage"));
        zoneMessage->setGeometry(QRect(110, 350, 251, 71));
        Allumettes = new QLabel(centralwidget);
        Allumettes->setObjectName(QString::fromUtf8("Allumettes"));
        Allumettes->setGeometry(QRect(140, 240, 431, 91));
        Allumettes->setFrameShape(QFrame::Box);
        Allumettes->setScaledContents(false);
        Allumettes->setOpenExternalLinks(false);
        Allumettes->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
        OK = new QPushButton(centralwidget);
        OK->setObjectName(QString::fromUtf8("OK"));
        OK->setGeometry(QRect(510, 350, 101, 41));
        QFont font1;
        font1.setPointSize(17);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(true);
        font1.setWeight(75);
        OK->setFont(font1);
        OK->setAutoDefault(false);
        NbAEnlever = new QLineEdit(centralwidget);
        NbAEnlever->setObjectName(QString::fromUtf8("NbAEnlever"));
        NbAEnlever->setGeometry(QRect(410, 370, 61, 25));
        Jouer = new QPushButton(centralwidget);
        Jouer->setObjectName(QString::fromUtf8("Jouer"));
        Jouer->setGeometry(QRect(580, 160, 89, 25));
        QFont font2;
        font2.setBold(true);
        font2.setUnderline(true);
        font2.setWeight(75);
        Jouer->setFont(font2);
        IHMjoueur->setCentralWidget(centralwidget);
        menubar = new QMenuBar(IHMjoueur);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        IHMjoueur->setMenuBar(menubar);
        statusbar = new QStatusBar(IHMjoueur);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        IHMjoueur->setStatusBar(statusbar);

        retranslateUi(IHMjoueur);

        QMetaObject::connectSlotsByName(IHMjoueur);
    } // setupUi

    void retranslateUi(QMainWindow *IHMjoueur)
    {
        IHMjoueur->setWindowTitle(QApplication::translate("IHMjoueur", "IHMjoueur", nullptr));
        TITRE->setText(QApplication::translate("IHMjoueur", "Jeu des Allumettes", nullptr));
        Joueur1NomLabel->setText(QApplication::translate("IHMjoueur", "Nom Joueur 1 :", nullptr));
        Joueur2NomLabel->setText(QApplication::translate("IHMjoueur", "Nom Joueur 2 :", nullptr));
        zoneMessage->setText(QString());
        Allumettes->setText(QString());
        OK->setText(QApplication::translate("IHMjoueur", "OK", nullptr));
        Jouer->setText(QApplication::translate("IHMjoueur", "JOUER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IHMjoueur: public Ui_IHMjoueur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IHMJOUEUR_H
