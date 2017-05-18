/**
 * 	Laborator 10 SDA-AB: Divide et Impera
 * 	Author: Iulian-Razvan Matesica <iulian.matesica@gmail.com>
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * Task 1: Sortare folosind qsort.
 *
 * Algoritmul de cautare binara functioneaza doar pe vectori sortati.
 * Inainte de a cauta trebuie sa sortam vectorul.
 *
 * Puteti folosi functia 'qsort', deja implementata in biblioteca standard C.
 * Pentru a o putea folosi este necesara includerea header-ului 'stdlib.h'.
 *
 * Antetul functiei 'qsort' este urmatorul:
 *
 * void qsort(void *base, size_t nmemb, size_t size,
 *            int (*compar)(const void *, const void *));
 *
 * Functia primeste 4 paramtrii:
 *  - void    *base     Pointer catre vectorul ce trebuie sortat.
 *  - size_t  nmemb     Numarul de elemente din vectorul 'base'.
 *  - size_t  size      Dimensiunea in bytes a unui element.
 *  - int (*compar)(const void *, const void *) Este un pointer catre
 *    functia de comparare.
 *
 *    Functia de comparare primeste doi parametrii de tip 'const void *' si
 *    returneaza un 'int'.
 *    Functia trebuie sa intoarca:
 *       - un numar < 0, daca primul parametru este mai mic ca al doilea.
 *       - 0, daca parametrii sunt egali
 *       - un numar > 0, daca primul parametru este mai mare ca al doilea.
 *
 *    Atentie la tipul parametrilor: const void *. Keyword-ul 'const' este
 *    important - spune ca functia respectiva nu va schimba valorile parametrilor.
 */
void sort(int *v, int n)
{
	/**
	 * TODO: Implementati functia de comparare apoi apelati functia qsort
	 * pentru vectorul v, cu n elemente de tip int.
	 */
}

/**
 * Task 2: Cautare binara
 *
 * Vectorul primit v este sortat. Functia de sortare de la task-ul 1 este
 * apaleata de catre main().
 */
int binary_search(int *v, int left, int right, int x)
{
	/**
	 * Împărțim vectorul în doi sub-vectori de dimensiunea n / 2.
   * Aplicăm algoritmul de căutare binară pe sub-vectorul care conține
 	 * valoarea căutată
   * Soluția sub-problemei devine soluția problemei inițiale, motiv pentru
	 * care nu mai este nevoie de etapa de combinare.
	 */

	/* TODO */
}

/**
 * Task 3: Turnurile din Hanoi
 *
 * Se considera 3 tije A, B, C şi n discuri de dimensiuni distincte (1, 2.. n
 * ordinea crescătoare a dimensiunilor) situate inițial toate pe tija A în
 * ordinea 1,2..n (de la vârf către baza). Singura operație care se poate
 * efectua este de a selecta un disc ce se află în vârful unei tije şi plasarea
 * lui în vârful altei tije astfel încât să fie așezat deasupra unui disc de
 * dimensiune mai mare decât a sa.
 *
 * Sa se găsească un algoritm prin care se mută toate discurile pe tija B
 * (problema turnurilor din Hanoi).
 *
 * https://ocw.cs.pub.ro/courses/pa/laboratoare/laborator-01
 */
void hanoi(int num, char src, char dst, char tmp)
{
	/**
	 *  Pentru rezolvarea problemei folosim următoarea strategie [9]:
   *   - mutam primele n-1 discuri de pe tija A pe tija C folosindu-ne de
	 *     tija B.
   *   - mutam discul n pe tija B.
   *   - mutam apoi cele n-1 discuri de pe tija C pe tija B folosindu-ne de
	 *     tija A.
	 *
	 * Algoritm:
	 * hanoi(num, src, dst, tmp)
	 *   1. daca num == 1 atunci
	 *       1.1. Afisare mesaj "Mut disc de pe %src pe %dst"
	 *   2. altfel
	 *       // Mutam n-1 discuri de pe SRC pe TMP, prin DST ca tija temporara
	 *       2.1. hanoi(num - 1, src, tmp, dst)
	 *       // Acum avem acces la discul cel mai de jos, e singur pe tija SRC
	 *       2.2. 1.1. Afisare mesaj "Mut disc de pe %src pe %dst"
	 *       // Mutam discurile de pe TMP pe DST, prin SRC ca tija temporara
	 *       2.3. hanoi(num - 1, tmp, dst, src);
	 */

	/* TODO */
}

int main()
{
	int v[] = {0, 2, 5, 9, 3, 1, 5, 6};
	int n = sizeof(v) / sizeof(v[0]);

	printf("Binary Search pe vectorul: ");
	for (int i = 0; i < n; ++i)
		printf("%d, ", v[i]);
	printf("\n");
	sort(v, n);

	int xs[] = {3, 8, 1};
	for (int i = 0; i < sizeof(xs) / sizeof(xs[0]); ++i) {
		if (binary_search(v, 0, n - 1, xs[i]) > 0)
			printf("%d este in vector\n", xs[i]);
		else
			printf("%d nu este in vector\n", xs[i]);
	}

	printf("\nTurnurile din Hanoi (2 discuri)\n");
	hanoi(2, 'a', 'b', 'c');

	printf("\nTurnurile din Hanoi (3 discuri)\n");
	hanoi(3, 'a', 'b', 'c');

	return 0;
}
