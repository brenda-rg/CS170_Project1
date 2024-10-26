#ifndef NODE_CPP_
#define NODE_CPP_
// node data structure file
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "node.h"
using namespace std;

//basic node struct we can change as we implement
void Node::printV() {
    vector<int> v = data;
    for (int i = 0;i < 9; i++) {
        cout << " " << v.at(i);
        if(i%3 != 2) {
            cout << " ";
        }
        else { 
            cout << endl;
        }
    }
    cout << endl;
};

#endif //NODE_CPP_
