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

#ifndef GIVEBACK_H
#define GIVEBACK_H

#include <QWidget>

class MainWindow;

namespace Ui {
class Giveback;
}

class Giveback : public QWidget
{
    Q_OBJECT

public:
    explicit Giveback(QWidget *parent = nullptr);
    ~Giveback();
    void getmain(MainWindow* mainwindow);
    void load_page();

private slots:
    void on_pushButtonGiveBack_clicked();

private:
    Ui::Giveback *ui;
    MainWindow* main;
};

#endif // GIVEBACK_H
