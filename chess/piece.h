#pragma once
#ifndef piece_h
#define piece_h

#include <iostream>
#include<string>
#include<windows.h>
#include<fstream>
#include<stdio.h>
#include<conio.h>
using namespace std;

class piece {
	char character;
	bool AmIking = false;
public:
	piece() { character = ' '; };

	void setter(char a);
	char getter();
	bool get_AmIking();
	void set_AmIking(bool);
	virtual bool move(int &prev_row, int &prev_col, int &next_row, int &next_col, piece *cp[9][9]) = 0;
	bool IsHorizontalMove(int &prev_row, int &prev_col, int &next_row, int &next_col);
	bool IsVerticalMove(int &prev_row, int &prev_col, int &next_row, int &next_col);
	bool IsDiagonalMove(int &prev_row, int &prev_col, int &next_row, int &next_col);
	bool IsHosizontalPathClear(int &prev_row, int &prev_col, int &next_row, int &next_col, piece *cp[9][9]);
	bool IsVerticalPathClear(int &prev_row, int &prev_col, int &next_row, int &next_col, piece *cp[9][9]);
	bool IsDiagonalPathClear(int &prev_row, int &prev_col, int &next_row, int &next_col, piece *cp[9][9]);



};
bool piece:: IsDiagonalPathClear(int &prev_row, int &prev_col, int &next_row, int &next_col, piece *cp[9][9])
{
	int delta = abs(prev_row - next_row);
	if (prev_row > next_row && prev_col < next_col) //northeast
	{
		for (int i =1; i < delta; i++)
		{
			if (cp[prev_row - i][prev_col + i] != 0)
				return false;
		}
	}
	else if (prev_row < next_row && prev_col < next_col) //southeast
	{
		for (int i = 1; i < delta; i++)
		{
			if (cp[prev_row + i][prev_col + i] != 0)
				return false;
		}
	}
	else if (prev_row > next_row && prev_col > next_col) //northwest
	{
		for (int i = 1; i < delta; i++)
		{
			if (cp[prev_row - i][prev_col - i] != 0)
				return false;
		}
	}
	else if (prev_row < next_row && prev_col > next_col) //southwest
	{
		for (int i = 1; i < delta; i++)
		{
			if (cp[prev_row + i][prev_col - i] != 0)
				return false;
		}
	}
	return true;
}
bool piece::IsVerticalPathClear(int &prev_row, int &prev_col, int &next_row, int &next_col, piece *cp[9][9])
{
	if (prev_row < next_row)
	{
		for (int i = prev_row+1; i < next_row; i++)
			if (cp[i][prev_col] != 0)
				return false;
	}
	else
	{
		for (int j = prev_row-1; j > next_row; j--)
			if (cp[j][prev_col] != 0)
				return false;
	}
	return true;
}
bool piece::IsHosizontalPathClear(int &prev_row, int &prev_col, int &next_row, int &next_col, piece *cp[9][9])
{
	if (prev_col < next_col)
	{
		for (int i = prev_col+1; i < next_col; i++)
			if (cp[prev_row][i] != 0)
				return false;
	}
	else
	{
		for (int j = prev_col-1; j > next_col; j--)
			if (cp[prev_row][j] != 0)
				return false;
	}
	return true;
}
bool piece::IsDiagonalMove(int &prev_row, int &prev_col, int &next_row, int &next_col)
{
	if (abs(prev_row - next_row) == abs(prev_col - next_col))
		return true;
	return false;
}
bool piece::IsHorizontalMove(int &prev_row, int &prev_col, int &next_row, int &next_col)
{
	if (prev_row == next_row)
		return true;
	return false;
}
bool piece::IsVerticalMove(int &prev_row, int &prev_col, int &next_row, int &next_col)
{
	if (prev_col == next_col)
		return true;
	return false;
}

void piece::setter(char a)
{
	character = a;
}
void piece::set_AmIking(bool aik)
{
	AmIking = aik;
}
char piece::getter()
{
	return character;
}
bool piece::get_AmIking()
{
	return AmIking;
}
#endif