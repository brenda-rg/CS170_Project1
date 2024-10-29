#ifndef PROBLEM_CPP_
#define PROBLEM_CPP_

#include <queue>
#include "problem.h"

using namespace std;

Problem::Problem() {
    head = new Node(defaultState);
};

Problem::Problem(vector<int> init) {
    head = new Node(init);
};

void Problem::printMoves() {
    print();
};

void Problem::print() {
    if (!head) {
            cout << "List is empty." << endl;
            return;
    }

    Node* temp = head;
    while (temp) {
        temp->printV();
        cout << " -> " << endl;
        temp = temp->next;
    }
    cout << "NULL" << endl; 
};

queue<Node*> Problem::expandNode(Node* oldNode) {
    queue<Node*> q; //queue with children of the current node;
    /* if (!head) {
        cout << "List is empty." << endl;
        return q;
    } */

    Node* temp = oldNode;
/*     while (temp-> next != nullptr) {
        temp = temp->next;
    } */
    vector<int> nextMove = moveleft(temp->data);
    if (nextMove != temp->data) {
        addMove(head, temp->data, nextMove);
        q.push(addMove(head, temp->data, nextMove));
    }
    nextMove = moveright(temp->data);
    if (nextMove != temp->data) {
        addMove(head, temp->data, nextMove);
        q.push(addMove(head, temp->data, nextMove));
    }
    nextMove = moveup(temp->data);
    if (nextMove != temp->data) {
        addMove(head, temp->data, nextMove);
        q.push(addMove(head, temp->data, nextMove));
    }
    nextMove = movedown(temp->data);
    if (nextMove != temp->data) {
        addMove(head, temp->data, nextMove);
        q.push(addMove(head, temp->data, nextMove));
    }
    cout << "done adding new moves..." << endl;
    return q;

};

//0 is the blank space
/* for reference
    vector index =
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
            }
        }
    }

    cout <<"--TEST func() moveup--" << endl;
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
            }
        }
    }

    cout <<"--TEST func() movedown--" << endl;
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
            }
        }
    }

    cout <<"--TEST func() moveright--" << endl;
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
            }
        }
    }

    cout <<"--TEST func() moveleft--" << endl;
    return newConfig;
};

//add expanded move to problem tree (just for creating a tree so ignore this for now)
Node* Problem::addMove(Node* head, vector<int> oldData, vector<int> newData) {
        Node* curr = head;
        while (curr != nullptr) {
            if(curr->data == oldData) {
                break;
            }
            curr = curr->next;
        }
        if (curr == nullptr) {
            return head;
        }
        Node* newNode = new Node(newData);
        newNode->next = curr->next;
        curr->next = newNode;
        return newNode;
    };

#endif //PROBLEM_CPP_