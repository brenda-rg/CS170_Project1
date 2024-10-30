#ifndef PROBLEM_CPP_
#define PROBLEM_CPP_

#include "problem.h"

using namespace std;

//default constructor
Problem::Problem() {
    head = new Node(defaultState);
    pair<vector<int>,bool> p1 (defaultState, true);
    visited.insert(p1);
};

//constructor given starting state
Problem::Problem(vector<int> init) {
    head = new Node(init);
    pair<vector<int>,int> p1 (init, 1);
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
vector<int> Problem::moveup(vector<int> currPos) {
    vector<int> newConfig = currPos;
    for(int i = 0; i < 9; i++){
        if(newConfig.at(i) == 0){
            //if below the first row then swap the blank and the value above
            if(i > 2) {
                int temp = newConfig.at(i-3);
                newConfig.at(i-3) = 0;
                newConfig.at(i) = temp;
                //cout <<"--TEST func() moveup--" << endl;
                break;
            }
        }
    }
    return newConfig;
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
queue<Node*> Problem::expandNode(Node* oldNode) {
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
            nextMove = moveleft(oldNode->data);
        }
        else if(i == 1) {
            nextMove = moveright(oldNode->data);
        }
        else if(i == 2) {
            nextMove = moveup(oldNode->data);
        }
        else {
            nextMove = movedown(oldNode->data);
        }

        if(visited.find(nextMove) != visited.end()) {
            repeat = true;
        }
        //cout << "--------------" <<  repeat <<endl;
        if (!repeat) { // if not a repeat then add to queues
            //Node* newMove = addMove(head, temp->data, nextMove);
            Node* newMove= new Node(nextMove, oldNode);
            (oldNode->children).push_back(newMove);
            pair<vector<int>, bool> p1 (nextMove, true);
            visited.insert(p1);
            cout << "New move added: " << endl;
            newMove->printV();
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

#endif //PROBLEM_CPP_