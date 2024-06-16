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

#ifndef _PERSON_H_
#define _PERSON_H_

#include <QString>

class Person
{

private:
    int     id;
    int     age;
    QString name;
    QString lastname;

public:

    // Constructor
    Person();
    Person(int id, QString  name, QString  lastname, int age);

    // Setter functions
    void    set_name(QString  name = "");
    void    set_lastname(QString  lastname = "");
    void    set_age (int age = 0);

    // Getter functions
    QString get_name()              const       { return this->name; };
    QString get_lastname()          const       { return this->lastname; };
    int     get_age()               const       { return this->age; };
    int     get_id()                const       { return this->id; };
};
#endif
