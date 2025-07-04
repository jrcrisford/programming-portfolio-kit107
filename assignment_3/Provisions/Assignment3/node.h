/*
*	Node
*	Author: J.R.Dermoudy
*	Version: May 2024
*
*	This file holds the specification of the linked-list Node.
*
*	This file is complete.
*/

#ifndef _NODE_H
#define _NODE_H

struct node_int;
typedef struct node_int *node;

void init_node(node *np, void *o);
void set_data_node(node n, void *o);
void set_next_node(node v, node n);
void *get_data_node(node n);
node get_next_node(node n);

#endif