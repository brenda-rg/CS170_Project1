#ifndef NODE_H_
#define NODE_H_
// node data structure file
#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

//basic node struct we can change as we implement

struct Node {

    vector<int> data;
    int gn = 0;
    int hn = 0;
    int fn = 0;
    Node* parent;
    Node* c1;
    Node* c2;
    Node* c3;
    Node* c4;
    vector<Node*> children;

    //run problem to make vectors with new moves, 
    //then create a Node with the vector and point it to the parent/old node
    Node(vector<int> new_data)
    {
        data = new_data;
        parent = nullptr;
        c1 = nullptr; 
        c2 = nullptr; 
        c3 = nullptr; 
        c4 = nullptr; 
    }
    Node(vector<int> new_data, Node* old_data)
    {
        data = new_data;
        parent = old_data;
        c1 = nullptr; 
        c2 = nullptr; 
        c3 = nullptr; 
        c4 = nullptr;  
    }
    void printV();
};


#endif //NODE_H_