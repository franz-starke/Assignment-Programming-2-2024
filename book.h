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

#include "media.h"

#ifndef _BOOK_H_
#define _BOOK_H_
class Book : public Media
{

private:
    int     pages;

public:

    // Constructor
    Book();
    Book(int id, QString  title, QString  author, int pages);
    Book(int id, QString  title, QString  author, int pages, int borrower);

    // Setter functions
    void set_pages(int pages=0);

    //Getter functions
    int     get_pages()             const       { return this->pages; };
};
#endif
