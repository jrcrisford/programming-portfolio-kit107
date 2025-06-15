// KIT107 Assignment 2
/*
 * Specification for the theme ADT
 * Author Joshua Crisford (574082)
 * Version 06/05/24
 */

#ifndef theme_H
#define theme_H

#include "node.h"
#include "set.h"

//Define theme_format as a pointer to a linked list node  
//representing a cluster of sets within a theme
typedef node theme_format;

//Declaration of the theme structure
struct theme_int;

//Define theme as a pointer to the theme structure
typedef struct theme_int *theme;

void init_theme(theme *tp);
theme_format get_sets(theme t);
void set_sets(theme t, theme_format f);
void add_set_to_theme(theme t, set s);

#endif