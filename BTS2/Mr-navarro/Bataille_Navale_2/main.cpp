#include "ihm_bataille_navale_2.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IHM_Bataille_Navale_2 w;
    w.show();
    return a.exec();
}
