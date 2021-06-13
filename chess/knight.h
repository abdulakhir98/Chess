#pragma once
#include "Piece.h"

class knight :public piece
{
public:

	bool move(int &prev_row, int &prev_col, int &next_row, int &next_col, piece *cp[9][9]);


};
bool knight::move(int &prev_row, int &prev_col, int &next_row, int &next_col, piece *cp[9][9])
{
	if (((abs(prev_row - next_row) == 2) && (abs(prev_col - next_col) == 1)) || ((abs(prev_row - next_row) == 1) && (abs(prev_col - next_col) == 2)))
	{
		/*cp[next_row][next_col] = cp[prev_row][prev_col];
		cp[prev_row][prev_col] = nullptr;*/
		return true;
	}
	return false;
}

