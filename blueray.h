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

#ifndef _BLUERAY_H_
#define _BLUERAY_H_
class BlueRay : public Media
{

private:
    float   duration;
    int     agerestriction;

public:

    // Constructor
    BlueRay();
    BlueRay(int id, QString  title, QString  author, float duration, int agerestriction);
    BlueRay(int id, QString  title, QString  author, float duration, int agerestriction,int borrower);

    // Setter functions
    void set_duration(float duration=0.0);
    void set_agerestriction(int age=0);

    //Getter functions
    float   get_duration()          const       { return this->duration; };
    int     get_agerestriction()    const       { return this->agerestriction; };
};
#endif
