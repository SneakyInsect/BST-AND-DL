#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

using namespace std;


struct ListElement{
        string name, surname;
        int ID;
        struct ListElement *next;
    };

extern ListElement* head;

void append(struct ListElement** head, string name, string surname, int ID){
    struct ListElement* newListElement = new ListElement;

    struct ListElement *last = *head; //Assigning new pointer to current last element

    //Assigning data to new Element:
    newListElement->name = name;
    newListElement->surname = surname;
    newListElement->ID = ID;

    //As for now newListElement is the last element so set its' pointer to NULL
    newListElement->next = NULL;

    //If first element, change heads' pointer to the current one
    if (*head == NULL){
        *head = newListElement;
        return;
    }

    //seek for the last element
    while (last->next != NULL)
        last = last->next;

    //To the found last element, add pointer to currently added element
    last->next = newListElement;
    return;
}

void displayList(struct ListElement *list){
    //traverse the list to display each ListElement
    while (list != NULL){
        cout<<list->name<<" "<<list->surname<<" "<<list->ID<<"\n";
        list = list->next;
    }
}

ListElement* FindByID(struct ListElement *list, int ID){
    while (list != NULL)
    {
        if(list->ID == ID){
            return list;
        }
        else
            list = list->next;
    }
    return NULL;
}

void insertAfter(struct ListElement* prev_ListElement, string name, string surname, int ID)
{
    //If Null create as first element
    if (prev_ListElement == NULL){
        return;//append(&head, name, surname, ID);
    }

    //create new struct
    struct ListElement* newListElement = new ListElement;

    //assign data
    newListElement->name = name;
    newListElement->surname = surname;
    newListElement->ID = ID;

    //copy pointer
    newListElement->next = prev_ListElement->next;

    //assign newListElement pointer to the prev list element
    prev_ListElement->next = newListElement;
}

ListElement* WhereToPut(struct ListElement *list, int ID){
    ListElement* prev = NULL;
    while (list != NULL)
    {
        if(list->ID > ID){
            return prev;
        }
        else {
            prev = list;
            list = list->next;
        }
    }
    return NULL;
}

#endif