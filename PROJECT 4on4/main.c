//   OR LEVY
//ID: 206263352

#include "Header.h"

/*************** Main ****************/
int main()
{
	int move;
	initBoard();
	PrintActiveBoard();
	while (! GameOver())
	{
		printf(" HELLO PLAYER 1\n please enter a column input (a number between 1 to 7:\n");
		scanf("%d", &move);
		move = GoodToGo(move);
		InsertChar(move, 'X');
		clearScreen();
		PrintActiveBoard();
		if (! GameOver())
		{
			printf(" HELLO PLAYER 2\n please enter a column input (a number between 1 to 7:\n");
			scanf("%d", &move);
			move = GoodToGo(move);
			InsertChar(move, 'O');
			clearScreen();
			PrintActiveBoard();
		}
		else
			printf("game is over,\n\n PLAYER 1 WINS!!\n\n");	
	}
	system("pause");

}
