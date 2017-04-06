/**
 * 	Laborator 5 SDA-AB: Stive si Cozi, 2017
 * 	Author: Iulian-Razvan Matesica <iulian.matesica@gmail.com>
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"

queue_t *queue_create()
{
	queue_t *queue;

	queue = (queue_t*)malloc(sizeof(queue_t));
	queue->head = NULL;
	queue->tail = NULL;
	queue->length = 0;

	return queue;
}

queue_node_t *queue_node_create(int val)
{
	queue_node_t *node = NULL;

	node = (queue_node_t*)malloc(sizeof(queue_node_t));
	node->val	= val;
	node->next = NULL;

	return node;
}

void queue_push(queue_t *queue, int val)
{
	queue_node_t *node = queue_node_create(val);

	if(queue == NULL)
		return;

	if(queue->head == NULL) {
		queue->head = node;
		queue->tail = node;
		goto incr_length;
	}

	if(queue->tail != NULL) {
		queue->tail->next = node;
		queue->tail = node;
	}

incr_length:
	queue->length++;
}

int queue_pop(queue_t *queue)
{
	int val = 0;
	queue_node_t *node;

	if(queue == NULL || queue->head == NULL)
		return 0;

	node 	= queue->head;
	val 	= node->val;

	queue->head = queue->head->next;
	queue->length--;

	free(node);
	return val;
}

int queue_front(queue_t *queue)
{
	if(queue == NULL || queue->head == NULL)
		return 0;

	return queue->head->val;
}

int queue_back(queue_t *queue)
{
	if(queue == NULL || queue->tail == NULL)
		return 0;

	return queue->tail->val;
}

int queue_empty(queue_t *queue)
{
	return queue->length == 0;
}

int queue_length(queue_t *queue)
{
	return queue->length;
}
