#pragma once
#ifndef bishop_h
#define bishop_h

#include "Piece.h"

class bishop :public piece
{
public:
	
	bool move(int &prev_row, int &prev_col, int &next_row, int &next_col, piece *cp[9][9]);

};


bool bishop::move(int &prev_row, int &prev_col, int &next_row, int &next_col, piece *cp[9][9])
{
	if (IsDiagonalMove(prev_row, prev_col, next_row, next_col) && IsDiagonalPathClear(prev_row, prev_col, next_row, next_col, cp))
	{
		/*cp[next_row][next_col] = cp[prev_row][prev_col];
		cp[prev_row][prev_col] = nullptr;*/
		return true;
	}
	return false;
}
#endif