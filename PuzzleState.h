 /*
     * This class describes what a PuzzleState is.
	 * The blank_position is for decreasing the time
	 * to check what tile operator is applicable
 */
#ifndef _PUZZLESTATE_
#define _PUZZLESTATE_
#include <iostream>
#include <vector>

using namespace std;

class PuzzleState
{
  public:
	 // default constructor
	 PuzzleState() { }

	 //constructor
	 PuzzleState(int n, int m) {
		 tiles.resize(n*m);
		 rows = n;
		 cols = m;
	}
	 // destructor
	 ~PuzzleState() { }

	 // copy constructor
	 PuzzleState( const PuzzleState & rhs )
            : rows(rhs.rows), cols(rhs.cols),
			  tiles(rhs.tiles),
			  blank_position_row(rhs.blank_position_row),
			  blank_position_col(rhs.blank_position_col)
			  { }

	 bool operator==(const PuzzleState & rhs) const;
	 bool operator!=(const PuzzleState & rhs) const;
	 const PuzzleState & operator=( const PuzzleState & rhs ); //assignment op
	 bool isNullState(){ return rows==0; }

	 bool canMoveUp();
	 bool canMoveDown();
	 bool canMoveLeft();
	 bool canMoveRight();
	 PuzzleState moveBlankUp();
	 PuzzleState moveBlankDown();
	 PuzzleState moveBlankLeft();
	 PuzzleState moveBlankRight();

	 void read( istream & in );
	 void print( ostream & out);

	// test prints

	//  void testPrint() {
	// 	// print tiles, blank position, rows and cols from the input state
    // 	cout << "Tiles: ";
    // 	for (int i = 0; i < tiles.size(); i++) {
    //     cout << tiles.at(i) << " ";
    // 	}
    // 	cout << endl;

	// 	cout << "The number of rows is: " << rows << endl;
	// 	cout << "The number of columns is: " << cols << endl;
	// 	cout << "The row of blank tile is: " << blank_position_row << endl;
	// 	cout << "The column of blank tile is: " << blank_position_col << endl;
	//  }

     static PuzzleState  NullState;
  private:
	  int rows;
	  int cols;
      vector<int> tiles;
      int blank_position_row;
	  int blank_position_col;
};
istream & operator>>( istream &  in, PuzzleState & rhs );
ostream & operator<<( ostream & out, PuzzleState & rhs );
#endif
