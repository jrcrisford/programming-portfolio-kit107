/*
 * Implementation for Queue using linked-list
 *	Author: <<YOUR STUDENT IDs AND NAMES HERE>>
 *	Version: May 2024
 *
 *	This file holds the queue ADT.  It comprises
 *	a head-of-queue field (first).
 *
 *	YOU NEED TO MAKE CHANGES TO THIS FILE!
 */


#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "queue.h"
#include "assig_three124.h"


// types

// internal data structure for the queue
struct queue_int {
	node first;		// the first item in the queue
};


// functions

/*
	*	init_queue
	*	initialiser function.
	*	Pre-condition: none
	*	Post-condition: create a new queue variable with a NULL first
	*					field and the address of it assigned to the
	*					parameter (qp)
	*	Informally: creates an empty queue
	* 
	*	Parameter:	qp pointer to queue being created
*/
void init_queue(queue *qp)
{
	trace("queue: Initialiser starts");

	*qp = (queue)malloc(sizeof(struct queue_int));
	(*qp)->first = NULL;

	trace("queue: Initialiser ends");
}


/*
	*	is_empty_queue
	*	Emptiness test.
	*	Pre-condition: the queue variable is defined and valid
	*	Post-condition: true is returned if the queue variable is
	*					empty, false is returned otherwise
	*	Informally: indicate if the queue contains no nodes
	*
	*	Return: boolean whether or not the queue is empty
	* 
	*	Parameter:	q the queue being examined
*/
bool is_empty_queue(queue q)
{
	trace("is_empty_queue: is_empty_queue starts and ends");

	return q->first == NULL;
}


/*
	*	front
	*	Find value at front of queue.
	*	Pre-condition: the queue variable is defined and valid
	*	Post-condition: the value at the front of queue is returned
	*	Informally: find the value at the front of queue
	*
	*	Return: (void *) the value at the front of the queue
	*
	*	Parameter:	q the queue being examined
*/
void *front(queue q)
{
	trace("front: front starts");

	if (is_empty_queue(q))
	{
		fprintf(stderr, "front : empty queue");
		exit(1);
	}

	trace("front: front ends");
	return get_data_node(q->first);
}


/*
	*	rear
	*	Remove head of the queue
	*	Pre-condition: the queue variable is defined and valid
	*	Post-condition: the value at the front of queue is deleted updating
	*					the "first" field accordingly
	*	Informally: delete the head of the queue
	*
	*	Parameter:	q the queue being altered
*/
void rear(queue q)
{
	trace("rear: rear starts");

	if (is_empty_queue(q))
	{
		fprintf(stderr, "rear : empty queue");
		exit(1);
	}
	
	//Store the current first node in a temporary variable 
	node temp = q->first;
	//Update the first node to the next node in queue
	q->first = get_next_node(temp);
	//Free the memory of the old first node
	free(temp);

	trace("rear: rear ends");
}


/*
	*	add
	*	Add item to back of queue
	*	Pre-condition: the queue variable is defined and valid
	*	Post-condition: a new node is created containing the parameter
	*					value (o) in the data field and NULL in the
	*					next field and this is inserted at the rear
	*					of the linked list
	*	Informally: add an item to the back of the queue
	*
	*	Parameter:	q the queue being altered
	*				o the value to be added to back of queue
*/
void add(queue q, void *o)
{
	trace("add: add starts");

	//Create and initialise new node to add to queue
	node new_node;
	init_node(&new_node, o);

	//DEBUG
	if (new_node == NULL)
	{
		fprintf(stderr, "Failed to initalise new node\n");
		exit(1);
	}
	else
	{
		//printf("Initialised new node with data: %p\n", get_data_node(new_node));
	}

	//Check if queue is empty
	if (is_empty_queue(q))
	{
		//If queue is empty set new node as the first node
		q->first = new_node;
	}
	else
	{
		//If queue is not empty find the last node
		node temp = q->first;
		while (get_next_node(temp) != NULL)
		{
			temp = get_next_node(temp);
		}
		//Set the new node as the next node of the last node
		set_next_node(temp, new_node);
	}

	trace("add: add ends");
}


/*
	*	to_string_queue
	*	String conversion for queue
	*	Pre-condition: none
	*	Post-condition: a string value is returned consisting of the
	*				string representation of all items in the queue,
	*				from left to right, separated by " " and contained
	*				within "<" and ">"
	*	Informally: produce a string representation of the queue
	*
	*	Return: (char *) printable contents of queue
	*
	*	Parameter:	q the queue being displayed
	*				f a format string for printing
*/
char *to_string_queue(queue q, char *f)
{
	node c;
	char *fmt = (char *)malloc(10 * sizeof(char));
	char *s=(char *)malloc(100*10*sizeof(char));
	
	if (is_empty_queue(q))
	{
		s = "<>";
	}
	else 
	{
		s[0] = '\0';
		sprintf(fmt, "%%s%s", f);
		c = q->first;
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
