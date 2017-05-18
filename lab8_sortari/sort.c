/**
 * 	Laborator 8 SDA-AB: Algoritmi de sortare 1
 * 	Author: Iulian-Razvan Matesica <iulian.matesica@gmail.com>
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* DO NOT TOUCH THIS! */
#define ARRAY_SIZE 10
#define ARRAY_MAX  31

/**
 * Task 1: Bubble sort.
 *
 * Functia primeste in vector v cu n elemente.
 * Sa se sorteze crescator vectorul folosind algoritmul Bubble Sort.
 *
 *    > Average:      O(n^2)
 *    > Worst case:   O(n^2)
 *    > Best case:    O(n)
 *    > Extra memory: O(1)
 *    > Este stabil
 *    > Este in-place (vectorul dat ca input este modificat - devine sortat)
 */
void bubble_sort(int *v, int n)
{
	/**
	 *
   * Ideea de baza a sortarii prin metoda bulelor este in a parcurge
	 * tabloul, de la stanga spre dreapta, fiind comparate elementele
	 * alaturate a[i-1] si a[i]. Daca vor fi gasite 2 elemente neordonate,
	 * valorile lor vor fi interschimbate.
	 * Parcurgerea tabloului de la stanga spre dreapta se va repeta atata
	 * timp cat vor fi intalnite elemente neordonate.
   *
	 * A = array of n elements.
	 *
	 * do
	 *     swapped = false
	 *     for i = 1, n-1 do
	 *         if A[i - 1] > A[i] then
	 *             swap(A[i - 1], A[i])
	 *             swapped = true
	 *         end if
	 *     end for
	 * while swapped
	 */

	/* You're awesome ;). Now code. :D */
}


/*
 * !! La alegere, task 2 a) SAU 2 b). !!
 *
 * Task 2 a): Selection sort
 *
 * Functia primeste in vector v cu n elemente.
 * Sa se sorteze crescator vectorul folosind algoritmul Selection Sort.
 *
 *    > Average:      O(n^2)
 *    > Worst case:   O(n^2)
 *    > Best case:    O(n^2)
 *    > Extra memory: O(1)
 *    > Este stabil
 *    > Este in-place (vectorul dat ca input este modificat - devine sortat)
 */
void selection_sort(int *v, int n)
{
	/**
	 * Acest algoritm selecteaza, la fiecare pas j, cel mai mic element
	 * din vectorul nesortat (restul vectorului). Valoarea minima
	 * gasita la pasul j este pusa in vector la poziţia j,facandu-se
	 * intereschimbarea cu poziţia actuala a minimului. Nu este un
	 * algoritm indicat pentru vectorii mari, in majoritatea cazurilor
	 * oferind rezultate mai slabe decat insertion sort şi bubble sort.
	 *
	 * A = array of n elements.
	 *
	 * for j = 0, n - 2 do
	 *    // Presupunem ca min este primul element
	 *    min_i = j
	 *    // Caut elementul cel mai mic incepand de la j + 1 (restul lui A)
	 *    for i = j + 1, n - 1 do
 	 *        if A[i] < A[min_i] then
	 *            // Retinem indicele elementului cel mai mic gasit
	 *            min_i = i
	 *        end if
	 *    end for
	 *
	 *    // Daca am gasit un element mai mic ca A[j], le interschimb
	 *    if min_i != j then
	 *        swap(A[j], A[min_i])
	 *    end if
	 * end for
	 */

	 /* Your awesome code comes here. :D */
}


/**
 * Task 2 b): Insertion sort.
 *
 * Functia primeste in vector v cu n elemente.
 * Sa se sorteze crescator vectorul folosind algoritmul Insertion Sort.
 *
 *    > Average:      O(n^2)
 *    > Worst case:   O(n^2)
 *    > Best case:    O(n)
 *    > Extra memory: O(1)
 *    > Este stabil
 *    > Este in-place (vectorul dat ca input este modificat - devine sortat)
 */
void insertion_sort(int *v, int n)
{
	/**
   * Sortarea prin inserţie seamană oarecum cu sortarea prin selecţie.
	 * Tabloul este împărţit imaginar în două părţi - o parte sortată şi o
	 * parte nesortată. La început, partea sortată conţine primul element
	 * al tabloului şi partea nesortată conţine restul tabloului.
   * La fiecare pas, algoritmul ia primul element din partea nesortată
	 * şi il inserează în locul potrivit al părţii sortate.
   * Când partea nesortată nu mai are nici un element, algoritmul se opreste.
   *
	 * A = array of n elements.
	 *
	 * for i = 1, n - 1 do
	 *     j = i
	 *     while j > 0 and A[j - 1] > A[j]
	 *         swap(A[j], A[j - 1])
	 *     end while
	 * end for
	 */

	/* How are ya? */
}


/**
 * !! La alegere, task 3 a) SAU 3 b). !!
 * Task 3 a): Quick Sort
 *
 * Functia primeste in vector v cu n elemente.
 * Sa se sorteze crescator vectorul folosind algoritmul Quick Sort.
 *
 *    > Average:      O(n log n)
 *    > Worst case:   O(n^2)
 *    > Best case:    O(n log n)
 *    > Extra memory: O(log n)
 *    > NU este stabil
 *    > Este in-place (vectorul dat ca input este modificat - devine sortat)
 */
void quick_sort(int *v, int left, int right)
{
	/**
   * Algoritmul se bazează pe următorii paşi:
   * 1. alegerea unui element pe post de pivot
   * 2. parcurgerea vectorului din două părţi(de la stânga la pivot, de la
	 *    dreapta la pivot, ambele în acelaşi timp)
   * 3. interschimbarea elementelor care se află pe „partea greşită“ a
	 *    pivotului(mutăm la dreapta pivotului elementele mai mari, la stânga
	 *    pivotului elementel mai mici)
   * 4. divizarea algoritmului: după ce mutăm elementele pe „partea corectă“ a
	 *    pivotului, avem 2 subşiruri de sortat, iar pivotul se află pe poziţia
	 *    bună.
	 *
	 * Algoritmul este in lab:
	 * http://elf.cs.pub.ro/sda-ab/wiki/laboratoare/laborator-08#quick-sort
	 */

	/* If you got so far, ask for a candy (yummy). C'mon, do it! :D */
}


/**
 * !! La alegere, task 3 a) SAU 3 b). !!
 * Task 3 b): Merge Sort
 *
 * Functia primeste in vector v cu n elemente.
 * Sa se sorteze crescator vectorul folosind algoritmul Merge Sort.
 *
 *    > Average:      O(n log n)
 *    > Worst case:   O(n log n)
 *    > Best case:    O(n log n)
 *    > Extra memory: O(n)
 *    > Este stabil
 *    > NU este in-place (necesita un alt vector temporar pentru merge)
 *      dar la final vectorul final sortat se va afla in A
 */
void merge_sort(int *v, int left, int right)
{
	/**
   * Algoritmul se bazează pe următoarele observatii
   * 1. se împarte vectorul în secvenţe din ce în ce mai mici, astfel
	 *    încât fiecare secvenţă să fie ordonată la un moment dat şi interclasată
	 *    cu o altă secvenţă din vector corespunzătoare.
   * 2. practic, interclasarea va începe când se ajunge la o secvenţă formată
	 *    din două elemente. Aceasta, odată ordonată, se va interclasa cu o
	 *    alta corespunzătoare(cu 2 elemente). Cele două secvenţe vor alcătui un
	 *    subşir ordonat din vector mai mare(cu 4 elemente) care, la rândul lui,
	 *    se va interclasa cu un subşir corespunzător(cu 4 elemente) ş.a.m.d.
	 *
	 * Algoritmul este in lab:
	 * http://elf.cs.pub.ro/sda-ab/wiki/laboratoare/laborator-08#merge-sort
	 */

	/* If you got so far, ask for a candy (yummy). C'mon, ask, you deserve it! :D */
}

/* DO NOT TOUCH THIS!. */
void gen_array(int *array, int n);
void print_array(int *array, int n);

int main()
{
	int array[ARRAY_SIZE];

	/* 1. Bubble sort. */
	gen_array(array, ARRAY_SIZE);
	bubble_sort(array, ARRAY_SIZE);
	printf("Task 1: Bubble sort: \n");
	print_array(array, ARRAY_SIZE);

	/* 2a. Selection sort. */
	gen_array(array, ARRAY_SIZE);
	selection_sort(array, ARRAY_SIZE);
	printf("Task 2 a): Selection sort: \n");
	print_array(array, ARRAY_SIZE);

	/* 2b. Insertion sort. */
	gen_array(array, ARRAY_SIZE);
	insertion_sort(array, ARRAY_SIZE);
	printf("Task 2 b): Insertion sort: \n");
	print_array(array, ARRAY_SIZE);

	/* 3a. Quick sort. */
	gen_array(array, ARRAY_SIZE);
	quick_sort(array, 0, ARRAY_SIZE - 1);
	printf("Task 3 a): Quick sort: \n");
	print_array(array, ARRAY_SIZE);

	/* 3b. Quick sort. */
	gen_array(array, ARRAY_SIZE);
	merge_sort(array, 0, ARRAY_SIZE - 1);
	printf("Task 3 b): Merge sort: \n");
	print_array(array, ARRAY_SIZE);

	return 0;
}

/**
 * Generates a random array.
 */
void gen_array(int *array, int n)
{
	static int seeeeeeed = 0;
	int i;

	srand(time(NULL));// + seeeeeeed++);
	for (i = 0; i < n; ++i)
		array[i] = rand() % ARRAY_MAX;
}

void print_array(int *array, int n)
{
	int i;

	for (i = 0; i < n; ++i)
		printf("%d, ", array[i]);

	printf("\n\n");
}
