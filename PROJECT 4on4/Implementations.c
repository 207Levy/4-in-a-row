
#include "Header.h"
/********** Implementations **********/
char getCell(int row, int col)
{
	return board[row - 1][col - 1];
}

void setCell(int row, int col, char sign)
{
	board[row - 1][col - 1] = sign;
}

void initBoard()
{
	int i, j;

	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			setCell(i + 1, j + 1, ' ');
		}
	}
}

void clearScreen()
{
	system("cls");
}


void Printrow(int row)
{
	int i;
	for (i = 1; i <= COLS; i++)
	{
		printf("  %c  ", getCell(row, i));
	}
	printf("\n\n");
	return;
}

void PrintActiveBoard()
{
	printf("    1    2    3    4    5    6    7 \n\n");
	printf("A ");
	Printrow(1);

	printf("B ");
	Printrow(2);

	printf("C ");
	Printrow(3);

	printf("D ");
	Printrow(4);

	printf("E ");
	Printrow(5);

	printf("F ");
	Printrow(6);

}

int GoodToGo(int num)
{
	while (num > 7 || num < 1)
	{
		printf("error,\nplease enter a right number for a column (between 1 to 7)\n");
		scanf("%d", &num);
	}
	return num;
}

void InsertChar(int column, char xo)
{
	int i = 6;
	while (getCell(1, column) != ' ')
	{
		printf(" this column is full,\n please select another column\n");
		scanf("%d", &column);
		column = GoodToGo(column);
	}
	while (i > 0)
	{
		if (getCell(i, column) == ' ')
		{
			setCell(i, column, xo);
			return;
		}
		else
			i--;
	}
}


bool GameOver()
{
	int i, allcol = 0;
	for (i = 1; i <= COLS; i++)
	{
		if (getCell(1, i) != ' ')
			allcol++;
	}
	if (allcol == 7)
	{
		printf(" GAME OVER\n\n IT'S A DRAW!!\n\n");
		return true;
	}
	else if (InARow())
		return true;
	else if (DIAGONAL())
		return true;
	return false;
}

bool InARow()
{

	int j, i, r, c;


	for (r = 1; r <= ROWS; r++)
	{
		for (i = 1; i <= 4; i++)
		{
			if (getCell(r, i) == 'X' && getCell(r, i + 1) == 'X' && getCell(r, i + 2) == 'X' && getCell(r, i + 3) == 'X')
			{
				return true;
			}
			else if (getCell(r, i) == 'O' && getCell(r, i + 1) == 'O' && getCell(r, i + 2) == 'O' && getCell(r, i + 3) == 'O')
			{
				printf("game is over,\n\n PLAYER 2 WINS!!\n\n");
				return true;
			}

		}
	}

	for (c = 1; c <= COLS; c++)
	{
		for (i = 1; i <= 3; i++)
		{
			if (getCell(i, c) == 'X' && getCell(i + 1, c) == 'X' && getCell(i + 2, c) == 'X' && getCell(i + 3, c) == 'X')
			{
				return true;
			}
			else if (getCell(i, c) == 'O' && getCell(i + 1, c) == 'O' && getCell(i + 2, c) == 'O' && getCell(i + 3, c) == 'O')
			{
				printf("game is over,\n\n PLAYER 2 WINS!!\n\n");
				return true;
			}

		}
	}
	return false;
}


bool DIAGONAL()
{
	int i, j;
	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j <= 4; j++)
		{
			if (getCell(i, j) == 'X' && getCell(i + 1, j + 1) == 'X' && getCell(i + 2, j + 2) == 'X' && getCell(i + 3, j + 3) == 'X')
			{
				return true;
			}
			else if (getCell(i, j) == 'O' && getCell(i + 1, j + 1) == 'O' && getCell(i + 2, j + 2) == 'O' && getCell(i + 3, j + 3) == 'O')
			{
				printf("game is over,\n\n PLAYER 2 WINS!!\n\n");
				return true;
			}
		}
	}

	for (i = 6; i >= 4; i--)
	{
		for (j = 1; j <= 4; j++)
		{
			if (getCell(i, j) == 'X' && getCell(i - 1, j + 1) == 'X' && getCell(i - 2, j + 2) == 'X' && getCell(i - 3, j + 3) == 'X')
			{
				printf("game is over,\n\n PLAYER 1 WINS!!\n\n");
				return true;
			}
			else if (getCell(i, j) == 'O' && getCell(i - 1, j + 1) == 'O' && getCell(i - 2, j + 2) == 'O' && getCell(i - 3, j + 3) == 'O')
			{
				printf("game is over,\n\n PLAYER 2 WINS!!\n\n");
				return true;
			}
		}
	}
	return false;

}