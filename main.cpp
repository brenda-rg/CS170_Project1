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
using namespace std;

int main() {
    //default 8-puzzle positions
    //ignore this(for testing so far)
    vector<int> startConfig{1,2,0,4,5,3,7,8,6};
    cout << endl <<"If you have a configuration please input the configuration values separated by commas from left to right and row by row"
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
    p2.printMoves();
    cout << endl;
    cout << "testing..." << endl;
    return 0;
}