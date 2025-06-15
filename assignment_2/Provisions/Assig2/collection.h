// KIT107 Assignment 2
/*
 * Specification for the Collection ADT
 * Author Joshua Crisford
 * Version 06/05/24
 */

#ifndef COLLECTION_H
#define COLLECTION_H

#include "node.h"
#include "set.h"
#include "theme.h"

//Define the format for collection nodes
typedef node collection_format;

//Define the collection ADT
struct collection_int;
typedef struct collection_int *collection;

void init_collection(collection *lp);
collection_format get_themes(collection l);
void set_themes(collection l, collection_format f);
void add_set_to_collection(collection l, set s);
void list_by_year(collection l);
void theme_breakdown(collection l);
void most_expensive(collection l);

#endif