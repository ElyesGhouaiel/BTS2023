/********************************************************************************
** Form generated from reading UI file 'ihm_bataille_navale_2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IHM_BATAILLE_NAVALE_2_H
#define UI_IHM_BATAILLE_NAVALE_2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IHM_Bataille_Navale_2
{
public:
    QWidget *centralwidget;
    QLabel *TitreBatailleNavale;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *IHM_Bataille_Navale_2)
    {
        if (IHM_Bataille_Navale_2->objectName().isEmpty())
            IHM_Bataille_Navale_2->setObjectName(QString::fromUtf8("IHM_Bataille_Navale_2"));
        IHM_Bataille_Navale_2->resize(800, 600);
        centralwidget = new QWidget(IHM_Bataille_Navale_2);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        TitreBatailleNavale = new QLabel(centralwidget);
        TitreBatailleNavale->setObjectName(QString::fromUtf8("TitreBatailleNavale"));
        TitreBatailleNavale->setGeometry(QRect(80, 20, 851, 41));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        TitreBatailleNavale->setFont(font);
        TitreBatailleNavale->setFrameShape(QFrame::Box);
        TitreBatailleNavale->setAlignment(Qt::AlignCenter);
        IHM_Bataille_Navale_2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(IHM_Bataille_Navale_2);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        IHM_Bataille_Navale_2->setMenuBar(menubar);
        statusbar = new QStatusBar(IHM_Bataille_Navale_2);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        IHM_Bataille_Navale_2->setStatusBar(statusbar);

        retranslateUi(IHM_Bataille_Navale_2);

        QMetaObject::connectSlotsByName(IHM_Bataille_Navale_2);
    } // setupUi

    void retranslateUi(QMainWindow *IHM_Bataille_Navale_2)
    {
        IHM_Bataille_Navale_2->setWindowTitle(QApplication::translate("IHM_Bataille_Navale_2", "IHM_Bataille_Navale_2", nullptr));
        TitreBatailleNavale->setText(QApplication::translate("IHM_Bataille_Navale_2", "La Bataille Navale \303\240 imprimer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IHM_Bataille_Navale_2: public Ui_IHM_Bataille_Navale_2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IHM_BATAILLE_NAVALE_2_H
