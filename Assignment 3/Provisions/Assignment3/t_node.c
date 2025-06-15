/*
 *	Tree Node ADT
 *	Author: <<YOUR STUDENT IDs AND NAMES HERE>>
 *	Version: May 2024
 *	
 *	This file holds the Tree Node ADT which represents
 *	the nodes in a doubly-linked general tree.  Tree
 *	nodes consist of a "data" field, a level number
 *	("level"), and three references to other nodes 
 *	(these being the parent node ("parent"), the child
 *	node ("child") and the next eldest sibling node
 *	("sibling")).
 *	
 *	YOU NEED TO MAKE CHANGES TO THIS FILE!
 */


#include <stdlib.h>
#include "assig_three124.h"
#include "t_node.h"


//types

// internal data structure for t_node
struct t_node_int
{
	void *data;		// the value stored in the node
	int level;		// the level of the current node
	t_node parent;	// the parent node of the current node
	t_node child;	// the eldest child node of the current node
	t_node sibling;	// the next eldest node of the current node
};


// functions

/*
	*	init_t_node
	*	Initialiser function
	*	Pre-condition: none
	*	Post-condition: the t_node variable holds the parameter value
	*					(o) within its "data" field, the parameter
	*					value (l) within its "level" field, and its
	*					"child", "sibling", and "parent" fields are
	*					null
	*	Informally: intialises the fields of the newly
	*				created t_node variable to hold the given parameters
	*				and to terminate the "child", "sibling", and
	*				"parent" fields
	*
	*	Parameter:	tp a pointer to the t_node being created
	*				o intended value for the data field
	*				l intended value for the level field
*/
void init_t_node(t_node *tp, void *o, int l)
{
    trace("t_node: Initialiser starts");

	//Allocate memory for new t_node
	*tp = (t_node)malloc(sizeof(struct t_node_int));	
	
	//Set t_node data and level fields
	(*tp)->data = o;							
	(*tp)->level = l;

	//Initalise t_node family fields
	(*tp)->parent = NULL;
	(*tp)->child = NULL;
	(*tp)->sibling = NULL;

    trace("t_node: Initialiser ends");
}


/*
	*	set_t_node_data
	*	Set function for "data" field.
	*	Pre-condition: none
	*	Post-condition: the t_node varable's data field is altered to
	*					hold the given (o) value
	*	Informally: assign the value of the parameter to the t_node
	*				variable's "data" field
	* 
	*	Parameter:	t the t_node being altered
	*				o intended value for the data field
*/
void set_t_node_data(t_node t, void *o)
{
    trace("set_t_node_data: set_t_node_data starts");

	t->data=o;

    trace("set_t_node_data: set_t_node_data ends");
}
	
	
/*
	*	set_t_node_level
	*	Set function for "level" field.
	*	Pre-condition: none
	*	Post-condition: the t_node variable's level field is altered to
	*					hold the given (l) value
	*	Informally: assign the value of the parameter to the t_node
	*				variable's "level" field
	*
	*	Parameter:	t the t_node being altered
	*				l intended value for the level field
*/
void set_t_node_level(t_node t, int l)
{
    trace("set_t_node_level: set_t_node_level starts");

	t->level = l;

    trace("set_t_node_level: set_t_node_level ends");
}
	
	
/*
	*	set_t_node_parent
	*	Set function for "parent" field.
	*	Pre-condition: none
	*	Post-condition: the t_node variable's parent field is altered
	*					to hold the given (n) value
	*	Informally: assign the value of the parameter to the t_node
	*				variable's "parent" field
	*
	*	Parameter:	t the t_node being altered
	*				n intended value for the parent field
*/
void set_t_node_parent(t_node t, t_node n)
{
	trace("set_t_node_parent: set_t_node_parent starts");

	t->parent = n;

	trace("set_t_node_parent: set_t_node_parent ends");
}


/*
*	set_t_node_child
	*	Set function for "child" field.
	*	Pre-condition: none
	*	Post-condition: the t_node variable's child field is altered
	*					to hold the given (n) value
	*	Informally: assign the value of the parameter to the t_node
	*				variable's "child" field
	*
	*	Parameter:	t the t_node being altered
	*				n intended value for the child field
*/
void set_t_node_child(t_node t, t_node n)
{
	trace("set_t_node_child: set_t_node_child starts");

	t->child = n;

	trace("set_t_node_child: set_t_node_child ends");
}


/*
	*	set_t_node_sibling
	*	Set function for "sibling" field.
	*	Pre-condition: none
	*	Post-condition: the t_node variable's sibling field is altered
	*					to hold the given (n) value
	*	Informally: assign the value of the parameter to the t_node
	*				variable's "sibling" field
	*
	*	Parameter:	t the t_node being altered
	*				n intended value for the sibling field
*/
void set_t_node_sibling(t_node t, t_node n)
{
	trace("set_t_node_sibling: set_t_node_sibling starts");

	t->sibling = n;

	trace("set_t_node_sibling: set_t_node_sibling ends");
}


/*
	*	get_t_node_data
	*	Get function for "data" field.
	*	Pre-condition: none
	*	Post-condition: the t_node variable's data field is returned
	*	Informally: examine the t_node variable's "data" instance
	*				variable returning its value
	*
	*	Return: (void *) the item in the data field of t
	*
	*	Parameter:	t the t_node being examined
*/
void *get_t_node_data(t_node t)
{
    trace("get_t_node_data: get_t_node_data starts and ends");

	return t->data;
}
	
	
/*
	*	get_t_node_level
	*	Get function for "level" field.
	*	Pre-condition: none
	*	Post-condition: the t_node variable's level field is
	*				returned
	*	Informally: examine the t_node variable's "level" instance
	*				variable returning its value
	*
	*	Return: int the value in the level field of t
	*
	*	Parameter:	t the t_node being examined
*/
int get_t_node_level(t_node t)
{
    trace("get_t_node_level: get_t_node_level starts and ends");

	return t->level;
}
	
	
/*
	*	get_t_node_parent
	*	Get function for "parent" field.
	*	Pre-condition: none
	*	Post-condition: the t_node variable's parent field is
	*					returned
	*	Informally: examine the t_node variable's "parent"
	*				field returning its value
	*
	*	Return: t_node the value in the parent field of t
	*
	*	Parameter:	t the t_node being examined
*/
t_node get_t_node_parent(t_node t)
{
	trace("get_t_node_parent: get_t_node_parent starts and ends");

	return t->parent;
}


/*
	*	get_t_node_child
	*	Get function for "child" field.
	*	Pre-condition: none
	*	Post-condition: the t_node variable's child field is
	*					returned
	*	Informally: examine the t_node variable's "child"
	*				field returning its value
	*
	*	Return: t_node the value in the child field of t
	*
	*	Parameter:	t the t_node being examined
*/
t_node get_t_node_child(t_node t)
{
	trace("get_t_node_child: get_t_node_child starts and ends");

	return t->child;
}


/*
	*	get_t_node_sibling
	*	Get function for "sibling" field.
	*	Pre-condition: none
	*	Post-condition: the t_node variable's sibling field is
	*					returned
	*	Informally: examine the t_node variable's "sibling"
	*				field returning its value
	*
	*	Return: t_node the value in the sibling field of t
	*
	*	Parameter:	t the t_node being examined
*/
t_node get_t_node_sibling(t_node t)
{
	trace("get_t_node_sibling: get_t_node_sibling starts and ends");

	return t->sibling;
}
