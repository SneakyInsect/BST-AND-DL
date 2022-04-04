#include <iostream>
#include <vector>

using namespace std;

    struct ListElement{
        string name, surname;
        int ID;
        struct ListElement *next;
    };

    struct ListHead{
        struct ListElement *first;
    };

int main(){
    vector <ListElement> Elements;

    
    return 0;
}