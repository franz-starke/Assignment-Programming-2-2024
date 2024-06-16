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

#include "mainwindow.h"
#include "managepersons.h"
#include "ui_managepersons.h"

Managepersons::Managepersons(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Managepersons)
{
    ui->setupUi(this);
    ui->tableWidgetPerson->verticalHeader()->setVisible(false);
    ui->tableWidgetPerson->setColumnWidth(0,50);
    ui->tableWidgetPerson->setColumnWidth(1,200);
    ui->tableWidgetPerson->setColumnWidth(2,50);
}

Managepersons::~Managepersons()
{
    delete ui;
}

void Managepersons::getmain(MainWindow* mainwindow){
    main = mainwindow;
}

void Managepersons::load_page(){
    ui->tableWidgetPerson->setSortingEnabled(false);
    ui->tableWidgetPerson->clear();

    QTableWidgetItem * iditem = new QTableWidgetItem();
    iditem->setData(Qt::DisplayRole, "ID");
    QTableWidgetItem * nameitem = new QTableWidgetItem();
    nameitem->setData(Qt::DisplayRole, "Name");
    QTableWidgetItem * ageitem = new QTableWidgetItem();
    ageitem->setData(Qt::DisplayRole, "Alter");

    ui->tableWidgetPerson->setHorizontalHeaderItem(0,iditem);
    ui->tableWidgetPerson->setHorizontalHeaderItem(1,nameitem);
    ui->tableWidgetPerson->setHorizontalHeaderItem(2,ageitem);

    ui->tableWidgetPerson->setRowCount(main->person_list.length());
    for(int i=0; i<main->person_list.length();i++){
        QTableWidgetItem * iditem = new QTableWidgetItem();
        iditem->setData(Qt::DisplayRole, main->person_list[i].get_id());
        QTableWidgetItem * nameitem = new QTableWidgetItem();
        nameitem->setData(Qt::DisplayRole, main->person_list[i].get_name()+" "+main->person_list[i].get_lastname());
        QTableWidgetItem * ageitem = new QTableWidgetItem();
        ageitem->setData(Qt::DisplayRole, main->person_list[i].get_age());
        ui->tableWidgetPerson->setItem(i,0,iditem);
        ui->tableWidgetPerson->setItem(i,1,nameitem);
        ui->tableWidgetPerson->setItem(i,2,ageitem);
    }

    ui->spinBoxAlter->setValue(0);
    ui->lineEditNachname->setText("");
    ui->lineEditVorname->setText("");
    ui->labelNoName->hide();
    ui->labelPersonExists->hide();
    selected_index = -1;
    ui->tableWidgetPerson->setSortingEnabled(true);
}

void Managepersons::on_tableWidgetPerson_cellPressed(int row, int column)
{
    for(int i=0; i<main->person_list.length(); i++){
        if (main->person_list[i].get_id() == ui->tableWidgetPerson->item(row,0)->text().toInt()){
            select_person(i);
            break;
        }
    }
}

void Managepersons::on_tableWidgetPerson_cellActivated(int row, int column)
{
    for(int i=0; i<main->person_list.length(); i++){
        if (main->person_list[i].get_id() == ui->tableWidgetPerson->item(row,0)->text().toInt()){
            select_person(i);
            break;
        }
    }
}

void Managepersons::select_person(int index){
    selected_index = index;
    ui->lineEditVorname->setText(main->person_list[index].get_name());
    ui->lineEditNachname->setText(main->person_list[index].get_lastname());
    ui->spinBoxAlter->setValue(main->person_list[index].get_age());
}

void Managepersons::on_pushButtonSave_clicked()
{
    if (selected_index != -1){
        if (ui->lineEditVorname->text() != QString("") && ui->lineEditNachname->text() != QString("")) {
            if (!main->edit_person(main->person_list[selected_index].get_id(),
                                          ui->lineEditVorname->text(),
                                          ui->lineEditNachname->text(),
                                          ui->spinBoxAlter->value())){
                ui->labelPersonExists->show();
            }
        } else {
            ui->labelNoName->show();
        }
    }
    load_page();
}


void Managepersons::on_pushButtonDelete_clicked()
{
    if(selected_index != -1){
        main->delete_person(selected_index);
    }
    load_page();
}

