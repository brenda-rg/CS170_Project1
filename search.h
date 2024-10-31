#include <iostream>
#include <vector>
#include <queue>
#include "node.h"
#include "problem.cpp"
using namespace std;


class searchQ {
    public:
    void QTraverse(Problem, int);
    void MTH(queue<Node*> travNode);
    void EDH(Problem);
    void UCS(queue<Node*>);
    
    private:
    queue <Node*> searchQ;
       
};
