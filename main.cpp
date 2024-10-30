//main file
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
#include "search.cpp"
using namespace std;

int main() {
    //default 8-puzzle positions
    //ignore this(for testing so far)
    vector<int> startConfig{1,2,0,4,5,3,7,8,6};
    vector<int> row1;
    vector<int> row2;
    vector<int> row3;
    Problem p;
    int var;

    cout << endl <<"Welcome to XXX (change this to your student ID) 8 puzzle solver." << endl
    << "Type “1” to use a default puzzle, or “2” to enter your own puzzle." << endl;

    cin >> var;
    if (var == 2) {

        cout << "Enter your puzzle, use a zero to represent the blank" << endl
        << "Enter the first row, use space or tabs between numbers" << endl;
        for(int i = 0; i < 3; i++) {
            cin >> var;
            row1.push_back(var);
            startConfig.at(i) = var;
        }
        cout << endl << "Enter the second row, use space or tabs between numbers" << endl;
        for(int i = 0; i < 3; i++) {
            cin >> var;
            row2.push_back(var);
            startConfig.at(i+3) = var;
        }
        cout << endl << "Enter the third row, use space or tabs between numbers" << endl;
        for(int i = 0; i < 3; i++) {
            cin >> var;
            row3.push_back(var);
            startConfig.at(i+6) = var;
        }
        p = Problem(startConfig);
    }
    else {
        p = Problem();
    }
    // check if valid (ie: no repeats and values only from 0-9)
    //throw exception?
    searchQ search;

    cout << endl << "Enter your choice of algorithm (Please type the number of your choice)" << endl
        << "1. Uniform Cost Search" << endl
        << "2. A* with the Misplaced Tile heuristic." << endl
        << "3. A* with the Euclidean distance heuristic" << endl;
    cin >> var;
    while(true) {

        if(var == 1) {
            search.UCS(p);
            cout << "test1" << endl;
            break;
        }

        else if(var == 2) {
            cout << "test" << endl;
            break;
        }

        else if(var == 3) {
            cout << "test" << endl;
            break;
        }
        else {
            cout << "Choice is invalid, please input onf of the choices below" << endl;
            cout << endl << "Enter your choice of algorithm (Please type the number of your choice)" << endl
            << "1. Uniform Cost Search" << endl
            << "2. A* with the Misplaced Tile heuristic." << endl
            << "3. A* with the Euclidean distance heuristic" << endl;
            cin >> var;
            
        }
    }
/* 

    << "If you have a configuration please input the configuration values separated by commas from left to right and row by row"
    << endl << "Input the blank space as 0.\n\n" 
    << "For example an for an 8 puzzle that looks like this: \n\n2  4  6" << endl 
    << "5  7  8" << endl
    << "1  3  blank" << endl <<endl
    << "You would input: \n 2, 4, 6, 5 ,7, 8, 1, 3, 0"
    << endl << endl << "If you want to use the default configuration please input -1." << endl << endl;
    Problem p = Problem();
    cout << "Printing default state moves:" << endl;
    p.printMoves();
    cout << endl;

    cout << "Printing new moves:" << endl;
    p.expandNode();
    p.printMoves();
    cout << endl;

    cout << "Printing input state moves:" << endl;
    Problem p2 = Problem(startConfig);
    p2.printMoves();
    cout << endl;
    cout << "Printing new moves:" << endl;
    p2.expandNode();
    p2.printMoves(); */
    cout << endl;
    cout << "testing..." << endl;
    return 0;
}