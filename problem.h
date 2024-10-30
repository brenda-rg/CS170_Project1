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
        vector<int> defaultState = {0,1,2,4,5,3,7,8,6};
        //operations
        vector<int> moveup(vector<int>);
        vector<int> movedown(vector<int>);
        vector<int> moveright(vector<int>);
        vector<int> moveleft(vector<int>);

    public:
        Problem();
        Problem(vector<int> init);
        map<vector<int>, int> visited;
        void outMap();
        vector<int> goalState = {1,2,3,4,5,6,7,8,0};
        //functions
        queue <Node*> expandNode(Node* oldNode, int choice);
        void printPath(Node*);
        void printVect(vector<int>);
        Node* getHead();
};

#endif //PROBLEM_H_