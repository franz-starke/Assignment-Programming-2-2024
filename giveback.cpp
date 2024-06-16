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
#include "giveback.h"
#include "ui_giveback.h"

Giveback::Giveback(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Giveback)
{
    ui->setupUi(this);
}

void Giveback::getmain(MainWindow* mainwindow){
    main = mainwindow;
}


void Giveback::load_page(){
    ui->comboBoxMedia->clear();
    for (int i=0;i<main->media_list.length();i++){
        if (main->media_list[i]->get_borrower() != 0){
            ui->comboBoxMedia->addItem(QString::number(main->media_list[i]->get_id())+" "+
                                       main->media_list[i]->get_type()+": "+
                                       main->media_list[i]->get_title()+" "+
                                       main->media_list[i]->get_author());
        }
    }

}

Giveback::~Giveback()
{
    delete ui;
}

void Giveback::on_pushButtonGiveBack_clicked()
{
    if (ui->comboBoxMedia->currentText().split(" ")[0] != "") {
        for (int i=0;i<main->media_list.length();i++){
            if (ui->comboBoxMedia->currentText().split(" ")[0] == QString::number(main->media_list[i]->get_id())){
                main->media_list[i]->set_borrower(0);
                main->save_savefile();
                main->load_dashboard();
                close();
                break;
            }
        }
    }
}

