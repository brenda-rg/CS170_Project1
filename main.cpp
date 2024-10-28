#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <list>
#include <cstring>
#include <math.h>
#include "problem.cpp"
using namespace std;

int main() {
    //default 8-puzzle positions
    //ignore this(for testing so far)
    vector<int> startConfig{1,2,0,4,5,3,7,8,6};
    vector<int> row1;
    vector<int> row2;
    vector<int> row3;
    int var;
    int integer;
    Problem p = Problem(startConfig);

    cout << endl <<"Welcome to XXX (change this to your student ID) 8 puzzle solver." << endl
    << "Type “1” to use a default puzzle, or “2” to enter your own puzzle." << endl;
    cin >> var;
    if (var == 2) {

        cout << "Enter your puzzle, use a zero to represent the blank" << endl
        << "Enter the first row, use space or tabs between numbers" << endl;
        for(int i = 0; i < 3; i++) {
            cin >> var;
            row1.push_back(var);
        }
        cout << endl << "Enter the second row, use space or tabs between numbers" << endl;
        for(int i = 0; i < 3; i++) {
            cin >> var;
            row1.push_back(var);
        }
        cout << endl << "Enter the third row, use space or tabs between numbers" << endl;
        for(int i = 0; i < 3; i++) {
            cin >> var;
            row1.push_back(var);
        }
    }
    // check if valid (ie: no repeats and values only from 0-9)
    //throw exception?



    cout << endl << "Enter your choice of algorithm (Please type the number of your choice)" << endl
    << "1. Uniform Cost Search" << endl
    << "2. A* with the Misplaced Tile heuristic." << endl
    << "3. A* with the Euclidean distance heuristic" << endl;

    cin >> integer;
    if (integer = 1){
        //run unifrom cost seach 
        Problem()
    }
    if (integer = 2)
    {
        // run A* with misplaced Tile
    }
    else {
        //run A* with euclidean distance 
    }

    cout << endl;
    cout << "testing..." << endl;
    return 0;
}