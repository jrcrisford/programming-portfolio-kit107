/*
* Implementation for Node
* Author: Julian Dermoudy
* Version: May 2024
*
* This file is complete.
*/

#include <stdlib.h>
#include "node.h"


// types

// internal data structure for the node
struct node_int {
	void *data;
	node next;
};


// functions

/*
	*	init_node
	*	initialiser function.
	*	Pre-condition: none
	*	Post-condition: a new node is created and the node variable's
	*					data field refers to the parameter value (o) and
	*					next is NULL.  The address of the new node is
	*					assigned to the first parameter (np_
	*	Informally: creates a node
	* 
	* 	Parameter:	np pointer to game_state being created
	*				o value to be added within the node
*/
void init_node(node *np, void *o)
{
	*np = (node)malloc(sizeof(struct node_int));
	(*np)->data = o;
	(*np)->next = NULL;
}

/*
	* 	get_data
	*	Get function for data field.
	*	Pre-condition: the node variable is defined and valid
	*	Post-condition: the value of the node variable's data
	*					field is returned
	*	Informally: return the node variable's data field
	*
	*	Return: (void *) the data field of the current node
	* 
	*	Parameter:	n the node being examined
*/
void *get_data_node(node n)
{
	return (n->data);
}

/*
	* 	get_next
	*	Get function for next field.
	*	Pre-condition: the node variable is defined and valid
	*	Post-condition: the value of the node variable's next
	*					field is returned
	*	Informally: return the node variable's next field
	*
	*	Return: node the next field of the current node
	*
	*	Parameter:	n the node being examined
*/
node get_next_node(node n)
{
	return (n->next);
}

/*
	* 	set_data_node
	*	Set function for data field.
	*	Pre-condition: the given node is defined
	*	Post-condition: the value of the node variable's data
	*					field is updated to the given (void *) value
	*	Informally: update the node variable's data
	*
	*	Parameter:	n the node being altered
	*				o value to be placed into the node's data field
*/
void set_data_node(node n, void *o)
{
	n->data = o;
}

/*
	* 	set_next_node
	*	Set function for next field.
	*	Pre-condition: the given node is defined
	*	Post-condition: the value of the node variable's next
	*					field is updated to the given (void *) value
	*	Informally: update the node variable's data
	*
	*	Parameter:	v the node being altered
	*				n value to be placed into the node's next field
*/
void set_next_node(node v, node n)
{
	v->next = n;
}


