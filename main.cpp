//main file
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
    Problem p = Problem(startConfig);

    cout << endl <<"Welcome to XXX (change this to your student ID) 8 puzzle solver." << endl
    << "Type '1' to use a default puzzle, or '2' to enter your own puzzle." << endl;
    << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle." << endl;

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
    return 0;
}