/**
 * 	Laborator 4 SDA-AB: Arbori, 2017
 * 	Author: Iulian-Razvan Matesica <iulian.matesica@gmail.com>
 */

#ifndef QUEUE_H_
#define QUEUE_H

#include <stdio.h>

typedef struct queue_node_t {
	/* Valoarea retinuta de catre nod. */
	void *val;

	/* Pointer catre urmatorul element de tip nod. */
	struct queue_node_t *next;
} queue_node_t;

typedef struct queue_t {
	/* Capul listei inlantuite. */
	struct queue_node_t *head;
	/* Coada listei inlantuite. */
	struct queue_node_t *tail;

	/* Dimensiunea cozii. */
	unsigned int length;
} queue_t;

/**
 * Creeaza o coada vida.
 *
 * Functia nu primeste niciun parametru.
 * Ea doar aloca spatiu de memorie pentru o coada cu tipul 'queue_t' si
 * returneaza un pointer catre spatiul alocat.
 */
queue_t *queue_create();

/**
 * Creeaza un nod nou pentru lista inlantuita.
 *
 * Functia primeste o valoare de tip intreg, aloca dinamic spatiu pentru
 * un nod nou din lista inlantuita, il initializeaza si returneaza
 * un pointer catre acest nod.
 */
queue_node_t *queue_node_create(void *val);

/**
 * Adauga un element nou in coada.
 *
 * Functia primeste ca parametrii un pointer catre coada in care se va adauga
 * un element nou cu valoarea 'val'.
 */
void queue_push(queue_t *queue, void *val);


/**
 * Scoate un element din coada.
 *
 * Functia primeste ca parametrii un pointer catre coada din care trebuie
 * scos un element.
 *
 * Functia returneaza valoarea retinuta de catre nod.
 */
void *queue_pop(queue_t *queue);

/**
 * Functia returneaza valoarea primului element din coada, fara sa il stearga.
 *
 * Functia primeste ca parametru un pointer catre coada din care trebuie
 * intors elementul.
 *
 * In caz ca (virgula) coada e vida, se intoarce valoarea constantei INT_MIN.
 * Ea este definita in biblioteca limits.h
 */
void *queue_front(queue_t *queue);

/**
 * Functia returneaza valoarea ultimului element din coada, fara sa il stearga.
 *
 * Functia primeste ca parametru un pointer catre coada din care trebuie
 * intors elementul.
 *
 * In caz ca (virgula) coada e vida, se intoarce valoarea constantei INT_MIN.
 * Ea este definita in biblioteca limits.h
 */
void *queue_back(queue_t *queue);

/**
 * Functia returneaza 1 daca coada este vida, 0 in caz contrar.
 *
 * Functia primeste ca parametru un pointer catre coada.
 */

int queue_empty(queue_t *queue);

/**
 * Functia returneaza dimensiunea cozii.
 * Functia primeste ca parametru un pointer catre coada.
 */
int queue_length(queue_t *queue);

#endif
