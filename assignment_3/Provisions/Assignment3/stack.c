/*
 * Implementation for Stack using linked-list
 *	Author: <<YOUR STUDENT IDs AND NAMES HERE>>
 *	Version: May 2024
 *
 *	This file holds the stack ADT.  It comprises
 *	a top-of-stack field (tos).
 *
 *	YOU NEED TO MAKE CHANGES TO THIS FILE!
 */

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "stack.h"
#include "assig_three124.h"


// types

// internal data structure for the stack
struct stack_int {
	node tos;	// the top item in the stack
};


//functions

/*
	*	init_stack
	*	initialiser function.
	*	Pre-condition: none
	*	Post-condition: create a new stack variable with a NULL tos
	*					field and the address of it assigned to the
	*					parameter (kp)
	*	Informally: creates an empty stack
	* 
	*	Parameter:	kp pointer to stack being created
*/
void init_stack(stack *kp)
{
	trace("stack: Initialiser starts");

	*kp = (stack)malloc(sizeof(struct stack_int));
	(*kp)->tos = NULL;

	trace("stack: Initialiser ends");
}


/*
	*	is_empty_stack
	*	Emptiness test.
	*	Pre-condition: the stack variable is defined and valid
	*	Post-condition: true is returned if the stack variable is
	*					empty, false is returned otherwise
	*	Informally: indicate if the stack contains no nodes
	*
	*	return boolean whether or not the stack is empty
	* 	 
	*	Parameter:	k the stack being examined
*/
bool is_empty_stack(stack k)
{
	trace("is_empty_stack: is_empty_stack starts and ends");

	return k->tos == NULL;
}


/*
	*	top
	*	Find value at top of stack.
	*	Pre-condition: the stack variable is defined and valid
	*	Post-condition: the value at the top of stack is returned
	*	Informally: find the value at the top of stack
	*
	*	Return: (void *) the value on top of the stack
	*
	*	Parameter:	k the stack being examined
*/
void *top(stack k)
{
	trace("top: top starts");

	//Check if stack is empty
	if (is_empty_stack(k))
	{
		fprintf(stderr, "top: empty stack");
		exit(1);
	}

	trace("top: top ends");
	//Return the data of the top node in stack
	return get_data_node(k->tos);
}


/*
	*	pop
	*	Remove top of the stack
	*	Pre-condition: the stack variable is defined and valid
	*	Post-condition: the value at the top of stack is deleted updating
	*					the "tos" field accordingly
	*	Informally: delete the top of the stack
	*
	*	Parameter:	k the stack being altered
*/
void pop(stack k)
{
	trace("pop: pop starts");

	//Check if stack is empty
	if (is_empty_stack(k))
	{
		fprintf(stderr, "pop: empty stack");
		exit(1);
	}
	//Store the current top node in a temp variable
	node temp = k->tos;

	//Update the top of stack to next node in stack
	k->tos = get_next_node(temp);

	//Free memory of old top node
	free(temp);

	trace("pop: pop ends");
}


/*
	*	push
	*	Add item to top of stack
	*	Pre-condition: the stack variable is defined and valid
	*	Post-condition: a new node is created containing the parameter
	*					value (o) in the data field and the existing
	*					stack in the next field and this is inserted 
	*					at the front of the linked list with the tos 
	*					field of the stack parameter (s) set to point
	*					to it
	*	Informally: add an item to the top of the stack
	*
	*	Parameter:	s the stack being altered
	*				o the value to be added to top of stack
*/
void push(stack k,void *o)
{
	trace("push: push starts");

	//Create and initalise new node to add
	node new_node;
	init_node(&new_node, o);

	//Set next node of the new node to the current top of stack
	set_next_node(new_node, k->tos);

	//Update top of stack to be new node
	k->tos = new_node;

	trace("push: push ends");
}


/*
	*	to_string_stack
	*	String conversion for stack
	*	Pre-condition: none
	*	Post-condition: a string value is returned consisting of the
	*				string representation of all items in the stack,
	*				from left to right, separated by " " and contained
	*				within "<" and ">"
	*	Informally: produce a string representation of the stack
	*
	*	Return: (char *) printable contents of stack
	*
	*	Parameter:	s the stack being displayed
	*				f a format string for printing
*/
char *to_string_stack(stack k, char *f)
{
	node c;
	char *fmt = (char *)malloc(10 * sizeof(char));
	char *s=(char *)malloc(100*10*sizeof(char));
	
	if (is_empty_stack(k))
	{
		s = "<>";
	}
	else 
	{
		s[0] = '\0';
		sprintf(fmt, "%%s%s", f);
		c = k->tos;
		while (c != NULL)
		{
			sprintf(s, fmt, s,*(int *)(get_data_node(c)));
			if (get_next_node(c) != NULL)
			{
				sprintf(s, "%s, ", s);
			}
			c = get_next_node(c);
		}
	}
	return s;
}
