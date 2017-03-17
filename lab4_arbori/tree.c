/**
 *  Laborator 4 SDA-AB: Arbori, 2017
 *  Author: Iulian-Razvan Matesica <iulian.matesica@gmail.com>
 */

#include <stdio.h>
#include "queue.h"

/**
 * Structura reprezinta un nod dintr-un arbore binar.
 * Un arbore binar ar doar doi copii: left si right.
 *
 * IT'S MAGIC! DON'T TOUCH THIS!
 */
typedef struct tree_node_t {
  /* Valoarea pe care o retine acest nod. */
  int val;

  /* Pointer catre copilul din stanga. */
  struct tree_node_t *left;
  /* Poiner catre copilul din dreapta. */
  struct tree_node_t *right;

} tree_node_t;

/**
 * Structura reprezinta un arbore.
 * Ea retine un pointer catre radacina arborelui.
 *
 * Radacina este si ea un nod oarecare, de tipul 'tree_node_t'
 * ce are doi copii.
 *
 * Un arbore are o singura radacina, ea se afla pe nivelul 0.
 * MAGIC! DON'T TOUCH!
 */
typedef struct tree_t {
  /* Nodul radacina. */
  tree_node_t *root;
  /* Numarul de noduri total din arbore. */
  unsigned int nodes_count;

} tree_t;

/**
 * TASK 1 a).
 *
 * Functia aloca memorie pentru o structura de tipul 'tree_t'
 * si o initializeaza.
 * Valorea initiala pentru root este NULL (IMPORTANT!).
 *
 * Returneaza un pointer catre zona de memorie alocata.
 */
tree_t *tree_create()
{
  tree_t *tree = NULL;

  /* TODO: Alocare copac si initializare. */

  return tree;
}

/**
 * TASK 1 b).
 *
 * Functia aloca memorie pentru un nod din arbore si il initializeaza
 * cu valoarea primita ca parametru.
 * IMPORTANT: trebuie initializati si membrii 'left' si 'right'!
 *
 * Returneaza un pointer catre nodul creat.
 */
tree_node_t *tree_create_node(int val)
{
  tree_node_t *node = NULL;

  /* TODO: Alocare si initializare nod din copac. */

  return node;
}

/**
 * TASK 2 a).
 *
 * INSERARE NOD: ITERATIV
 * Functia creeaza un nod cu valoarea 'val' si il adauga in arborele 'tree'
 * pe pozitia corespunzatoare.
 * Pozitia este identificata pe baza faptul ca arborele pe care lucram este
 * un arbore binar de cautare.
 *
 * Un nod dintr-un arbre binar de cautare are proprietatile:
 *    - valoarea nodului 'left' este mai mica decat valoarea din nodul curent
 *    - valoarea nodului 'right' este mai mare decat valoarea din nodul curent
 *
 * Trebuie sa gasim nodul de care trebuie legat (parintele trebuie retinut).
 */
void tree_add_node_iterative(tree_t *tree, int val)
{
  if(tree == NULL)
    return;

  /* Pornim de la radacina arborelui. */
  tree_node_t *p = tree->root;
  tree_node_t *parent;

  /* TODO: Cautare iterativa a pozitiei unde trebuie inserat nodul. */
  while(p != NULL) {
    /**
     * TODO: Mergem cu p la stanga sau la dreapta?
     * (retinem parintele).
     */

  }

  /* TODO: Creare nod cu valoarea val. */

  /* TODO: Legare nod de catre parinte (la stanga sau dreapta). */

}

/**
 * BONUS: TASK 2 b).
 *
 * INSERARE NOD: RECURSIV (OPTIONAL!)
 * RECOMANDARE: Lasati-l pe final, mai bine le faceti pe urmatoarele.
 *
 * Se procedeaza asemanator ca la varianta iterativa, difera doar parcurgerea
 * pana se gaseste parintele de care trebuie legat nodul.
 */
void tree_add_node_recursive(tree_node_t **root, int val)
{
  /* Your magic comes here. */
}

/**
 * TASK 3 a).
 *
 * Parcurgere in adancime (DFS).
 *
 * Afisare arbore: pre-ordine.
 * Afisarea arborelui incepe de la nodul primit ca parametru.
 * (de cele mai multe ori, de la radacina (: ).
 *
 * Cel mai usor de facut: recursiv.
 */
void tree_print_dfs_preorder(tree_node_t *root)
{
  /* Do your magic. */
}

/**
 * TASK 3 b).
 *
 * Parcurgere in adancime (DFS).
 *
 * Afisare arbore: in-ordine.
 * Cel mai usor de facut: recursiv.
 */
void tree_print_dfs_inorder(tree_node_t *root)
{
  /* Do your magic. */
}

/**
 * TASK 3 c).
 *
 * Parcurgere in adancime (DFS).
 *
 * Afisare arbore: post-ordine.
 * Cel mai usor de facut: recursiv.
 */
void tree_print_dfs_postorder(tree_node_t *root)
{
  /* Do your magic. */
}

/**
 * TASK 4
 *
 * Parcurgere in latime (BFS).
 *
 * Parcurgerea BFS (Breadth-first search) presupune afisarea mai intai
 * a tuturor nodurilor de pe un nivel inainte sa se treaca la urmatorul.
 *
 * Pentru a putea face acest lucru, avem nevoie sa retinem vecinii unui nod
 * (left si right), sa afisam nodul curent, apoi sa mergem la urmatorul de pe
 * acelasi nivel.
 *
 * Putem folosi o coada pentru a face acest lucru.
 *  1. Initial, adaugam radacina in coada.
 *  2. Cat timp coada nu este vida, extragem un nod din coada (notam cu X).
 *      a) adauga in coada vecinii lui X.
 *      b) afisam nodul X.
 *  3. O sa se iasa din coada cand aceasta devine vida, pentru ca, atunci cand
 *     o sa ajungem la frunze, nu mai avem vecini de adaugat.
 *
 */
void tree_print_bfs(tree_t *tree)
{
  tree_node_t *node;
  /**
   * Folosim coada de la laboratorul trecut. Este deja implementat complet
   * in fisierul queue.c.
   *
   * De data asta, un nod din coada nu mai retine un numar 'int', ci retine
   * un pointer catre un nod din arborele nostru. Adica, o sa adaugam in coada
   * elemente de tipul 'tree_node_t*'.
   *
   * Este important sa facem cast explicit la tipul 'tree_node_t*' cand lucram
   * cu operatii de push si pop. Facem asta pentru ca valoarea unui nod din
   * coada este un pointer la void, 'void *' = un pointer catre orice tip.
   *
   * In cazul nostru, tipul nostru este 'tree_node_t*'.
   */
  queue_t *q = queue_create();

  if(!tree || !tree->root)
    return;

  /**
  * TODO: Adaugare nod radacin in coada.
  * Folositi functia queue_push(queue_t *q, int val);
  */




  /* Cat timp mai avem noduri de vizitat. */
  while(!queue_empty(q)) {
    /* Scoatem un nod din coada. */
    node = (tree_node_t*) queue_pop(q);

    /* TODO: Afisare + adaugarea vecinilor in coada */

  }
}

/**
 * TASK 5 a).
 *
 * CAUTARE NOD: ITERATIV
 *
 * Cautarea unui nod cu valoarea 'val' in arbore.
 * IMPORTANT: Functia primeste ca parametru un pointer catre un arbore!
 *            (aka: tree_t)
 *
 * Functia intoarce un pointer catre nod (de tipul tree_node_t) daca elementul
 * exista in arbore.
 * Daca nu exista intoarce NULL.
 */
tree_node_t *tree_search_iterative(tree_t *tree, int val)
{
  /* Pornim de la radacina arborelui. */
  tree_node_t *p = tree->root;
  /* Pointer catre element. */
  tree_node_t *node = NULL;

  /* Parcurege ca la inserare iterativa. */
  return node;
}

/**
 * TASK 5 b).
 *
 * CAUTARE NOD: RECURSIV
 *
 * IMPORTANT: Functia primeste ca parametru un pointer catre un un nod
 *            din arbore, NU catre un arbore ca la iterativ.
 *            (aka: tree_node_t)
 *            Cautarea se face incepand de la acest nod, in jos.
 *
 * Cautarea unui nod cu valoarea 'val' in arbore.
 * Functia intoarce un pointer catre nod (de tipul tree_node_t) daca elementul
 * exista in arbore.
 * Daca nu exista intoarce NULL.
 */
tree_node_t *tree_search_recursive(tree_node_t *tree, int val)
{
  /* TODO: Having fun? :D */

  /**
   * DELETE ME: I'm here just to keep the compiler from crying... alone...
   * in a corner. (LOL).
   */
  return NULL;
}

/**
 * BONUS: TASK 6.
 *
 * Sterge nodul cu valoarea val din arbore.
 */
void tree_remove(tree_t *tree, int val)
{
  /**
   * Cauta elementul cu valoarea val si il sterge.
   * Cand un element este sters, altul trebuie sa ii ia locul.
   * Fiind vorba de un arbore binar de cautare, urmasului unui nod X
   * este cel mai din stanga nod, din subarborele din dreapta lui X.
   * Notam acest nod cu Y (e de fapt o frunza).
   *
   * Stergerea presupune interschimbarea nodului X cu Y. Astfel, nodul nostru X
   * ii ia locul lui Y si devine frunza. Acum doar stergem frunza (stergem
   * legaturile parintelui catre aceasta frunza dupa care eliberam memoria).
   */

   /* Pentru testare, modifica in main (urmareste comentariile). */
}

int main()
{
  int i;
  tree_node_t *node;
  tree_t *tree = tree_create();

  tree_add_node_iterative(tree, 10);
  tree_add_node_iterative(tree, 5);
  tree_add_node_iterative(tree, 15);
  tree_add_node_iterative(tree, 2);
  tree_add_node_iterative(tree, 7);
  tree_add_node_iterative(tree, 13);
  tree_add_node_iterative(tree, 17);
  tree_add_node_iterative(tree, 1);
  tree_add_node_iterative(tree, 3);

  if(tree == NULL)
    return 0;

  tree_add_node_recursive(&tree->root, 12);
  tree_add_node_recursive(&tree->root, 14);
  tree_add_node_recursive(&tree->root, 16);
  tree_add_node_recursive(&tree->root, 18);

  printf("\nParcurgere pre-ordine:\n");
  tree_print_dfs_preorder(tree->root);

  printf("\nParcurgere in-ordine:\n");
  tree_print_dfs_inorder(tree->root);

  printf("\nParcurgere post-ordine:\n");
  tree_print_dfs_postorder(tree->root);

  printf("\nParcurgere BFS:\n");
  tree_print_bfs(tree);

  for(i = 1; i <= 20; i += 2) {
    printf("%d in arbore? ", i);
    node = tree_search_recursive(tree->root, i);
    printf("%s", (node ? "Recursiv: DA" : "Recursiv: NU   |   "));

    node = tree_search_iterative(tree, i);
    printf("%s", (node ? "Iterativ: DA" : "Iterativ: NU"));
    printf("\n");
  }

  /* TODO: Modifica i <= 1 cu i <= 20. */
  for(i = 1; i <= 1; i += 2) {
    printf("Dupa stergerea lui %d:\n", i);
    tree_remove(tree, i);
    tree_print_bfs(tree);
    printf("\n");
  }

  return 0;
}
