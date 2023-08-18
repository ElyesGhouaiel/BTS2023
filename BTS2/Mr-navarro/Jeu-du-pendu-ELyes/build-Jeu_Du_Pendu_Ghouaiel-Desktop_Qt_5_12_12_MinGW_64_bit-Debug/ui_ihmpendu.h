/********************************************************************************
** Form generated from reading UI file 'ihmpendu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IHMPENDU_H
#define UI_IHMPENDU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IHMPendu
{
public:
    QWidget *centralwidget;
    QLabel *PenduBattons;
    QLabel *NBrErreurs;
    QLabel *JeuduPenduTitre;
    QLabel *NomDuJoueur;
    QLineEdit *LineEditNomDuJoueur;
    QPushButton *Bonton_Jouer;
    QPushButton *Bonton_Config;
    QLabel *MotaTrouver;
    QLabel *LabelMotaTrouver;
    QLabel *NomduFichier;
    QLabel *MotDisponibles;
    QWidget *gridLayoutWidget;
    QGridLayout *alphabet;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *IHMPendu)
    {
        if (IHMPendu->objectName().isEmpty())
            IHMPendu->setObjectName(QString::fromUtf8("IHMPendu"));
        IHMPendu->resize(1170, 654);
        IHMPendu->setWindowOpacity(1.000000000000000);
        centralwidget = new QWidget(IHMPendu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        PenduBattons = new QLabel(centralwidget);
        PenduBattons->setObjectName(QString::fromUtf8("PenduBattons"));
        PenduBattons->setGeometry(QRect(50, 20, 301, 321));
        NBrErreurs = new QLabel(centralwidget);
        NBrErreurs->setObjectName(QString::fromUtf8("NBrErreurs"));
        NBrErreurs->setGeometry(QRect(140, 360, 141, 31));
        JeuduPenduTitre = new QLabel(centralwidget);
        JeuduPenduTitre->setObjectName(QString::fromUtf8("JeuduPenduTitre"));
        JeuduPenduTitre->setGeometry(QRect(430, 20, 241, 51));
        QFont font;
        font.setPointSize(25);
        font.setBold(true);
        font.setWeight(75);
        JeuduPenduTitre->setFont(font);
        JeuduPenduTitre->setTextFormat(Qt::AutoText);
        JeuduPenduTitre->setScaledContents(false);
        NomDuJoueur = new QLabel(centralwidget);
        NomDuJoueur->setObjectName(QString::fromUtf8("NomDuJoueur"));
        NomDuJoueur->setGeometry(QRect(380, 80, 111, 17));
        LineEditNomDuJoueur = new QLineEdit(centralwidget);
        LineEditNomDuJoueur->setObjectName(QString::fromUtf8("LineEditNomDuJoueur"));
        LineEditNomDuJoueur->setGeometry(QRect(380, 110, 113, 25));
        Bonton_Jouer = new QPushButton(centralwidget);
        Bonton_Jouer->setObjectName(QString::fromUtf8("Bonton_Jouer"));
        Bonton_Jouer->setGeometry(QRect(640, 110, 111, 31));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        Bonton_Jouer->setFont(font1);
        Bonton_Config = new QPushButton(centralwidget);
        Bonton_Config->setObjectName(QString::fromUtf8("Bonton_Config"));
        Bonton_Config->setGeometry(QRect(638, 160, 111, 25));
        MotaTrouver = new QLabel(centralwidget);
        MotaTrouver->setObjectName(QString::fromUtf8("MotaTrouver"));
        MotaTrouver->setGeometry(QRect(380, 220, 111, 17));
        LabelMotaTrouver = new QLabel(centralwidget);
        LabelMotaTrouver->setObjectName(QString::fromUtf8("LabelMotaTrouver"));
        LabelMotaTrouver->setGeometry(QRect(380, 270, 521, 111));
        LabelMotaTrouver->setFrameShape(QFrame::Box);
        LabelMotaTrouver->setLineWidth(2);
        NomduFichier = new QLabel(centralwidget);
        NomduFichier->setObjectName(QString::fromUtf8("NomduFichier"));
        NomduFichier->setGeometry(QRect(30, 570, 311, 17));
        MotDisponibles = new QLabel(centralwidget);
        MotDisponibles->setObjectName(QString::fromUtf8("MotDisponibles"));
        MotDisponibles->setGeometry(QRect(850, 570, 231, 17));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(60, 400, 971, 131));
        alphabet = new QGridLayout(gridLayoutWidget);
        alphabet->setObjectName(QString::fromUtf8("alphabet"));
        alphabet->setContentsMargins(0, 1, 0, 0);
        IHMPendu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(IHMPendu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1170, 20));
        IHMPendu->setMenuBar(menubar);
        statusbar = new QStatusBar(IHMPendu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        IHMPendu->setStatusBar(statusbar);

        retranslateUi(IHMPendu);

        QMetaObject::connectSlotsByName(IHMPendu);
    } // setupUi

    void retranslateUi(QMainWindow *IHMPendu)
    {
        IHMPendu->setWindowTitle(QApplication::translate("IHMPendu", "IHMPendu", nullptr));
        PenduBattons->setText(QString());
        NBrErreurs->setText(QString());
        JeuduPenduTitre->setText(QApplication::translate("IHMPendu", "Jeu Du Pendu", nullptr));
        NomDuJoueur->setText(QApplication::translate("IHMPendu", "Nom du joueur :", nullptr));
        Bonton_Jouer->setText(QApplication::translate("IHMPendu", "JOUER", nullptr));
        Bonton_Config->setText(QApplication::translate("IHMPendu", "Config", nullptr));
        MotaTrouver->setText(QApplication::translate("IHMPendu", "Mot \303\240 Trouver :", nullptr));
        LabelMotaTrouver->setText(QString());
        NomduFichier->setText(QApplication::translate("IHMPendu", "Nom du fichier :", nullptr));
        MotDisponibles->setText(QApplication::translate("IHMPendu", "Mots Dipsonibles :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IHMPendu: public Ui_IHMPendu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IHMPENDU_H
