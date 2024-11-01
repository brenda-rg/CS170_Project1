#include <iostream>
#include <vector>
#include <queue>
#include "node.h"
#include "problem.cpp"
using namespace std;


class searchQ {
    public:
    void QTraverse(Problem, int); //
    void MTH(queue<Node*> travNode);
    void EDH(queue<Node*>);
    void UCS(queue<Node*>);
    vector<Node* > QToV;
    
    
    private:
    queue <Node*> searchQ;
    void sortQ(queue<Node*>);
       
};