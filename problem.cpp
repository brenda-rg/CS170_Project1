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
                // if the 0 is in the 6th position 
                /*123
                240 //0 is in the 6th position 
                568*/
                int temp = newConfig.at(i+3);
                newConfig.at(i+3) = 0;
                newConfig.at(i) = temp;
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
queue<Node*> Problem::expandNode(Node* oldNode, int option) {
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

        if(visited.count(nextMove) != 0) {
            repeat = true;
        }
        if (!repeat) { // if not a repeat then add to queues
            Node* newMove= new Node(nextMove, oldNode);
            if (option == 2){
                newMove->hn = newMove->misplacedH();
            }
            if (option == 3){
                newMove->hn = newMove->euclideanH();
            }
            (oldNode->children).push_back(newMove);
            pair<vector<int>, bool> p1 (nextMove, true);
            visited.insert(p1);
            q.push(newMove);
        }
    } 
    return q;

};

void Problem::printPath(Node* curr) {
    depth = 0;
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
        depth +=1;
    }
    //cout << "Depth of Goal: " << depth << endl;
};



#endif //PROBLEM_CPP_