#include <iostream>
#include <vector>
#include <queue>
#include "search.h"
#include "node.cpp"
using namespace std;

//take into paramter expand function call to get queue
void searchQ::UCS(queue<Node*> travNode) {

    //until queue is empty, push travNode into searchQ and pop head of travNode
    while (!travNode.empty()) {
        searchQ.push(travNode.front());
        travNode.pop();
    }
}

void searchQ::QTraverse(Problem goal, int choice) {
    int numExpanded = 0;
    //check if empty and pop from search q
    //else pop
    //while empty or find solution
    if (choice == 2){
     goal.getHead()->hn = goal.getHead()->misplacedH();
    }
    if (choice == 3){
        goal.getHead()->hn = goal.getHead()->euclideanH();
    }
    searchQ.push(goal.getHead());
    int maxQ =1;

    Node* lastnode = searchQ.front();
    
    do {
       Node* newnode = searchQ.front();
       

        if (newnode->data == goal.goalState) {
            newnode->printV();
            cout << "GOAL!!!" << endl
            << "Number of nodes expanded: " << numExpanded << endl
            << "max Number of nodes in queue: " << maxQ << endl;
            cout << "The best path with g(n) = " << newnode->gn
            << " and h(n) = " << newnode->hn << endl;
            goal.printPath(newnode);
            exit(0);
        }
        else {
            searchQ.pop();
            cout << "The best state to expand with g(n) = " << newnode->gn <<  " and h(n) = " <<  newnode->hn << " is:" << endl;
            newnode->printV();
            cout << "Expanding..." << endl << endl;
            numExpanded +=1;
            if (choice == 1) {
                UCS(goal.expandNode(newnode,1));
            }
            if (choice == 2) {
                MTH(goal.expandNode(newnode,2));
               
            }
            if (choice == 3) {
                EDH(goal.expandNode(newnode,3));
            }
            
        }
        lastnode = searchQ.front();
        if(maxQ < searchQ.size()) maxQ = searchQ.size();
    }
    while(!searchQ.empty());
    if (searchQ.empty()) {
        cout << "failure" << endl
        << "Number of nodes expanded: " << numExpanded << endl
        << "Max number of nodes in queue: " << maxQ << endl;
        cout << "The best path with g(n) = " << lastnode->gn
        << " and h(n) = " << lastnode->hn << endl;
        exit(0);
    }
}

struct Compare{
    bool operator()(Node* a, Node* b){
    return a->fn > b->fn;
}
};

void searchQ::MTH(queue<Node*>travNode){
    priority_queue<Node*, vector<Node*> , Compare> prior_q;
    vector < Node*> prior_v;
    while (!travNode.empty()) {
        searchQ.push(travNode.front());
        travNode.pop();
    }
    while(!searchQ.empty()) {
        Node* node = searchQ.front();
        node->fn = node ->gn + node->hn ;
        //priority queue would be pushed 
        prior_q.push(node);
        searchQ.pop();
    }
    // while the prior queue is not empty we can take the prior queue and we replace it with the prior 
    while(!prior_q.empty()){
        searchQ.push(prior_q.top());
        prior_q.pop();
    }
}

void searchQ::EDH(queue<Node*>travNode){
    priority_queue<Node*, vector<Node*> , Compare> prior_q;
    vector < Node*> prior_v;
     while (!travNode.empty()) {
        searchQ.push(travNode.front());
        travNode.pop();
    }
    while(!searchQ.empty()) {
        Node* node = searchQ.front();
        node->fn = node ->gn + node->hn ;
        //priority queue would be pushed 
        prior_q.push(node);
        searchQ.pop();
    }
    // while the prior queue is not empty we can take the prior queue and we replace it with the prior 
    while(!prior_q.empty()){
        searchQ.push(prior_q.top());
        prior_q.pop();
    }
}