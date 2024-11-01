#ifndef NODE_CPP_
#define NODE_CPP_

#include "node.h"
#include <math.h>
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
    //this->printV();
    int mh = 0;
    for (int i = 0; i < data.size(); i++) {
        if(data.at(i) == 0){
            mh = mh;
        }
        else if (data.at(i) != (i + 1)) {
            ++mh;
        }
    }
    hn = mh;
    fn = gn + hn;
    return mh;
};


double Node::euclideanH() {
    //this->printV();
    double count = 0;
    for(int i = 0; i  < data.size(); i++) {
        count = count + calculateDist(i, data.at(i));
    }
    hn = count;
    fn = gn + hn;
    return count;
};

/* for reference
    vector index:
    { 0  1  2
      3  4  5
      6  7  8 }

    mod values:
    { 0  1  2 
      0  1  2
      0  1  2 }
    div values:
    { 0  0  0 
      1  1  1
      2  2  2 }
    
*/

double Node::calculateDist(int currpos, int num) { //give the vector position and the value of the number at that position
    if(num == 0) num = 9;
    int currColumn = currpos%3; //column
    int currRow = currpos/3; // row
    int goalRow = (num-1)/3;
    int goalColumn = (num-1)%3;

    double x = currColumn-goalColumn;
    double y = currRow-goalRow;
    double dist = pow(x,2) + pow(x,2);
    dist = sqrt(dist);
    return dist;
}


#endif //NODE_CPP_
