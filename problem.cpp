#ifndef PROBLEM_CPP_
#define PROBLEM_CPP_

#include "problem.h"
#include <iostream>

using namespace std;

//default constructor
Problem::Problem() {
    head = new Node(defaultState);
    pair<vector<int>,int> p1 (defaultState, 0);
    visited.insert(p1);
};

//constructor given starting state
Problem::Problem(vector<int> init) {
    head = new Node(init);
    pair<vector<int>,int> p1 (init, 0);
    visited.insert(p1);
};

//PRIVATE
//0 is the blank space
/* for reference
    vector index:
    { 0  1  2
      3  4  5
      6  7  8 }

    mod values:
    { 0  1  2 
      0  1  2
      0  1  2 }
    
*/
   
//operations
vector<int> Problem::moveup(vector<int> curr) {
    for(int i = 0; i < 9; i++){
        if(curr.at(i) == 0){
            //if below the first row then swap the blank and the value above
            if(i > 2) {
                int temp = curr.at(i-3);
                curr.at(i-3) = 0;
                curr.at(i) = temp;
                //cout <<"--TEST func() moveup--" << endl;
                break;
            }
        }
    }
    return curr;
};

vector<int> Problem::movedown(vector<int> currPos){
    vector<int> newConfig = currPos;
    for(int i = 0; i < 9; i++){
        if(newConfig.at(i) == 0){
            //if below the first row then swap the blank and the value above
            if(i < 6) {
                int temp = newConfig.at(i+3);
                newConfig.at(i+3) = 0;
                newConfig.at(i) = temp;
                //cout <<"--TEST func() movedown--" << endl;
                break;
                
            }
        }
    }
    return newConfig;
};


vector<int> Problem::moveright(vector<int> currPos) {
    vector<int> newConfig = currPos;
    for(int i = 0; i < 9; i++){
        if(newConfig.at(i) == 0){
            //if below the first row then swap the blank and the value above
            if(i%3 < 2) {
                int temp = newConfig.at(i+1);
                newConfig.at(i+1) = 0;
                newConfig.at(i) = temp;
                //cout <<"--TEST func() moveright--" << endl;
                break;
            }
        }
    }
    return newConfig;
};

vector<int> Problem::moveleft(vector<int> currPos) {
    vector<int> newConfig = currPos;
    for(int i = 0; i < 9; i++){
        if(newConfig.at(i) == 0){
            //if below the first row then swap the blank and the value above
            if(i%3 > 0) {
                int temp = newConfig.at(i-1);
                newConfig.at(i-1) = 0;
                newConfig.at(i) = temp;
                //cout <<"--TEST func() moveleft--" << endl;
                break;
            }
        }
    }
    return newConfig;
};


//PUBLIC

Node* Problem::getHead() {
    return head;
};

//expand the current node
queue<Node*> Problem::expandNode(Node* oldNode, int choice) {
    queue<Node*> q; //queue with children of the current node;

    if (!head) {
        cout << "List is empty." << endl;
        return q;
    }

    //make sure the values aren't repeated with one of the values in the tree so far
    vector<int> nextMove;
    bool repeat;

    for(int i = 0; i < 4; i++) {
        repeat = false;
        if(i == 0){
            nextMove = movedown(oldNode->data);
        }
        else if(i == 1) {
            nextMove = moveup(oldNode->data);
        }
        else if(i == 2) {
            nextMove = moveleft(oldNode->data);
        }
        else {
            nextMove = moveright(oldNode->data);
        }

        if(visited.count(nextMove)) {
            repeat = true;
        }
        //cout << "--------------" <<  repeat <<endl;
        if (!repeat) { // if not a repeat then add to queues
            //printVect(nextMove);
            //cout << endl;
            Node* newMove= new Node(nextMove, oldNode);
            if(choice == 2) {
            newMove->hn = newMove->misplacedH();
            newMove->fn = newMove->gn + newMove->hn;
            }
            (oldNode->children).push_back(newMove);
            pair<vector<int>, int> p1 (nextMove, 0);
            visited.insert(p1);
            visited.at(oldNode->data) = 1;
            cout << "New move added: " << endl;
            //cout << "Current map values: " << endl;
            //outMap();
            cout << endl;
            q.push(newMove);
        }
    } 
    return q;

};

void Problem::printPath(Node* curr) {
    if (!head) {
            cout << "List is empty." << endl;
            return;
    }
    Node* temp = curr;
    stack<Node*> path;
    while(temp != nullptr) {
        path.push(temp);
        temp = temp->parent;
    }
    while(!path.empty()) {
        path.top()->printV();
        path.pop();
    }
};

//for debugging map
void Problem::outMap() {
    map<vector<int>, int>::iterator it;
    int i = 0;

    for (it = visited.begin(); it != visited.end(); it++)
    {
        cout << i << ") ";
        printVect(it->first);    // string (key)
        cout << ':'
        << it->second;   // string's value 
        cout << std::endl;
        cout << std::endl;
    }
};

void Problem::printVect(vector<int> v) {
    for (auto & element : v) {
        cout << element << ", ";
    }
    cout << endl;
}

#endif //PROBLEM_CPP_