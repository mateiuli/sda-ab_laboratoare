#ifndef LIST_H
#define LIST_H

/**
 * TASK 1.
 *
 * Completati structura de mai jos astfel incat sa reprezinte
 * un nod dintr-o lista simplu inlantuita.
 * Valoarea pe care o va retine un nod va fi de tip intreg.
 *
 * Sugestii de nume pentru variabile: val, next. =)
 */
typedef struct {
	/* TODO: Valoarea retinuta de catre nod. */

	/* TODO: Pointer catre urmatorul element de tip nod. */

} node_t;

/**
 * Functia primeste o valoare, creeaza un nou nod cu aceasta
 * valoare si returneaza un pointer catre nodul creat.
 */
node_t *create(int val);


/**
 * Functia creaza un nou nod cu valoarea 'val'
 * si il adauga la finalul listei.
 *
 * Functia returneaza noul cap al listei (daca e cazul), sau vechiul.
 */
node_t *append_node(node_t *list_head, int val);

/**
 * Functia afiseaza la stdout continutul listei.
 * Valorile sunt separate prin virgula.
 */
void print_list(node_t *list_head);

/**
 * Functia creaza un nou nod cu valoarea 'val'
 * si il adauga la finalul liste.
 *
 * Functia returneaza noul cap al listei (daca e cazul), sau vechiul.
 */
node_t *prepend_node(node_t *list_head, int val);

/**
 * Functia primeste un numar intreg si cauta in lista acest numar.
 * Daca gaseste numarul in lista, returneaza nodul care il contine.
 * Daca nu il gaseste returneaza NULL.
 * Daca elementul apare de mai multe ori, se returneaza prima aparitie.
 */
node_t *get_node(node_t *list_head, int val);

/**
 * Functia cauta valoarea 'val' in lista si daca gaseste un element
 * cu aceasta valoare o schimba cu 'new_val'.
 *
 * Functia returneaza un pointer catre acest element, sau
 * NULL daca nodul nu exista.
 */
node_t *modify_node(node_t *list_head, int val, int new_val);

/**
 * Functia creaza un nod nou cu valoarea 'after_val' si il
 * insereaza dupa nodul cu valoarea 'val'.
 * Se returneaza un pointer catre nodul nou creat.
 *
 * Daca nodul cu valoarea 'val' nu exista in lista, lista
 * ramane nemodificata si se returneaza capul listei.
 */
node_t *insert_node(node_t *list_head, int val, int after_val);


/**
 * Functia cauta nodul cu valoarea 'val' si il sterge din lista.
 * Functia returneaza noul cap al listei (daca e cazul), sau vechiul.
 *
 * Daca nodul cu valoarea 'val' nu exista in lista, lista
 * ramane nemodificata si se returneaza capul listei.
 */
node_t *remove_node(node_t *list_head, int val);


#endif
