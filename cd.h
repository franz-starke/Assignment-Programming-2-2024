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

#ifndef _CD_H_
#define _CD_H_
class CD : public Media
{

private:
    float   duration;

public:

    // Constructor
    CD();
    CD(int id, QString  title, QString  author, float duration);
    CD(int id, QString  title, QString  author, float duration, int borrower);

    // Setter functions
    void set_duration(float duration=0.0);

    //Getter functions
    float   get_duration()          const       { return this->duration; };
};
#endif
