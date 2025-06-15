// KIT107 Assignment 2
/*
 * Implementation for the Node ADT
 * Author Julian Dermoudy
 * Version 19/03/2024
 *
 * THIS FILE IS COMPLETE
*/

#include <stdlib.h>
#include "node.h"


/* Types */

struct node_int {
	void *data;
	node next;
};


/* Functions */

/*
* 'Constructor' for node
* Param np pointer to node being constructed
* Param o value to place into data field
*/
void init_node(node *np,void *o)
{
	*np = (node)malloc(sizeof(struct node_int));
	(*np)->data = o;
	(*np)->next = NULL;
}

/*
* Getter for data
* Param n node variable to examine
* Return data field
*/
void *get_data(node n)
{
	return (n->data);
}

/*
* Getter for next
* Param n node variable to examine
* Return next field
*/
node get_next(node n)
{
	return (n->next);
}

/*
* Setter for data
* Param n node variable to update
* Param o value to be placed into the node's data field
*/
void set_data(node n,void *o)
{
	n->data = o;
}

/*
* Setter for next
* Param n1 node variable to update
* Param n2 value to be placed into the node's next field
*/
void set_next(node n1, node n2)
{
	n1->next = n2;
}

