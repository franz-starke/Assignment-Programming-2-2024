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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "QList"
#include "QString"

#include "createperson.h"
#include "createmedia.h"
#include "managepersons.h"
#include "managemedias.h"
#include "borrow.h"
#include "giveback.h"

#include "person.h"
#include "blueray.h"
#include "dvd.h"
#include "cd.h"
#include "book.h"

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int newest_person_index;
    int newest_media_index;
    QList<Person> person_list;
    QList<Media*> media_list;

    void load_dashboard();
    bool create_person(QString name, QString lastname, int age);
    bool edit_person(int id, QString name, QString lastname, int age);
    void delete_person(int index);
    bool create_book(QString title, QString author, int pagecount);
    bool edit_book(int id, QString title, QString author, int pagecount);
    bool create_cd(QString title, QString author, double duration);
    bool edit_cd(int id, QString title, QString author, double duration);
    bool create_dvd(QString title, QString author, double duration, int age);
    bool edit_dvd(int id, QString title, QString author, double duration, int age);
    bool create_blueray(QString title, QString author, double duration, int age);
    bool edit_blueray(int id, QString title, QString author, double duration, int age);
    void delete_media(int index);
    void load_savefile();
    void save_savefile();

private slots:
    void on_actionErstellenPerson_triggered();
    void on_createPersonBTN_clicked();
    void on_createMediaBTN_clicked();
    void on_actionErstellenMedium_triggered();
    void on_actionVerwaltenPersonen_triggered();
    void on_actionVerwaltenMedien_triggered();
    void on_borrowBTN_clicked();
    void on_givebackBTN_clicked();

    void on_actionAusleihen_triggered();

    void on_actionZur_ckgeben_triggered();

private:
    Ui::MainWindow *ui;
    Createperson createpersonwindow;
    Createmedia createmediawindow;
    Managepersons managepersons;
    Managemedias managemedias;
    Borrow borrow;
    Giveback giveback;
};
#endif // MAINWINDOW_H
