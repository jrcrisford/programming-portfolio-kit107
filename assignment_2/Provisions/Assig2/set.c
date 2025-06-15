// KIT107 Assignment 2
/*
 * Implementation for the Set ADT
 * Author Julian Dermoudy
 * Version 16/04/2024
 *
 * THIS FILE IS COMPLETE
 */

#include <stdio.h>
#include <stdlib.h>
#include "set.h"


/* Types */

struct set_int {
	int id;
	char *group;
	char *category;
	char *type;
	int year;
	char *name;
	int pieces;
	double price;
};


/* Functions*/

/*
* 'Constructor' for set
* Param sp pointer to set being constructed
* Param i id
* Param g group
* Param c category
* Param t type
* Param y year
* Param n name
* Param p pieces
* Param r retail price
*/
void init_set(set *sp, int i, char *g, char *c, char *t, int y, char *n, int p, double r)
{
	// create space for the set
	*sp = (set)malloc(sizeof(struct set_int));

	// update the fields
	(*sp)->id = i;
	(*sp)->group = g;
	(*sp)->category = c;
	(*sp)->type = t;
	(*sp)->year = y;
	(*sp)->name = n;
	(*sp)->pieces = p;
	(*sp)->price = r;
}

/*
* Getter for id
* Param s set variable to examine
* Return id field
*/
int get_id(set s)
{
	return (s->id);
}

/*
* Getter for group
* Param s set variable to examine
* Return group field
*/
char *get_group(set s)
{
	return (s->group);
}

/*
* Getter for category
* Param s set variable to examine
* Return category field
*/
char *get_category(set s)
{
	return (s->category);
}

/*
* Getter for type
* Param s set variable to examine
* Return type field
*/
char *get_type(set s)
{
	return (s->type);
}

/*
* Getter for year
* Param s set variable to examine
* Return year field
*/
int get_year(set s)
{
	return (s->year);
}

/*
* Getter for name
* Param s set variable to examine
* Return name field
*/
char *get_name(set s)
{
	return (s->name);
}

/*
* Getter for pieces
* Param s set variable to examine
* Return pieces field
*/
int get_pieces(set s)
{
	return (s->pieces);
}

/*
* Getter for price
* Param s set variable to examine
* Return price field
*/
double get_price(set s)
{
	return (s->price);
}

/*
* Setter for id
* Param s set variable to update
* Param i value to be placed into the set's id field
*/
void set_id(set s, int i)
{
	s->id = i;
}

/*
* Setter for group
* Param s set variable to update
* Param g value to be placed into the set's group field
*/
void set_group(set s, char *g)
{
	s->group = g;
}

/*
* Setter for category
* Param s set variable to update
* Param c value to be placed into the set's category field
*/
void set_category(set s, char *c)
{
	s->category = c;
}

/*
* Setter for type
* Param s set variable to update
* Param t value to be placed into the set's type field
*/
void set_type(set s, char *t)
{
	s->type = t;
}

/*
* Setter for year
* Param s set variable to update
* Param y value to be placed into the set's year field
*/
void set_year(set s, int y)
{
	s->year = y;
}

/*
* Setter for name
* Param s set variable to update
* Param n value to be placed into the set's name field
*/
void set_description(set s, char *n)
{
	s->name = n;
}

/*
* Setter for pieces
* Param s set variable to update
* Param p value to be placed into the set's pieces field
*/
void set_pieces(set s, int p)
{
	s->pieces = p;
}

/*
* Setter for price
* Param s set variable to update
* Param r value to be placed into the set's price field
*/
void set_price(set s, double r)
{
	s->price = r;
}

/*
* Display function
* Param s set to be displayed
* Return s formatted as a string
*/
char *to_string(set s)
{
	char *r = (char *)malloc(200 * sizeof(char));
	
	sprintf(r, "Set %d \"%s\" (%d) worth $%0.2lf, with %d pieces -- %s | %s | %s", s->id, 
		s->name, s->year, s->price, s->pieces, s->group, s->category, s->type);
	
	return r;
}
