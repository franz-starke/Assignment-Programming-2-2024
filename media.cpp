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
#include <QString>

using namespace std;

// Constructor
Media::Media()
{   
    set_title("");
    set_author("");
    set_status(false);
    set_id(0);
}

Media::Media(int id, QString  title, QString  author)
{   
    set_title(title);
    set_author(author);
    set_status(false);
    set_id(id);
}

// Setter functions
void Media::set_status(bool status)
{   
    this->status=status;
}

void Media::set_title(QString  title)
{   
    this->title=title;
}

void Media::set_author(QString  author)
{   
    this->author=author;
}

void Media::set_borrower(int borrower)
{   
    this->borrower=borrower;
}

void Media::set_id(int id){
    this->id = id;
}

void Media::set_type(QString type){
    this->type = type;
}
