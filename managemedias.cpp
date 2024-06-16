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

#include "managemedias.h"
#include "ui_managemedias.h"

#include "mainwindow.h"
#include "QString"
#include "book.h"
#include "cd.h"
#include "dvd.h"
#include "blueray.h"

Managemedias::Managemedias(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Managemedias)
{
    ui->setupUi(this);
    ui->tableWidgetMedia->verticalHeader()->setVisible(false);
    ui->tableWidgetMedia->setColumnWidth(0,50);
    ui->tableWidgetMedia->setColumnWidth(1,75);
    ui->tableWidgetMedia->setColumnWidth(2,175);
    ui->tableWidgetMedia->setColumnWidth(3,175);
}

void Managemedias::getmain(MainWindow* mainwindow){
    main = mainwindow;
}

void Managemedias::load_page(){
    ui->lineEditTitle->setText("");
    ui->lineEditAutor->setText("");
    ui->tableWidgetMedia->setSortingEnabled(false);
    ui->tableWidgetMedia->clear();

    QTableWidgetItem * iditem = new QTableWidgetItem();
    iditem->setData(Qt::DisplayRole, "ID");
    QTableWidgetItem * typeitem = new QTableWidgetItem();
    typeitem->setData(Qt::DisplayRole, "Type");
    QTableWidgetItem * titleitem = new QTableWidgetItem();
    titleitem->setData(Qt::DisplayRole, "Title");
    QTableWidgetItem * authoritem = new QTableWidgetItem();
    authoritem->setData(Qt::DisplayRole, "Autor");

    ui->tableWidgetMedia->setHorizontalHeaderItem(0,iditem);
    ui->tableWidgetMedia->setHorizontalHeaderItem(1,typeitem);
    ui->tableWidgetMedia->setHorizontalHeaderItem(2,titleitem);
    ui->tableWidgetMedia->setHorizontalHeaderItem(3,authoritem);

    ui->tableWidgetMedia->setRowCount(main->media_list.length());
    for(int i=0; i<main->media_list.length();i++){
        QTableWidgetItem * iditem = new QTableWidgetItem();
        iditem->setData(Qt::DisplayRole, main->media_list[i]->get_id());
        QTableWidgetItem * typeitem = new QTableWidgetItem();
        typeitem->setData(Qt::DisplayRole, main->media_list[i]->get_type());
        QTableWidgetItem * titleitem = new QTableWidgetItem();
        titleitem->setData(Qt::DisplayRole, main->media_list[i]->get_title());
        QTableWidgetItem * authoritem = new QTableWidgetItem();
        authoritem->setData(Qt::DisplayRole, main->media_list[i]->get_author());

        ui->tableWidgetMedia->setItem(i,0,iditem);
        ui->tableWidgetMedia->setItem(i,1,typeitem);
        ui->tableWidgetMedia->setItem(i,2,titleitem);
        ui->tableWidgetMedia->setItem(i,3,authoritem);
    }

    ui->spinBoxSeitenzahl->setValue(0);
    ui->spinBoxAlter->setValue(0);
    ui->doubleSpinBoxDauer->setValue(0.0);

    ui->labelAll->hide();
    ui->labelSeitenanzahl->hide();
    ui->spinBoxSeitenzahl->hide();
    ui->labelDauer->hide();
    ui->labelAlter->hide();
    ui->doubleSpinBoxDauer->hide();
    ui->spinBoxAlter->hide();

    selected_index = -1;
    ui->tableWidgetMedia->setSortingEnabled(true);
}

void Managemedias::select_media(int index){
    selected_index = index;
    ui->spinBoxSeitenzahl->setValue(0);
    ui->spinBoxAlter->setValue(0);
    ui->doubleSpinBoxDauer->setValue(0.0);

    ui->labelSeitenanzahl->hide();
    ui->spinBoxSeitenzahl->hide();
    ui->labelDauer->hide();
    ui->labelAlter->hide();
    ui->doubleSpinBoxDauer->hide();
    ui->spinBoxAlter->hide();

    ui->lineEditTitle->setText(main->media_list[index]->get_title());
    ui->lineEditAutor->setText(main->media_list[index]->get_author());

    if (main->media_list[index]->get_type() == "Buch") {
        ui->labelSeitenanzahl->show();
        ui->spinBoxSeitenzahl->show();
        ui->spinBoxSeitenzahl->setValue(((Book*) main->media_list[index])->get_pages());
    } else if (main->media_list[index]->get_type() == "CD") {
        ui->labelDauer->show();
        ui->doubleSpinBoxDauer->show();
        ui->doubleSpinBoxDauer->setValue(((CD*) main->media_list[index])->get_duration());
    } else if (main->media_list[index]->get_type() == "DVD") {
        ui->labelDauer->show();
        ui->labelAlter->show();
        ui->doubleSpinBoxDauer->show();
        ui->spinBoxAlter->show();
        ui->spinBoxAlter->setValue(((DVD*) main->media_list[index])->get_agerestriction());
        ui->doubleSpinBoxDauer->setValue(((DVD*) main->media_list[index])->get_duration());
    } else if (main->media_list[index]->get_type() == "Blueray") {
        ui->labelDauer->show();
        ui->labelAlter->show();
        ui->doubleSpinBoxDauer->show();
        ui->spinBoxAlter->show();
        ui->spinBoxAlter->setValue(((BlueRay*) main->media_list[index])->get_agerestriction());
        ui->doubleSpinBoxDauer->setValue(((BlueRay*) main->media_list[index])->get_duration());
    }
}

Managemedias::~Managemedias()
{
    delete ui;
}

void Managemedias::on_tableWidgetMedia_cellPressed(int row, int column)
{
    for(int i=0; i<main->media_list.length(); i++){
        if (main->media_list[i]->get_id() == ui->tableWidgetMedia->item(row,0)->text().toInt()){
            select_media(i);
            break;
        }
    }
}

void Managemedias::on_tableWidgetMedia_cellActivated(int row, int column)
{
    for(int i=0; i<main->media_list.length(); i++){
        if (main->media_list[i]->get_id() == ui->tableWidgetMedia->item(row,0)->text().toInt()){
            select_media(i);
            break;
        }
    }
}

void Managemedias::on_pushButtonSave_clicked()
{
    if (selected_index != -1){
        if (ui->lineEditTitle->text() != QString("") && ui->lineEditAutor->text() != QString("")){
            if (main->media_list[selected_index]->get_type() == "Buch") {
                main->edit_book(selected_index,ui->lineEditTitle->text(),ui->lineEditAutor->text(),ui->spinBoxSeitenzahl->value());
            } else if (main->media_list[selected_index]->get_type() == "CD") {
                main->edit_cd(selected_index,ui->lineEditTitle->text(),ui->lineEditAutor->text(),ui->doubleSpinBoxDauer->value());
            } else if (main->media_list[selected_index]->get_type() == "DVD") {
                main->edit_dvd(selected_index,ui->lineEditTitle->text(),ui->lineEditAutor->text(),ui->doubleSpinBoxDauer->value(),ui->spinBoxAlter->value());
            } else if (main->media_list[selected_index]->get_type() == "Blueray") {
                main->edit_blueray(selected_index,ui->lineEditTitle->text(),ui->lineEditAutor->text(),ui->doubleSpinBoxDauer->value(),ui->spinBoxAlter->value());
            }
        } else {
            ui->labelAll->show();
        }
        load_page();
    }
}

void Managemedias::on_pushButtonDelete_clicked()
{
    if(selected_index != -1){
        main->delete_media(selected_index);
        load_page();
    }
}

