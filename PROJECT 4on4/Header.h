#pragma once




#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

/*************** Board ***************/
#define ROWS 6
#define COLS 7
char board[ROWS][COLS];


/*********** Declarations ************/

/// This function initializes the game board by assigning each cell
/// with ' ' (resulting with an empty game board).
void initBoard();

/// This function gets a row number and a column number (a cell),
/// and returns the character in that cell (could be 'X', 'O' or ' ').
/// For example:
/// char c = getCell(1, 1);
char getCell(int row, int col);

/// This function gets a row number, a column number and a sign,
/// and assigns the cell with the given sign.
/// For example:
/// setCell(1, 1, 'X');
void setCell(int row, int col, char sign);

/// This function clears the screen.
void clearScreen();

// This function prints a whole raw.
void Printrow(int row);

// This function prints the board,
// with all the inputs we insert so far.
void PrintActiveBoard();

// This function checks if the input is proper
//(between 1 to 7).
int GoodToGo(int num);


// This feunction puts a variable in a column, 
// if the column is full it sends a proper message.
void InsertChar(int column, char xo);

// This function checks if the game is over,
// as a draw or a win, and sends a right message.
//***if player 1 wins,  the "printf" in the main gets activated.***
bool GameOver();

// This feunction checks if there is a straight 
// comb of four 'X' or 'O' in a row or a column.
bool InARow();


// This feunction checks if there is a straight 
// comb of four 'X' or 'O' in a diagonal.
bool DIAGONAL();




