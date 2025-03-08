#include "dfs.h"
#include "../PuzzleMove.h"
#include "../PuzzleState.h"
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



int printPath(PuzzleMove* move) {
    vector<PuzzleMove*> path;               // stores the path from current move upto the root move
    // store the path
    while (move != nullptr) {
        path.push_back(move);
        move = move->getParent();
    }

    // reverse the path for printing
    reverse(path.begin(), path.end());

    // print the path
    cout << "\n*** Solution Found ***" << endl;
    for (const auto& node : path) {
        int i = node->getMoveName();
        string moveName = "";
        switch (i) {
            case 0:
                moveName = "down";
                break;
            case 1:
                moveName = "left";
                break;
            case 2:
                moveName = "right";
                break;
            case 3:
                moveName = "up";
                break;
            default:
                break;
        }
        cout << moveName << endl << endl;
        cout << node->getState() << endl;
    }
    return path.size() - 1;
}

void dfs (PuzzleState startState, PuzzleState goalState) {
    if (startState == goalState) {
        cout << "\n*** Solution Found Immediately: start state is the goal state. ***" << endl;
        return;
    }

    // initialize an stack
    stack<PuzzleMove*> s;
    vector<PuzzleState> visited;

    visited.push_back(startState);
    PuzzleMove* rootMove = new PuzzleMove(startState, nullptr, nullMove);
    //s.push(rootMove);

    PuzzleMove* currMove = rootMove;
    PuzzleState currState = currMove->getState();

    int numNodesExpanded = 0;
    while (true) {
        cout << "Checking State: " << numNodesExpanded << endl;
        numNodesExpanded++;
        if (currState == goalState) {
            // print path and the number of nodes expanded
            int pathLength = printPath(currMove);
            cout << "Number of ndoes expanded: " << numNodesExpanded << endl;
            cout << "Path Length to Goal: " << pathLength << endl;
            return;
        }

        // stores the next possible states/moves
        vector<pair<PuzzleState, MoveType>> nextMoves = {{currState.moveBlankDown(), MoveType::down},
                                                        {currState.moveBlankLeft(), MoveType::left},
                                                        {currState.moveBlankRight(), MoveType::right},
                                                        {currState.moveBlankUp(), MoveType::up}};

        if (nextMoves.size() == 0) {
            currMove = s.top();
            currState = currMove->getState();
            s.pop();
            continue;
        }

        for (const auto& next : nextMoves) {
            PuzzleState nextState = next.first;
            MoveType nextMove = next.second;

            if (find(visited.begin(), visited.end(), nextState) == visited.end()) {
                s.push(currMove);
                PuzzleMove* newMove = new PuzzleMove(nextState, currMove, nextMove);
                currMove = newMove;
                currState = nextState;
                visited.push_back(nextState);
                break;
            }
        }

    }

}




