/**
 * 	Laborator 5 SDA-AB: Stive si Cozi, 2017
 * 	Author: Iulian-Razvan Matesica <iulian.matesica@gmail.com>
 */
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

list_t *list_create()
{
	list_t *list = malloc(sizeof(list_t));
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;

	return list;
}

static list_node_t *list_node_create(int val)
{
	list_node_t *node = malloc(sizeof(list_node_t));
	node->val = val;
	node->next = NULL;
}

void list_add(list_t *list, int val)
{
	if(!list)
		return;

	list_node_t *node = list_node_create(val);
	if(!list->head) {
		list->head = node;
		list->tail = node;
		return;
	}

	list->tail->next = node;
	list->tail = list->tail->next;
	list->length++;
}

void list_print(list_t *list)
{
	list_node_t *node;
	if(!list)
		return;

	node = list->head;
	while(node) {
		printf("%d, ", node->val);
		node = node->next;
	}
}

void list_remove(list_t *list, int val)
{
	if(!list)
		return;

	/* TODO TASK 7: Cautati nodul cu valoarea val in lista si stergeti-l. */

}
