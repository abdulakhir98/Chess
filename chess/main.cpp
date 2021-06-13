#include "board.h"
#include "player.h"
int main()
{
	board cboard;
	player p1(cboard, 1), p2(cboard, 2);
	cboard.display();
	while (true)
	{
		p1.move();
		p2.move();
	}
	
}