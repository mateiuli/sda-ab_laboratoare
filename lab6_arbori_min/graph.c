/**
 * 	Laborator 6 SDA-AB: Arbori minimi de acoperire
 * 	Author: Iulian-Razvan Matesica <iulian.matesica@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES	64
#define MAX_NODES 16

/**
 * Pentru aplicarea algoritmilor ce gasesc un arbore minim de acoperire
 * nu ne mai intereseaza sa retinem graful ca pana acum (complet - prin
 * liste de adiacenta sau matrice de adiacienta).
 * Tot ce trebui sa retinem sunt doar muchiile grafului nostru.
 *
 * Structura de mai jos reprezinta o muchie intre nodurile (src, dst).
 * Muchia are atasata un cost.
 *
 * DO NO TOUCH THIS!
 */
typedef struct edge_t {
	int src;
	int dst;
	int cost;
} edge_t;

/**
 * Vom retine un graf doar prin vectorul de muchii al acestuia.
 * La inceput nu stim exact cate muchii poate sa aiba graful nostru. Pentru
 * simplitate folosim un vector alocat static unde fiecare element reprezinta
 * o muchie din graf (cu un cost atasat).
 *
 * DO NOT TOUCH THIS!
 */
typedef struct graph_t {
	/* Vector de muchii. */
	edge_t edges[MAX_EDGES];
	/* Numarul de muchii ale grafului. */
	int num_edges;
	/* Numarul de noduri ale grafului. */
	int num_nodes;

	/* TASK 4: Culoarea unui nod. */
	int color[MAX_NODES];
} graph_t;

/* DO NOT TOUCH THIS!. */
void graph_sort_edges(graph_t *graph);

/**
 * TASK 1.
 *
 * Aloca memorie pentru structura 'graph_t'.
 * Initializeaza 'num_nodes' si 'num_edges' cu zero.
 *
 */
graph_t *graph_create()
{
	graph_t *graph = NULL;

	/* TODO TASK 1: alocare memorie si initializare structura. */


	/**
	 * TODO TASK 4 (cand ajungeti la TASK 4 trebuie completat si aici).
	 * Initial, inainte de aplicarea algoritmului Kruskal, fiecare nod face
	 * parte din propriul subarbore.
	 * Asignati cate o culoare diferita fiecarui nod.
	 * Culoarea unui nod o reprezentam ca un numar intreg.
	 * HINT: color[X] = X
	 * Unde X reprezinta id-ul unui nod.
	 */

	return graph;
}

/**
 * TASK 2.
 *
 * Functia deschide fisierul 'filename' pentru citire. Formatul fisierului
 * de intrare este urmatorul:
 *		- pe prima linie se afla 'num_nodes' - numarul de noduri din graf.
 *		- pe a doua linie se afla 'num_edges' - numarul de muchii.
 *		- pe urmatoarele 'num_edges' linii se afla cate o muchie sub forma
 *			urmatoare: <nod_sursa> <nod_dest> <cost>
 *
 * Toate aceste informatii sunt salvate in structura 'graph' primita ca
 * parametru. Ea trebuie sa fie alocata inainte de apelarea functie (de catre
 * functia 'graph_create').
 *
 */
void graph_read(const char *filename, graph_t *graph)
{
	FILE *f = fopen(filename, "r");

	if (graph == NULL)
		goto err_close_file;

	/* TODO TASK 2: Citire 'num_nodes' de pe prima linie. */


	/* TODO TASK 2: Citire 'num_edges' de pe a doua linie. */


	/* Citire 'num_edges' perechi: <nod_sursa> <nod_dest> <cost_muchie> */

err_close_file:
	fclose(f);
}

/**
 * TASK 3.
 *
 * Sa se afiseze graful 'graph'. Afisati numarul de noduri, numarul de
 * muchii si perechile de muchii, cu tot cu cost, cate una pe linie:
 *  (src, dest) = cost
 */
void graph_print(graph_t *graph)
{
	if (!graph)
		return;

	/* TODO TASK 3: Afisare numar noduri, numar muchii. */


	/* TODO TASK 3: Afisare perechi muchii (src, dst) = cost. Una pe linie. */


}

/**
 * TASK 4. Algoritmul Kruskal.
 *
 * Functia primeste ca parametru un graf (citit din fisier).
 * Aplica algoritmul Kruskal peste acest graf si returneaza un alt graf
 * care este format doar din muchiile care fac parte din arborele minim de
 * acoperire.
 *
 */
graph_t *graph_kruskal(graph_t *graph)
{
	/* min_graph retine arborele minim de acoperire in urma aplicarii Kruskal. */
	graph_t *min_graph = graph_create();

	if (min_graph == NULL || graph == NULL)
		return NULL;

	/* Sortare muchii in ordine crescatoare dupa cost. */
	graph_sort_edges(graph);

	/**
	 * Fiind dat un graf cu N noduri, orice arbore minim de acoperire are
	 * N - 1 muchii.
	 * Bucla de mai jos se traduce astfel: cat timp nu am pus in arborele minim
	 * de acoperire N - 1 muchii, mai trebuie sa adaugam.
	 * Extragem pe rand muchii din graful initial (fiind sortate in ordine
	 * crescatoare dupa cost, trebuie doar sa parcurgem muchiile).
	 */
	int i = 0;

	/**
	 * Algoritmul Kruskal.
	 *
	 * 1. Cat timp nu am gasit arborele minim:
	 * 		2.1. Extragere posibila muchie (src, dst) cu cost minim din graf initial.
	 *		2.2. Daca varfurile muchiei sunt colorate diferit, atunci:
	 *			3.1. Adaugare muchie extrasa (src, dst) in vectorul de muchii
	 * 				   al arborelui minim (min_graph->edges[]).
	 *			3.2. Incrementare numar de muchii din min_graph.
	 *			3.3. Varfurile muchiei faceau parte din subarbori diferiti, adica
	 *					 nodurile erau colorate diferit. Acum ca le-am unit prin
	 *           muchia de cost minim (src, dst), ele fac parte din acelasi
	 *					 subarbore, deci trebuie ca toate nodurile sa fie colorate la fel.
	 *           Altfel spus:
	 *					 Muchia extrasa este (src, dst). Culorile nodurilor 'src' si
	 *					 'dst' difera. Trebuie acum ca toate nodurile din graf care
	 *					 aveau culoarea color[dst] sa isi schimbe culoarea in color[src].
	 *					 (prin colorarea identica marcam faptul ca nodurile fac parte
	 * 					 din acelasi subarbore).
	 */

	min_graph->num_nodes = graph->num_nodes;
	min_graph->num_edges = 0;

	/* 1. Cat timp nu am gasit arborele minim. */
	while (min_graph->num_edges < graph->num_nodes - 1) {
		/* Cu i parcurgem muchiile grafului initial, sortate crescator. */
		if (i >= graph->num_edges)
			break;

		/* 2.1 Extragere muchie cu cost minim din graful initial. */
		edge_t edge = graph->edges[i++];

		/* 2.2. Daca varfurile muchiei sunt colorate diferit. */
		if (graph->color[edge.src] != graph->color[edge.dst]) {
			/* TODO: Pas 3.1. Adaugare muchie in arborele minim (min_graph). */


			/* TODO: Pas 3.2. Incrementare numar de muchii din min_graph. */


			/* TODO: Pas 3.3. Unire subarbori (recolorare noduri). */


		}
	}


	return min_graph;
}

/**
 * BONUS TASK 5. Algoritmul Prim.
 *
 * Functia primeste ca parametru un graf (citit din fisier).
 * Aplica algoritmul Prim peste acest graf si returneaza un alt graf
 * care este format doar din muchiile care fac parte din arborele minim de
 * acoperire.
 *
 */
graph_t *graph_prim(graph_t *graph)
{
	/* min_graph retine arborele minim de acoperire in urma aplicarii Prim. */
	graph_t *min_graph = graph_create();

	if (min_graph == NULL || graph == NULL)
		return NULL;

	/**
	 * Algoritmul incrementează mărimea unui arbore, pornind de la un nod,
	 * până când sunt incluse toate nodurile.

   * Intrare: Un graf conex ponderat cu nodurile V și muchiile E.
   * 1. Initializare: Vnou = {x}, unde x este un nod arbitrar (punct de plecare)
	 * 		din V, Enou = {}.
   * 2. repetă până când Vnou = V:
   *    2.1. Alege muchia (u,v) din E de cost minim astfel încât u este în Vnou și v
	 *				nu e (dacă există mai multe astfel de muchii, se alege arbitrar).
   * 		2.2. Se adaugă v la Vnou, (u,v) la Enou
   * 3. Ieșire: Vnou și Enou descriu arborele parțial de cost minim
	 */
	int i = 0;

	/* Initial graful (arborele minim este vid). */
	min_graph->num_nodes = 0;
	min_graph->num_edges = 0;

	/* Adaugam un nod oarecare de start (presupunem nodul 0). */
	min_graph->num_nodes = 1;

	/* TODO TASK 5: Show off. */

	return min_graph;
}

int main()
{
	graph_t *graph = graph_create();
	graph_read("graph.txt", graph);

	printf("Graful initial:\n");
	graph_print(graph);

	printf("Arborele minim de acoperire Kruskal:\n");
	graph_t *mink_graph = graph_kruskal(graph);
	graph_print(mink_graph);

	printf("Arborele minim de acoperire Prim:\n");
	graph_t *minp_graph = graph_prim(graph);
	graph_print(minp_graph);


	return 0;
}

int edge_comp(const void *a, const void *b)
{
	edge_t *edge_a = (edge_t *)a;
	edge_t *edge_b = (edge_t *)b;

	return edge_a->cost - edge_b->cost;
}

void graph_sort_edges(graph_t *graph)
{
	if (!graph)
		return;

	qsort(graph->edges, graph->num_edges, sizeof(edge_t), edge_comp);
}
