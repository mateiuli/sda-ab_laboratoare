/**
 * 	Laborator 9 SDA-AB: Algoritmi de sortare 2
 * 	Author: Iulian-Razvan Matesica <iulian.matesica@gmail.com>
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BUCKET_SIZE 32
#define MAX_DIGITS      10

/**
 * Un Bucket B este de fapt un vector in care salvam la fiecare iteratie I doar
 * acele numere al caror digit I este B.
 */
typedef struct bucket_t {
	int elem[MAX_BUCKET_SIZE];
	int num_elem;
} bucket_t;

/**
 * Fiecare cifra are asociat un bucket.
 * Fie numarul cu 3 digiti 123. Fiecare cifra (1, 2 si 3) are cate un bucket
 * asociat.
 * buckets[1] reprezinta bucket-ul cifrei 1, buckets[2] pentru cifra 2 si tot asa.
 */
bucket_t buckets[MAX_DIGITS];

/**
 * TASK 1.
 *
 * Implementati functia 'get_digit'. Ea primeste ca paremtrii un numar intreg
 * si indicele digit-ului pe care trebuie sa-l returneze.
 *
 * Consideram digit-ul 0 ca fiind caracterul cel mai din dreapta.
 * Exemplu: numarul 123, are ca digit 0 pe 3, iar ca digit 2 pe 1.
 */
int get_digit(int number, int digit)
{
	while (number > 0 && digit > 0) {
		number /= 10;
		digit--;
	}

	return number % 10;
}

/**
 * TASK 2.
 *
 * Vectorul cu bucket-uri este declarat global - se numeste 'buckets'.
 * Fiecare digit are cate un bucket.
 *
 * Functia trebuie sa parcurga pe rand fiecare bucket, iar de acolo
 * sa copieze fiecare element inapoi in vectorul v.
 */
void buckets_to_array(int *v, int n)
{
	/**
	 * TODO: Mutam elementele fiecarui bucket inapoi in v.
	 * Dupa mutare, trebuie resetat numarul de elemente din bucket-ul respectiv.
	 */

}

void radix_sort(int *v, int n)
{

	/**
	 * TODO:
	 * Pentru fiecare digit copiem elementele din v in bucketul corespunzator.
	 * Dupa ce toate elementele au fost mutate in bucket-uri, trebuie sa le
	 * copiem inapoi (din bucket-uri in vectorul v).
	 * Acest proces se reia pentru fiecare digit.
	 * Dupa MAX_DIGITS iteratii in v se va afla vectorul sortat.
	 *
	 * Care este complexitatea algoritmului? Cum poate fi imbunatatita?
	 *
	 * Un exemplu fain: https://en.wikipedia.org/wiki/Radix_sort
	 */

}

int main()
{
	int v[] = {4, 1, 9, 10, 3, 0, 7};
	int n = 7;

	printf("Vectorul nesortat: \n");
	for (int i = 0; i < n; ++i)
		printf("%d, ", v[i]);
	printf("\n");

	radix_sort(v, n);

	printf("Vectorul sortat: \n");
	for (int i = 0; i < n; ++i)
		printf("%d, ", v[i]);
	printf("\n");

	return 0;
}
