#include "Piece.h"

class pawn :public piece
{
	bool first;
public:
	pawn() { first = false; };
	void setter(char a) { piece::setter(a); }
	char geter() { return piece::getter(); }
	bool move(int &prev_row, int &prev_col, int &next_row, int &next_col, piece *cp[9][9]);


};


bool pawn::move(int &prev_row, int &prev_col, int &next_row, int &next_col, piece *cp[9][9])
{
	int choice = 0; //1 for player one, 2 for player two
	if ((cp[prev_row][prev_col]->getter() < 91))
	{
		choice = 2;
		if (prev_row > next_row)
			return false;
	}
		
			
	else if ((cp[prev_row][prev_col]->getter() > 96))
	{
		choice = 1;
		if(prev_row < next_row)
			return false;
	}
				
	int numberofmoves;
	if ((abs(next_row - prev_row) == 2) && (prev_row == 2 || prev_row == 7))
		numberofmoves = 2;
	else if (abs(next_row - prev_row) == 1)
		numberofmoves = 1;
	else
		return false;
	if ((cp[next_row][next_col] != nullptr) && (IsVerticalMove(prev_row, prev_col, next_row, next_col)))
		return false;
	else if ((cp[next_row][next_col] == nullptr) && ((IsVerticalMove(prev_row, prev_col, next_row, next_col) && IsVerticalPathClear(prev_row, prev_col, next_row, next_col, cp))))
	{
		/*cp[next_row][next_col] = cp[prev_row][prev_col];
		cp[prev_row][prev_col] = nullptr;*/
		return true;

	}
	else if ((cp[next_row][next_col] != nullptr) && IsDiagonalMove(prev_row, prev_col, next_row, next_col) && IsDiagonalPathClear(prev_row, prev_col, next_row, next_col, cp) && (numberofmoves == 1))
	{
		/*cp[next_row][next_col] = cp[prev_row][prev_col];
		cp[prev_row][prev_col] = nullptr;*/
		return true;
	}
	return false;
}
#pragma once
