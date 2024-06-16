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
#include "cd.h"

using namespace std;

// Constructor
CD::CD()
{   
    set_title("");
    set_author("");
    set_status(false);
    set_id(0);
    set_duration(0.0);
    set_type("CD");
    set_borrower(0);
}

CD::CD(int id, QString  title, QString  author, float duration)
{   
    set_title(title);
    set_author(author);
    set_status(false);
    set_id(id);
    set_duration(duration);
    set_type("CD");
    set_borrower(0);
}

CD::CD(int id, QString  title, QString  author, float duration, int borrower)
{
    set_title(title);
    set_author(author);
    set_status(false);
    set_id(id);
    set_duration(duration);
    set_type("CD");
    set_borrower(borrower);
}

// Setter functions
void CD::set_duration(float duration)
{   
    if ( duration>=0.0 ){
        this->duration=duration;
    }else{
        this->duration=0.0;
    }
}
