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

#ifndef CREATEPERSON_H
#define CREATEPERSON_H

#include <QWidget>
class MainWindow;

namespace Ui {
class Createperson;
}

class Createperson : public QWidget
{
    Q_OBJECT

public:
    explicit Createperson(QWidget *parent = nullptr);
    ~Createperson();
    void getmain(MainWindow* mainwindow);
    void load_page();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Createperson *ui;
    MainWindow* main;
};

#endif // CREATEPERSON_H
