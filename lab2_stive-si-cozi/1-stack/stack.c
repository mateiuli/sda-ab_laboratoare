#include <stdio.h>

/**
 * Structura de mai jos NU reprezinta o stiva, ea reprezinta doar un element
 * dintr-o lista inlantuita. Structura ce defineste o stiva este mai jos.
 *
 * DON'T TOUCH THIS.
 */
typedef struct {
	/* Valoarea retinuta de catre nod. */
  int val;

	/* Pointer catre urmatorul element de tip nod. */
  struct stack_node_t *next;
} stack_node_t;

/**
 * Structura ce reprezinta o Stiva.
 * Stivele pot fi implementate prin mai multe modalitati: vector static/dinamic
 * sau printr-o lista inlantuita.
 *
 * Implementarea prin lista inlantuita este preferata in majoritatea cazurilor
 * pentru ca este foarte eficienta atat din punct de vedere al operatiilor
 * de adaugare/stergere dar si din punct de vedere al memoriei (alocam doar cat
 * avem nevoie).
 *
 * Vom folosi in continuare o stiva implementat printr-o lista inlantuita,
 * O stiva de tipul 'stack_t' va contine capul listei inlantuite. Fiecare
 * element din aceasta lista inlantuita va fi un nod de tipul 'node_t'.
 *
 * DON'T TOUCH THIS.
 */
typedef struct {
  /* Capul listei inlantuite. */
  struct stack_t *head;

  /* Dimensiunea stivei. */
  unsigned int length;
} stack_t;

/**
 *
 */
int main()
{

  return 0;
}
