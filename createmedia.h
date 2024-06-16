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

#ifndef CREATEMEDIA_H
#define CREATEMEDIA_H

#include <QWidget>
class MainWindow;

namespace Ui {
class Createmedia;
}

class Createmedia : public QWidget
{
    Q_OBJECT

public:
    explicit Createmedia(QWidget *parent = nullptr);
    ~Createmedia();
    void getmain(MainWindow* mainwindow);
    void load_page();

private slots:
    void on_pushButton_clicked();
    void on_comboBoxMediaType_currentIndexChanged(int index);

private:
    Ui::Createmedia *ui;
    MainWindow* main;
};

#endif // CREATEMEDIA_H
