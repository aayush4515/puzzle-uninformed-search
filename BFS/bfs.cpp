#include "bfs.h"
#include "../PuzzleMove.h"
#include "../PuzzleState.h"
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// void bfs (PuzzleState startState, PuzzleState goalState) {
//     PuzzleState currState;                                // stores the current state
//     queue<PuzzleState> q;                                 // declare a queue that stores the puzzle states for bfs
//     vector<PuzzleState> visited;                          // keeps track of the visited states

//     q.push(startState);
//     visited.push_back(startState);

//     int i = 0;
//     while (!q.empty()) {
//         cout << "Checking state: " << i << endl;
//         i++;

//         currState = q.front();                            // store the current state
//         q.pop();

//         if (currState == goalState) {
//             cout << "Goal Found!!!" << endl;
//             cout << "Number of ndoes expanded: " << i << endl;
//             return;
//         }

//         // generate possible next states and store it in a vector
//         vector<PuzzleState> nextStates = {currState.moveBlankDown(), currState.moveBlankLeft(), currState.moveBlankRight(), currState.moveBlankUp()};

//         // check if the next state is already in the queue, if not, push it to the queue and the set of visited states
//         for (const auto& nextState : nextStates) {
//             if (find(visited.begin(), visited.end(), nextState) == visited.end()) {
//                 q.push(nextState);
//                 visited.push_back(nextState);
//             }
//         }
//     }
// }

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



void bfs (PuzzleState startState, PuzzleState goalState) {
    if (startState == goalState) {
        cout << "\n*** Solution Found Immediately: start state is the goal state. ***" << endl;
        return;
    }
    queue<PuzzleMove*> q;
    vector<PuzzleState> visited;

    visited.push_back(startState);
    PuzzleMove* rootMove = new PuzzleMove(startState, nullptr, nullMove);
    q.push(rootMove);

    int numNodesExpanded = 0;
    while (!q.empty()) {
        PuzzleMove* currMove = q.front();
        PuzzleState currState = currMove->getState();
        q.pop();

        if (currState == goalState) {
            // print path and the number of nodes expanded
            int pathLength = printPath(currMove);
            cout << "Number of ndoes expanded: " << numNodesExpanded << endl;
            cout << "Path Length to Goal: " << pathLength << endl;
            return;
        }

        numNodesExpanded++;

        // stores the next possible states/moves
        vector<pair<PuzzleState, MoveType>> nextMoves = {{currState.moveBlankDown(), MoveType::down},
                                                        {currState.moveBlankLeft(), MoveType::left},
                                                        {currState.moveBlankRight(), MoveType::right},
                                                        {currState.moveBlankUp(), MoveType::up}};

        // check if next states are alreadt visited, if not, add them to the queue to be viisted
        for (const auto& next : nextMoves) {
            PuzzleState nextState = next.first;
            MoveType nextMove = next.second;

            if (find(visited.begin(), visited.end(), nextState) == visited.end()) {
                PuzzleMove* newMove = new PuzzleMove(nextState, currMove, nextMove);
                q.push(newMove);
                visited.push_back(nextState);
            }
        }


    }

}


