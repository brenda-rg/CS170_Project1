#ifndef PROBLEM_H_
#define PROBLEM_H_

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <string>
#include "node.cpp"
using namespace std;

class Problem {
    private:
        Node* head;
        vector<int> defaultState = {3,2,1,4,8,7,6,5,0};
        void print();
        Node* addMove(Node* head, vector<int> pos, vector<int> newData);
        vector<int> moveup(vector<int>);
        vector<int> movedown(vector<int>);
        vector<int> moveright(vector<int>);
        vector<int> moveleft(vector<int>);

    public:
        Problem();
        Problem(vector<int> init);
        vector<int> initialState;
        vector<int> goalState = {1,2,3,4,5,6,7,8,0};
        queue <Node*> expandNode();
        bool checksolution(vector<int>&);
        void printMoves();
};

#endif //PROBLEM_H_