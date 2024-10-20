#ifndef PROBLEM_CPP_
#define PROBLEM_CPP_

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <string>
#include "node.h"
#include "problem.h"
using namespace std;

Problem::Problem(){};

//0 is the blank space

/* for reference
    vector index =
    { 0  1  2
      3  4  5
      6  7  8 }

    mod values:
    { 0  1  2
      0  1  2
      0  1  2 }
    
    */
   

vector<int> moveup(vector<int> currPos) {
    vector<int> newConfig = currPos;
    for(int i = 0; i < 9; i++){
        if(newConfig.at(i) == 0){
            //if below the first row then swap the blank and the value above
            if(i > 2) {
                int temp = newConfig.at(i-3);
                newConfig.at(i-3) = 0;
                newConfig.at(i) = temp;
            }
        }
    }

    cout <<"--TEST func() moveup--" << endl;
    return newConfig;
};

vector<int> movedown(vector<int> currPos){
    vector<int> newConfig = currPos;
    for(int i = 0; i < 9; i++){
        if(newConfig.at(i) == 0){
            //if below the first row then swap the blank and the value above
            if(i < 6) {
                int temp = newConfig.at(i+3);
                newConfig.at(i+3) = 0;
                newConfig.at(i) = temp;
            }
        }
    }

    cout <<"--TEST func() movedown--" << endl;
    return newConfig;
};


vector<int> moveright(vector<int> currPos) {
    vector<int> newConfig = currPos;
    for(int i = 0; i < 9; i++){
        if(newConfig.at(i) == 0){
            //if below the first row then swap the blank and the value above
            if(i%3 < 2) {
                int temp = newConfig.at(i+1);
                newConfig.at(i+1) = 0;
                newConfig.at(i) = temp;
            }
        }
    }

    cout <<"--TEST func() moveright--" << endl;
    return newConfig;
};

vector<int> moveleft(vector<int> currPos) {
    vector<int> newConfig = currPos;
    for(int i = 0; i < 9; i++){
        if(newConfig.at(i) == 0){
            //if below the first row then swap the blank and the value above
            if(i%3 > 0) {
                int temp = newConfig.at(i-1);
                newConfig.at(i-1) = 0;
                newConfig.at(i) = temp;
            }
        }
    }

    cout <<"--TEST func() moveleft--" << endl;
    return newConfig;
};

#endif PROBLEM_CPP_