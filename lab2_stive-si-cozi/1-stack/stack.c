/**
 * 	Laborator 2 SDA-AB: Stive si Cozi, 2017
 * 	Author: Iulian-Razvan Matesica <iulian.matesica@gmail.com>
 */
#include <stdio.h>
#include <limits.h>

/**
 * Structura de mai jos NU reprezinta o stiva, ea reprezinta doar un element
 * dintr-o lista inlantuita. Structura ce defineste o stiva este mai jos.
 *
 * DON'T TOUCH THIS.
 */
typedef struct {
	/* Valoarea retinuta de catre nod. */
	int val;

	/* Pointer catre urmatorul element de tip nod. */
	struct stack_node_t *next;
} stack_node_t;

/**
 * Structura ce reprezinta o Stiva.
 * Stivele pot fi implementate prin mai multe modalitati: vector static/dinamic
 * sau printr-o lista inlantuita.
 *
 * Implementarea prin lista inlantuita este preferata in majoritatea cazurilor
 * pentru ca este foarte eficienta atat din punct de vedere al operatiilor
 * de adaugare/stergere dar si din punct de vedere al memoriei (alocam doar cat
 * avem nevoie).
 *
 * Vom folosi in continuare o stiva implementat printr-o lista inlantuita,
 * O stiva de tipul 'stack_t' va contine capul listei inlantuite. Fiecare
 * element din aceasta lista inlantuita va fi un nod de tipul 'stack_node_t'.
 *
 * DON'T TOUCH THIS.
 */
typedef struct {
	/* Capul listei inlantuite. */
	struct stack_node_t *head;

	/* Dimensiunea stivei. */
	unsigned int length;
} stack_t;

/**
 * TASK 1.
 *
 * Creeaza o stiva vida.
 *
 * Functia nu primeste niciun parametru.
 * Ea doar aloca spatiu de memorie pentru o stiva cu tipul 'stack_t' si
 * returneaza un pointer catre spatiul alocat.
 */
stack_t *stack_create()
{
	stack_t *stack = NULL;

	/* TODO: TASK 1: Alocare memorie pentru o stiva vida. Initializare campuri. */

	return stack;
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
stack_node_t *stack_node_create(int val)
{
	stack_node_t *node = NULL;

	/* TODO: TASK 2, a): Alocare si initializare nod. */

	return node;
}

/**
 * TASK 2, b).
 *
 * Adauga un element nou in stiva.
 *
 * Functia primeste ca parametrii un pointer catre stiva in care se va adauga
 * un element nou cu valoarea 'val'.
 */
void stack_push(stack_t *stack, int val)
{
	stack_node_t *node = NULL;

	/* TODO: Creeare nod. Adaugare in stiva. */

}

/**
 * TASK 3.
 *
 * Afiseaza la stdout (consola) continutul stivei, impreuna cu lungimea ei.
 *
 * Functia primeste ca parametrii un pointer catre stiva care trebuie afisata.
 */
void stack_print(stack_t *stack)
{
	/* TODO: Parcurgere si afisare. */

}

/**
 * TASK 4.
 *
 * Scoate un element din stiva.
 *
 * Functia primeste ca parametrii un pointer catre stiva din care trebuie
 * scos un element.
 *
 * Functia returneaza valoarea retinuta de catre nod.
 */
int stack_pop(stack_t *stack)
{
	int val = 0;

	/* TODO: Identificare nod de tipul 'stack_node_t' ce trebuie scos. */

	/* TODO: Copiere valoare. Stergere nod.*/

	return val;
}

/**
 * TASK 5 a)
 *
 * Functia returneaza valoarea elementului din varful stivei, fara sa stearga
 * elementul.
 *
 * Functia primeste ca parametru un pointer catre stiva din care trebuie
 * intors elementul din varf.
 *
 * In caz ca stiva e vida, se intoarce valoarea constantei INT_MIN. Ea este
 * definita in biblioteca limits.h
 */
int stack_top(stack_t *stack)
{
	int val = 0;

	/* TODO */

	return val;
}

/**
 * TASK 5 b)
 *
 * Functia returneaza 1 daca stiva este vida, 0 in caz contrar.
 *
 * Functia primeste ca parametru un pointer catre stiva.
 */
int stack_empty(stack_t *stack)
{
	/* TODO */

	return 0;
}

/**
 * TASK 5 c)
 *
 * Functia returneaza dimensiunea stivei.
 *
 * Functia primeste ca parametru un pointer catre stiva.
 */
int stack_length(stack_t *stack)
{
	/* TODO */

	return 0;
}

/**
 * Cateva teste pentru fiecare functie.
 */
int main()
{
	int val;

	/* Test TASK 1. DO NOT TOUCH. */
	stack_t *stack = stack_create();

	/* Test TASK 2, 3 si 4. DO NOT TOUCH. */
	stack_push(stack, 3);
	stack_push(stack, 10);
	stack_push(stack, 7);
	stack_print(stack);

	val = stack_pop(stack);
	printf("Valoarea scoasa = %d\n", val);
	stack_print(stack);

	val = stack_pop(stack);
	printf("Valoarea scoasa = %d\n", val);
	stack_print(stack);

	val = stack_pop(stack);
	printf("Valoarea scoasa = %d\n", val);
	stack_print(stack);

	val = stack_pop(stack);
	printf("Valoarea scoasa = %d\n", val);
	stack_print(stack);

	/* TASK 5. */
	stack_push(stack, 5);
	stack_push(stack, 15);
	stack_push(stack, 30);
	stack_push(stack, 1);

	val = stack_top(stack);
	printf("Valoarea din varf = %d\n", val);
	stack_print(stack);

	printf("Dimensiunea stivei = %d\n", stack_length(stack));
	printf("Stiva vida? %s\n", (stack_empty(stack) ? "DA" : "NU"));

  return 0;
}
