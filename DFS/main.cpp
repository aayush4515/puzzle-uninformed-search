#include <iostream>
#include "../PuzzleState.h"
#include "../PuzzleMove.h"
#include "dfs.h"
#include <vector>
using namespace std;

int main() {

    // Project Description
    cout << "*** P01 Puzzle Uninformed Search - BFS ***" << endl;
    cout << "< ======================================================== >" << endl << endl;

    // Input # of rows and columns
    int numRowsCols = 0;
    cout << "Enter number of rows and columns: ";
    cin >> numRowsCols;
    cout << endl;

    // create a new start state and goal state
    PuzzleState startState(numRowsCols, numRowsCols);
    PuzzleState goalState(numRowsCols, numRowsCols);

    cout << "Enter Start State row by row:" << endl;
    cin >> startState;

    cout << "\nEnter Goal State row by row:" << endl;
    cin >> goalState;

    // // print the puzzle state for testing
    // cout << startState << endl << endl;
    // cout << goalState << endl;

    // // move up and print for testing
    // PuzzleState newState = startState.moveBlankUp();
    // cout << "New state:" << endl << endl;
    // cout << newState << endl;


    dfs(startState, goalState);


    return 0;
}