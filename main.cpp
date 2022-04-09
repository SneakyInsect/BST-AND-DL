#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "orderedlist.h"

using namespace std;

int main(){
    int records = 1000;
    vector<int> v(records/10);
    iota(v.begin(), v.end(), 1000000);
    random_shuffle(v.begin(), v.end());
    //for(auto x : v) cout<<x<<" ";

    ListElement* head = NULL;
    ListElement* PutAfter;
    
    ifstream inData;
    inData.open("C:\\Users\\samue\\Documents\\BST AND DL\\outputTest_1.txt");
    string inputName, inputSurname;
    int inputID; //temporary variables from input

    //displayList(head);
    while(inData>>inputName>>inputSurname>>inputID) {
   S     //cout<<inputName<<" "<<inputSurname<<" "<<inputID<<"\n";
        PutAfter = WhereToPut(head, inputID);
        if (PutAfter == NULL) {
            append(&head, inputName, inputSurname, inputID);
        } else
            insertAfter(PutAfter, inputName, inputSurname, inputID);

    }
    displayList(head);

    return 0;
}