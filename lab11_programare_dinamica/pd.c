/**
 * 	Laborator 12 SDA-AB: Programare Dinamica
 * 	Author: Iulian-Razvan Matesica <iulian.matesica@gmail.com>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

/**
 * Structura reprezinta un obiect oarecare, definit de proft si greutate,
 * folosit pentru rezolvarea problemei rucsacului.
 */
typedef struct object_t {
	/* Profitul obiectului. */
	int p;
	/* Greutatea obiectului. */
	int g;
} object_t;

/**
 * Task 1 a): Fibonacci recursiv
 *
 * Implementati recursiv functia pentru calcularea al n-lea numar din sirul
 * lui Fibonacci.
 *
 * Sirul lui Fibonacci se genereaza pe baza urmatoarei relatii de recurenta:
 *  fib(n) =   n, pentru n <= 1
 *             fib(n - 1) + fib(n - 2), pentru n > 1
 *
 */
int fibonacci_rec(int n)
{
	return 0; /* DELETEEEEEE MEEEE! */
}

/**
 * Task 1 b): Fibonacci recursiv cu memoizare
 *
 * Memoizarea este procesul prin care salvam in memorie rezultatul unei
 * operatii costisitoare cu scopul de a-l refolosi ulterior.
 * Astfel, evitam recalcularea acestuia.
 *
 */
#define MAX_FIB 100
int fibmem[MAX_FIB] = {0, 1};

int fibonacci_memo(int n)
{
	/**
	 * Fibonacci cu memoizare presupune salvarea intr-un vector secventa de
	 * numere, pe parcurs ce sunt calculate, cu scopul de a fi refolosite pe viitor.
	 * Folosim vectorul fibmem[].
	 * fibmem[i] = X inseamna ca al i-lea termen din sirului lui Fibonacci este X.
	 * Daca fibmem[i] = 0, inseamna ca al i-lea termen inca nu a fost calculat.
	 *
	 * Initial pornim cu fibmem[0] = 0, fibmem[1] = 1 (initializarea de mai sus).
	 * Fata de algoritmul simplu recursiv, in loc sa returnam termenul oarecare K
	 * din sir, il salvam in vector fibmem, pe pozitia K (fibmem[K]), apoi il
	 * returnam.
	 */

	/**
	 * Algoritm
	 *
	 * function fibonacci(n)
	 *     // fibmem[i] = 0 inseamna ca al i-lea termen nu a fost calculat.
	 *     1. if n == 0 then
	 *         1.1. return 0
	 *     // Putem retine maxim MAX_FIB termeni.
	 *     2. if n > MAX_FIB then
	 *         2.1. return -1
	 *     // Calculam al n-lea termen daca nu a fost deja calculat
	 *     3. if fibmem[n] == 0 then
	 *         3.1. fibmem[n] = fibonacci(n - 1) + fibonacci(n - 2)
	 *     // Odata calculat al n-lea termen, il returnam.
	 *     4. return fibmem[n]
	 */

	return 0; /* DELETEEEEEE MEEEE! */
}

/**
 * Task 2: Subsir strict crescator de lungime maxima.
 *
 *
 *
 */
void subsir_maximal(int *v, int n)
{
	/* Alocare memorie pentru best si prev (n elemente de tip int). */
	int *best = malloc(n * sizeof(int));
	int *prev = malloc(n * sizeof(int));

	/* TODO: Initializati vectorii best cu 1 si prev cu -1. */


	/**
	 * TODO
	 *
	 * // Pentru fiecare element din vector
	 * 1. for i = 0, n - 1
	 *    // Cautam elementul strict mai mic ca el, cu cel mai mare best
	 *    2. for j = i - 1, 0
	 *        3. if v[j] < v[i] AND best[i] < best[j] + 1
	 *            // best-ul lui i este setat
	 *            4. best[i] = best[j] + 1
	 *            // Salvam elementul anterior pentru refacerea secventei
	 *            5. prev[i] = j
	 */



	/**
	 * TODO
	 *
	 * Trebuie sa cautam, in vectorul best, elementul cel mai mare
	 * (adica cel mai mare best gasit). Salvam indicele elementului in max_i.
	 */
	int max_best = 1;
	int max_i = 0;



	/**
	 * TODO: Afisare secventa
	 *
	 * Pornind de la elementul cu cel mai bun best, mergem inapoi si afisam
	 * secventa optima gasita.
	 *
	 * // Cat timp nu am ajuns la final
	 * 1. while max_i != -1
	 *    2. print v[max_i]
	 *    // Mergem la elementul precedent lui max_i
	 *    3. max_i = prev[max_i]
	 */


}

/**
 * Task 3: Problema rucsacului
 *
 * Implementati functia 'knapsack'. Aceasta primeste ca parametrii un vector
 * de n obiecte (vedeti structura object_t) si greutatea maxima care incape
 * in rucsac G. Functia returneaza profitul maxim care se poate obtine.
 *
 * Folositi tehnica programarii dinamice pentru determinarea profitului maxim.
 */
int knapsack(object_t *obs, int n, int G)
{
	int **D;

	/* TODO: Alocati memorie pentru matricea D cu n+1 linii si n+1 coloane. */


	/* TODO: Initializati toata matricea cu 0. */


	/**
	 * TODO:
	 *
	 * Fie G = greutatea maxima a rucsacului
	 * Fie D matricea unde construim solutia noastra
	 * Fie OG[i] = greutatea obiectului i
	 * Fie OP[i] = profitul obiectului i
	 *
	 * // Adaugam pe rand cate un obiect in rucsac.
	 * // Indicele i ne spune cate obiecte sunt in rucsac la momentul respectiv.
	 * 1. for i = 1, n
	 *    // Pentru fiecare greutate (1...G)
	 *    2. for j = 1, G
	 *       // Daca obiectul i cu indicele i - 1 nu incape in greutatea j
	 *       3. if OG[i - 1] > j
	 *           // Ramane profitul anterior
	 *           4. D[i][j] = D[i - 1][j]
	 *       // Daca obiectul incape in greutatea j
	 *       5. else
	 *           // Alegem profitul maxim dintre profitul fara acest obiect
	 *           // si profitul cu acest obiect + profitul obtinut din umplerea
	 *           // greutatii j - OG[i - 1] (spatiul ramas dupa adaugarea obiectului).
	 *           6. D[i][j] = max(
	 *													D[i - i][j],
	 *                          OP[i - 1] + D[i - 1][j - OG[i - 1]]
	 *                        )
	 */


	return 0; /* Replaceee meeee!! */
}

int main()
{
	int i;

	printf("Fibonnaci recursiv.\n");
	for (i = 0; i < 6; i++)
		printf("fib(%d) = %d\n", i, fibonacci_rec(i));

	printf("Fibonnaci recursiv cu memoizare.\n");
	for (i = 0; i < 6; i++)
		printf("fib(%d) = %d\n", i, fibonacci_rec(i));

	printf("Cel mai lung subsir strict crescator din: ");
	int v[] = {24, 12, 15, 15, 8, 19};
	for (i = 0; i < sizeof(v) / sizeof(v[0]); i++)
		printf("%d ", v[i]);
	printf("\n");
	subsir_maximal(v, sizeof(v) / sizeof(v[0]));
	printf("\n");

	/* Lista de obiecte. */
	object_t obs[] = {
		{.p = 10, .g = 4},
		{.p = 3,  .g = 4},
		{.p = 5,  .g = 2},
		{.p = 1,  .g = 1},
		{.p = 10, .g = 5},
		{.p = 8,  .g = 6},
	};

	printf("Problema rucsacului, profit maxim: %d\n",
		knapsack(obs, sizeof(obs) / sizeof(obs[0]), 6));
}
