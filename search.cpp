#include <iostream>
#include <vector>
#include <queue>
#include "search.h"
#include "node.cpp"
using namespace std;

//take into paramter expand function call to get queue
void searchQ::UCS(queue<Node*> travNode, int choice) {

    //until queue is empty, push travNode into searchQ and pop head of travNode
    cout << "Adding " << travNode.size() << " states" << endl;
    while (!travNode.empty()) {
        searchQ.push(travNode.front());
        travNode.pop();
    }
};

void searchQ::MTH(queue<Node*> travNode, int choice) {
    UCS(travNode, 1);
    sortQ(searchQ);
};

void searchQ::sortQ(queue<Node*> &q)  
{ 
    for (int i = 1; i <= q.size(); i++) 
    { 
        int min_index = minIndex(q, q.size() - i); 
        insertMinToRear(q, min_index); 
    } 
};

int searchQ::minIndex(queue<Node*> &q, int sortedIndex) 
{ 
    int min_index = -1; 
    Node* min_val = q.front(); 
    int n = q.size(); 
    for (int i=0; i<n; i++) 
    { 
        Node* curr = q.front(); 
        q.pop();  // This is dequeue() in C++ STL 
  
        // we add the condition i <= sortedIndex 
        // because we don't want to traverse 
        // on the sorted part of the queue, 
        // which is the right part. 
        if (curr->fn <= min_val->fn && i <= sortedIndex) 
        { 
            min_index = i; 
            min_val = curr; 
        } 
        q.push(curr);  // This is enqueue() in  
                       // C++ STL 
    } 
    return min_index; 
} 
  
// Moves given minimum element to rear of  
// queue 
void searchQ::insertMinToRear(queue<Node*> &q, int min_index) 
{ 
    Node* min_val; 
    int n = q.size(); 
    for (int i = 0; i < n; i++) 
    { 
        Node* curr = q.front(); 
        q.pop(); 
        if (i != min_index) 
            q.push(curr); 
        else
            min_val = curr; 
    } 
    q.push(min_val); 
} 

void searchQ::QTraverse(Problem goal, int choice) {
    //check if empty and pop from search q
    //else pop
    //while empty or find solution
    searchQ.push(goal.getHead());
    do {
        Node* best = searchQ.front();
        //Node* best = searchQ.top();
        if (best->data == goal.goalState) {
            cout << "goal" << endl;
            cout << "The best path with g(n) = " << best->gn <<endl;
            cout << "total nodes visited: " << goal.visited.size() << endl;
            //goal.outMap();
            goal.printPath(best);
            exit(0);
        }
        else {
            searchQ.pop();
            cout << "The best state to expand with g(n) = " << best->gn << " and h(n) = "<< best->hn << " is:" << endl;
            best->printV();
            cout << "Expanding..." << endl;
            cout << "current queue size: "<< searchQ.size() << endl;
                cout << "-----------------" << endl;
            if(choice == 1) {
                UCS(goal.expandNode(best,1), 1);
            }
            else if(choice == 2) {
                MTH(goal.expandNode(best,2), choice);
            }
            else {
                UCS(goal.expandNode(best,3), choice);
            }
        }
    }
    while(!searchQ.empty());
    if (searchQ.empty()) {
        cout << "failure";
        exit(0);
    }
};