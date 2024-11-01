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
    //QTraverse(goal.expandNode(goal.head));
    if (choice == 2){
     goal.getHead()->hn = goal.getHead()->misplacedH();
    }
    if (choice == 3){
        goal.getHead()->hn = goal.getHead()->euclideanH();
    }
    searchQ.push(goal.getHead());
    
    do {
       Node* newnode = searchQ.front();
       

        if (newnode->data == goal.goalState) {
            newnode->printV();
            cout << "GOAL!!!" << endl
            << "Number of nodes expanded: " << numExpanded << endl
            << "Number of nodes in queue: " << searchQ.size() << endl;
            cout << "The best path with g(n) = " << newnode->gn
            << " and h(n) = " << newnode->hn << endl;
            goal.printPath(newnode);
            exit(0);
        }
        else {
            searchQ.pop();
            cout << "The best state to expand with g(n) = " << newnode->gn <<  " and h(n) = " <<  newnode->hn << " is:" << endl;
            cout << "The best state to expand with f(n) = " << newnode->fn << endl;
            newnode->printV();
            cout << "Expanding..." << endl;
            numExpanded +=1;
            if (choice == 1) {
                UCS(goal.expandNode(newnode,1));
            }
            if (choice == 2) {
                cout << "The misplaced tiles h(n) = " << newnode->hn << endl;
                MTH(goal.expandNode(newnode,2));
               
            }
            if (choice == 3) {
                cout << "The euclidean distance h(n) = " << newnode->hn << endl;
                EDH(goal.expandNode(newnode,3));
            }
            
        }
    }
    while(!searchQ.empty());
    if (searchQ.empty()) {
        cout << "failure";
        exit(0);
    }
}

struct Compare{
    bool operator()(Node* a, Node* b){
    return a->fn > b->fn;
}
};

void searchQ::MTH(queue<Node*>travNode){
   // priority_queue<Node*> prior_q;
    //vector < Node*> prior_v;
    priority_queue<Node*, vector<Node*> , Compare> prior_q;
    vector < Node*> prior_v;
    while (!travNode.empty()) {
        searchQ.push(travNode.front());
        travNode.pop();
    }
while(!searchQ.empty()) {

    Node* node = searchQ.front();
    //searchQ.push(travNode.front());
    //node->hn = node->misplacedH();
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
    //UCS(travNode);
    priority_queue<Node*, vector<Node*> , Compare> prior_q;
    vector < Node*> prior_v;
     while (!travNode.empty()) {
        searchQ.push(travNode.front());
        travNode.pop();
    }
    while(!searchQ.empty()) {
        Node* node = searchQ.front();
            //node->hn = node->euclideanH();
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