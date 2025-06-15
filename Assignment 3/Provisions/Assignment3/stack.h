/*
*	Stack
*	Author: J.R.Dermoudy
*	Version: May 2024
*
*	This file holds the specification of the Stack.
*
*	This file is complete.
*/

#ifndef _STACK
#define _STACK

#include <stdbool.h>

struct stack_int;
typedef struct stack_int *stack;

void init_stack(stack *kp);
bool is_empty_stack(stack k);
void push(stack k, void *o);
void *top(stack k);
void pop(stack k);

#endif