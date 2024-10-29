#include <iostream>
#include <vector>
#include <queue>
#include "search.h"
using namespace std;

//take into paramter expand function call to get queue
void searchQ::QTraverse(queue<Node*> travNode) {

    //until queue is empty, push travNode into searchQ and pop head of travNode
    while (!travNode.empty()) {
        searchQ.push(travNode.front());
        travNode.pop();
    }
}

void searchQ::UCS(Problem goal) {
    //check if empty and pop from search q
    //else pop
    //while empty or find solution
    searchQ.push(goal.head);
    if (searchQ.empty()) {
        cout << "failure";
        exit(0);
    }
    else {
        while(!searchQ.empty()) {
            if (searchQ.front()->data == goal.goalState) {
                cout << "goal";
                exit(0);
            }
            else {
                 QTraverse(goal.expandNode(goal.head));
                searchQ.pop();
            }
        }
    }
}