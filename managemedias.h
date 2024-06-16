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

#ifndef MANAGEMEDIAS_H
#define MANAGEMEDIAS_H

#include <QWidget>

class MainWindow;

namespace Ui {
class Managemedias;
}

class Managemedias : public QWidget
{
    Q_OBJECT

public:
    explicit Managemedias(QWidget *parent = nullptr);
    ~Managemedias();
    void getmain(MainWindow* mainwindow);
    void load_page();
    void select_media(int index);

private slots:
    void on_tableWidgetMedia_cellPressed(int row, int column);
    void on_tableWidgetMedia_cellActivated(int row, int column);
    void on_pushButtonSave_clicked();

    void on_pushButtonDelete_clicked();

private:
    Ui::Managemedias *ui;
    MainWindow* main;
    int selected_index;
};

#endif // MANAGEMEDIAS_H
