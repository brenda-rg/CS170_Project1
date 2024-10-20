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

    int data;
    Node* next;
    Node* prev;

    Node(int new_data)
    {
        data = new_data;
        next = nullptr; 
    }
};

#endif NODE_H_