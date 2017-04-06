/**
 * 	Laborator 5 SDA-AB: Stive si Cozi, 2017
 * 	Author: Iulian-Razvan Matesica <iulian.matesica@gmail.com>
 */
#ifndef LIST_H
#define LIST_H

typedef struct list_node_t {
	int val;
	struct list_node_t *next;

} list_node_t;

typedef struct list_t {
	struct list_node_t *head;
	struct list_node_t *tail;
	unsigned int length;

} list_t;

/**
 * Aloca memorie pentru o lista vida.
 */
list_t *list_create();

/**
 * Functia creaza un nou nod cu valoarea 'val'
 * si il adauga la finalul listei.
 */
void list_add(list_t *list, int val);

/**
 * Functia afiseaza la stdout continutul listei.
 * Valorile sunt separate prin virgula.
 */
void list_print(list_t *list);

/**
 * Functia cauta nodul cu valoarea 'val' si il sterge din lista.
 */
void list_remove(list_t *list, int val);

#endif
