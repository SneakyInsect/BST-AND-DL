#include <iostream>
#include <fstream>
#include "orderedlist.h"

using namespace std;

int main(){
    ListElement* head = NULL;
    ListElement* PutAfter;
    
    ifstream inData;
    inData.open("C:\\Users\\samue\\Documents\\BST AND DL\\outputTest_1.txt");

    string inputName, inputSurname;
    int inputID; //temporary variables from input

    displayList(head);
    while(inData>>inputName>>inputSurname>>inputID) {
        cout<<inputName<<" "<<inputSurname<<" "<<inputID<<"\n";
        PutAfter = WhereToPut(head, inputID);
        if (PutAfter == NULL) {
            //cout << "dupa \n";
            append(&head, inputName, inputSurname, inputID);
        }
        else
            insertAfter(PutAfter, inputName, inputSurname, inputID);
    }
    displayList(head);

    return 0;
}