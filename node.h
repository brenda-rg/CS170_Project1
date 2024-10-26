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
    Node* next;
    Node* prev;

    //run problem to make vectors with new moves, 
    //then create a Node with the vector and point it to the parent/old node
    Node(vector<int> new_data)
    {
        data = new_data;
        next = nullptr; 
    }
    Node(vector<int> new_data, Node* old_data)
    {
        data = new_data;
        prev = old_data;
        next = nullptr; 
    }
    void printV();
};


#endif //NODE_H_