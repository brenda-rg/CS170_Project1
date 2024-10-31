#include <iostream>
#include <vector>
#include <queue>
#include "search.h"
#include "node.cpp"
using namespace std;

//take into paramter expand function call to get queue
void searchQ::UCS(queue<Node*> travNode) {

    //until queue is empty, push travNode into searchQ and pop head of travNode
    cout << "Adding " << travNode.size() << " states" << endl;
    while (!travNode.empty()) {
        searchQ.push(travNode.front());
        travNode.pop();
    }
}

void searchQ::QTraverse(Problem goal, int choice) {
    //check if empty and pop from search q
    //else pop
    //while empty or find solution
    //QTraverse(goal.expandNode(goal.head));
    searchQ.push(goal.getHead());
    do {
        if (searchQ.front()->data == goal.goalState) {
            cout << "goal" << endl;
            cout << "The best path with g(n) = " << searchQ.front()->gn <<endl;
            goal.printPath(searchQ.front());
            exit(0);
        }
        else {
            cout << "The best state to expand with g(n) = " << searchQ.front()->gn << " is:" << endl;
            searchQ.front()->printV();
            cout << "Expanding..." << endl;
            if (choice == 1) {
                UCS(goal.expandNode(searchQ.front()));
            }
            if (choice == 2) {
                MTH(goal.expandNode(searchQ.front()));
            }
        
            searchQ.pop();
        }
    }
    while(!searchQ.empty());
    if (searchQ.empty()) {
        cout << "failure";
        exit(0);
    }
}

void searchQ::MTH(queue<Node*> travNode) {

    UCS(travNode);
    queue<Node*> temp = searchQ;
    Node* tempNode = searchQ.front();
    Node* hold;
    temp.pop();

    while (!temp.empty()) {
        while (!temp.empty()) {
            if (tempNode->hn > temp.front()->hn) {
                hold = tempNode;
                tempNode = temp.front();
                temp.front() = hold;
            }
            temp.pop();
        }
        // store heuristic value
        travNode.front()->misplacedH();
        // push this value to front of searchQ
        searchQ.push(travNode.front());
        //pop travNode front value
        travNode.pop();
    }
}