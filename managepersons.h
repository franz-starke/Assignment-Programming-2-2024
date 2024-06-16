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

#ifndef MANAGEPERSONS_H
#define MANAGEPERSONS_H

#include <QWidget>

class MainWindow;

namespace Ui {
class Managepersons;
}

class Managepersons : public QWidget
{
    Q_OBJECT

public:
    explicit Managepersons(QWidget *parent = nullptr);
    ~Managepersons();
    void getmain(MainWindow* mainwindow);
    void load_page();
    void select_person(int index);

private slots:
    void on_tableWidgetPerson_cellPressed(int row, int column);
    void on_tableWidgetPerson_cellActivated(int row, int column);
    void on_pushButtonSave_clicked();
    void on_pushButtonDelete_clicked();

private:
    Ui::Managepersons *ui;
    MainWindow* main;
    int selected_index;
};

#endif // MANAGEPERSONS_H
