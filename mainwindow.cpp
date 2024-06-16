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
#include "ui_mainwindow.h"

#include "person.h"
#include "iostream"
#include "fstream"

#include <QFile>
#include <QList>
#include <QTextStream>
#include <QStringList>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    newest_person_index = 0;
    newest_media_index = 0;
    ui->tableWidgetBorrow->verticalHeader()->setVisible(false);
    ui->tableWidgetBorrow->setColumnWidth(0,40);
    ui->tableWidgetBorrow->setColumnWidth(1,175);
    ui->tableWidgetBorrow->setColumnWidth(2,40);
    ui->tableWidgetBorrow->setColumnWidth(3,130);
    ui->tableWidgetBorrow->setColumnWidth(4,175);
    ui->tableWidgetBorrow->setColumnWidth(5,175);
    load_savefile();
    load_dashboard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::load_savefile(){
    QFile savefile("save.txt");
    int i = 0;
    QStringList persons;
    QStringList persondata;
    QStringList medias;
    QStringList mediadata;
    if (savefile.open(QIODevice::ReadOnly))
    {
       QTextStream stream(&savefile);
       while (!stream.atEnd())
       {
            QString line = stream.readLine();
            if (line != ("")){
                switch(i){
                    case 0:
                        newest_person_index = line.toInt();
                        break;
                    case 1:
                        newest_media_index = line.toInt();
                        break;
                    case 2:
                        persons = line.split(";");
                        for (int n=0;n<persons.length();n++){
                            if (persons[n] != ""){
                                persondata = persons[n].split("~");
                                person_list.append(Person(persondata[0].toInt(),persondata[1],persondata[2],persondata[3].toInt()));
                            }
                        }
                        break;
                    case 3:
                        medias = line.split(";");
                        for (int n=0;n<medias.length();n++){
                            if (medias[n] != ""){
                                mediadata = medias[n].split("~");
                                if (mediadata[1] == "Buch"){
                                    Media* book = new Book(mediadata[0].toInt(),mediadata[2],mediadata[3],mediadata[5].toInt(),mediadata[4].toInt());
                                    media_list.append(book);
                                } else if (mediadata[1] == "CD"){
                                    Media* cd = new CD(mediadata[0].toInt(),mediadata[2],mediadata[3],mediadata[5].toDouble(),mediadata[4].toInt());
                                    media_list.append(cd);
                                } else if (mediadata[1] == "DVD"){
                                    Media* dvd = new DVD(mediadata[0].toInt(),mediadata[2],mediadata[3],mediadata[5].toDouble(),mediadata[6].toInt(),mediadata[4].toInt());
                                    media_list.append(dvd);
                                } else if (mediadata[1] == "Blueray"){
                                    Media* blueray = new BlueRay(mediadata[0].toInt(),mediadata[2],mediadata[3],mediadata[5].toDouble(),mediadata[6].toInt(),mediadata[4].toInt());
                                    media_list.append(blueray);
                                }
                            }
                        }
                        break;
                }
                i++;
            }

       }
       savefile.close();
    }
}

void MainWindow::save_savefile(){
    std::ofstream savefile;
    savefile.open("save.txt");
    savefile << QString::number(newest_person_index).toStdString()<<"\n";
    savefile << QString::number(newest_media_index).toStdString()<<"\n";
    for(int i=0;i<person_list.length();i++){
        savefile << QString::number(person_list[i].get_id()).toStdString() << "~";
        savefile << person_list[i].get_name().toStdString() << "~";
        savefile << person_list[i].get_lastname().toStdString() << "~";
        savefile << QString::number(person_list[i].get_age()).toStdString() << ";";
    }
    savefile << "\n";
    for(int i=0;i<media_list.length();i++){
        savefile << QString::number(media_list[i]->get_id()).toStdString() << "~";
        savefile << media_list[i]->get_type().toStdString() << "~";
        savefile << media_list[i]->get_title().toStdString() << "~";
        savefile << media_list[i]->get_author().toStdString() << "~";
        savefile << QString::number(media_list[i]->get_borrower()).toStdString() << "~";
        if (media_list[i]->get_type() == "Buch"){ savefile << QString::number(((Book*) media_list[i])->get_pages()).toStdString();}
        else if (media_list[i]->get_type() == "CD"){ savefile << QString::number(((CD*) media_list[i])->get_duration()).toStdString();}
        else if (media_list[i]->get_type() == "DVD"){
            savefile << QString::number(((DVD*) media_list[i])->get_duration()).toStdString() << "~";
            savefile << QString::number(((DVD*) media_list[i])->get_agerestriction()).toStdString();
        } else if (media_list[i]->get_type() == "Blueray"){
            savefile << QString::number(((BlueRay*) media_list[i])->get_duration()).toStdString() << "~";
            savefile << QString::number(((BlueRay*) media_list[i])->get_agerestriction()).toStdString();
        }
        savefile << ";";
    }
    savefile << "\n";
    savefile.close();
}

bool MainWindow::create_person(QString name, QString lastname, int age){
    for (int i=0;i<person_list.length();i++){
        if (person_list[i].get_name() == name && person_list[i].get_lastname() == lastname){
            return false;
        }
    }
    newest_person_index ++;
    person_list.append(Person(newest_person_index,name,lastname,age));
    save_savefile();
    load_dashboard();
    return true;
}

bool MainWindow::edit_person(int id, QString name, QString lastname, int age){
    for (int i=0;i<person_list.length();i++){
        if (person_list[i].get_name() == name && person_list[i].get_lastname() == lastname){
            if (id != person_list[i].get_id()){
                return false;
            }
        }
    }
    int index = -1;
    for (int i=0;i<person_list.length();i++){
        if (person_list[i].get_id() == id){
            index = i;
            break;
        }
    }
    if (index == -1){ return false; }
    person_list[index]=Person(id,name,lastname,age);
    save_savefile();
    load_dashboard();
    return true;
}

void MainWindow::delete_person(int index){
    person_list.removeAt(index);
    for (int i=0;i<media_list.length();i++){
        if (media_list[i]->get_borrower() == person_list[i].get_id()){
            media_list[i]->set_borrower(0);
        }
    }
    save_savefile();
    load_dashboard();
}

bool MainWindow::create_book(QString title, QString author,int pagecount){
    newest_media_index ++;
    Media* book = new Book(newest_media_index,title,author,pagecount);
    media_list.append(book);
    save_savefile();
    load_dashboard();
    return true;
}

bool MainWindow::edit_book(int index, QString title, QString author, int pagecount){
    int id = media_list[index]->get_id();
    int borrower = media_list[index]->get_borrower();
    free(media_list[index]);
    Media* book = new Book(id,title,author,pagecount,borrower);
    media_list[index] = book;
    save_savefile();
    load_dashboard();
    return true;
}

bool MainWindow::create_cd(QString title, QString author, double duration){
    newest_media_index ++;
    Media* cd = new CD(newest_media_index,title,author,duration);
    media_list.append(cd);
    save_savefile();
    load_dashboard();
    return true;
}

bool MainWindow::edit_cd(int index, QString title, QString author, double duration){
    int id = media_list[index]->get_id();
    int borrower = media_list[index]->get_borrower();
    free(media_list[index]);
    Media* cd = new CD(id,title,author,duration,borrower);
    media_list[index] = cd;
    save_savefile();
    load_dashboard();
    return true;
}

bool MainWindow::create_dvd(QString title, QString author, double duration, int age){
    newest_media_index ++;
    Media* dvd = new DVD(newest_media_index,title,author,duration,age);
    media_list.append(dvd);
    save_savefile();
    load_dashboard();
    return true;
}

bool MainWindow::edit_dvd(int index, QString title, QString author, double duration, int age){
    int id = media_list[index]->get_id();
    int borrower = media_list[index]->get_borrower();
    free(media_list[index]);
    Media* dvd = new DVD(id,title,author,duration,age,borrower);
    media_list[index] = dvd;
    save_savefile();
    load_dashboard();
    return true;
}

bool MainWindow::create_blueray(QString title, QString author, double duration, int age){
    newest_media_index ++;
    Media* blueray = new BlueRay(newest_media_index,title,author,duration,age);
    media_list.append(blueray);
    save_savefile();
    load_dashboard();
    return true;
}

bool MainWindow::edit_blueray(int index, QString title, QString author, double duration, int age){
    int id = media_list[index]->get_id();
    int borrower = media_list[index]->get_borrower();
    free(media_list[index]);
    Media* blueray = new BlueRay(id,title,author,duration,age,borrower);
    media_list[index] = blueray;
    save_savefile();
    load_dashboard();
    return true;
}

void MainWindow::delete_media(int index){
    free(media_list[index]);
    media_list.removeAt(index);
    save_savefile();
    load_dashboard();
}

void MainWindow::load_dashboard(){
    ui->personListWidget->clear();
    for (int i=0;i<person_list.length();i++){
        ui->personListWidget->addItem(
                    QString::number(person_list[i].get_id())+": "+
                    person_list[i].get_name()+" "+
                    person_list[i].get_lastname());
    }

    ui->tableWidgetBorrow->setSortingEnabled(false);
    ui->tableWidgetBorrow->clear();

    QTableWidgetItem * pid = new QTableWidgetItem();
    pid->setData(Qt::DisplayRole, "PID");
    QTableWidgetItem * personname = new QTableWidgetItem();
    personname->setData(Qt::DisplayRole, "Person Name");
    QTableWidgetItem * mid = new QTableWidgetItem();
    mid->setData(Qt::DisplayRole, "MID");
    QTableWidgetItem * mediatype = new QTableWidgetItem();
    mediatype->setData(Qt::DisplayRole, "Media Type");
    QTableWidgetItem * mediatitle = new QTableWidgetItem();
    mediatitle->setData(Qt::DisplayRole, "Media Title");
    QTableWidgetItem * mediaauthor = new QTableWidgetItem();
    mediaauthor->setData(Qt::DisplayRole, "Media Autor");

    ui->tableWidgetBorrow->clear();
    ui->tableWidgetBorrow->setHorizontalHeaderItem(0,pid);
    ui->tableWidgetBorrow->setHorizontalHeaderItem(1,personname);
    ui->tableWidgetBorrow->setHorizontalHeaderItem(2,mid);
    ui->tableWidgetBorrow->setHorizontalHeaderItem(3,mediatype);
    ui->tableWidgetBorrow->setHorizontalHeaderItem(4,mediatitle);
    ui->tableWidgetBorrow->setHorizontalHeaderItem(5,mediaauthor);


    int tabrow = 1;
    ui->mediaListWidget->clear();
    for (int i=0;i<media_list.length();i++){
        ui->mediaListWidget->addItem(
                    QString::number(media_list[i]->get_id())+" "+
                    media_list[i]->get_type()+": "+
                    media_list[i]->get_title()+" "+
                    media_list[i]->get_author()+" "+
                    media_list[i]->get_status());

        if (media_list[i]->get_borrower() != 0){
            for (int n=0;n<person_list.length();n++){
                if (media_list[i]->get_borrower() == person_list[n].get_id()){

                    ui->tableWidgetBorrow->setRowCount(tabrow);
                    QTableWidgetItem * pid = new QTableWidgetItem();
                    pid->setData(Qt::DisplayRole,person_list[n].get_id());
                    QTableWidgetItem * personname = new QTableWidgetItem();
                    personname->setData(Qt::DisplayRole, person_list[n].get_name()+" "+person_list[n].get_lastname());
                    QTableWidgetItem * mid = new QTableWidgetItem();
                    mid->setData(Qt::DisplayRole, media_list[i]->get_id());
                    QTableWidgetItem * mediatype = new QTableWidgetItem();
                    mediatype->setData(Qt::DisplayRole, media_list[i]->get_type());
                    QTableWidgetItem * mediatitle = new QTableWidgetItem();
                    mediatitle->setData(Qt::DisplayRole, media_list[i]->get_title());
                    QTableWidgetItem * mediaauthor = new QTableWidgetItem();
                    mediaauthor->setData(Qt::DisplayRole, media_list[i]->get_author());

                    ui->tableWidgetBorrow->setItem(tabrow-1,0,pid);
                    ui->tableWidgetBorrow->setItem(tabrow-1,1,personname);
                    ui->tableWidgetBorrow->setItem(tabrow-1,2,mid);
                    ui->tableWidgetBorrow->setItem(tabrow-1,3,mediatype);
                    ui->tableWidgetBorrow->setItem(tabrow-1,4,mediatitle);
                    ui->tableWidgetBorrow->setItem(tabrow-1,5,mediaauthor);
                    tabrow ++;
                }
            }
        }
    }

    ui->tableWidgetBorrow->setSortingEnabled(true);
}

void MainWindow::on_actionErstellenPerson_triggered()
{
    createpersonwindow.getmain(this);
    createpersonwindow.show();
    createpersonwindow.load_page();
}


void MainWindow::on_createPersonBTN_clicked()
{
    createpersonwindow.getmain(this);
    createpersonwindow.show();
    createpersonwindow.load_page();
}


void MainWindow::on_createMediaBTN_clicked()
{
    createmediawindow.getmain(this);
    createmediawindow.show();
    createmediawindow.load_page();
}


void MainWindow::on_actionErstellenMedium_triggered()
{
    createmediawindow.getmain(this);
    createmediawindow.show();
    createmediawindow.load_page();
}

void MainWindow::on_actionVerwaltenPersonen_triggered()
{
    managepersons.getmain(this);
    managepersons.show();
    managepersons.load_page();
}


void MainWindow::on_actionVerwaltenMedien_triggered()
{
    managemedias.getmain(this);
    managemedias.show();
    managemedias.load_page();
}

void MainWindow::on_borrowBTN_clicked()
{
    borrow.getmain(this);
    borrow.show();
    borrow.load_page();
}


void MainWindow::on_givebackBTN_clicked()
{
    giveback.getmain(this);
    giveback.show();
    giveback.load_page();
}


void MainWindow::on_actionAusleihen_triggered()
{
    borrow.getmain(this);
    borrow.show();
    borrow.load_page();
}




void MainWindow::on_actionZur_ckgeben_triggered()
{
    giveback.getmain(this);
    giveback.show();
    giveback.load_page();
}

