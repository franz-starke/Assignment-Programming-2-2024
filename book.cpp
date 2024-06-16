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
#include "book.h"

using namespace std;

// Constructor
Book::Book()
{   
    set_title("");
    set_author("");
    set_status(false);
    set_id(0);
    set_pages(0);
    set_type("Buch");
    set_borrower(0);
}

Book::Book(int id, QString  title, QString  author, int pages)
{   
    set_title(title);
    set_author(author);
    set_status(false);
    set_id(id);
    set_pages(pages);
    set_type("Buch");
    set_borrower(0);
}

Book::Book(int id, QString  title, QString  author, int pages, int borrower)
{
    set_title(title);
    set_author(author);
    set_status(false);
    set_id(id);
    set_pages(pages);
    set_type("Buch");
    set_borrower(borrower);
}

// Setter functions
void Book::set_pages(int pages)
{   
    if ( pages>=0 ){
        this->pages=pages;
    }else{
        this->pages=0;
    }
}
