/*
*	Game Tree
*	Author: J.R.Dermoudy
*	Version: May 2024
*
*	This file holds the specification of the game_tree.
*
*	This file is complete.
*/

#ifndef _GAME_TREE
#define _GAME_TREE

#include <stdbool.h>
#include "queue.h"
#include "stack.h"

struct game_tree_int;
typedef struct game_tree_int *game_tree;

void init_game_tree(game_tree *tp, bool e, void *o, int l);
bool is_empty_game_tree(game_tree t);
void set_data(game_tree t, void *o);
void *get_data(game_tree t);
void set_level(game_tree t, int l);
int get_level(game_tree t);
void set_parent(game_tree t, game_tree p);
game_tree get_parent(game_tree t);
void set_child(game_tree t, game_tree c);
game_tree get_child(game_tree t);
void set_sibling(game_tree t, game_tree s);
game_tree get_sibling(game_tree t);
void generate_levelBF(game_tree t, queue q);
game_tree build_gameBF(game_tree t, queue q, int d);
void generate_levelDF(game_tree t, stack s);
game_tree build_gameDF(game_tree t, stack s, int d);
char *to_string_game_tree(game_tree t);

#endif