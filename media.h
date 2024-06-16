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

#ifndef _MEDIA_H_
#define _MEDIA_H_

#include <QString>

class Media
{

private:
    bool    status;
    int     id;
    QString title;
    QString author;
    int     borrower;
    QString type;

public:

    // Constructor
    Media();
    Media(int id, QString  title, QString  author);

    // Setter functions
    void    set_status  (bool status = false);
    void    set_title   (QString  title = "");
    void    set_author  (QString  author = "");
    void    set_borrower(int borrower = 0);
    void    set_id      (int id = 0);
    void    set_type    (QString type = "");

    // Getter functions
    bool    get_status()            const       { return this->status; };
    QString get_title()             const       { return this->title; };
    QString get_author()            const       { return this->author; };
    int     get_borrower()          const       { return this->borrower; };
    int     get_id()                const       { return this->id; };
    QString get_type()              const       { return this->type; };
};
#endif
