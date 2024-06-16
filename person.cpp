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

#include "person.h"
#include <QString>

using namespace std;

// Constructor
Person::Person()
{   
    set_name("");
    set_lastname("");
    set_age(0);
    this->id = 0;
}

Person::Person(int id, QString name, QString lastname, int age)
{   
    set_name(name);
    set_lastname(lastname);
    set_age(age);
    this->id = id;
}

// Setter functions
void Person::set_name(QString name)
{   
    this->name=name;
}

void Person::set_lastname(QString lastname)
{   
    this->lastname=lastname;
}

void Person::set_age(int age)
{   
    if (age > 0){
        this->age=age;
    }else{
        this->age=0;
    }
}
