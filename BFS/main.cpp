#include <iostream>
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

    // 2D arrays to store start state (row-by-row) amd end state (row-by-row), initialized to all 0s; both matrices are N*N
    vector<vector<int>> startState(numRowsCols, vector<int>(numRowsCols));
    vector<vector<int>> goalState(numRowsCols, vector<int>(numRowsCols));

    // user-input for start state
    cout << "Enter Start State row by row:" << endl;
    for (int i = 0; i < numRowsCols; i++) {
        for (int j = 0; j < numRowsCols; j++) {
            cin >> startState[i][j];
        }
    }
    //user-input for goal state
    cout << "Enter Goal State row by row:" << endl;
    for (int i = 0; i < numRowsCols; i++) {
        for (int j = 0; j < numRowsCols; j++) {
            cin >> goalState[i][j];
        }
    }

    return 0;
}