/**
 * 	Laborator 5 SDA-AB: Stive si Cozi, 2017
 * 	Author: Iulian-Razvan Matesica <iulian.matesica@gmail.com>
 */
#include <stdio.h>
#include <limits.h>

typedef struct stack_node_t {
	int val;
	struct stack_node_t *next;
} stack_node_t;

typedef struct stack_t {
	struct stack_node_t *head;
	unsigned int length;
} stack_t;

/**
 * Creeaza o stiva vida.
 *
 * Functia nu primeste niciun parametru.
 * Ea doar aloca spatiu de memorie pentru o stiva cu tipul 'stack_t' si
 * returneaza un pointer catre spatiul alocat.
 */
stack_t *stack_create();

/**
 * Creeaza un nod nou pentru lista inlantuita.
 *
 * Functia primeste o valoare de tip intreg, aloca dinamic spatiu pentru
 * un nod nou din lista inlantuita, il initializeaza si returneaza
 * un pointer catre acest nod.
 */
stack_node_t *stack_node_create(int val);

/**
 * Adauga un element nou in stiva.
 *
 * Functia primeste ca parametrii un pointer catre stiva in care se va adauga
 * un element nou cu valoarea 'val'.
 */
void stack_push(stack_t *stack, int val);

/**
 * Scoate un element din stiva.
 *
 * Functia primeste ca parametrii un pointer catre stiva din care trebuie
 * scos un element.
 *
 * Functia returneaza valoarea retinuta de catre nod.
 */
int stack_pop(stack_t *stack);

/**
 * Functia returneaza valoarea elementului din varful stivei, fara sa stearga
 * elementul.
 *
 * Functia primeste ca parametru un pointer catre stiva din care trebuie
 * intors elementul din varf.
 *
 * In caz ca stiva e vida, se intoarce valoarea constantei INT_MIN. Ea este
 * definita in biblioteca limits.h
 */
int stack_top(stack_t *stack);

/**
 * Functia returneaza 1 daca stiva este vida, 0 in caz contrar.
 * Functia primeste ca parametru un pointer catre stiva.
 */
int stack_empty(stack_t *stack);

/**
 * Functia returneaza dimensiunea stivei.
 * Functia primeste ca parametru un pointer catre stiva.
 */
int stack_length(stack_t *stack);
