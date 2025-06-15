/*
*	Game State ADT Implementation
*	Author: <<YOUR STUDENT IDs AND NAMES HERE>>
*	Version: May 2024
*
*	This file holds the game_state ADT.  It comprises
*	the coordinate of the knight's current position
*	(as "row" and "column"), and the board (as a
*	two-dimensional array called "board").
*
*	YOU NEED TO MAKE CHANGES TO THIS FILE!
*/


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "game_state.h"
#include "assig_three124.h"


// types

// internal data structure for game_state
struct game_state_int {
	int row;									// which row is the knight on now
	int column;									// which column is the knight on now
	int moves;									// how many moves have been made so far
	square_state board[DIMENSION][DIMENSION];	// the board (a table of squares)
};


// functions

/*
	*	init_game_state
	*	initialiser function.
	*	Pre-condition: none
	*	Post-condition: a game_state variable is created and pointed
	*					to by the first parameter.  Its row field
	*					is set to -1 its column field is set to -1,
	*					and each element in the board table is set
	*					to 'empty'
	*	Informally: creates an initial game_state
	* 
	*	Parameter: gp pointer to game_state being created
*/
void init_game_state(game_state *gp)
{
	int r, c;  // row and column indices

	trace("init_game_state: init_game_state starts");

	*gp = (game_state)malloc(sizeof(struct game_state_int));

	//DEBUG
	if (*gp == NULL)
	{
		fprintf(stderr, "Memory allocation failed for game state\n");
		exit(1);
	}
	
	(*gp)->row = -1;
	(*gp)->column = -1;

	for (r = 0; r < DIMENSION; r++)
	{
		for (c = 0; c < DIMENSION; c++)
		{
			init_square_state(&((*gp)->board[r][c]), r + 1, c + 1);
			//printf("Initialised square_state at [%d][%d]: row=%d, column=%d, visited=%d, move=%d\n", r, c, get_row_num((*gp)->board[r][c]), get_column_num((*gp)->board[r][c]), occupied((*gp)->board[r][c]), get_count((*gp)->board[r][c])); //DEBUG
		}
	}
	(*gp)->moves = 0;

	trace("init_game_state: init_game_state ends");
}


/*
	* 	get_row
	*	Get function for row field.
	*	Pre-condition: none
	*	Post-condition: the value of the game_state variable's row
	*					field is returned
	*	Informally: return the game_state variable's row
	*
	*	Return: int the current row number of the knight
	* 
	*	Parameter: g game_state variable being examined
*/
int get_row(game_state g)
{
	trace("get_row: get_row starts and finishes");

	return g->row;
}


/*
	* 	get_column
	*	Get function for column field.
	*	Pre-condition: none
	*	Post-condition: the value of the game_state variable's column
	*					field is returned
	*	Informally: return the game_state variable's column
	*
	*	Return: int the current column number of the knight
	* 
 	*	Parameter: g game_state variable being examined
*/
int get_column(game_state g)
{
	trace("get_column: get_column starts and finishes");

	return g->column;
}


/*
	* 	set_row
	*	Set function for row field.
	*	Pre-condition: the given game_state is defined and the given row
	*					is within the bounds of that game_state variable's
	*					board
	*	Post-condition: the value of the game_state variable's row
	*					field is updated to the given int value
	*	Informally: update the game_state variable's row
	*
	*	Parameter: 	g game_state variable being examined
	*				r int value to be placed into the game_state's row field
*/
void set_row(game_state g, int r)
{
	trace("set_row: set_row starts");

	g->row = r;

	trace("set_row: set_row ends");
}


/*
	* 	set_column
	*	Set function for column field.
	*	Pre-condition: the given game_state is defined and the given column
	*					is within the bounds of that game_state variable's
	*					board
	*	Post-condition: the value of the game_state variable's column
	*					field is updated to the given int value
	*	Informally: update the game_state variable's column
	*
	*	Parameter: 	g game_state variable being examined
	*				c int value to be placed into the game_state's column field
*/
void set_column(game_state g, int c)
{
	trace("set_column: set_column starts");

	g->column = c;

	trace("set_column: set_column ends");
}


/*
	*	get_moves
	*	Get count of number of moves on the board.
	*	Pre-condition: the given game_state has at least one knight on it.
	*	Post-condition: the number of knights on the board is returned.
	*	Informally: determine the number of moves which have been made
	*
	*	Return: int the number of moves made on the board
	*	Parameter: 	g game_state variable being examined

*/
int get_moves(game_state g)
{
	trace("get_moves: get_moves starts and finishes");

	return g->moves;
}


/*
	*	set_moves
	*	Set count of number of moves on the board.
	*	Pre-Condition: the given game_state has been defined.
	*	Post-Condition: the moves field of the given game_state has been
	*					updated.
	*	Informally: remember how many moves have been made
	* 
 	*	Parameter: 	g game_state variable being examined
	*				m number of moves to set
*/
void set_moves(game_state g, int m)
{
	trace("set_moves: set_moves starts");

	g->moves = m;

	trace("set_moves: set_moves ends");
}
/*
	* 	get_square
	*	Get function for a square_state.
	*	Pre-condition: the given coordinate is within the bounds of the board
	*	Post-condition: the value of the indicated square_state variable
	*					is returned
	*	Informally: return the square_state in the game_state variable's board
	*
	*	Return: square_state the nominated square_state
	* 
	*	Parameter: 	g game_state variable being examined
	*				r the row component of the desired square's coordinate
	*				c the column component of the desired square's coordinate
*/
square_state get_square(game_state g, int r, int c)
{
	trace("get_square: get_square starts and finishes");

	//DEBUG
	if (r < 1 || r > DIMENSION || c < 1 || c > DIMENSION)
	{
		fprintf(stderr, "Invalid board position accessed: (%d, %d)\n", r, c);
		exit(1);
	}

	//printf("Accessing square at (%d, %d)\n", r, c);	//DEBUG
	return g->board[r - 1][c - 1];
}


/*
	* 	set_square
	*	Set function for a square_state.
	*	Pre-condition: the given square_state value is defined and is within the
	*				   dimension of the board array
	*	Post-condition: the square of the board at the given coordinate is updated
	*					to the given square_state value
	*	Informally: update the game_state board variable's element to the given value
	*
	*	Parameter: 	g game_state variable being examined
	*				s value to be placed into the game_state's board field
*/
void set_square(game_state g, square_state s)
{
	int r, c;	// row and column of given square_state

	trace("set_square: set_square starts");

	r = get_row_num(s);
	c = get_column_num(s);

	g->board[r - 1][c - 1] = s;

	trace("set_square: set_square ends");
}


/*
	* 	valid
	*	Check whether a square is on the board
	*	Pre-condition: the given game_state is defined 
	*	Post-condition: true is returned if (r,c) is within the bounds
	*					of the given game_state variable's board field,
	*					and false is returned otherwise
	*	Informally: Return whether or not a square is on the board
	*
	*	Return: bool whether the coordinate is on the board
	*
	*	Parameter: 	g game_state variable being examined
	*				r row value to check
	*				c column value to check
	*/
bool valid(game_state g, int r, int c)
{
	trace("valid: valid starts and finishes");

	return r >= 1 && r <= DIMENSION && c >= 1 && c <= DIMENSION;
}


/*
	* 	taken
	*	Check whether a square on the board has already been visited
	*	Pre-condition: the given game_state is defined and (r,c) is
	*					within the bounds of the given game_state
	*					variable's board field
	*	Post-condition: true is returned if (r,c) has been visited (i.e.
	*					is non-zero, and false is returned otherwise
	*	Informally: Return whether or not a square has been taken
	*
	*	Return: bool whether a knight has occupied the given coordinate
	*			on the given board
	*
	*	Parameter: 	g game_state variable being examined
	*				r row value to check
	*				c column value to check
*/
bool taken(game_state g, int r, int c)
{
	trace("taken: taken starts and finishes");

	return occupied(g->board[r - 1][c - 1]);
}


/*
	* 	land
	*	Visit a square on the board
	*	Pre-condition: the given game_state is defined and (r,c) is
	*					within the bounds of the given game_state
	*					variable's board field
	*	Post-condition: the square at (r,c) has been visited and it
	*					has been recorded that this is the current
	*					location of the knight in the given board
	*	Informally: Visit a square
	*
	*	Parameter: 	g game_state variable being altered
	*				r row value to check
	*				c int column value to check
*/
void land(game_state g, int r, int c)
{
	trace("land: land starts");

	if (r < 1 || r > DIMENSION || c < 1 || c > DIMENSION)
	{
		fprintf(stderr, "Invalid board position (%d, %d)\n", r, c);
		exit(1);
	}

	//Mark the square as visited and increment the move counter
	occupy(g->board[r - 1][c - 1], g->moves + 1);
	
	//Update row and column position of knight
	g->row = r;
	g->column = c;
	g->moves++;

	//printf("After occupy: row=%d, column=%d, moves=%d\n", g->row, g->column, g->moves); //DEBUG
	trace("land: land ends");
}


/*
	* 	clone_game_state
	*	Deeply clone a game_state
	*	Pre-condition: the given game_state is defined
	*	Post-condition: a deep clone of the given game_sate is returned
	*	Informally: Copy a game
	*
	*	Return: game_state the independent copy of the game_state
	*
	*	Parameter: 	g game_state variable being copied
*/
game_state clone_game_state(game_state g)
{
	game_state p;	//Pointer to the new game_state
	int r;			//Row for iteration
	int c;			//Column for iteration

	trace("clone_game_state: clone_game_state starts");

	//Initalise the new game state
	init_game_state(&p);

	//Copy the current position of the knight
	set_row(p, get_row(g));
	set_column(p, get_column(g));

	//Copy the number of moves so far
	set_moves(p, get_moves(g));

	//Iterate over each column and row (aka each cell) in the board
	for (r = 1; r < DIMENSION; r++)
	{
		for (c = 1; c < DIMENSION; c++)
		{
			//Clone each square state, assign to the new game state
			set_square(p, clone_square_state(get_square(g, r, c)), r, c);
		}
	}

	trace("clone_game_state: clone_game_state finishes");

	return p;
}


/*
	* 	show_game_state
	*	Display a game state
	*	Pre-condition: the given game_state is defined
	*	Post-condition: the given game_state has been displayed on
	*					the standard output stream
	*	Informally: Print the board
	* 
	*	Parameter: 	g game_state variable being displayed
*/
void show_game_state(game_state g)
{
	int x, y;

	trace("show_game_state: show_game_state starts");

	// for all rows
	for (x = 1; x <= DIMENSION; x++)
	{
		// print row separator
		printf("+");
		for (y = 1; y <= DIMENSION * 4 - 1; y++)
		{
			printf("-");
		}
		printf("+\n");

		// print all columns
		printf("|");
		for (y = 1; y <= DIMENSION; y++)
		{
			//printf("Accessing square at (%d, %d)\n", x, y); //DEBUG
			show_square_state(get_square(g, x, y));
			printf("|");
		}
		printf("\n");
	}
	
	// print row separator
	printf("+");
	for (y = 1; y <= DIMENSION * 4 - 1; y++)
	{
		printf("-");
	}
	printf("+\n");

	trace("show_game_state: show_game_state ends");
}