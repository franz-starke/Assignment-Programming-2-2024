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
#include "ui_borrow.h"
#include "borrow.h"

#include "dvd.h"
#include "blueray.h"

Borrow::Borrow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Borrow)
{
    ui->setupUi(this);
    ui->tableWidgetPersons->verticalHeader()->setVisible(false);
    ui->tableWidgetPersons->setColumnWidth(0,45);
    ui->tableWidgetPersons->setColumnWidth(1,155);
    ui->tableWidgetPersons->setColumnWidth(2,155);

    ui->tableWidgetMedias->verticalHeader()->setVisible(false);
    ui->tableWidgetMedias->setColumnWidth(0,64);
    ui->tableWidgetMedias->setColumnWidth(1,165);
    ui->tableWidgetMedias->setColumnWidth(2,165);
    ui->tableWidgetMedias->setColumnWidth(3,165);
}

void Borrow::getmain(MainWindow* mainwindow){
    main = mainwindow;
}


void Borrow::load_page(){
    personindex = -1;
    mediaindex = -1;

    ui->tableWidgetPersons->setSortingEnabled(false);
    ui->tableWidgetMedias->setSortingEnabled(false);
    ui->tableWidgetPersons->clear();
    ui->tableWidgetMedias->clear();
    ui->textBrowserOut->clear();

    QTableWidgetItem * iditem = new QTableWidgetItem();
    iditem->setData(Qt::DisplayRole, "ID");
    QTableWidgetItem * nameitem = new QTableWidgetItem();
    nameitem->setData(Qt::DisplayRole, "Name");
    QTableWidgetItem * ageitem = new QTableWidgetItem();
    ageitem->setData(Qt::DisplayRole, "Alter");

    ui->tableWidgetPersons->setHorizontalHeaderItem(0,iditem);
    ui->tableWidgetPersons->setHorizontalHeaderItem(1,nameitem);
    ui->tableWidgetPersons->setHorizontalHeaderItem(2,ageitem);

    QTableWidgetItem * id = new QTableWidgetItem();
    id->setData(Qt::DisplayRole, "ID");
    QTableWidgetItem * type = new QTableWidgetItem();
    type->setData(Qt::DisplayRole, "Typ");
    QTableWidgetItem * title = new QTableWidgetItem();
    title->setData(Qt::DisplayRole, "Titel");
    QTableWidgetItem * author = new QTableWidgetItem();
    author->setData(Qt::DisplayRole, "Autor");

    ui->tableWidgetMedias->setHorizontalHeaderItem(0,id);
    ui->tableWidgetMedias->setHorizontalHeaderItem(1,type);
    ui->tableWidgetMedias->setHorizontalHeaderItem(2,title);
    ui->tableWidgetMedias->setHorizontalHeaderItem(3,author);

    ui->tableWidgetPersons->setRowCount(main->person_list.length());
    for(int i=0; i<main->person_list.length();i++){
        QTableWidgetItem * iditem = new QTableWidgetItem();
        iditem->setData(Qt::DisplayRole, main->person_list[i].get_id());
        QTableWidgetItem * nameitem = new QTableWidgetItem();
        nameitem->setData(Qt::DisplayRole, main->person_list[i].get_name()+" "+main->person_list[i].get_lastname());
        QTableWidgetItem * ageitem = new QTableWidgetItem();
        ageitem->setData(Qt::DisplayRole, main->person_list[i].get_age());
        ui->tableWidgetPersons->setItem(i,0,iditem);
        ui->tableWidgetPersons->setItem(i,1,nameitem);
        ui->tableWidgetPersons->setItem(i,2,ageitem);
    }

    int tabrow = 0;
    ui->tableWidgetMedias->setRowCount(tabrow);
    for(int i=0; i<main->media_list.length();i++){
        if (main->media_list[i]->get_borrower() == 0){
            tabrow ++;
            ui->tableWidgetMedias->setRowCount(tabrow);
            QTableWidgetItem * iditem = new QTableWidgetItem();
            iditem->setData(Qt::DisplayRole, main->media_list[i]->get_id());
            QTableWidgetItem * typeitem = new QTableWidgetItem();
            typeitem->setData(Qt::DisplayRole, main->media_list[i]->get_type());
            QTableWidgetItem * titleitem = new QTableWidgetItem();
            titleitem->setData(Qt::DisplayRole, main->media_list[i]->get_title());
            QTableWidgetItem * authoritem = new QTableWidgetItem();
            authoritem->setData(Qt::DisplayRole, main->media_list[i]->get_author());

            ui->tableWidgetMedias->setItem(tabrow-1,0,iditem);
            ui->tableWidgetMedias->setItem(tabrow-1,1,typeitem);
            ui->tableWidgetMedias->setItem(tabrow-1,2,titleitem);
            ui->tableWidgetMedias->setItem(tabrow-1,3,authoritem);
        }

    }
    ui->tableWidgetPersons->setSortingEnabled(true);
    ui->tableWidgetMedias->setSortingEnabled(true);
}


Borrow::~Borrow()
{
    delete ui;
}

void Borrow::set_text(){
    if (personindex == -1){
        ui->textBrowserOut->setText(main->media_list[mediaindex]->get_type()+" "+
                                    main->media_list[mediaindex]->get_title()+", von "+
                                    main->media_list[mediaindex]->get_author()+" soll ausgeliegehen werden");
    } else if (mediaindex == -1){
        ui->textBrowserOut->setText(main->person_list[personindex].get_name()+" "+main->person_list[personindex].get_lastname()+
                                    " möchte ein Medium ausleihen.");
    } else {
        ui->textBrowserOut->setText(main->person_list[personindex].get_name()+" "+main->person_list[personindex].get_lastname()+" möchte "+
                                    main->media_list[mediaindex]->get_title()+", von "+
                                    main->media_list[mediaindex]->get_author()+" ausleihen");
    }
}

void Borrow::on_tableWidgetPersons_cellActivated(int row, int column)
{
    for(int i=0; i<main->person_list.length(); i++){
        if (main->person_list[i].get_id() == ui->tableWidgetPersons->item(row,0)->text().toInt()){
            personindex = i;
            break;
        }
    }

    set_text();
}


void Borrow::on_tableWidgetPersons_cellClicked(int row, int column)
{
    for(int i=0; i<main->person_list.length(); i++){
        if (main->person_list[i].get_id() == ui->tableWidgetPersons->item(row,0)->text().toInt()){
            personindex = i;
            break;
        }
    }

    set_text();
}


void Borrow::on_tableWidgetMedias_cellActivated(int row, int column)
{
    for(int i=0; i<main->media_list.length(); i++){
        if (main->media_list[i]->get_id() == ui->tableWidgetMedias->item(row,0)->text().toInt()){
            mediaindex = i;
            break;
        }
    }

    set_text();
}


void Borrow::on_tableWidgetMedias_cellClicked(int row, int column)
{
    for(int i=0; i<main->media_list.length(); i++){
        if (main->media_list[i]->get_id() == ui->tableWidgetMedias->item(row,0)->text().toInt()){
            mediaindex = i;
            break;
        }
    }

    set_text();
}


void Borrow::on_pushButtonBorrow_clicked()
{
    if (personindex != -1 && mediaindex != -1){
        bool ageverification = true;
        if (main->media_list[mediaindex]->get_type() == "DVD"){
            if (((DVD*) main->media_list[mediaindex])->get_agerestriction() > main->person_list[personindex].get_age()){
                ageverification = false;
                ui->textBrowserOut->setText("Medium kann aufgrund einer Altersbeschränkung nicht ausgeliehen werden.");
            }
        }
        if (main->media_list[mediaindex]->get_type() == "Blueray"){
            if (((BlueRay*) main->media_list[mediaindex])->get_agerestriction() > main->person_list[personindex].get_age()){
                ageverification = false;
                ui->textBrowserOut->setText("Medium kann aufgrund einer Altersbeschränkung nicht ausgeliehen werden.");
            }
        }
        if (ageverification){
            main->media_list[mediaindex]->set_borrower(main->person_list[personindex].get_id());
            main->save_savefile();
            main->load_dashboard();
            close();
        }
    }
}

