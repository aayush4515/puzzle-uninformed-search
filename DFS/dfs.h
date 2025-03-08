#ifndef _DFS_
#define _DFS_

#include "../PuzzleState.h"
#include "../PuzzleMove.h"

int printPath(PuzzleMove* move);
void dfs (PuzzleState startState, PuzzleState goalState);

#endif