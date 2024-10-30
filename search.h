#include <iostream>
#include <vector>
#include <queue>
#include "node.h"
#include "problem.cpp"
using namespace std;

struct node_cmp
{
   bool operator()( const Node* a, const Node* b ) const 
   {
    return a->fn < b->fn;
   }
};

class searchQ {
    public:
    void UCS(Problem);
    void MTH(Problem);
    void EDH(Problem);
    
    private:
        priority_queue<Node*, vector<Node*>, node_cmp> searchQ;
        void QTraverse(queue<Node*>);
        
        
};
