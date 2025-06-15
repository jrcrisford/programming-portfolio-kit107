// KIT107 Assignment 2
/*
 * Implementation for the theme ADT
 * Author Joshua Crisford (574082)
 * Version 06/05/24
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "theme.h"


/* Types */

struct theme_int
{
	theme_format first_set;
};


/* Functions */

/*
* 'Constructor' for themes
* Param pp pointer to themes being constructed
*/
void init_theme(theme *tp)
{
	//Allocate memory for the theme
	*tp = (theme)malloc(sizeof(struct theme_int));

	//Check if memory allocation was successful
	if (*tp == NULL)
	{
		printf("Error failed to allocate memory for theme\n");
		return;
	}

	//Initalise first_set to null to represent there are no sets initialy
	(*tp)->first_set = NULL;
}

/*
* Getter for first_set
* Param p themes variable to examine
* Return first_set field
*/
theme_format get_sets(theme t)
{
	//Return the pointer to first set
	return (t->first_set);
}

/*
* Setter for first_set
* Param p themes variable to update
* Param f value to be placed into the theme's first_set field
*/
void set_sets(theme t, theme_format f)
{
	//Set the pointer to the first set in the theme
	t->first_set = f;
}

/*
* Doer function to add a set to a year
* Param t theme variable to update
* Param s set value to be added into the appropriate theme in chronological order
*/
void add_set_to_theme(theme t, set s)
{
	//Pointer to the first set
	theme_format current_node = t->first_set;
	
	//Keeps track of the previous node set
	theme_format prev_node = NULL;

	//Create a node that holds the new set
	node new_node;
	init_node(&new_node, s);

	//printf("\nADDING %s\n", to_string(s));

	//Move through the linked list until finding where to put the set
	while ((current_node != NULL) && (get_year((set)(get_data(current_node))) < get_year(s)))
	{
		prev_node = current_node;
		current_node = get_next(current_node);
	}

	//Insert the new set
	if (prev_node == NULL)
	{
		//If list is empty insert at the beginning
		set_sets(t, new_node);
	}
	else
	{
		//Insert new set between the previous and current node
		set_next(prev_node, new_node);
	}
	set_next(new_node, current_node);
}
