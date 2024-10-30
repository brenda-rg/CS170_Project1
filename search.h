#include <iostream>
#include <vector>
#include <queue>
#include "node.h"
#include "problem.cpp"
using namespace std;

//used to designate the priority for the prio_queue

struct comp_nod {
    bool operator() (const Node* a, const Node* b) {
        return a->fn > b->fn;
    }
};

class searchQ {
    public:
    void QTraverse(Problem, int);
    
    private:
        //priority_queue<Node*, vector<Node*>, comp_nod> searchQ;
        queue<Node*> searchQ;
        void UCS(queue<Node*>, int choice);
        void MTH(queue<Node*>, int choice);
        void EDH(queue<Node*>, int choice);
        void sortQ(queue<Node*> &);
        int minIndex(queue<Node*> &q, int sortedIndex); 
        void insertMinToRear(queue<Node*> &q, int min_index); 
        
        
};
