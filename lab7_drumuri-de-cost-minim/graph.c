#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>


#define COST_MAX 10000

/**
 * Structura retine un graf printr-o matrice de adiacenta.
 * 'num_nodes' = numarul de noduri din graf
 * 'cost[][]'  = cost[x][y] = C => distanta de la x la y este C.
 * Daca nu exista legatura de la x la y atunci costul este maxim.
 * Puteti folosi constanta COST_MAX definita mai sus.
 *
 * DO NOT TOUCH THIS!
 */
typedef struct graph_t {
	unsigned int num_nodes;
	int **cost;
} graph_t;

/**
 * TASK 1.
 *
 * Functia deschide fisierul 'filename' pentru citire. Formatul fisierului
 * de intrare este urmatorul:
 *		- pe prima linie se afla 'num_nodes' - numarul de noduri din graf.
 *		- pe a doua linie se afla 'num_edges' - numarul de muchii.
 *		- pe urmatoarele 'num_edges' linii se afla cate o muchie sub forma
 *			urmatoare: <nod_sursa> <nod_dest> <cost>
 *
 * Toate aceste informatii sunt salvate in structura 'graph' care trebuie
 * alocata si initializata inainte de citirea fisierului.
 */
graph_t *graph_read(const char *filename)
{
	FILE *f = fopen(filename, "r");
	graph_t *graph = NULL;

	/* TODO: Alocare graph. */


	/* TODO: Citire numar noduri. Alocare matrice de adiacenta. */


	/* TODO: Initializare matrice de adiacenta (cu ce cost?). */


	/* TODO: Citire muchii din fisier. */


	fclose(f);
	return graph;
}


/**
 * TASK 2: Algoritmul Floyd-Warshall.
 *
 * Functia primeste ca parametru un graph reprezentat de structura
 * graph_t, aplica algoritmul Floyd-Warshall pentru gasirea drumului minim
 * dintre oricare doua noduri.
 * In urma aplicarii algoritmului matricea de adiacenta cu costuri va fi
 * modificata si cost[x][y] va reprezenta costul minim dintre nodurile x si y.
 *
 */
void graph_floyd_warshall(graph_t *graph)
{
	/**
	 * Initializari:
	 * 1. let dist be a |V| × |V| array of minimum distances initialized to ∞ (infinity)
	 * 2. for each vertex v
	 * 3.    dist[v][v] ← 0
	 * 4. for each edge (u,v)
	 * 5.    dist[u][v] ← w(u,v)  // the weight of the edge (u,v)
	 * Algoritmul:
	 * 6. for k from 1 to |V|
	 * 7.    for i from 1 to |V|
	 * 8.       for j from 1 to |V|
	 * 9.          if dist[i][j] > dist[i][k] + dist[k][j]
	 * 10.             dist[i][j] ← dist[i][k] + dist[k][j]
	 * 11.         end if
	 */
}

/**
 * TASK 3: Algoritmul Dijkstra
 *
 * Algoritmul Floyd-Warshall gaseste distanta minima dintre oricare doua
 * noduri. Algoritmul Dijkstra gaseste drumul minim de la un nod de start
 * la toate celalate noduri.
 *
 * Indicele nodului de start este dat ca parametru.
 * Algoritmul Djikstra nu modifica matricea de adiacenta. El salveaza distanta
 * de la nodul de start la oricare alt nod X intr-un vector dist[].
 * Afisati acest vector.
 */
void graph_dijkstra(graph_t *graph, int start_node)
{
	/**
	 * Dijkstra.
	 *
	 * Avem nevoie de urmatorii vectori:
	 *		dist[], unde dist[X] reprezinta distanta de la nodul de start la nodul X.
	 *		prev[], unde prev[X] reprezinta id-ul parintelui nodului X, din drumul
	 *						minim (pornind de la nodul de start catre X).
	 *		visited[], unde visited[X]  = 0 daca nu am vizitat deja nodul X
	 *																= 1 daca l-am vizitat
	 *
	 * 1. initializare
	 *   2. pentru fiecare nod X
	 *     2.1. dist[X] = COST_MAX daca nu exista legatura intre start_nod si X
	 *                  = cost[start_nod][X] daca exista legatura intre ele
	 *
	 *     2.2. prev[X] = -1 (nod cu id nedefinit)
	 *     2.3. visited[X] = 0
	 *
	 *   3. dist[start_node] = 0; Distanta initiala de la start_node la el insusi
	 *
	 *   4. cat timp nu am vizitat toate nodurile
	 *     4.1. Caut un nod nevizitat, Y_MIN, in dist[] care are distanta minima
	 *          fata de nodul de start.
	 *     4.2. Marchez nodul Y_MIN ca vizitat.
	 *     4.3. Relaxare muchii: Pentru fiecare nod Z nevizitat verific daca nu cumva
	 *          am gasit un drum de la 'start_node' la Z, care trece prin Y_MIN,
	 *          mai scurt decat costul actual dintre 'start_node' si Z.
	 *          Pentru fiecare nod Z nevizitat:
	 *          4.4. daca dist[Z] > dist[Y_MIN] + cost[Y_MIN][Z] atunci
	 *              4.5. dist[Z] = dist[Y_MIN] + cost[Y_MIN][Z]
	 *              4.6. prev[Z] = Y_MIN
	 */


}


/* DO NOT TOUCH THIS SHIT! (MY PRECIOUS!) */
void graph_print(graph_t *graph);
graph_t *graph_copy(graph_t *graph);

int main()
{
	graph_t *graph;
	graph_t *gcopy;

	graph = graph_read("graph.txt");
	printf("Matricea de adiacenta citita:\n");
	graph_print(graph);

	printf("Floyd-Warshall:\n");
	gcopy = graph_copy(graph);
	graph_floyd_warshall(gcopy);
	graph_print(gcopy);

	printf("Dijkstra (nod start 0):\n");
	gcopy = graph_copy(graph);
	graph_dijkstra(gcopy, 0);

	printf("Dijkstra (nod start 5):\n");
	gcopy = graph_copy(graph);
	graph_dijkstra(gcopy, 5);

	return 0;
}

void graph_print(graph_t *graph)
{
	int i, j;

	if (!graph) {
		printf("nothing to show\n");
		return;
	}

	printf("      ");
	for (i = 0; i < graph->num_nodes; ++i)
		printf("%3d ", i);
	printf("\n");

	printf("      ");
	for (i = 0; i < graph->num_nodes; ++i)
		printf("----");
	printf("\n");

	for (i = 0; i < graph->num_nodes; ++i) {
		printf("%3d | ", i);
		for (j = 0; j < graph->num_nodes; ++j)
			printf("%3d ", graph->cost[i][j] >= COST_MAX ? 0 : graph->cost[i][j]);
		printf("\n");
	}
}

graph_t *graph_copy(graph_t *graph)
{
	graph_t *gcopy = NULL;
	int i;

	if (!graph)
		return NULL;

	gcopy = malloc(sizeof(*gcopy));
	gcopy->num_nodes = graph->num_nodes;
	gcopy->cost = malloc(graph->num_nodes * sizeof(int*));

	for (i = 0; i < gcopy->num_nodes; ++i) {
		gcopy->cost[i] = malloc(graph->num_nodes * sizeof(int));
		memcpy(gcopy->cost[i], graph->cost[i], graph->num_nodes * sizeof(int));
	}

	return gcopy;
}
