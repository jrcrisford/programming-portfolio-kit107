// KIT107 Assignment 2
/*
 * Implementation for driver
 *
 * Author Julian Dermoudy
 * Version 17/04/2024
 *
 * THIS FILE IS COMPLETE
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"
#include "collection.h"


/* Functions*/

void read_in_data(collection l)
{
	const char *FILENAME = "data.txt";	// the name of the text file
	const int LIMIT = INT_MAX;			// set to a small number, e.g. 10 when debugging
	const int MAX_LINE_LENGTH = 160;	// maximum length of any line in the text file
	const char *READING = "/-\|";		// for displaying a 'wheel' while the file is being read

	char *line;		// a line of text from the file
	char *tokens;	// the line of text broken up into a stream of vertical-bar separated tokens

	int id;			// the id extracted from the line of text
	char *group;	// the group extracted from the line of text
	char *category;	// the category extracted from the line of text
	char *type;		// the type extracted from the line of text
	int year;		// the year extracted from the line of text
	char *name;		// the name extracted from the line of text
	int pieces;		// the number of pieces extracted from the line of text
	double price;	// the price extracted from the line of text

	FILE *fp;		// the file itself

	set a_set;		// a set
	int count = 0;	// the number of lines (sets) read from the file

	// open the file
	fp = fopen(FILENAME, "r");
	if (fp == NULL)
	{
		// couldn't open the file, so quit
		fprintf(stderr,"Cannot open file.\n");
		exit(1);
	}
	else
	{
		//printf("File opened successfully\n");
		line = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));

		// read in all the set data, one line at a time, stopping at LIMIT
		while ((count < LIMIT) && (fscanf(fp, "%[^\n]\n", line) != EOF))
		{
			//printf("Reading line: %s\n");
			printf("\r%c", READING[count % strlen(READING)]);	// comment out if you don't want this

			// skip lines in the file which are comments
			if (line[0] != '#')
			{
				count++;
				//printf("count is %d\t",count);	// uncomment when debugging
				//printf("%s\n", line);	// uncomment when debugging

				// break up input line into components
				tokens = strtok(line, "\t");
				id = atoi(tokens);

				tokens = strtok(NULL, "\t");
				group = (char *)malloc(20 * sizeof(char));
				sprintf(group, "%s", tokens);
					
				tokens = strtok(NULL, "\t");
				category = (char *)malloc(30 * sizeof(char));
				sprintf(category, "%s", tokens);

				tokens = strtok(NULL, "\t");
				type = (char *)malloc(45 * sizeof(char));
				sprintf(type, "%s", tokens);

				tokens = strtok(NULL, "\t");
				year = atoi(tokens);

				tokens = strtok(NULL, "\t");
				name = (char *)malloc(105 * sizeof(char));
				sprintf(name, "%s", tokens);

				tokens = strtok(NULL, "\t");
				pieces = atoi(tokens);

				tokens = strtok(NULL, "\t");
				price = atof(tokens);

				// create a set based on the components of input line
				init_set(&a_set, id, group, category, type, year, name, pieces, price);
				//printf("%s\n", to_string(a_set));	// uncomment when debugging

				// add created set to the collection
				add_set_to_collection(l , a_set);
				//printf("Added set to collection.\n");
			}
		}
		printf("\r "); // clean up the line of reading progress output...
	}
	fclose(fp);
}

/*
* Entry point
*/
int main(int argc, char *argv[])
{
	collection the_collection;	// the collection!

	// print and underline heading
	printf("Historical LEGO sets\n");
	printf("====================\n\n");

	// initialise collection
	init_collection(&the_collection);
	
	// read data in from file and fill data structures
	read_in_data(the_collection);

	// process and show the results
	list_by_year(the_collection);
	theme_breakdown(the_collection);
	most_expensive(the_collection);
}