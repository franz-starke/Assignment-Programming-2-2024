//#######################################################//
//                                                       //
//   ____  ____   _________   ____      ____  ______     //
//  |_   ||   _| |  _   _  | |_  _|    |_  _||_   _ `.   //
//    | |__| |   |_/ | | \_|   \ \  /\  / /    | | `. \  //
//    |  __  |       | |        \ \/  \/ /     | |  | |  //
//   _| |  | |_     _| |_        \  /\  /     _| |_.' /  //
//  |____||____|   |_____|        \/  \/     |______.'   //
//                                                       //
//#######################################################//
//                                                       //
//                 Medienverwaltung 2024                 //
//                 Beleg von Franz Starke                //
//                 S86320 16.06.2024                     //
//                 Studiengrupe 23/041/01                //
//                                                       //
//#######################################################//

#include "createmedia.h"
#include "ui_createmedia.h"

#include "mainwindow.h"

Createmedia::Createmedia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Createmedia)
{
    ui->setupUi(this);
}

Createmedia::~Createmedia()
{
    delete ui;
}

void Createmedia::getmain(MainWindow* mainwindow){
    main = mainwindow;
}

void Createmedia::load_page(){

    ui->spinBoxSeitenzahl->setMaximum(2147483647);

    ui->comboBoxMediaType->setCurrentIndex(0);
    ui->spinBoxSeitenzahl->setValue(0);
    ui->spinBoxAlter->setValue(0);
    ui->doubleSpinBoxDauer->setValue(0.0);

    ui->lineEditAutor->setText("");
    ui->lineEditTitle->setText("");

    ui->labelDauer->hide();
    ui->labelAlter->hide();
    ui->doubleSpinBoxDauer->hide();
    ui->spinBoxAlter->hide();
    ui->labelAll->hide();
}

void Createmedia::on_pushButton_clicked()
{

    if (ui->lineEditTitle->text() != QString("") && ui->lineEditAutor->text() != QString("")){
        switch(ui->comboBoxMediaType->currentIndex()){
            case 0:
                main->create_book(ui->lineEditTitle->text(),ui->lineEditAutor->text(),ui->spinBoxSeitenzahl->value());
                break;
            case 1:
                main->create_cd(ui->lineEditTitle->text(),ui->lineEditAutor->text(),ui->doubleSpinBoxDauer->value());
                break;
            case 2:
                main->create_dvd(ui->lineEditTitle->text(),ui->lineEditAutor->text(),ui->doubleSpinBoxDauer->value(),ui->spinBoxAlter->value());
                break;
            case 3:
                main->create_blueray(ui->lineEditTitle->text(),ui->lineEditAutor->text(),ui->doubleSpinBoxDauer->value(),ui->spinBoxAlter->value());
                break;
            default:
                break;
        }
        close();
    } else {
        ui->labelAll->show();
    }
}


void Createmedia::on_comboBoxMediaType_currentIndexChanged(int index)
{
    ui->spinBoxSeitenzahl->setValue(0);
    ui->spinBoxAlter->setValue(0);
    ui->doubleSpinBoxDauer->setValue(0.0);

    ui->labelSeitenanzahl->hide();
    ui->spinBoxSeitenzahl->hide();
    ui->labelDauer->hide();
    ui->labelAlter->hide();
    ui->doubleSpinBoxDauer->hide();
    ui->spinBoxAlter->hide();

    switch (index){
        case 0:
            ui->labelSeitenanzahl->show();
            ui->spinBoxSeitenzahl->show();
            break;
        case 1:
            ui->labelDauer->show();
            ui->doubleSpinBoxDauer->show();
            break;
        case 2:
            ui->labelDauer->show();
            ui->labelAlter->show();
            ui->doubleSpinBoxDauer->show();
            ui->spinBoxAlter->show();
            break;
        case 3:
            ui->labelDauer->show();
            ui->labelAlter->show();
            ui->doubleSpinBoxDauer->show();
            ui->spinBoxAlter->show();
            break;
        default:
            break;
    }
}

