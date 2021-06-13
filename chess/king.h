#pragma once
#include "Piece.h"


class King :public piece
{
protected:
	bool moved = false;
public:
	King()
	{
		set_AmIking(true);
	}
	bool move(int &prev_row, int &prev_col, int &next_row, int &next_col, piece *cp[9][9]);


};
bool King::move(int &prev_row, int &prev_col, int &next_row, int &next_col, piece *cp[9][9]) {
	
	if (next_row == 8 && next_col == 7) //castling
	{
		if ((moved == false) && (cp[8][8]->getter() == 'r'))
		{
			cp[8][6] = cp[8][8];
			cp[8][7]= cp[prev_row][prev_col];
			cp[prev_row][prev_col] = nullptr;
			cp[8][8] = nullptr;
			moved = true;
			return true;
		}
	}
	if (next_row == 8 && next_col == 3)
	{
		if (moved == false && cp[8][1]->getter() == 'r')
		{
			cp[8][4] = cp[8][1];
			cp[8][3] = cp[prev_row][prev_col];
			cp[prev_row][prev_col] = nullptr;
			cp[8][1] = nullptr;
			moved = true;
			return true;
		}
	}
	if (next_row == 1 && next_col == 3)
	{
		if (moved == false && cp[1][1]->getter() == 'R')
		{
			cp[1][4] = cp[1][1];
			cp[1][3] = cp[prev_row][prev_col];
			cp[prev_row][prev_col] = nullptr;
			cp[1][1] = nullptr;
			moved = true;
			return true;

		}
	}
	if (next_row == 1 && next_col == 7)
	{
		if (moved == false && cp[1][8]->getter() == 'R')
		{
			cp[1][6] = cp[1][8];
			cp[1][7] = cp[prev_row][prev_col];
			cp[prev_row][prev_col] = nullptr;
			cp[1][8] = nullptr;
			moved = true;
			return true;
		}
	}


	int numberofmoves;
	if (abs(next_row - prev_row) == 1 || abs(next_col - prev_col) == 1)
		numberofmoves = 1;
	else
		return false;
	if ((IsVerticalMove(prev_row, prev_col, next_row, next_col) && IsVerticalPathClear(prev_row, prev_col, next_row, next_col, cp)) || (IsHorizontalMove(prev_row, prev_col, next_row, next_col) && IsHosizontalPathClear(prev_row, prev_col, next_row, next_col, cp)) || (IsDiagonalMove(prev_row, prev_col, next_row, next_col) && IsDiagonalPathClear(prev_row, prev_col, next_row, next_col, cp)))
	{
		cp[next_row][next_col] = cp[prev_row][prev_col];
		cp[prev_row][prev_col] = nullptr;
		moved = true;
		return true;
	}

	return false;
}
