#include <iostream>
#include <vector>
#include <queue>
#include "node.h"
#include "problem.cpp"
using namespace std;

class searchQ {
    public:
    void UCS(Problem);

    private:
        queue<Node*> searchQ;
        void QTraverse(queue<Node*>);
        
        
};
