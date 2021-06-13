#pragma once
#ifndef castle_h
#define castle_h

#include "Piece.h"

class rook :public piece
{
public:
	
	bool move(int &prev_row, int &prev_col, int &next_row, int &next_col, piece *cp[9][9]);


};


bool rook::move(int &prev_row, int &prev_col, int &next_row, int &next_col, piece *cp[9][9])
{
	if ((IsVerticalMove(prev_row, prev_col, next_row, next_col) && IsVerticalPathClear(prev_row, prev_col, next_row, next_col, cp)) || (IsHorizontalMove(prev_row, prev_col, next_row, next_col) && IsHosizontalPathClear(prev_row, prev_col, next_row, next_col, cp)))
	{
		/*cp[next_row][next_col] = cp[prev_row][prev_col];
		cp[prev_row][prev_col] = nullptr;*/
		return true;
	}
	return false;
}
#endif
