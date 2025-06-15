// KIT107 Assignment 2
/*
 * Implementation for the Collection ADT
 * Author Joshua Crisford (574082)
 * Version 06/05/24
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "collection.h"


/* Types */

struct collection_int
{
	collection_format first_theme;
};


/* Functions */

/*
 * 'Constructor' for collection
 * Param lp pointer to collection being constructed
 */
void init_collection(collection *lp)
{
	//Allocate memory for the collection
	*lp = (collection)malloc(sizeof(struct collection_int));

	//Initalise first_set to null to represent there are no sets initialy
	(*lp)->first_theme = NULL;
}

/*
 * Getter for themes
 * Param l collection variable to examine
 * Return first_theme field
 */
collection_format get_themes(collection l)
{
	return l->first_theme;
}

/*
 * Setter for themes
 * Param l collection variable to update
 * Param f value to be placed into the collection's first_theme field
 */
void set_themes(collection l, collection_format f)
{
	l->first_theme = f;
}

/*
 * Doer function to add a set to the collection
 * Param l collection variable to update
 * Param r value to be added to the collection in alphabetical order of theme and chronological order of year
 */
void add_set_to_collection(collection l, set s)
{
	node new_node;										//The new node to be inserted
	collection_format current_theme = get_themes(l);	//The current theme being examined
	collection_format prev_theme = NULL;				//The previous theme in the collection
	collection_format new_theme = NULL;					//A new theme to be created if necessary

	//Check if the list is empty
	if (get_themes(l) == NULL)
	{
		//Create a new theme and add the set to it
		init_theme(&new_theme);							//Create new theme	
		add_set_to_theme(new_theme, s);					//Add theme to set	
		init_node(&new_node, new_theme);				//Create node for theme
		set_themes(l, new_node);						//Add theme to collection
	}
	//If the list has data
	else
	{		
		//Find the position to put the theme based on alphabetical order
		while ((current_theme != NULL) && (strcmp(get_category((set)get_data(get_sets(get_data(current_theme)))), get_category(s)) < 0))
		{
			//Make the previous theme the current theme
			prev_theme = current_theme;
			current_theme = get_next(current_theme);
		}

		//Check if there is an existing theme and retrieves and compares the category
		if (current_theme != NULL && strcmp(get_category((set)get_data(get_sets(get_data(current_theme)))), get_category(s)) == 0)
		{
			//Add set to theme
			add_set_to_theme(get_data(current_theme), s);
		}
		//If there is no existing theme in collection
		else 
		{
			//Create a new theme and add set to it
			init_theme(&new_theme);						//Create new theme
			add_set_to_theme(new_theme, s);				//Add set to new theme
			init_node(&new_node, new_theme);			//Create node for theme

			//If collection is empty, set new theme as first theme
			if (prev_theme == NULL)
			{
				//Set first theme to new theme
				set_themes(l, new_node);
			}
			//If collection is not empty
			else
			{
				//Insert new theme between previous and current theme
				set_next(prev_theme, new_node);
			}

			//Insert new theme into linked list
			set_next(new_node, current_theme);
		}
	}
}

/*
 * Doer function to display how the number of sets has changed in a range of themes
 * Param l collection variable to process
 */
void list_by_year(collection l)
{
	int year;											//To store the user input year
	bool found_set = false;								//Tracks if sets are found for the input year
	collection_format current_theme = get_themes(l);	//Variable used to iterate through each theme
	
	printf("1. List Collection by Year\n");
	printf("--------------------------\n");
	printf("Enter year: ");
	//Read user input and store in year variable
	scanf("%d", &year);									

	//Check if no themes in collection
	if (current_theme == NULL)
	{
		printf("No themes in the collection\n");
		return;
	}

	//Iterate through each theme
	while (current_theme != NULL)
	{
		//Variable used to iterate through sets in current theme
		theme_format current_set = get_sets((theme)get_data(current_theme));	

		//Check if sets are present in the current theme
		while (current_set != NULL)
		{
			//Stores the year of current set
			int set_year = get_year((set)get_data(current_set));				

			//If the year matches user input print the set's details
			if (set_year == year)
			{
				printf("%s\n", to_string((set)get_data(current_set)));
				found_set = true;
			}
			//Move to the next set
			current_set = get_next(current_set);								
		}
		//Move to the next theme
		current_theme = get_next(current_theme);								
	}

	//If not sets found for input year
	if (!found_set)
	{
		printf("No set data for %d!\n", year);
	}
}
	
/*
 * Doer function to display histogram of port connectivity in the specified theme
 * Param l collection variable to process
 */
void theme_breakdown(collection l)
{
	//Retrieve first theme from collection
	collection_format current_theme = get_themes(l);

	printf("\n2. Distribution of Sets by Theme\n");
	printf("--------------------------------\n");
	
	//Check if no themes in collection
	if (current_theme == NULL)
	{
		printf("No set data to search.\n");
		return;
	}

	//Iterate through each theme in collection and print distribution of sets
	while (current_theme != NULL)
	{
		
		char* theme_name = get_category((set)get_data(get_sets((theme)get_data(current_theme))));	//Retrieve the name of the current theme	
		int set_count = 0;																			//Holds count of sets in the teme
		theme_format current_set = get_sets((theme)get_data(current_theme));						//Retrieve the first set in the current theme

		//Count sets in the theme
		while (current_set != NULL)
		{
			set_count++;
			current_set = get_next(current_set);
		}

		//Find number of asterisks based on the set count
		int asterisks = set_count / 100 + (set_count % 100 != 0 ? 1 : 0);

		//Print theme name, set count and asterisks
		printf("%s %d | ", theme_name, set_count);
		for (int i = 0; i < asterisks; i++)
		{
			printf("*");
		}
		printf("\n");

		//Move to the next theme in the collection
		current_theme = get_next(current_theme);
	}
}

/*
 * Doer function to display the sets with maximum price 
 * Param l collection variable to process
 */
void most_expensive(collection l)
{
	double max_price = 0.0;								//Stores the maximum price found
	set* max_price_sets = NULL;							//Pointer to an array of sets with the maximum price
	int max_count = 0;									//Counter for the number of sets with the maximum price
	collection_format current_theme = get_themes(l);	//Get the first theme from the collection

	//Iterate through each theme in the collection
	while (current_theme != NULL)
	{
		//Get the sets within the current theme
		theme_format current_set = get_sets((theme)get_data(current_theme));

		//Iterate through each set in the theme
		while (current_set != NULL)
		{
			set s = (set)get_data(current_set);			//Store set data
			double price = get_price(s);				//Store set price

			//If price of current set is greater the price(s) found so far update max_price
			if (price > max_price)
			{
				max_price = price;

				//Allocate memory for a new array to store the set(s)
				max_price_sets = malloc(sizeof(set));

				//Check if memory allocation failed and, if so, free any previously allocated memory
				if (max_price_sets == NULL)
				{
					printf("Memory allocation for max_price_sets failed\n");
					free(max_price_sets);
					return;
				}

				//Copy the set data to max_price_sets
				*max_price_sets = s;
				max_count = 1;
			}
			//If the price of the cuurent set matches that of highest price found so far
			else if (price == max_price)
			{
				max_count++;

				//Reallocate memory for the additional set
				max_price_sets = realloc(max_price_sets, max_count * sizeof(set));

				//Check if memory allocation failed and, if so, free any previously allocated memory
				if (max_price_sets == NULL)
				{
					printf("Memory allocation for max_price_sets failed\n");
					free(max_price_sets);
					return;
				}
				//Store the current set in the array
				max_price_sets[max_count - 1] = s;
			}	
			//Move to next set in theme
			current_set = get_next(current_set);
		}
		//Move to next theme in collection
		current_theme = get_next(current_theme);
	}

	//Print result
	printf("\n3. Most Expensive Set\n");
	printf("---------------------\n");

	//Check if there are no sets in the collection
	if (max_price_sets == NULL)
	{
		printf("No set data to search");
	}
	else
	{
		printf("The maximum cost for a set in the collection is $%0.2lf\n", max_price);
		printf("The set(s) with that price are:\n");
		
		//Print each set with the maximum price
		for (int i = 0; i < max_count; i++)
		{
			printf("%s\n", to_string(max_price_sets[i]));
		}
	}

	//Free memory allocated to max_price_sets
	free(max_price_sets);
}
