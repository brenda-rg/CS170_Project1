#ifndef PROBLEM_H_
#define PROBLEM_H_

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <string>
#include "node.h"
using namespace std;

class Problem {
    public:
        Problem();
        vector<int> initialState;
        vector<int> goalState = {1,2,3,4,5,6,7,8,0};

    private:
        vector<int> moveup(vector<int>, int);
        vector<int> movedown(vector<int>, int);
        vector<int> moveright(vector<int>, int);
        vector<int> moveleft(vector<int>, int);
};

#endif PROBLEM_H_