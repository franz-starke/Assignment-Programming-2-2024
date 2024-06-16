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

#ifndef BORROW_H
#define BORROW_H

#include <QWidget>

class MainWindow;

namespace Ui {
class Borrow;
}

class Borrow : public QWidget
{
    Q_OBJECT

public:
    explicit Borrow(QWidget *parent = nullptr);
    ~Borrow();
    void getmain(MainWindow* mainwindow);
    void load_page();
    void set_text();

private slots:
    void on_tableWidgetPersons_cellActivated(int row, int column);
    void on_tableWidgetMedias_cellActivated(int row, int column);
    void on_pushButtonBorrow_clicked();

    void on_tableWidgetPersons_cellClicked(int row, int column);

    void on_tableWidgetMedias_cellClicked(int row, int column);

private:
    Ui::Borrow *ui;
    MainWindow* main;
    int personindex;
    int mediaindex;
};

#endif // BORROW_H
