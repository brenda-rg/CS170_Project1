#include <iostream>
#include <vector>
#include <queue>
#include "search.h"
#include "node.cpp"
using namespace std;

//take into paramter expand function call to get queue
void searchQ::QTraverse(queue<Node*> travNode) {

    //until queue is empty, push travNode into searchQ and pop head of travNode
    cout << "Adding " << travNode.size() << " states" << endl;
    while (!travNode.empty()) {
        searchQ.push(travNode.front());
        travNode.pop();
    }
}

void searchQ::UCS(Problem goal) {
    //check if empty and pop from search q
    //else pop
    //while empty or find solution
    //QTraverse(goal.expandNode(goal.head));
    searchQ.push(goal.getHead());
    do {
        if (searchQ.top()->data == goal.goalState) {
            cout << "goal" << endl;
            cout << "The best path with g(n) = " << searchQ.top()->gn <<endl;
            goal.printPath(searchQ.top());
            exit(0);
        }
        else {
            cout << "The best state to expand with g(n) = " << searchQ.top()->gn << " is:" << endl;
            searchQ.top()->printV();
            cout << "Expanding..." << endl;
            QTraverse(goal.expandNode(searchQ.top()));
            searchQ.pop();
        }
    }
    while(!searchQ.empty());
    if (searchQ.empty()) {
        cout << "failure";
        exit(0);
    }
}