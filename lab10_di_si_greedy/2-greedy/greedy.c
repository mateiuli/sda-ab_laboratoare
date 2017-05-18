/**
 * 	Laborator 10 SDA-AB: Divide et Impera
 * 	Author: Iulian-Razvan Matesica <iulian.matesica@gmail.com>
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * Structura reprezinta un obiect oarecare, definit de proft si greutate,
 * folosit pentru rezolvarea problemei rucsacului.
 */
typedef struct object_t {
	/* Profitul obiectului. */
	float p;
	/* Greutatea obiectului. */
	float g;
	/* Eficienta obiectului (trebuie calculata), */
	float e;
} object_t;

/**
 * Task 1
 *
 * Implementati functia 'knapsack'. Aceasta primeste ca parametrii un vector
 * de n obiecte (vedeti structura object_t) si greutatea maxima care incape
 * in rucsac G.
 *
 * Determinati folosind un algoritm de tip greedy profitul maxim care poate fi
 * obtinut. Afisati profitul obtinut si greutatea libera ramasa in rucsac.
 * Cand puneti un obiect in rucsac afisati un mesaj care sa contina
 * greutatea si profitul obiectului ales.s
 *
 */
void knapsack(object_t *obs, int n, float G)
{
	int i;

	/**
	 * TODO: Calculare 'eficienta' pentru fiecare obiect.
	 *
	 * Puteti folosi campul 'e' din structura object_t a fiecarui obiect pentru
	 * salvarea eficientei.
	 *
	 * Eficienta = Profit / Greutate
	 */


	/**
	 * TODO: Sortarea obiectelor descrescator dupa eficienta.
	 *
	 * Folositi functia 'qsort' din biblioteca standard.
	 * Trebuie sa implementati functia de comparare a doua elemente de tipul
	 * object_t.
	 */


	/**
	 * TODO: Adaugare obiecte in rucsac.
	 *
	 * Obiectele trebuie parcurse in ordine, dupa eficienta, si alese doar acele
	 * obiecte care mai incap in rucsac.
	 *
	 * profit = 0
	 * // Pentru fiecare obiect
	 * 1. for i = 1, n then
	 *    // Daca e loc suficient in rucsac penru obiectl i
	 *    2. if G - obiect[i].greutate >= 0 then
	 *        3. G = G - obiect[i].greutate >= 0
	 *        4. profit += obiect[i].profit
	 */

}

/**
 * Structura pentru task-ul 2: problema spectacloelor.
 *
 * Un element de tipul times_t reprezinta un spectacol si e definit de timpul
 * de start si timpul de final.
 */
typedef struct times_t {
	int t_start;
	int t_final;
} times_t;

/**
 * Task 2: Problema spectacolelor
 *
 * Se dau mai multe spectacole, prin timpii de start și timpii de final.
 * Se cere o planificare astfel încât o persoană să poată vedea cât mai multe
 * spectacole.
 * Rezolvarea constă în sortarea spectacolelor crescător după timpii de final,
 * apoi la fiecare pas se alege primul spectacol care are timpul de start mai
 * mare decât ultimul timp de final.
 *
 * Functia primeste un vector de spectacole (pereche de timp start si final) si
 * numarul de elemente din vector.
 *
 * Sa se afiseze perechile (timp start, timp final) a spectacolelor care sunt
 * alese.
 */
void spectacole(times_t *times, int n)
{
	/**
	 * TODO:
	 *
	 * Sortare vector 'times' dupa timpul de final (crescator).
	 * Puteti folosi functia 'qsort' din stdlib.h. Trebuie sa implementati
	 * functia de comparare a doua elemente de tipul 'times_t'.
	 */

	/* TODO: Parcurgere, alegere spectacole + afisarea acestora. */

}

int main()
{
	/* Lista de obiecte. */
	object_t obs[] = {
		{.p = 10, .g = 4},
		{.p = 3,  .g = 4},
		{.p = 5,  .g = 2},
		{.p = 1,  .g = 1},
		{.p = 10, .g = 5},
		{.p = 8,  .g = 6},
	};

	printf("Problema rucsacului:\n");
	knapsack(obs, sizeof(obs) / sizeof(obs[0]), 16);

	/* Lista cu spectacole. */
	times_t times[] = {
		{.t_start = 0, .t_final = 5},
		{.t_start = 5, .t_final = 8},
		{.t_start = 2, .t_final = 6},
		{.t_start = 6, .t_final = 9},
		{.t_start = 0, .t_final = 2},
	};

	printf("\nProblema spectacolelor:\n");
	spectacole(times, sizeof(times) / sizeof(times[0]));
}
