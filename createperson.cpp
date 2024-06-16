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

#include "createperson.h"
#include "ui_createperson.h"

#include "mainwindow.h"

Createperson::Createperson(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Createperson)
{
    ui->setupUi(this);
}

Createperson::~Createperson()
{
    delete ui;
}

void Createperson::getmain(MainWindow* mainwindow){
    main = mainwindow;
}

void Createperson::load_page(){
    ui->lineEditVorname->setText("");
    ui->lineEditNachname->setText("");
    ui->spinBox->setValue(0);
    ui->labelPersonExists->hide();
    ui->labelNoName->hide();
}

void Createperson::on_pushButton_clicked()
{
    ui->labelPersonExists->hide();
    ui->labelNoName->hide();
    if (ui->lineEditVorname->text() != QString("") && ui->lineEditNachname->text() != QString("")){
        if (!main->create_person(ui->lineEditVorname->text(),ui->lineEditNachname->text(),ui->spinBox->value())){
            ui->labelPersonExists->show();
        }else{
            close();
        }
    } else {
        ui->labelNoName->show();
    }
}
