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
#include "blueray.h"

using namespace std;

// Constructor
BlueRay::BlueRay()
{   
    set_title("");
    set_author("");
    set_status(false);
    set_id(0);
    set_duration(0.0);
    set_agerestriction(0);
    set_type("Blueray");
    set_borrower(0);
}

BlueRay::BlueRay(int id, QString  title, QString  author, float duration, int agerestriction)
{   
    set_title(title);
    set_author(author);
    set_status(false);
    set_id(id);
    set_duration(duration);
    set_agerestriction(agerestriction);
    set_type("Blueray");
    set_borrower(0);
}

BlueRay::BlueRay(int id, QString  title, QString  author, float duration, int agerestriction, int borrower)
{
    set_title(title);
    set_author(author);
    set_status(false);
    set_id(id);
    set_duration(duration);
    set_agerestriction(agerestriction);
    set_type("Blueray");
    set_borrower(borrower);
}

// Setter functions
void BlueRay::set_duration(float duration)
{   
    if ( duration>=0.0 ){
        this->duration=duration;
    }else{
        this->duration=0.0;
    }
}

void BlueRay::set_agerestriction(int age)
{   
    if ( age>=0 ){
        this->agerestriction=age;
    }else{
        this->agerestriction=0;
    }
}
