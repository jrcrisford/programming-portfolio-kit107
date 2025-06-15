// KIT107 Assignment 2
/*
 * Specification for the set ADT
 * Author Julian Dermoudy
 * Version 16/04/2024
 *
 * THIS FILE IS COMPLETE
 */

#ifndef set_H
#define set_H

struct set_int;
typedef struct set_int *set;

void init_set(set *sp, int i, char *g, char *c, char *t, int y, char *n, int p, double r);
int get_id(set s);
char *get_group(set s);
char *get_category(set s);
char *get_type(set s);
int get_year(set s);
char *get_name(set s);
int get_pieces(set s);
double get_price(set s);
void set_id(set s, int i);
void set_group(set s, char *g);
void set_category(set s, char *c);
void set_type(set s, char *t);
void set_year(set s, int y);
void set_namen(set s, char *n);
void set_pieces(set s, int p);
void set_price(set s, double r);
char *to_string(set s);

#endif