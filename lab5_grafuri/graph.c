/**
 * 	Laborator 5 SDA-AB: Stive si Cozi, 2017
 * 	Author: Iulian-Razvan Matesica <iulian.matesica@gmail.com>
 */
#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "stack.h"
#include "queue.h"

/**
 * Structura retine un graf bazat pe liste de adiacenta.
 * Fiecare nod din graf este reprentat de o structura 'graph_node_t'.
 *
 * Elementul cu indicele X din vector este un element de tipul 'list_t'
 * care are retine intr-o lista inlantuita vecinii nodului X.
 */
typedef struct graph_t {
  /* Vector dinamic de liste inlantuite cu vecinii fiecarui nod. */
  list_t **nodes;

  /* Numarul de noduri din graf. */
  unsigned int num_nodes;
} graph_t;

/**
 * TASK 1.
 *
 * Functia aloca memorie pentru o structura de tipul 'graph_t'.
 *
 * Initializeaza campul 'num_nodes' din structura.
 * Aloca memorie pentru 'num_nodes' noduri, unde fiecare element este o lista
 * inlantuita de tipul 'list_t'.
 */
graph_t *graph_create(int num_nodes)
{
  graph_t *graph = NULL;

  /* TODO: Alocare structura. */


  /* TODO: Initializare num_nodes. */


  /* TODO: Alocare memorie pentru vectorul de noduri. */


  /**
   * TODO: Pentru fiecare nod din vector, creati cate o lista vida.
   * Studiati fisierul 'list.h' pentru identificarea functiei care aloca
   * memorie pentru o astfel de lista.
   */

  return graph;
}

/**
 * TASK 2.
 *
 * Functia creeaza legatura de la nodul cu indicele 'from_node' si nodul
 * cu indicele 'to_node' in graf-ul 'graph'.
 *
 * Pentru graf neorientat trebuie adaugata si legatura inversa, de la
 * 'to_node' la 'from_node'.
 */
void graph_add(graph_t *graph, int from_node, int to_node)
{
  if(!graph || !graph->nodes)
    return;

  if(from_node >= graph->num_nodes || to_node >= graph->num_nodes)
    return;

  /* TODO: Studiati 'list.h'. */
}

/**
 * TASK 3.
 *
 * Afisati intreg graful, fiecare nod pe o linie impreuna cu vecinii lui.
 * <nod X>: <vecin_1>, <vecin_2>, ...
 */
void graph_print(graph_t *graph)
{
  if(!graph || !graph->nodes)
    return;

}

/**
 * TASK 4.
 *
 * Cititi graful din fisierul 'filename'.
 * Trebuie sa alocati memorie pentru structura 'graph' cu 'num_nodes' noduri.
 * Apoi trebuie citit, pentru fiecare nod, lista lui de vecini.
 *
 * Structura fisierului de intrare este urmatoarea:
 *    - pe prima linie se afla numarul de noduri 'num_nodes'.
 *    - pe urmatoarele 'num_nodes' linii se afla lista de vecini
 *      a fiecarui nod sub urmatoarea forma:
 *          <ID_NOD> <NR_VECINI> <VECIN1> <VECIN2> ...
 *
 * Functia returneaza un pointer catre o structura de tip 'graph_t',
 * populata cu informatiile din fisier.
 *
 * HINT: folositi functiile implementate mai sus. :)
 */
graph_t *graph_read(const char *filename)
{
  graph_t *graph = NULL;
  FILE *file = NULL;

  /* TODO: Deschidere fisier. */


  /* TODO: Citire 'num_nodes' si alocare memorie pentru structura 'graph_t'. */


  /* TODO: Citirea si salvarea vecinilor fiecarui nod, din fisier. */


  /* TODO: Inchidere fisier. */


  return graph;
}

/**
 * TASK 5.
 *
 * Realizati o parcurgere in latime a grafului 'graph', pornind de la
 * nodul 'start_nod'.
 *
 * Algoritmul BFS (Breadth First Search) este implementat cu o coada.
 * Folositi coada 'queue_t' cu operatiile descrise in fisierul
 * 'queue.h'. Coada accepta elemente de tipul 'int'.
 *
 * ATENTIE: Trebuie implementat un mecanism prin care sa identificam daca
 * am vizitat deja un nod (graful are cicluri).
 */
void graph_bfs(graph_t *graph, int start_nod)
{
  if(!graph || !graph->nodes)
    return;

  /* Alocare memorie pentru o coada vida. */
  queue_t *q = queue_create();

  /* TODO: Adaugarea primului nod in coada. */


  /* TODO: Identificare si initializare mecanism pentru marcare ca vizitat. */


  /* Cat timp mai avem noduri de vizitat. */
  while(!queue_empty(q)) {
    /* Scoatem un nod din coada. */
    int node = queue_pop(q);

    /* TODO: Afisare nod. */


    /* TODO: Marcare ca vizitat. */


    /* TODO: Adaugare in coada vecinii nevizitati ai lui 'node'. */


  }
}

/**
 * TASK 6.
 *
 * Realizati o parcurgere in adancime a grafului 'graph', pornind de la
 * nodul 'start_nod'.
 *
 * Algoritmul DFS (Depth First Search) este implementat cu o stiva.
 * Folositi stiva 'stack_t' cu operatiile descrise in fisierul
 * 'stack.h'. Stiva accepta elemente de tipul 'int'.
 *
 * ATENTIE: Trebuie implementat un mecanism prin care sa identificam daca
 * am vizitat deja un nod (graful are cicluri).
 */
void graph_dfs(graph_t *graph, int start_nod)
{
  if(!graph || !graph->nodes)
    return;

  /* Alocare memorie pentru o stiva vida. */
  stack_t *s = stack_create();

  /* TODO: Adaugarea primului nod in stiva. */


  /* TODO: Identificare si initializare mecanism pentru marcare ca vizitat. */


  /* Cat timp mai avem noduri de vizitat. */
  while(!stack_empty(s)) {
    /* Scoatem un nod din coada. */
    int node = stack_pop(s);

    /* TODO: Afisare nod. */


    /* TODO: Marcare ca vizitat. */


    /* TODO: Adaugare in stiva vecinii nevizitati ai lui 'node'. */


  }
}

/**
 * BONUS: TASK 7.
 *
 * Functia sterge legatura de la nodul cu indicele 'from_node' si nodul
 * cu indicele 'to_node' in graf-ul 'graph'.
 *
 * Pentru graf neorientat trebuie stearsa si legatura inversa, de la
 * 'to_node' la 'from_node'.
 */
void graph_del(graph_t *graph, int from_node, int to_node)
{
  if(!graph || !graph->nodes)
    return;

  if(from_node >= graph->num_nodes || to_node >= graph->num_nodes)
    return;

  /*
   * TODO: Implementati functia list_remove() din 'list.c'.
   * Urmariti TODO de acolo.
   */
}

/**
 * BONUS: TASK 8.
 *
 * Verfica daca exista un subgraf conex care sa contina nodul 'node'.
 * Afiseaza id-urile nodurilor din componenta conexa din care face parte
 * si nodul 'node'.
 */
void graph_print_subgraph(graph_t *graph, int node)
{
  if(!graph || !graph->nodes || node >= graph->num_nodes)
    return;

  /* HINT: folositi DFS si mecanismul de vizitare.  */
}

int main()
{
  /* Test TASK 1 - 3. */
  printf("Graf simplu:\n");
  graph_t *simple_graph = graph_create(4);
  graph_add(simple_graph, 0, 1);
  graph_add(simple_graph, 0, 2);
  graph_add(simple_graph, 2, 3);
  graph_print(simple_graph);
  printf("\n\n");

  /* Test TASK 4. */
  printf("Graf complex:\n");
  graph_t *complex_graph = graph_read("graph.txt");
  graph_print(complex_graph);
  printf("\n\n");

  printf("BFS pe graf complex de la nodul 0:\n");
  graph_bfs(complex_graph, 0);
  printf("BFS pe graf complex de la nodul 5:\n");
  graph_bfs(complex_graph, 5);
  printf("\n\n");

  printf("DFS pe graf complex de la nodul 0:\n");
  graph_dfs(complex_graph, 0);
  printf("DFS pe graf complex de la nodul 5:\n");
  graph_dfs(complex_graph, 5);
  printf("\n\n");

  printf("Stergere legaturi (6, 4), (6, 5):\n");
  graph_del(complex_graph, 6, 4);
  graph_del(complex_graph, 6, 5);
  graph_print(complex_graph);
  printf("\n\n");

  printf("Subgraf-ul conex din care face parte 6:\n");
  graph_print_subgraph(complex_graph, 6);

  return 0;
}
