/*
*	Square State ADT Implementation
*	Author: J.R.Dermoudy
*	Version: May 2024
*
*	This file holds the square_state ADT.  It comprises
*	the coordinate of square (as "row" and "column"),
*	and whether or not the square is occupied.
*
*	YOU NEED TO MAKE CHANGES TO THIS FILE!
*/


#include <stdio.h>
#include <stdlib.h>
#include "square_state.h"
#include "assig_three124.h"


// types

// internal data structure for the state of a square
struct square_state_int {
	int row;		// row number of square
	int column;		// column number of square
	bool visited;	// has a knight been here
	int move;		// which number move is this
};


// functions

/*
	*	init_square_state
	*	initialiser function.
	*	Pre-condition: none
	*	Post-condition: a square_state variable is created and pointed
	*					to by the first parameter.  Its row field
	*					is set to r, its column field is set to c,
	*					and it is set to unoccupied.
	*	Informally: creates an unoccupied square space
	*
	*	Parameter:	sp a pointer to the square_state being created
	*				r intended row number for square
	*				c intended column number for square
*/
void init_square_state(square_state *sp, int r, int c)
{
	trace("init_square_state: init_square_state starts");

	*sp = (square_state)malloc(sizeof(struct square_state_int));
	//DEBUG
	if (*sp == NULL)
	{
		fprintf(stderr, "Memory allocation failed for square state\n");
		exit(1);
	}
	(*sp)->row = r;
	(*sp)->column = c;
	(*sp)->visited = false;
	(*sp)->move = 0;

	trace("init_square_state: init_square_state ends");
}


/*
	* 	get_row_num
	*	Get function for row field.
	*	Pre-condition: none
	*	Post-condition: the value of the square_state variable's row
	*					field is returned
	*	Informally: return the square_state variable's row
	*
	*	Return: int the current row number of the square
	*
	*	Parameter:	s the square_state being examined
*/
int get_row_num(square_state s)
{
	trace("get_row_num: get_row_num starts and finishes");

	return (s->row);
}


/*
	* 	get_column_num
	*	Get function for column field.
	*	Pre-condition: none
	*	Post-condition: the value of the square_state variable's column
	*					field is returned
	*	Informally: return the square_state variable's column
	*
	*	Return: int the current column number of the square
	* 
	*	Parameter:	s the square_state being examined
*/
int get_column_num(square_state s)
{
	trace("get_column_num: get_column_num starts and finishes");

	return s->column;
}


/*
* 	set_row_num
	*	Set function for row field.
	*	Pre-condition: the given square_state is defined 
	*	Post-condition: the value of the square_state variable's row
	*					field is updated to the given int value
	*	Informally: update the square_state variable's row
	*
	*	Parameter:	s the square_state being altered
	*				r the row number for the given square_state
*/
void set_row_num(square_state s, int r)
{
	trace("set_row_num: set_row_num starts");

	s->row = r;

	trace("set_row_num: set_row_num ends");
}


/*
	* 	set_column_num
	*	Set function for column field.
	*	Pre-condition: the given square_state is defined 
	*	Post-condition: the value of the square_state variable's column
	*					field is updated to the given int value
	*	Informally: update the square_state variable's column
	*
	*	Parameter:	s the square_state being altered
	*				c the column number for the given square_state
*/
void set_column_num(square_state s, int c)
{
	trace("set_column_num: set_column_num starts");

	s->column = c;

	trace("set_column_num: set_column_num ends");
}


/*
	*	get_count
	*	Return the move number of the given square_state
	*	Pre-condition: the given square_state is defined
	*	Post-condition: the value of the square_state's move field is
	*					returned
	*	Informally: look up the move number of the given square_state
	*
	*	Return: int the number of the move of the given square_state
	* 
	* 	Parameter:	s the square_state being examined
*/
int get_count(square_state s)
{
	trace("get_count: get_count starts and finishes");

	return s->move;
}


/*
	* 	occupied
	*	Check whether the square_state has already been occupied
	*	Pre-condition: the given square_state is defined 
	*	Post-condition: true is returned if the square has been visited
	*					(i.e. is true, and false is returned otherwise)
	*	Informally: Return whether or not a square has been taken
	* 
	*	Return: bool whether or not the current square_state has held a knight
	* 	Parameter:	s the square_state being examined
*/
bool occupied(square_state s)
{
	trace("occupied: visit starts and finishes");

	return s->visited;
}


/*
	* 	occupy
	*	Set function for visited field.
	*	Pre-condition: the given square_state is defined
	*	Post-condition: the value of the square_state variable's visited
	*					field is updated to true and move is updated to
	*					the given value
	*	Informally: visit this square_state variable
	*
	*	Parameter:	s the square_state being altered
	*				c the count of the move being made
*/
void occupy(square_state s, int c)
{
	trace("occupy: occupy starts");

	s->visited = true;	//Mark the square as visited
	s->move = c;		//Record the move number

	trace("occupy: occupy ends");
}


/*
*	clone_square_state
*	Clone a square state
*	Pre-condition: the given square_state is defined
*	Post-condition: a deep clone of the given square_state
*	variable is returned
*	Informally: Copy a square state
*
*	@Return: square_state the copy
* 
* 	Parameter:	s the square_state being copied
*/
square_state clone_square_state(square_state s)
{
	square_state n;

	trace("clone_square_state: clone_square_state starts");

	init_square_state(&n, get_row_num(s), get_column_num(s));
	if (occupied(s))
	{
		trace("clone_square_state: occupying square on copy");
		occupy(n, get_count(s));
	}

	trace("clone_square_state: clone_square_state finishes");

	return n;
}


/*
	* 	show_square_state
	*	Display a game state
	*	Pre-condition: the given square_state is defined
	*	Post-condition: the given square_state has been displayed on
	*					the standard output stream
	*	Informally: Print the square
	* 
	*	Parameter:	s the square_state being printed
*/
void show_square_state(square_state s)
{
	trace("show_square_state: show_square_state starts");

	if (occupied(s))	// knight is there
	{
		printf("%3d",s->move);
	}
	else				// empty
	{
		printf("   ");
	}

	trace("show_square_state: show_square_state ends");
}
