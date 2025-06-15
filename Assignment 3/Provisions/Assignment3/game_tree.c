/*
 *	Game Tree ADT Implementation
 *	Author: <<YOUR STUDENT IDs AND NAMES HERE>>
 *	Version: May 2024
 *	
 *	This file holds the game_tree ADT which is a
 *	general game tree.  The game_tree is built using
 *	t_node ADTs.  A game_tree variable consists of a
 *	"root" field which refers to a t_node variable
 *	which has a "data" field, "parent" and "child" and
 *	"sibling" references, and a "level" value.
 *	
 *	YOU NEED TO MAKE CHANGES TO THIS FILE!
*/


#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "t_node.h"
#include "game_state.h"
#include "game_tree.h"
#include "assig_three124.h"


// types

// internal data structure for game tree
struct game_tree_int
{
	t_node root;	// the node at the top of the tree
};


// functions

/*
	*	init_game_tree
	*	initialiser function.
	*	Pre-condition: none
	*	Post-condition: if the parameter value (e) is true then the 
	*					game_tree variable's "root" field is set to NULL
	*					otherwise the game_tree variable's "root" field
	*					refers to a new t_node variable containing the
	*					parameter value (o) of level with parameter 
	*					value (l) with a NULL parent and child, and a 
	*					NULL sibling
	*	Informally: creates either an empty tree or a leaf node as
	*				required
	* 
	*	Parameter:	tp a pointer to the game tree being created
	*				e should the new tree be empty?
	*				o the value for the data field (if applicable)
	*				l the level number for the game tree (if applicable)
*/
void init_game_tree(game_tree *tp,bool e,void *o,int l)
{
	trace("game_tree: initialiser starts");
	
	//Allocate memory for the new game_tree
	*tp = (game_tree)malloc(sizeof(struct game_tree_int));
	
	//If the game_tree should be empty
	if (e)
	{
		//Set root of game tree to NULL
		(*tp)->root = NULL;
	}
	else
	{
		//Otherwise initialise the root node with given data and level
		init_t_node(&((*tp)->root), o, l);
	}

	trace("game_tree: initialiser ends");
}
	
	
/*
	*	is_empty_game_tree
	*	Emptiness test.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: true is returned if the game_tree variable is
	*					empty, false is returned otherwise
	*	Informally: indicate if the game_tree contains no nodes
	*
	*	Return: boolean whether or not the game tree is empty
	*	Parameter:	t the game tree being examined
*/
bool is_empty_game_tree(game_tree t)
{
	trace("is_empty_game_tree: is_empty_game_tree starts and ends");
		
	return t->root == NULL;
}


/*
	*	get_data
	*	Get function for "root" instance variable's data value.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the value of the game_tree variable's data
	*					field is returned
	*	Informally: return the value within the root node
	*
	*	Return: void * the data item contained within the root node
	* 
	*	Parameter:	t the game tree being examined
*/
void *get_data(game_tree t)
{
	trace("get_data: get_data starts");
		
	if (is_empty_game_tree(t))
	{
		fprintf(stderr,"get_data: empty game tree");
		exit(1);
	}

	trace("get_data: get_data ends");
	return get_t_node_data(t->root);
}
	
	
/*
	*	get_level
	*	Get function for "root" instance variable's level value.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the value of the game_tree variable's data
	*					field's level is returned
	*	Informally: return the level value within the root node
	*
	*	Return: int the level number of the root node
	*	Parameter:	t the game tree being examined
*/
int get_level(game_tree t)
{
	trace("get_level: get_level starts");
		
	if (is_empty_game_tree(t))
	{
		fprintf(stderr, "get_level: empty game tree");
		exit(1);
	}

	trace("get_level: get_level ends");
	return get_t_node_level(t->root);
}
	

/*
	*	get_parent
	*	Get function for "root" instance variable's parent value.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the value of the game_tree variable's parent
	*					field is returned in a newly constructed
	*					game_tree variable
	*	Informally: return the game_tree variable's parent
	*
	*	Return: game_tree the parent of the current node
	* 
	*	Parameter:	t the game tree being examined
*/
game_tree get_parent(game_tree t)
{
	game_tree p;

	trace("get_parent: get_parent starts");

	if (is_empty_game_tree(t))
	{
		fprintf(stderr, "get_parent: empty game tree");
		exit(1);
	}

	init_game_tree(&p, true, NULL, -1);
	p->root = get_t_node_parent(t->root);

	trace("get_parent: get_parent ends");
	return p;
}


/*
	*	get_child
	*	Get function for "root" instance variable's child value.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the value of the game_tree variable's child
	*					field is returned in a newly constructed 
	*					game_tree variable
	*	Informally: return the game_tree variable's child
	*
	*	Return: game_tree the eldest child of the current node
	*
	*	Parameter:	t the game tree being examined
*/
game_tree get_child(game_tree t)
{
	game_tree c;

	trace("get_child: get_child starts");

	if (is_empty_game_tree(t))
	{
		fprintf(stderr, "get_child: empty game tree");
		exit(1);
	}

	init_game_tree(&c, true, NULL, -1);
	c->root = get_t_node_child(t->root);

	trace("get_child: get_child ends");
	return c;
}


/*
	* 	get_sibling
	*	Get function for "root" instance variable's sibling value.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the value of the game_tree variable's sibling
	*					field is returned in a newly constructed 
	*					game_tree variable
	*	Informally: return the game_tree variable's sibling
	*
	*	Return: game_tree the next sibling of the current node
	*
	*	Parameter:	t the game tree being examined
*/
game_tree get_sibling(game_tree t) 
{
	game_tree s;
		
	trace("get_sibling: get_sibling starts");
		
	if (is_empty_game_tree(t))
	{
		fprintf(stderr, "get_slibling: empty game tree");
		exit(1);
	}

	init_game_tree(&s, true, NULL, -1);
	s->root = get_t_node_child(t->root);

	trace("get_child: get_child ends");
	return s;
}


/*
	*	set_data
	*	Set function for "root" instance variable's data field.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the t_node variable's data field is altered to
	*					hold the given (o) value
	*	Informally: store the given value in the root node of the
	*				game_tree variable
	*
	*	Parameter:	t the game tree being altered
	*				o the value to install as data for root node
*/
void set_data(game_tree t,void *o)
{
	trace("set_data: set_data starts");
		
	if (is_empty_game_tree(t))
	{
		fprintf(stderr,"set_data: empty game tree");
		exit(1);
	}
		
	set_t_node_data(t->root, o);
		
	trace("set_data: set_data ends");
}
		
	
/*
	*	set_level
	*	Set function for "root" instance variable's level field.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the t_node variable's level field is altered
	*					to hold the given (l) value
	*	Informally: assign the given value as the level of the
	*				game_tree variable
	*
	*	Parameter:	t the game tree being altered
	*				l the level number for root of current game tree
*/
void set_level(game_tree t,int l)
{
	trace("set_level: set_level starts");
		
	if (is_empty_game_tree(t))
	{
		fprintf(stderr, "set_level: empty game tree");
		exit(1);
	}

	set_t_node_level(t->root, l);

	trace("set_level: set_level ends");
}
	
	
/*
	*	set_parent
	*	Set function for "root" instance variable's parent field.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the t_node variable's parent field is altered
	*					to hold the given (p) value
	*	Informally: assign the given value as the parent of the
	*				game_tree variable
	*
	*	Parameter:	t the game tree being altered
	*				p the game_tree to be set as parent of current game tree
*/
void set_parent(game_tree t, game_tree p)
{
	trace("set_parent: set_parent starts");

	if (is_empty_game_tree(t))
	{
		fprintf(stderr, "set_parent: empty game tree");
		exit(1);
	}

	set_t_node_parent(t->root, p->root);

	trace("set_parent: set_parent ends");
}


/*
	*	set_child
	*	Set function for "root" instance variable's child field.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the t_node variable's child field is altered
	*					to hold the given (c) value
	*	Informally: assign the given value as the child of the
	*				game_tree variable
	*
	*	Parameter:	t the game tree being altered
	*				c the game_tree to be set as eldest child of current game tree
*/
void set_child(game_tree t, game_tree c)
{
	trace("set_child: set_child starts");

	if (is_empty_game_tree(t))
	{
		fprintf(stderr, "set_child: empty game tree");
		exit(1);
	}

	set_t_node_child(t->root, c->root);

	trace("set_child: set_child ends");
}


/*
	*	set_sibling
	*	Set function for "root" instance variable's sibling field.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the t_node variable's sibling field is altered
	*					to hold the given (s) value
	*	Informally: assign the given value as the sibling of the
	*				game_tree variable
	*
	*	Parameter:	t the game tree being altered
	*				s the game_tree to be set as next sibling of current game tree
*/
void set_sibling(game_tree t,game_tree s)
{
	trace("set_sibling: set_sibling starts");
		
	if (is_empty_game_tree(t))
	{
		fprintf(stderr, "set_sibling: empty game tree");
		exit(1);
	}

	set_t_node_sibling(t->root, s->root);

	trace("set_sibling: set_sibling ends");
}
	
	
/*
	*	generate_levelBF
	*	Generate the next level of the tree in a breadth-first manner
	*	Pre-condition: the given tree is defined, the given queue
	*				   is defined
	*	Post-condition: an additional level of possible moves has
	*					been added to the given game tree and each
	*					tree node of the new level also has been
	*					added to the queue.
	*	Informally: generate the next level of the game tree
	*
	*	Parameter:	t the game tree being expanded
	*				q a queue of reachable but unexpanded game trees
*/
void generate_levelBF(game_tree t, queue q)
{
	const char *THINKING = "-\\|/";									// a 'cartwheel' character by character
	const int HORIZ_MOVES[] = { -2, -1, +1, +2, +2, +1, -1, -2 };	// moves left/right
	const int VERT_MOVES[] = { -1, -2, -2, -1, +1, +2, +2, +1 };	// moves up/down
	const int MOVE_COUNT = 8;										// number of potential moves

	int thought = 0;	// to show THINKING 'animation' -- i.e. that the program hasn't crashed (optional)
	int new_row;		//Holds the new row for move
	int new_column;		//Holds the new column for move

	trace("generate_levelBF: generate_levelBF starts");

	//Loop through all possible moves
	for (int i = 0; i < MOVE_COUNT; i++)
	{
		//Claculate new row and column positions based on current position
		new_row = get_row(get_data(t)) + HORIZ_MOVES[i];
		new_column = get_column(get_data(t)) + VERT_MOVES[i];

		//DEBUG
		//printf("Trying to move to (%d, %d)\n", new_row, new_column);

		//Check to see if position is valid and not yet taken
		if (valid(get_data(t), new_row, new_column) && !taken(get_data(t), new_row, new_column))
		{
			//DEBUG
			//printf("Move to (%d, %d) is valid\n", new_row, new_column);
			
			//Clone the game state to create a new state for new position
			game_state new_state = clone_game_state(get_data(t));

			//Mark the new position as visitied and update knight's position in new state
			land(new_state, new_row, new_column);

			//Initialise a new game tree node with the new game state, increment level
			game_tree new_tree;
			init_game_tree(&new_tree, false, new_state, get_level(t) + 1);

			//Set the current node as parent of newly created node
			set_parent(new_tree, t);

			//Check if current node has no children
			if (is_empty_game_tree(get_child(t)))
			{
				//Set the new node as the first child
				set_child(t, new_tree);
			}
			else
			{
				//Otherwise find the last sibling of the current node's first child
				game_tree sibling = get_child(t);
				while (!is_empty_game_tree(get_sibling(sibling)))
				{
					sibling = get_sibling(sibling);
				}
				//Set the new node as the next sibling
				set_sibling(sibling, new_tree);
			}
			//Add the new node to the queue
			add(q, new_tree);
		}
		else
		{
			//DEBUG
			//printf("Move to (%d, %d) is invalid or already taken\n", new_row, new_column);
		}
	}
	trace("generate_levelBF: generate_levelBF ends");
}


/*
	*	build_gameBF
	*	Build the game tree in a breadth-first manner
	*	Pre-condition: the given queue and game tree are defined, and
	*				   the given int value represents the desired depth
	*				   of the tree
	*	Post-condition: If the given tree isn't already deep enough, an
	*					additional level of possible moves is generated for
	*					the given game tree and each tree node of the
	*					new level is also added to the queue.
	*					Finally, the next tree is determined by removing
	*					the front of the queue and the process continues
	*					until the queue is empty
	*	Informally: build the game tree from the current point in a 
	*				breadth-first manner until it is "d" levels deep
	*
	*	Return:	the game tree with the first found solution, or an empty game
	*			tree if there is no solution
	*
	*	Parameter:	t the game tree being built
	*				q a queue of reachable but unexpanded game trees
	*				d the desired depth (length of tour) that game tree should be built to
*/
game_tree build_gameBF(game_tree t, queue q, int d)
{
	//Start tracing of function
	trace("build_gameBF: build_gameBF starts");

	//Add inital game tree to queue
	add(q, t);

	//Process tree until queue is empty
	while (!is_empty_queue(q))
	{
		//Get the game tree at the front of the queue
		game_tree current = front(q);

		//Remove game tree from queue
		rear(q);

		//Check if the current game tree is at the required spot
		if (get_level(current) == d)
		{
			//End tracing of function and return current game tree
			trace("build_gameBF: build_gameBF ends");
			return current;
		}
		//Generate next level of tree in BF manner
		generate_levelBF(current, q);
	}	
	//End tracing of function
	trace("build_gameBF: build_gameBF ends");
		
	//Initalise and return empty game tree if no solution found
	game_tree empty_tree;
	init_game_tree(&empty_tree, true, NULL, -1);
	return empty_tree;
}


/*
*	generate_levelDF
*	Generate the next level of the tree in a depth-first manner
*	Pre-condition: the given tree is defined, the given stack
*				   is defined
*	Post-condition: an additional level of possible moves has
*					been added to the given game tree and each
*					tree node of the new level also has been
*					added to the stack.
*	Informally: generate the next level of the game tree
*
*	Parameter:	t the game tree being expanded
*				k a stack of reachable but unexpanded game trees
*/
void generate_levelDF(game_tree t, stack k)
{
	const char *THINKING = "-\\|/";									// a 'cartwheel' character by character
	const int HORIZ_MOVES[] = { -2, -1, +1, +2, +2, +1, -1, -2 };	// moves left/right
	const int VERT_MOVES[] = { -1, -2, -2, -1, +1, +2, +2, +1 };	// moves up/down
	const int MOVE_COUNT = 8;										// number of potential moves

	int thought = 0;	// to show THINKING 'animation' -- i.e. that the program hasn't crashed (optional)

	trace("generate_levelDF: generate_levelDF starts");

	//COMPLETE ME!

	trace("generate_levelDF: generate_levelDF ends");
}


/*
	*	build_gameDF
	*	Build the game tree in a depth-first manner
	*	Pre-condition: the given stack and game tree are defined, and
	*				   the given int value represents the desired depth
	*				   of the tree
	*	Post-condition: If the given tree isn't already deep enough, an
	*					additional level of possible moves is generated for
	*					the given game tree and each tree node of the
	*					new level is also added to the stack.
	*					Finally, the next tree is determined by removing
	*					the top of the stack and the process continues
	*					until the stack is empty
	*	Informally: build the game tree from the current point in a
	*				depth-first manner until it is "d" levels deep
	*
	*	Return:	the game tree with the first found solution, or an empty game
	*			tree if there is no solution
	*
	*	Parameter:	t the game tree being built
	*				k a stack of reachable but unexpanded game trees
	*				d the desired depth (length of tour) that game tree should be built to
*/
game_tree build_gameDF(game_tree t, stack s, int d)
{
	trace("build_gameDF: build_game starts");

	//COMPLETE ME!

	trace("build_gameDF: build_gameDF ends");
}


/*
	*	to_string_game_tree
	*	String conversion for tree
	*	Pre-condition: none
	*	Post-condition: a string variable is returned consisting of the
	*				string representation of all items in the game_tree,
	*				from top to bottom in depth-first order, separated by
	*				" " and contained within "<" and ">"
	*	Informally: produce a string representation of the game tree
	*
	*	Return: (char *) printable contents of game tree
	* 
	*	Parameter:	t the game tree being displayed
*/
char *to_string_game_tree(game_tree t)
{
	game_tree c;
	char *s;

	trace("to_string_game_tree: to_string_game_tree starts");
		
	if (is_empty_game_tree(t))
	{
		trace("to_string_game_tree: to_string_game_tree ends");
		return "<>";
	}
	else
	{
		s=(char *)malloc(200*5*sizeof(char));

		sprintf(s,"%s (%d,%d) ",s,get_row(get_data(t)),get_column(get_data(t)));
		c=get_child(t);
		if (! is_empty_game_tree(c))
		{
			sprintf(s,"%s %s ",s,to_string_game_tree(c));
		}
		c=get_sibling(t);
		if (! is_empty_game_tree(c))
		{
			sprintf(s,"%s %s ",s,to_string_game_tree(c));
		}
	}

	trace("to_string_game_tree: to_string_game_tree ends");

	return s;
}

