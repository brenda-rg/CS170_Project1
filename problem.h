#ifndef PROBLEM_H_
#define PROBLEM_H_

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <list>
#include <string>
#include "node.cpp"
using namespace std;

class Problem {
    private:
        //Node* head;
        vector<int> defaultState = {1,2,0,4,5,3,7,8,6};
        void print(Node*);
        Node* addMove(Node* head, vector<int> pos, vector<int> newData); // might not need; just change to expand node and do a findnode check
        Node* findNode(Node *);

        //operations
        vector<int> moveup(vector<int>);
        vector<int> movedown(vector<int>);
        vector<int> moveright(vector<int>);
        vector<int> moveleft(vector<int>);

    public:
    Node *head;
        map<vector<int>, bool> visited;
        Problem();
        Problem(vector<int> init);
        vector<int> initialState;
        vector<int> goalState = {1,2,3,4,5,6,7,8,0};
        queue <Node*> expandNode(Node* oldNode);
        bool checksolution(vector<int>&);
        void printPath(Node*);
};

#endif //PROBLEM_H_