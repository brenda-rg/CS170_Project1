//main file
#include <iostream>
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
    int integer;
    searchQ searchnode;
    p = Problem(startConfig);

    cout << endl <<"Welcome to the 8 puzzle solver." << endl
    << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle." << endl;

    cin >> var;
    if (var == 2) {

        cout << "Enter your puzzle, use a zero to represent the blank" << endl
        << "Enter the first row, use space or tabs between numbers  \t";
        for(int i = 0; i < 3; i++) {
            cin >> var;
            row1.push_back(var);
            startConfig.at(i) = var;
        }
        cout << endl << "Enter the second row, use space or tabs between numbers  \t";
        for(int i = 0; i < 3; i++) {
            cin >> var;
            row2.push_back(var);
            startConfig.at(i+3) = var;
        }
        cout << endl << "Enter the third row, use space or tabs between numbers  \t";
        for(int i = 0; i < 3; i++) {
            cin >> var;
            row3.push_back(var);
            startConfig.at(i+6) = var;
        }
        cout << endl;
        p = Problem(startConfig);
    }
    else {
        p = Problem();
    }
    
    searchQ search;

    while(true) {
        cout << endl << "Enter your choice of algorithm (Please type the number of your choice)" << endl
        << "1. Uniform Cost Search" << endl
        << "2. A* with the Misplaced Tile heuristic." << endl
        << "3. A* with the Euclidean distance heuristic" << endl;
        cin >> var;

        if(var == 1) {
            search.QTraverse(p, 1);
            break;
        }

        else if(var == 2) {
            search.QTraverse(p, 2);
            break;
        }

        else if(var == 3) {
            search.QTraverse(p, 3);
            break;
        }
        else {
            cout << "Choice is invalid, please input one of the choices below" << endl;
        }
    }
    return 0;
}
