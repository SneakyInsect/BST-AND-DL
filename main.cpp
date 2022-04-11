#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

#include "orderedlist.h"
#include "tree.h"

using namespace std;
using namespace std::chrono;

int main(){
    bool DL = true, BST = true, balanced = true;

    vector<int> v;

    ifstream inData; // ifstream - input file stream
    inData.open("C:\\Users\\samue\\Documents\\BST AND DL\\outputs\\outputTest_10.txt");
    string inputName, inputSurname;
    int inputID; //temporary variables from input

    while (inData >> inputName >> inputSurname >> inputID) {
        v.push_back(inputID);
    }

    random_shuffle(v.begin(), v.end());


    if(DL) {
        ListElement* head = NULL;
        ListElement* temp;

        inData.clear();
        inData.seekg(0);

        auto start = system_clock::now();

        while (inData >> inputName >> inputSurname >> inputID) {
            //cout<<inputName<<" "<<inputSurname<<" "<<inputID<<"\n";
            temp = WhereToPut(head, inputID);
            if (temp == NULL) {
                append(&head, inputName, inputSurname, inputID);
            } else
                insertAfter(temp, inputName, inputSurname, inputID);
        }

        auto end = system_clock::now();
        auto elapsed = duration_cast <microseconds>(end - start);

        cout << elapsed.count() << " micros to create a DL\n";
//        displayList(head);

        start = system_clock::now();
        for(int x : v){
            FindByID(head, x);
        }
        end = system_clock::now();
        elapsed = duration_cast <microseconds>(end - start);
        cout << elapsed.count() << " micros to Find in DL\n";


        start = system_clock::now();
        for(int x : v){
            deleteElement(&head, x);
        }
        end = system_clock::now();
        elapsed = duration_cast <microseconds>(end - start);
        cout << elapsed.count() << " micros to delete everything-random order\n";

    }

    if(BST){
        TreeNode* root = NULL;

        inData.clear();
        inData.seekg(0);

        auto start = system_clock::now();
        while (inData >> inputName >> inputSurname >> inputID) {
            //cout<<inputName<<" "<<inputSurname<<" "<<inputID<<"\n";
            root = insert(root, inputName, inputSurname, inputID);
        }
        auto end = system_clock::now();
        auto elapsed = duration_cast <microseconds>(end - start);
        cout << elapsed.count() << " micros to create a BST\n";

        if(balanced){
            root = buildTree(root);
        }
        TreeNode *found;
        start = system_clock::now();
        for(int x : v){
            found = findByID(root, x);
        }
        end = system_clock::now();
        elapsed = duration_cast <microseconds>(end - start);
        cout << elapsed.count() << " micros to find everything BST\n";

        start = system_clock::now();
        for(int x : v){
            root = deleteNode(root, x);
        }
        end = system_clock::now();
        elapsed = duration_cast <microseconds>(end - start);
        cout << elapsed.count() << " micros to delete everything-random order\n";
        //inorder(root);


    }

    return 0;
}