#include "list.h"
#include <stdio.h>

/**
 * TASK 1.
 *
 * Completati structura din fisierul header.
 */

int main()
{	
	printf("Lab 1 - Liste inlantuite.\n");
	
	/**************************************************************************
	 * Test Task 2.
	 * Creati un nod cu o anumita valoare.
	 * Afisati valoarea la stdout.
	 */
	node_t *node = NULL;

	/* ... your code comes here ... */




	/**************************************************************************
	 * Test Task 3.
	 *
	 * Creati o variabila de tip 'node_t' cu numele 'head'.
	 * Ea va reprezenta cap-ul listei cu care veti lucra mai jos.
	 *
	 * Adaugati 5-6 noduri cu valori diferite la final listei.
	 * Aveti un exemplu.
	 */

	/* ... some cool code... */
	node_t *head = NULL;

	head = append_node(head, 42); /* Raspunsul universal :). */
	/* ... more badass code ... */



	/**************************************************************************
	 * Test Task 4.
	 */

	/* ... a long time ago ... */


	/**************************************************************************
	 * Test Task 5.
	 */



	/**************************************************************************
	 * Test Task 5.
	 */

	/* ... in a galaxy far far away ... */


	/**************************************************************************
	 * Test Task 5.
	 */



	/**************************************************************************
	 * Test Task 6.
	 */



	/**************************************************************************
	 * Test Task 7.
	 */



	/**************************************************************************
	 * Test Task 8.
	 */



	/**************************************************************************
	 * Test Task 9.
	 */



	return 0;
}

/**
 * TASK 2.
 *
 * Functia primeste o valoare, creeaza un nou nod cu aceasta
 * valoare si returneaza un pointer catre nodul creat.
 */
node_t *create(int val)
{
	/* TODO */
	return NULL;
}


/**
 * TASK 3.
 *
 * Functia creaza un nou nod cu valoarea 'val' 
 * si il adauga la finalul listei.
 *
 * Functia returneaza noul cap al listei (daca e cazul), sau vechiul.
 */
node_t *append_node(node_t *list_head, int val)
{
	/* TODO */
	return NULL;
}

/**
 * TASK 4.
 *
 * Functia afiseaza la stdout continutul listei.
 * Valorile sunt separate prin virgula.
 */
void print_list(node_t *list_head)
{
	/* TODO */
}

/**
 * TASK 5.
 *
 * Functia creaza un nou nod cu valoarea 'val' 
 * si il adauga la finalul liste.
 *
 * Functia returneaza noul cap al listei (daca e cazul), sau vechiul.
 */
node_t *prepend_node(node_t *list_head, int val)
{
	/* TODO */
	return NULL;
}

/**
 * TASK 6.
 *
 * Functia primeste un numar intreg si cauta in lista acest numar.
 * Daca gaseste numarul in lista, returneaza nodul care il contine.
 * Daca nu il gaseste returneaza NULL.
 * Daca elementul apare de mai multe ori, se returneaza prima aparitie.
 */
node_t *get_node(node_t *list_head, int val)
{
	/* TODO */
	return NULL;
}

/**
 * TASK 7.
 *
 * Functia cauta valoarea 'val' in lista si daca gaseste un element
 * cu aceasta valoare o schimba cu 'new_val'.
 *
 * Functia returneaza un pointer catre acest element, sau
 * NULL daca nodul nu exista.
 */
node_t *modify_node(node_t *list_head, int val, int new_val)
{
	/* TODO */
	return NULL;
}

/**
 * TASK 8.
 *
 * Functia creaza un nod nou cu valoarea 'after_val' si il 
 * insereaza dupa nodul cu valoarea 'val'. 
 * Se returneaza un pointer catre nodul nou creat.
 *
 * Daca nodul cu valoarea 'val' nu exista in lista, lista
 * ramane nemodificata si se returneaza capul listei.
 */
node_t *insert_node(node_t *list_head, int val, int after_val)
{

}


/**
 * TASK 9.
 *
 * Functia cauta nodul cu valoarea 'val' si il sterge din lista.
 * Functia returneaza noul cap al listei (daca e cazul), sau vechiul.
 *
 * Daca nodul cu valoarea 'val' nu exista in lista, lista
 * ramane nemodificata si se returneaza capul listei.
 */
node_t *remove_node(node_t *list_head, int val)
{

}
