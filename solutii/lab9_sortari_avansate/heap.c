/**
 * 	Laborator 8 SDA-AB: Algoritmi de sortare 2
 * 	Author: Iulian-Razvan Matesica <iulian.matesica@gmail.com>
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* DO NOT TOUCH THIS :D (IT'S... IT'S.. MAGIC!) */
#define swap(a, b) do { \
	int __tmp = (a);      \
	(a) = (b);            \
	(b) = __tmp;          \
} while (0);

#define HEAP_MAX_SIZE 100

typedef struct heap_t {
	/* Numarul curent de elemente in vector. */
	int num_elem;
	/* Vectorul in care se retine heap-ul. */
	int elem[HEAP_MAX_SIZE];
} heap_t;

/**
 * - "Captain, I request the permission to modify this line!"
 * - "Permission denied!"
 * - "Aye, aye, Captain!" ** flying away **
 */
void heapify(heap_t *heap, int index);

/**
 * TASK 1.
 *
 * Functia aloca memorie pentru un heap si il initializeaza (vid).
 */
heap_t *heap_create()
{
	heap_t *heap = NULL;

	heap = malloc(sizeof(heap_t));
	heap->num_elem = 0;

	return heap;
}

/**
 * TASK 1.
 *
 * Elibereaza memoria ocupata de catre heap.
 */
void heap_free(heap_t *heap)
{
	if (!heap)
		return;

	free(heap);
}

/**
 * TASK 1.
 *
 * (helper function)
 * Returneaza indicele parintelui lui 'index'.
 * > Daca 'index' este par, parintele este index/2 - 1
 * > Daca 'index' este impar, parintele este index/2
 */
int get_parent(int index)
{
	if (index == 0)
		return 0;

	return (index % 2 == 0) ? (index / 2 - 1) : (index / 2);
}

/**
 * TASK 1.
 *
 * (helper function)
 * Returneaza indicele fiului din stanga a lui 'index'.
 */
int get_left_child(int index)
{
	return 2 * index + 1;
}

/**
 * TASK 1.
 *
 * (helper function)
 * Returneaza indicele fiului din dreapta a lui 'index'.
 */
int get_right_child(int index)
{
	return 2 * index + 2;
}

/**
 * TASK 1.
 *
 * Returneaza 1 daca heap-ul este vid, 0 altfel.
 */
int heap_empty(heap_t *heap)
{
	if (!heap)
		return 0;

	return heap->num_elem == 0;
}

/**
 * TASK 2.
 *
 * Insereaza in heap-ul primit ca parametru valoarea 'value'.
 */
void heap_insert(heap_t *heap, int value)
{
	if (!heap)
		return;

	/**
	 * Elementele noi le adaugam tot timpul la finalul vectorului in care retinem
	 * arborele nostru binar.
	 * Dupa ce am adaugat noua valoare in vector trebuie sa o mutam pe pozitia
	 * corecta astfel incat sa respecte conditia de minheap/maxheap.
	 *
	 * Variabila index retine pozitia noului nod in vector.
	 */

	/* TODO: Adaugare 'value' la finalul vectorului. */
	int index = heap->num_elem++;
	heap->elem[index] = value;

	/**
	 * Acum trebuie sa mutam valoarea prin arbore astfel incat sa o pozitionam
	 * unde trebuie.
	 *
	 * Acest proces se numeste up-heap: urcarea noi valori in arborele nostru,
	 * de la frunze spre radacina, pana ajunge pe pozitia corecta.
	 * Ca un nod sa respecte conditia de min-heap trebuie ca valoarea acestuia
	 * sa fie cea mai mica din subarborele sau (considerand nodul respectiv
	 * radacina a subarborelui).
	 *
	 * Ca sa facem acest lucru trebuie sa comparam valoare elementului nou cu
	 * valoarea parintelui. Vom implementa un min-heap, deci daca noua valoare
	 * este mai mica decat valoarea parintelui, trebuie sa urcam in arbore nodul
	 * nou (le interschimbam). Procesul se reia pana cand nodul ajunge in pozitia
	 * corecta (fie cand nodul ajunge la radacina, fie cand nu mai este
	 * satisfacuta conditia de ordine < sau > ca parintele).
	 */

	/* TODO: Calculare index parinte. */
	int p_index = get_parent(index);

	/**
	 * TODO: Up-heap.
	 *
	 * Algoritm:
	 * fie V vectorul in care este retinut heap-ul.
	 * fie index = indicele curent al noului nod
	 * fie parinte = indicele parintelui lui 'index'.
	 *
	 * 1. cat timp index > 0 si V[index] < V[parinte] atunci
	 *    // interschimbam cu parintele
	 *    2. swap(V[index], V[parinte])
	 *    // Noul indice in V al nodului (a luat locul parintelui).
	 *    3. index = parinte
	 *    // Calculam parintele noului nod
	 *    4. parinte = get_parent(index).
	 */
	while (index > 0 && heap->elem[p_index] > heap->elem[index])  {
		/* Daca parintele are o valoare mai mare, le interschimbam. */
		swap(heap->elem[p_index], heap->elem[index]);
		/**
		 * Avansam in arbore - de jos in sus. Acum elementul nostru se afla la
		 * pozitia 'get_parent' iar parintele se afla la pozitia 'index' (swap).
		 * Facem update la pozitia curenta a valorii si calculam noul parinte.
		 */
		index = p_index;
		p_index = get_parent(index);
	}
}

/**
 * TASK 3.
 *
 * Functia returneaza cel mai mic element din heap.
 */
int heap_remove(heap_t *heap)
{
	if (!heap)
		return 0;

	/**
	 * Elementul cel mai mic se afla tot timpul la radacina.
	 * Radacina se afla pe pozitia 0 in vectorul nostru.
	 * Nu putem sa lasam arborele fara o radacina si trebuie sa gasim un
	 * element in locul acesteia. In locul ei aducem ultimul element din vector.
	 * Dupa aceasta modificare arborele nu mai respecta conditia de min-heap.
	 * Trebuie deci sa "cernem" noua radacina de sus in jos (de la radacina spre
	 * frunze) pana ajunge pe pozitia corecta. Acest proces se numeste down-heap.
	 */

	/* Salvam valoarea minima (radacina). */
	int min = heap->elem[0];

	/**
	 * TODO:
	 * Scoatem elementul cel mai mic din heap.
	 * In locul lui aducem ultimul element din vector.
	 * Trebuie sa decrementam numarul de noduri.
	 */

	/* In locul radacinii aducem ultimul element din vector. */
	heap->elem[0] = heap->elem[heap->num_elem - 1];
	/* Vectorul a scazut in dimensiune - am scos un element. */
	heap->num_elem--;

	/**
	 * Refacem arborele cu radacina pe pozitia 0.
	 * 'Cernem' radacina in jos pana la pozitia corecta.
	 * Procesul se mai numeste 'heapify' sau down-heap.
	 */
	heapify(heap, 0);

	return min;
}

/**
 * TASK 3.
 *
 * Functia ajusteaza arborele cu radacina pe pozitia 'index'.
 * Daca la inserare, se punea elementul la finalul vectorului si se urca
 * in arbore pana ajungea pe pozitia corecta, la scoaterea elementului
 * minim, in locul radacinii aducem un numar 'aleator' (ultimul din vector).
 * De data aceasta trebuie sa coboram valoarea in arbore pana ajunge pe pozitia
 * corecta.
 *
 * Operatiile mai sunt cunoscute si sub numele de up-hea[] pentru ajustarea la
 * inserare si down-heap pentru ajustarea la stergere.
 */
void heapify(heap_t *heap, int index)
{
	if (!heap || heap->num_elem == 0)
		return;

	/**
	 * Elementul cu indicele 'index' trebuie ajustat. El este o radacina a unui
	 * subarbore. Trebuie sa aducem ca radacina a subarborelui elementul cel mai
	 * mic dintre fiul din stanga, fiul din dreapta si valoarea actuala a radacinii.
	 *
	 * Exemplu de subarbore:
	 *                           ...
	 *                            \
	 *                   <radacina_subarbore>     <------------ aici este 'index'
	 *                /                        \
	 *        <fiul_din_stanga>         <fiul_din_dreapta>
	 *       /                 \       /                  \
	 *     ...                ...    ...                 ...
	 *
	 * <radacina_subarbore> = min(fiul din stanga, fiul din dreapta, radacina subarbore)
	 */

	/* Presupun ca valoarea minima se afla in radacina subarborelui. */
	int min_index = index;

	/* Calculez indicii celor doi copii. */
	int left  = get_left_child(index);
	int right = get_right_child(index);

	/**
	 * TODO: Cautare nod cu indice minim (descris mai sus).
	 * Aveti grija la indicii din 'left' si 'right'. Ce se intampla daca nodul
	 * cu indicele 'index' nu are copii?
	 */

	/* Minimul se afla la stanga? */
	if (left < heap->num_elem)
		if (heap->elem[left] < heap->elem[index])
			min_index = left;

	/* Minimul se afla la dreapta? */
	if (right < heap->num_elem)
		if (heap->elem[right] < heap->elem[min_index])
			min_index = right;

	/**
	 * TODO:
	 * In 'index' avem nodul curent iar in 'min_index' nodul minim.
	 * Daca acestea doua difera, le interschimbam si refacem arborele.
	 *
	 * Fie V vectorul in care este stocat heap-ul.
	 * 1. daca V[index] != V[min_index] atunci
	 *    // Nodul coboara in arbore
	 *    2. swap(V[index], V[min_index])
	 *    // Refacem arborele cu radacina in 'min_index'. Apelam recursiv heapify.
	 *    3. heapify(heap, min_index)
	 */

	if (heap->elem[index] != heap->elem[min_index]) {
		swap(heap->elem[index], heap->elem[min_index]);
		/**
		 * Am interschimbat radacina cu unul dintre fii. Coboram in arbore. Acum
		 * trebuie ajustat si subarborele cu a carui radacina am facut schimb
		 * (fiul din stanga sau dreapta).
		 */
		heapify(heap, min_index);
	}
}

/**
 * TASK 4.
 *
 * Acum ca avem o structura de date care ne garanteaza o relatie de ordine,
 * ne putem folosi de ea ca sa sortam un vector 'v' cu 'n' elemete.
 *
 */
void heap_sort(int *v, int n)
{
	/* TODO: Creare heap vid. */
	heap_t *heap = heap_create();

	/* TODO: Inserarea in heap a elementelor din v. */
	for (int i = 0; i < n; ++i)
		heap_insert(heap, v[i]);

	for (int i = 0; i < heap->num_elem; ++i)
		printf("%d, ", heap->elem[i]);
	printf("\n");

	int i = 0;

	/* TODO: Extragem din heap minimul pana cand devine vid. Salvam in v, in ordine. */
	while (!heap_empty(heap)) {
		v[i++] = heap_remove(heap);
	}

	/* TODO: Eliberare memorie ocupata de catre heap. */
	heap_free(heap);
}


int main()
{
	int v[] = {4, 1, 9, 10, 3, 0, 7};
	int n = 7;

	heap_sort(v, n);
	for (int i = 0; i < n; ++i)
		printf("%d, ", v[i]);
	printf("\n");

	return 0;
}
