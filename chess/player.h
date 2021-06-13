#pragma once
#include "Board.h"
#include<Windows.h>
#include<conio.h>

void getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}

class player
{
	board * cboard;
	int turn; //can be 1/2/0
public:
	player();
	player(board &, int);
	~player();
	void setturn(int);
	int getturn();
	void move();
	bool getActualRowCol(int, int, int&, int&);
	
};

void player::setturn(int turn)
{
	this->turn = turn;
}
int player::getturn()
{
	return(this->turn);
}
player::player()
{
	cboard = 0;
	turn = 0;
}
player::player(board&  b, int turn)
{
	cboard = &b;
	this->turn = turn;
}
player::~player()
{
	delete[]cboard;
}
bool player::getActualRowCol(int rpos, int cpos, int &previous_row, int &previous_col)
{
	if (rpos == 5 || rpos == 6)
		previous_row = 1;
	else if (rpos == 8 || rpos == 9)
		previous_row = 2;
	else if (rpos == 11 || rpos == 12)
		previous_row = 3;
	else if (rpos == 14 || rpos == 15)
		previous_row = 4;
	else if (rpos == 17 || rpos == 18)
		previous_row = 5;
	else if (rpos == 20 || rpos == 21)
		previous_row = 6;
	else if (rpos == 23 || rpos == 24)
		previous_row = 7;
	else if (rpos == 26 || rpos == 27)
		previous_row = 8;
	else
		return false;
	if (cpos >= 25 && cpos <= 27)
		previous_col = 1;
	else if (cpos >= 29 && cpos <= 31)
		previous_col = 2;
	else if (cpos >= 33 && cpos <= 35)
		previous_col = 3;
	else if (cpos >= 37 && cpos <= 39)
		previous_col = 4;
	else if (cpos >= 41 && cpos <= 43)
		previous_col = 5;
	else if (cpos >= 45 && cpos <= 47)
		previous_col = 6;
	else if (cpos >= 49 && cpos <= 51)
		previous_col = 7;
	else if (cpos >= 53 && cpos <= 55)
		previous_col = 8;
	else
		return false;
	return true;
}
void player::move()
{
	cboard->display();
	/*if (turn == '1')
	{
	*/	//cout << "Player 1 turn\n";
	int rpos, cpos;
		int prev_row, prev_col, next_row, next_col;
		
		while (true)
		{
			//cout << "select the piece to move\n";
			
			
			do {
				getRowColbyLeftClick(rpos, cpos);
				getActualRowCol(rpos, cpos, prev_row, prev_col);
			} while (cboard->checkplayer(prev_row, prev_col, turn) == false);
				
			cboard->Highlight(prev_row, prev_col);
			//cout << "select the destination\n";
			do {
				getRowColbyLeftClick(rpos, cpos);
			}while (getActualRowCol(rpos, cpos, next_row, next_col) == false);
			/*cout << "rpos " << rpos << "++" << "prow " << next_row << endl;
			cout << "cpos " << cpos << "++" << "pcol " << next_col << endl;*/

			cboard->move(prev_row, prev_col, next_row, next_col);
			break;
			//for(int i=0; cboard-> )
			//if (cboard->getpiecesym(rpos, cpos) >= 'a'&&cboard->getpiecesym(rpos, cpos) <= 'z')
			//{
			//	/*previous_row = rpos;
			//	previous_col = cpos;*/

			//}
			//else
			//	cout << "click on correct symbol\n";
		}
	/*}
	else if(turn==2)
		cout << "Player 2 turn\n";*/
	
	

}
