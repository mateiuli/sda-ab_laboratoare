/**
 * 	Laborator 2 SDA-AB: Stive si Cozi, 2017
 * 	Author: Iulian-Razvan Matesica <iulian.matesica@gmail.com>
 */
#include <stdio.h>
#include <limits.h>

/**
 * Structura de mai jos NU reprezinta o coada, ea reprezinta doar un element
 * dintr-o coada implementat ca o lista inlantuita.
 *
 * DON'T TOUCH THIS.
 */
typedef struct {
	/* Valoarea retinuta de catre nod. */
  int val;

	/* Pointer catre urmatorul element de tip nod. */
  struct queue_node_t *next;
} queue_node_t;

/**
 * Structura ce reprezinta o coada.
 * Cozile pot fi implementate prin mai multe modalitati: vector static/dinamic
 * sau printr-o lista inlantuita.
 *
 * Implementarea prin lista inlantuita este preferata in majoritatea cazurilor
 * pentru ca este foarte eficienta atat din punct de vedere al operatiilor
 * de adaugare/stergere dar si din punct de vedere al memoriei (alocam doar cat
 * avem nevoie).
 *
 * Vom folosi in continuare o coada implementat printr-o lista inlantuita,
 * O coada de tipul 'queue_t' va contine un pointer catre primul nod si un
 * pointer catre ultimul nod.
 *
 * Fiecare element din aceasta lista inlantuita va fi un nod de tipul
 * 'queue_node_t'.
 *
 * DON'T TOUCH THIS.
 */
typedef struct {
  /* Capul listei inlantuite. */
  struct queue_node_t *head;
	/* Coada listei inlantuite. */
	struct queue_node_t *tail;

  /* Dimensiunea cozii. */
  unsigned int length;
} queue_t;

/**
 * TASK 1.
 *
 * Creeaza o coada vida.
 *
 * Functia nu primeste niciun parametru.
 * Ea doar aloca spatiu de memorie pentru o coada cu tipul 'queue_t' si
 * returneaza un pointer catre spatiul alocat.
 */
queue_t *queue_create()
{
	queue_t *queue = NULL;

	/* TODO: TASK 1: Alocare memorie pentru o coada vida. Initializare campuri. */

	return queue;
}

/**
 * TASK 2, a)
 *
 * Creeaza un nod nou pentru lista inlantuita.
 *
 * Functia primeste o valoare de tip intreg, aloca dinamic spatiu pentru
 * un nod nou din lista inlantuita, il initializeaza si returneaza
 * un pointer catre acest nod.
 */
queue_node_t *queue_node_create(int val)
{
	queue_node_t *node = NULL;

	/* TODO: TASK 2, a): Alocare si initializare nod. */

	return node;
}

/**
 * TASK 2, b).
 *
 * Adauga un element nou in coada.
 *
 * Functia primeste ca parametrii un pointer catre coada in care se va adauga
 * un element nou cu valoarea 'val'.
 */
void queue_push(queue_t *queue, int val)
{
	queue_node_t *node = NULL;

	/* TODO: Creeare nod. Adaugare in coada. */

}

/**
 * TASK 3.
 *
 * Afiseaza la stdout (consola) continutul cozii, impreuna cu lungimea ei.
 *
 * Functia primeste ca parametrii un pointer catre coada care trebuie afisata.
 */
void queue_print(queue_t *queue)
{
	/* TODO: Parcurgere si afisare. */

}

/**
 * TASK 4.
 *
 * Scoate un element din coada.
 *
 * Functia primeste ca parametrii un pointer catre coada din care trebuie
 * scos un element.
 *
 * Functia returneaza valoarea retinuta de catre nod.
 */
int queue_pop(queue_t *queue)
{
	int val = 0;

	/* TODO: Identificare nod de tipul 'queue_node_t' ce trebuie scos. */

	/* TODO: Copiere valoare. Stergere nod.*/

	return val;
}

/**
 * TASK 5 a)
 *
 * Functia returneaza valoarea primului element din coada, fara sa il stearga.
 *
 * Functia primeste ca parametru un pointer catre coada din care trebuie
 * intors elementul.
 *
 * In caz ca (virgula) coada e vida, se intoarce valoarea constantei INT_MIN.
 * Ea este definita in biblioteca limits.h
 */
int queue_front(queue_t *queue)
{
	int val = 0;

	/* TODO */

	return val;
}

/**
 * TASK 5 b)
 *
 * Functia returneaza valoarea ultimului element din coada, fara sa il stearga.
 *
 * Functia primeste ca parametru un pointer catre coada din care trebuie
 * intors elementul.
 *
 * In caz ca (virgula) coada e vida, se intoarce valoarea constantei INT_MIN.
 * Ea este definita in biblioteca limits.h
 */
int queue_back(queue_t *queue)
{
	int val = 0;

	/* TODO */

	return val;
}

/**
 * TASK 5 c)
 *
 * Functia returneaza 1 daca coada este vida, 0 in caz contrar.
 *
 * Functia primeste ca parametru un pointer catre coada.
 */
int queue_empty(queue_t *queue)
{
	/* TODO */

	return 0;
}

/**
 * TASK 5 d)
 *
 * Functia returneaza dimensiunea cozii.
 *
 * Functia primeste ca parametru un pointer catre coada.
 */
int queue_length(queue_t *queue)
{
	/* TODO */

	return 0;
}

/**
 *
 */
int main()
{
	int val;

	/* Test TASK 1. DO NOT TOUCH. */
	queue_t *queue = queue_create();

	/* Test TASK 2, 3 si 4. DO NOT TOUCH. */
	queue_push(queue, 3);
	queue_push(queue, 10);
	queue_push(queue, 7);
	queue_print(queue);

	val = queue_pop(queue);
	printf("Valoarea scoasa = %d\n", val);
	queue_print(queue);

	val = queue_pop(queue);
	printf("Valoarea scoasa = %d\n", val);
	queue_print(queue);

	val = queue_pop(queue);
	printf("Valoarea scoasa = %d\n", val);
	queue_print(queue);

	val = queue_pop(queue);
	printf("Valoarea scoasa = %d\n", val);
	queue_print(queue);

	/* TASK 5. */
	queue_push(queue, 5);
	queue_push(queue, 15);
	queue_push(queue, 30);
	queue_push(queue, 1);

	val = queue_front(queue);
	printf("Valoarea primului element = %d\n", val);
	queue_print(queue);

	val = queue_back(queue);
	printf("Valoarea ultimului element = %d\n", val);
	queue_print(queue);

	printf("Dimensiunea cozii = %d\n", queue_length(queue));
	printf("coada vida? %s\n", (queue_empty(queue) ? "DA" : "NU"));

  return 0;
}
