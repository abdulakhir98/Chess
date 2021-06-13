#pragma once
#ifndef board_h
#define board_h

#include<iostream>
#include<string>
#include<windows.h>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include"Piece.h"
#include"Pawn.h"
#include"Bishop.h"
#include"castle.h"
#include"Knight.h"
#include"queen.h"
#include"King.h"
using namespace std;
enum
{
	BLACK = 0,
	GREY = 7,
	BLUE = 9,
	WHITE = 15

};
void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void setcolor(const int foreground, const int background)
{
	int color = foreground + (background * 16);
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole, color);
}
class board {
	piece *cp[9][9];
public:
	board();
	board(board&);
	~board();
	char getpiecesym(int, int);
	void display();
	bool checkplayer(int, int, int);
	void intialize();
	bool check(int, int);
	bool isLegal(int &prev_row, int &prev_col, int &next_row, int &next_col);
	void Highlight(int, int);
	void move(int &prev_row, int &prev_col, int &next_row, int &next_col);
	virtual bool IsOponentPiece(char piece, int row, int col);

};

void board::Highlight(int prev_row, int prev_col)
{
	if (cp[prev_row][prev_col]->get_AmIking()==false)
	{
		bool HL[9][9];
		int rpos, cpos;
		for (int i = 1; i < 9; i++)
			for (int j = 1; j < 9; j++)
			{
				HL[i][j] = isLegal(prev_row, prev_col, i, j);
			}
		for (int i = 1; i < 9; i++)
			for (int j = 1; j < 9; j++)
			{
				if (HL[i][j])
				{
					rpos = i + (3 + i) + i;
					cpos = j + (22 + j + 2 * j);
					gotoRowCol(rpos, cpos);
					cout << '*';
				}

			}
	}
	//display();
}
bool board::IsOponentPiece(char piece, int next_row, int next_col)
{
	if (piece >= 'a'&&piece <= 'z')
	{
		if ((cp[next_row][next_col]->getter() >= 'A' && cp[next_row][next_col]->getter() <= 'Z'))
		{
			return true;
		}
	}
	else if (piece >= 'A'&&piece <= 'Z')
	{
		if ((cp[next_row][next_col]->getter() >= 'a' && cp[next_row][next_col]->getter() <= 'z'))
		{
			return true;
		}
	}

	return false;
}
bool board::checkplayer(int prev_row, int prev_col, int turn)
{
	if (turn == 1 && cp[prev_row][prev_col]!=nullptr && cp[prev_row][prev_col]->getter() >= 'a')
		return true;
	else if (turn == 2 && cp[prev_row][prev_col] != nullptr && cp[prev_row][prev_col]->getter() <= 'Z')
		return true;
	return false;
}
char board::getpiecesym(int row, int col)
{
	return cp[row][col]->getter();
}
bool board::isLegal(int &prev_row, int &prev_col, int &next_row, int &next_col)
{
	char piece;
	if (cp[next_row][next_col] != nullptr)
	{
		piece = this->getpiecesym(prev_row, prev_col);
		if ((IsOponentPiece(piece, next_row, next_col)))  //either empty or oponent piece at the destination
		{
			if (cp[prev_row][prev_col]->move(prev_row, prev_col, next_row, next_col, cp))
			{
				/*cp[next_row][next_col] = cp[prev_row][prev_col];
				cp[prev_row][prev_col] = nullptr;*/
				return true;
			}

		}
	}
	else
	{
		if (cp[prev_row][prev_col]->move(prev_row, prev_col, next_row, next_col, cp))
		{
			/*cp[next_row][next_col] = cp[prev_row][prev_col];
			cp[prev_row][prev_col] = nullptr;*/
			return true;
		}
		
	}
	//display();
	return false;
}

void board::move(int &prev_row, int &prev_col, int &next_row, int &next_col)
{
	
	if (cp[prev_row][prev_col]->get_AmIking()==true)
		cp[prev_row][prev_col]->move(prev_row, prev_col, next_row, next_col, cp);
	else if (isLegal(prev_row, prev_col, next_row, next_col))
	{
		cp[next_row][next_col] = cp[prev_row][prev_col];
				cp[prev_row][prev_col] = nullptr;
	}

	if (check(next_row, next_col))
	{
		cout << "CHECK!!!";
		Sleep(5000);
	}
}

bool board::check(int prev_row, int prev_col)
{
	int king_rpos, king_cpos;
	if (cp[prev_row][prev_col]->getter() <= 91)
	{
		for(int i=1;i<9;i++)
			for (int j = 1; j < 9; j++)
			{
				if (cp[i][j] != nullptr && cp[i][j]->getter() == 'k')
				{
					king_rpos = i;
					king_cpos = j;
				}
			}
		for (int i = 1; i < 9; i++)
			for (int j = 1; j < 9; j++)
			{
				if (cp[i][j] != nullptr && cp[i][j]->getter() <= 'Z' && cp[i][j]->getter() != 'K')
				{
					if(isLegal(i, j, king_rpos, king_cpos))
						return true;
				}
			}
	}
	else if (cp[prev_row][prev_col]->getter() >= 'a')
	{
		for (int i = 1; i < 9; i++)
			for (int j = 1; j < 9; j++)
			{
				if (cp[i][j] != nullptr && cp[i][j]->getter() == 'K')
				{
					king_rpos = i;
					king_cpos = j;
				}
			}
		for (int i = 1; i < 9; i++)
			for (int j = 1; j < 9; j++)
			{
				if (cp[i][j] != nullptr && cp[i][j]->getter() >= 'a' && cp[i][j]->getter() != 'k')
				{
					if (isLegal(i, j, king_rpos, king_cpos))
						return true;
				}
			}
	}
	return false;
}

board::board()
{
	intialize();
}
board::~board()
{

}
board::board(board&)
{

}
void board::intialize()
{
	for (int i = 0; i < 9; i++)
		for (int col = 0; col < 9; col++)
			cp[i][col] = nullptr;
	for (int col = 1; col < 9; col++)
	{
		cp[2][col] = new pawn();
		cp[7][col] = new pawn();

		cp[2][col]->setter('P');
		cp[7][col]->setter('p');

	}

	cp[1][1] = new rook;
	cp[1][8] = new rook;
	cp[8][1] = new rook;
	cp[8][8] = new rook;
	cp[1][1]->setter('R');
	cp[1][8]->setter('R');
	cp[8][1]->setter('r');
	cp[8][8]->setter('r');

	cp[1][3] = new bishop;
	cp[1][6] = new bishop;
	cp[8][3] = new bishop;
	cp[8][6] = new bishop;
	cp[1][3]->setter('B');
	cp[1][6]->setter('B');
	cp[8][3]->setter('b');
	cp[8][6]->setter('b');
	cp[1][2] = new knight;
	cp[1][7] = new knight;
	cp[8][2] = new knight;
	cp[8][7] = new knight;
	cp[1][2]->setter('H');
	cp[1][7]->setter('H');
	cp[8][2]->setter('h');
	cp[8][7]->setter('h');
	cp[1][4] = new queen;
	cp[8][4] = new queen;
	cp[1][4]->setter('Q');
	cp[8][4]->setter('q');
	cp[1][5] = new King;
	cp[8][5] = new King;
	cp[1][5]->setter('K');
	cp[8][5]->setter('k');
}
void board::display()
{
	system("cls");
	cout << "\n\n\n\t\t\t";
	setcolor(2, 0);
	cout << "   1   2   3   4   5   6   7   8\n";
	setcolor(2, 0);
	for (int row = 1; row < 9; row++)
	{
		cout << "\t\t\t";
		setcolor(2, 0);
		cout << " ";
		setcolor(0, 2);
		for (int col = 1; col < 9; col++)
		{

			setcolor(2, 0);
			cout << "====";

		}

		cout << "\n";
		cout << "\t\t\t";
		setcolor(0, 2);
		for (int col = 1; col < 9; col++)
		{

			setcolor(2, 0);
			cout << "|";
			setcolor(0, 2);
			if (row % 2 == 0) {
				if (col % 2 == 0)	setcolor(2, 0);
			}
			else
				if (col % 2 != 0)	setcolor(2, 0);
			if (col != 9)	cout << "   ";
			if (row % 2 == 0) {
				if (col % 2 == 0)	setcolor(0, 2);
			}
			else
			{
				if (col % 2 != 0)	setcolor(0, 2);
			}
		}
		setcolor(2, 0);
		cout << "\n\t\t\t\b" << row << "|";
		setcolor(0, 2);
		for (int col = 1; col < 9; col++)
		{
			if (row % 2 == 0) {
				if (col % 2 == 0)	setcolor(2, 0);
			}
			else
				if (col % 2 != 0)	setcolor(2, 0);
			if (cp[row][col] != nullptr)
				cout << " " << cp[row][col]->getter() << " ";
			else
				cout << "   ";
			if (row % 2 == 0) {
				if (col % 2 == 0)	setcolor(0, 2);
			}
			else
			{
				if (col % 2 != 0)	setcolor(0, 2);
			}
			setcolor(2, 0);
			cout << "|";
			setcolor(0, 2);

		}
		setcolor(2, 0);
		cout << row << "\n";

	}
	cout << "\t\t\t";
	for (int col = 1; col < 9; col++)
	{

		setcolor(2, 0);
		cout << "====";
		setcolor(0, 2);
	}cout << "\n"; setcolor(2, 0);
	cout << "\t\t\t";
	cout << "  1   2   3   4   5   6   7   8\n";
	setcolor(2, 0);

}


#endif
