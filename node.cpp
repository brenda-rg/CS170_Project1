#ifndef NODE_CPP_
#define NODE_CPP_

#include "node.h"
using namespace std;

Node::Node() {
        parent = nullptr;
        gn =0;
        hn = 0;
        fn = 0;
};
/* Node::Node(Node* oldNode) {
    parent = oldNode->parent;
    data = oldNode->data;
    gn = oldNode->gn;
    gn = oldNode->hn;
    fn = oldNode->fn;

}; */

// basic/start config constructor
Node::Node(vector<int> new_data) {
        data = new_data;
        parent = nullptr;
        gn = 0;
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

int Node::misplacedH() {
    int count = 0;
    for(int i = 0; i < data.size(); i++ ) {
        if(data.at(i) != i+1) {
            count +=1;
        }
    }
    return count;
};

int Node::euclideanH() {
    int count = 0;

    return count;
};

#endif //NODE_CPP_
