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


void MainWindow::on_pushButton_clicked()
{
    {
        bool q,q1;

        QString x1 = ui->chfms->text();

        QString x2 = ui->chfkmh->text();

        float ms = x1.toFloat(&q);

        float kmh = x2.toFloat(&q1);

        if (x1=="" & x2=="" |(x1 !="" & x2!="") )
        {
           ui->erreur->setText("Erreur");
        }
        else
        {
            if (x1=="")

            {

            ms = kmh/3.6;

            x1 = QString::number(ms);

            ui->chfms->setText(x1);

            }
            if (x2=="")

            {

            kmh = ms*3.6;

            x2 = QString::number(kmh);

            ui->chfkmh->setText(x2);
            }
        }
    }
}
