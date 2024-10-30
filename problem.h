#ifndef PROBLEM_H_
#define PROBLEM_H_

#include <queue>
#include <map>
#include <stack>
#include "node.cpp"
using namespace std;

class Problem {
    private:
        Node* head;
        vector<int> defaultState = {1,2,0,4,5,3,7,8,6};
        map<vector<int>, bool> visited;
        //operations
        //Node* head;
        vector<int> defaultState = {3,2,1,4,8,7,6,5,0};
        void print();
        Node* addMove(Node* head, vector<int> pos, vector<int> newData);
        vector<int> moveup(vector<int>);
        vector<int> movedown(vector<int>);
        vector<int> moveright(vector<int>);
        vector<int> moveleft(vector<int>);

    public:
        Node* head;
        Problem();
        Problem(vector<int> init);
        vector<int> goalState = {1,2,3,4,5,6,7,8,0};
        //functions
        queue <Node*> expandNode(Node* oldNode);
        void printPath(Node*);
        Node* getHead();
};

#endif //PROBLEM_H_