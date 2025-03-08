#ifndef _BFS_
#define _BFS_

#include "../PuzzleState.h"
#include "../PuzzleMove.h"

int printPath(PuzzleMove* move);
void bfs (PuzzleState startState, PuzzleState goalState);

#endif