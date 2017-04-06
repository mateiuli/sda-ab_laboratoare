/**
 * 	Laborator 5 SDA-AB: Stive si Cozi, 2017
 * 	Author: Iulian-Razvan Matesica <iulian.matesica@gmail.com>
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

stack_t *stack_create()
{
	stack_t *stack = NULL;

	stack = malloc(sizeof(stack_t));
	stack->head = NULL;
	stack->length = 0;

	return stack;
}

stack_node_t *stack_node_create(int val)
{
	stack_node_t *node = NULL;

	node = malloc(sizeof(stack_node_t));
	node->val = val;
	node->next = NULL;

	return node;
}

void stack_push(stack_t *stack, int val)
{
	stack_node_t *node = NULL;
	stack_node_t *old_head;

	if(!stack)
		return;

	old_head = stack->head;
	node = stack_node_create(val);
	stack->head = node;
	stack->length++;
	node->next = old_head;
}

int stack_pop(stack_t *stack)
{
	int val;
	stack_node_t *node;

	if(!stack || !stack->head)
		return -1;

	node = stack->head;
	val = stack->head->val;
	stack->head = stack->head->next;
	stack->length--;

	free(node);
	return val;
}

int stack_top(stack_t *stack)
{
	if(!stack || !stack->head)
		return -1;

	return stack->head->val;
}

int stack_empty(stack_t *stack)
{
	return stack->length == 0;
}

int stack_length(stack_t *stack)
{
	return stack->length;
}
