#pragma once
#include "Bishop.h"
#include "castle.h"


class queen :public piece
{
public:
	bool move(int &prev_row, int &prev_col, int &next_row, int &next_col, piece *cp[9][9]);

};

bool queen::move(int &prev_row, int &prev_col, int &next_row, int &next_col, piece *cp[9][9]) {
	
	if ((IsDiagonalMove(prev_row, prev_col, next_row, next_col) && IsDiagonalPathClear(prev_row, prev_col, next_row, next_col, cp)) || (IsHorizontalMove(prev_row, prev_col, next_row, next_col) && IsHosizontalPathClear(prev_row, prev_col, next_row, next_col, cp)) || (IsVerticalMove(prev_row, prev_col, next_row, next_col) && IsVerticalPathClear(prev_row, prev_col, next_row, next_col, cp)))
	{
		/*cp[next_row][next_col] = cp[prev_row][prev_col];
		cp[prev_row][prev_col] = nullptr;*/
		return true;
	}
	return false;
}
