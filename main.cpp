#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <chrono>

#include "orderedlist.h"
#include "tree.h"

using namespace std;
using namespace std::chrono;

int main() {
    int n = 20;
    int a, b, c;
    vector<tuple<int, int, int>> DLres;
    vector<tuple<int, int, int>> TREEres;
    cout<<"create find delete:"<<endl;
    for(int i = 0; i<n; i++){
        bool DL = true, BST = true, balanced = false;

        vector<int> v;

        ifstream inData; // ifstream - input file stream
        inData.open("..\\outputs\\output_" + to_string(i+1) + ".txt");
        string inputName, inputSurname;
        int inputID; //temporary variables from input
        //cout<<i+1<<": \n";
        //int t = 0;
        while (inData >> inputName >> inputSurname >> inputID) {
            v.push_back(inputID);
            //++;
        }
        cout<<v.size()<<endl;

        random_shuffle(v.begin(), v.end());


        if (DL) {
            ListElement *head = NULL;
            ListElement *temp;

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
            auto elapsed = duration_cast<milliseconds>(end - start);

            //cout << elapsed.count() << " micros to create a DL\n";
            //        displayList(head);

            a = int(elapsed.count());
            start = system_clock::now();
            for (int x: v) {
                FindByID(head, x);
            }
            end = system_clock::now();
            elapsed = duration_cast<milliseconds>(end - start);
            //cout << elapsed.count() << " micros to Find in DL\n";
            b = int(elapsed.count());

            start = system_clock::now();
            for (int x: v) {
                deleteElement(&head, x);
            }
            end = system_clock::now();
            elapsed = duration_cast<milliseconds>(end - start);
            //cout << elapsed.count() << " micros to delete everything-random order\n";
            c = int(elapsed.count());
            DLres.push_back(make_tuple(a, b, c));
        }

        if (BST) {
            TreeNode *root = NULL;

            inData.clear();
            inData.seekg(0);

            auto start = system_clock::now();
            while (inData >> inputName >> inputSurname >> inputID) {
                //cout<<inputName<<" "<<inputSurname<<" "<<inputID<<"\n";
                root = insert(root, inputName, inputSurname, inputID);
            }
            auto end = system_clock::now();
            auto elapsed = duration_cast<milliseconds>(end - start);
            //cout << elapsed.count() << " micros to create a BST\n";
            a = int(elapsed.count());
            if (balanced) {
                root = buildTree(root);
            }
            TreeNode *found;
            start = system_clock::now();
            for (int x: v) {
                found = findByID(root, x);
            }
            end = system_clock::now();
            elapsed = duration_cast<milliseconds>(end - start);
            b = int(elapsed.count());
            //cout << elapsed.count() << " micros to find everything BST\n";

            start = system_clock::now();
            for (int x: v) {
                root = deleteNode(root, x);
            }
            end = system_clock::now();
            elapsed = duration_cast<milliseconds>(end - start);
            //cout << elapsed.count() << " micros to delete everything-random order\n";
            //inorder(root);
            c = int(elapsed.count());
            TREEres.push_back(make_tuple(a, b, c));
        }
    }
    cout<<"DL \n";
    for (auto [ X, Y, Z ] : DLres)
    {
        std::cout << X << " " << Y << " " << Z << std::endl;
    }
    cout<<"TREE \n";
    for (auto [ X, Y, Z ] : TREEres)
    {
        std::cout << X << " " << Y << " " << Z << std::endl;
    }

    return 0;
}