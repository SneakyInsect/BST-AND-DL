#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

struct ListElement{
        std::string name, surname;
        int ID;
        struct ListElement *next;
    };


#endif