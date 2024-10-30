#ifndef NODE_CPP_
#define NODE_CPP_

#include "node.h"
using namespace std;

// basic/start config constructor
Node::Node(vector<int> new_data) {
        data = new_data;
        parent = nullptr;
};

//constructor for expanded nodes
Node::Node(vector<int> new_data, Node* oldData) {
        data = new_data;
        parent = oldData;
        gn = oldData->gn + 1; 
};

//print node data in 8 puzzle format
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
