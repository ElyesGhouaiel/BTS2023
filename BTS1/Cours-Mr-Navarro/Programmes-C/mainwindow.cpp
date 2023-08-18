#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Nouveau_clicked()
{
    int a,b;
    a = rand()%10+1;
    b = rand()%10+1;
    ui->ch1->setNum(a);
    ui->ch2->setNum(b);
}

void MainWindow::on_verification_clicked()
{
    int a = 0,b = 0,z;
    QString c="";
  c=ui->lineEdit->text();
  z=c.toInt();
    if (z==(a*b))
    {
        ui->lineEdit->setText("Reponse correcte");
    }
    if(z !=(a*b))
    {
         ui->lineEdit->setText("reponse fausse");
    }
}
