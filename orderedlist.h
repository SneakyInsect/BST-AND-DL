#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

struct ListElement{
        string name, surname;
        int ID;
        struct ListElement *next;
    };

ListElement structify(string name, string surname, int ID){
    ListElement t;
    t.name = name;
    t.surname = surname;
    t.ID = ID;
}

#endif