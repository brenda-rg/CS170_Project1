#ifndef NODE_CPP_
#define NODE_CPP_

#include "node.h"
using namespace std;

// basic/start config constructor
Node::Node(vector<int> new_data) {
        data = new_data;
        parent = nullptr;
        fn = gn+hn;
};

//constructor for expanded nodes
Node::Node(vector<int> new_data, Node* oldData) {
        data = new_data;
        parent = oldData;
        gn = oldData->gn + 1; // how many are done
        fn = gn+hn;
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
    int mh = 0;
    for (int i = 0; i < data.size(); i++) {
        if(i == 8 && data.at(i) == 0){
            mh = mh;
        }
        else if (data.at(i) != (i + 1)) {
            ++mh;
        }
    }
    return mh;
};

#endif //NODE_CPP_
