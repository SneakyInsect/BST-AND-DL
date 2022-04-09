#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

#include "orderedlist.h"
#include "tree.h"

using namespace std;

int main(){
    bool DL = false, BST = true;

    int records = 1000;
    vector<int> v(records/10);
    iota(v.begin(), v.end(), 1000000);
    random_shuffle(v.begin(), v.end());

    //^-Random IDs for deletion

    
    ifstream inData;
    inData.open("C:\\Users\\samue\\Documents\\BST AND DL\\outputTest_1.txt");
    string inputName, inputSurname;
    int inputID; //temporary variables from input
    if(DL) {

        ListElement* head = NULL;
        ListElement* temp;

        //displayList(head);

        while (inData >> inputName >> inputSurname >> inputID) {
            //cout<<inputName<<" "<<inputSurname<<" "<<inputID<<"\n";
            temp = WhereToPut(head, inputID);
            if (temp == NULL) {
                append(&head, inputName, inputSurname, inputID);
            } else
                insertAfter(temp, inputName, inputSurname, inputID);

        }
        displayList(head);
    }

    if(BST){
        TreeNode* root = NULL;
        //TreeNode* Ttemp;

        //if(DL){
            inData.clear();
            inData.seekg(0);
        //}
        while (inData >> inputName >> inputSurname >> inputID) {
            //cout<<inputName<<" "<<inputSurname<<" "<<inputID<<"\n";
            root = insert(root, inputName, inputSurname, inputID);
        }
        root = deleteNode(root, 1000096);
        cout<<"\ninorder: \n";
        inorder(root);
        cout<<"\npostorder: \n";
        postorder(root);
        cout<<"\npreorder: \n";
        preorder(root);

        root = buildTree(root);
        cout<<"\nBalanced inorder: \n";
        inorder(root);
        cout<<"\nBalanced postorder: \n";
        postorder(root);
        cout<<"\nBalanced preorder: \n";
        preorder(root);

    }

    return 0;
}