#ifndef NODE_H_
#define NODE_H_

// node data structure file
#include <iostream>
#include <vector>
#include <string>
using namespace std;


//basic node struct we can change as we implement

struct Node {
    vector<int> data; //stores current state of 8 puzzle
    //costs
    int gn =0;
    int hn = 0;
    int fn = 0;
    Node* parent = nullptr; //parent of current node
    vector<Node*> children; //children of current state (ie. valid operations after expanding)

    //
    Node();
    //Node(Node*);
    //create a node for the current state of the 8 puzzle, parent unknown
    //should only be used for start configuration
    Node(vector<int> new_data);

    //create a node for the current state of the 8 puzzle, after expanding parent node
    Node(vector<int> new_data, Node* oldData);

    //print the node data in 8 puzzle format where 0 represents the blank
    void printV();

    //calculate the misplaced tile heuristic
    int misplacedH();

    //calculate the euclidean distance heuristic
    double euclideanH();

    double calculateDist(int, int);
};


#endif //NODE_H_