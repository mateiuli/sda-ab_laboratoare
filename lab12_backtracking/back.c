/**
 * 	Laborator 12 SDA-AB: Backtracking
 * 	Author: Iulian-Razvan Matesica <iulian.matesica@gmail.com>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* DO NOT TOCH THESE LINES! */
#define MAX_LEN_TASK   20
#define MAX_ASCII_CODE 255
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int pass_match(char *pass);

/**
 * TASK 1.
 *
 * Scrieti un algoritm Backtracking care sa genereze toate sirurile de
 * caractere de lungime n care pot fi generate folosind doar caracterele 'A' si 'B'.
 *
 * Sirurile generate: AAA, AAB, ABA, ABB, BAA, BAB, BBA, BBB,
 * Numarul de solutii este 2^3 = 8.
 *   (avem 2 caractere 'A' si 'B', iar lungimea sirului este 3).
 *
 * Functia primeste 3 parametrii:
 *   sol => vector in care se construieste sirul
 *   k   => dimensiunea actuala a vectorului la care se lucreaza (sirul de caractere)
 *   n   => lungimea maxima a sirului de caratere
 *
 * Afisati sirurile la iesirea standard.
 */
void back_task1(char *sol, int k, int n)
{
	/**
	 * TODO
	 *
	 * // Daca am construit o solutie, o afisez
	 * 1. if k >= n then
	 *     1.1. print sol
	 * // Daca mai am de construit
	 * 2. else
	 *     2.1. for c = 'A', 'B'
	 *         // Pun pe pozitia k caracterul c
	 *         2.2. sol[k] = c
	 *         // Merg in adancime - completez urmatorul nivel (k + 1)
	 *         2.3. back_task1(sol, k + 1, n)
	 */
}

/**
 * TASK 2.
 *
 * Se da un sir de caractere 'sir' de lungimea 'len'. Generati toate permutarile
 * acestui sir si afisati-le la iesirea standard.
 *
 * Folositi-va de vectorul 'sol' pentru construirea solutiei si de 'k' pentru
 * a retine lungimea sirului pe parcursul constructiei.
 *
 * La taskul 1 nu ne interesa daca un caracter era pus de mai multe ori.
 * Aici, la permutari, trebuie sa ne asiguram ca odata folosit un caracter,
 * nu il vom mai folsi pe viitor. Pentru asta putem folosi vectorul used[],
 * unde used[i] = 1 inseamna: caracterul sir[i] a fost deja folosit in constructie.
 *      used[i] = 0: caracterul sir[i] nu a am mai fost folosit.
 *
 */
int used[MAX_LEN_TASK];

void back_task2(char *sir, int len, char *sol, int k)
{
	/**
	 * TODO
	 *
	 * // Daca am construit o solutie, o afisez
	 * 1. if k >= n then
	 *     1.1. print sol
	 * // Daca mai am de construit
	 * 2. else
	 *     2.1. for i = 0, len - 1
	 *         2.2. if not used[i]
	 *             // Pun pe pozitia k caracterul sir[i]
	 *             2.3. sol[k] = sir[i]
	 *             // Marchez sir[i] ca folosit.
	 *             2.4. used[i] = 1;
	 *             // Merg in adancime - completez urmatorul nivel (k + 1)
	 *             2.5. back_task2(sir, len, sol, k + 1);
	 *             // Marchez sir[i] ca nefolosit - pentru alte solutii.
	 *             2.6. used[i] = 0;
	 */
}

/**
 * TASK 3: Bruteforce.
 *
 * Profu' tine subiectele de la examen pe Dropbox (cu tot cu rezolvari).
 * (desi.. ce tot zic eu, tinem acolo si rezolvarile la teme si tot - HOT STUFF!).
 * Doriti sa spargeti acest cont pentru... research purposes... of cors.
 *
 * Stiti emailul dar nu stiti parola. Folositi un algoritm bruteforce pentru
 * gasirea parolei.
 *
 * Bruteforce presupune generarea tuturor parolelor.
 * Parola profului are urmatoarele proprietati:
 *   - lungime fixa de 9 caractere
 *   - contine doar caracterele 'm', 'n' si 'o'
 *
 * Folositi functia pass_match() pentru a verifica daca solutia construita
 * este intr-adevar parola cautata.
 */
void back_task3(char *caractere, int len, int pass_len, char *sol, int k)
{
	/**
	 * TODO
	 *
	 * // Daca am construit o parola, o testez si o afisez daca e cea buna
	 * 1. if k >= pass_len then
	 *     1.1. if pass_match(sol)
	 *          1.2. printf sol
	 *
	 * // Daca mai am de construit (nu am ajuns la lungimea pass_len).
	 * 2. else
	 *     // Parcurg elementele multimii 'carctere'
	 *     2.1. for i = 0, len - 1
	 *         // Pun pe pozitia k caracterul 'caractere[i]'
	 *         2.2. sol[k] = caractere[i]
	 *         // Acum ca pe pozitia k il am pe caractere[i], incerc sa pun ceva pe k + 1.
	 *         2.3. back_task3(caractere, len, pass_len, sol, k + 1);
	 */
}

/**
 * TASK 3: Apelati functia de bruteforce.
 *
 */
void task3()
{
	/* Multimea caracterelor folosite in parola. */
	char caractere[] = {'m', 'n', 'o'};
	/* In acest vector se vor construi solutiile, pe rand. */
	char pass[MAX_LEN_TASK];
	/* Initializam tot vectorul cu 0. */
	memset(pass, 0, sizeof(pass));

	/**
	 * TODO: Apelati functia back_task3.
	 *
	 * Functia primeste urmatorii parametrii:
	 * Parametrul 1: multimea de caractere folosite
	 * Parametrul 2: numarul de caractere din multime
	 * Parametrul 3: lungimea parolei cautate (9)
	 * Parametrul 4: un vector temporar in care se construiesc parolelel (pass).
	 * Parametrul 5: lungimea initiala a parolei (se porneste de la un sir vid,
	 * deci parametrul este 0).
	 */

}

/**
 * Task 4: Problema reginelor.
 *
 * Fiind data o tabla de sah 'm' cu dimensiunea n linii, n coloane, sa se
 * genereze toate posibilitatile de aranjare a n regine pe tabla.
 *
 * Regulile sunt urmatoarele:
 *  - nu se afla doua regine pe aceasi linie
 *  - nu se afla doua regine pe aceasi coloana
 *  - nu se afla doua regine pe aceasi diagonala
 *
 * Functia is_ok_pos care primeste matricea 'm', dimensiunea ei 'n'
 * si verifica daca putem pune o regina pe pozitia (row, col).
 * (este deja implementata - mergeti la functia back_task4 de mai jos).
 *
 * Fuctia returneaza 0 daca NU putem pune regina pe pozitia (row, col), altfel
 * returneaza 1.
 *
 * Matricea 'm' contine caracterul ' ' (space) unde este liber si 'R' unde
 * este plasata o regina.
 *
 */
int is_ok_pos(char **m, int n, int row, int col)
{
	/* Parcurgem coloana col, de sus in jos. */
	for (int i = 0; i < n; i++)
		if (m[i][col] == 'R')
			return 0;

	/* Parcurgem linia row, de la stanga la dreapta. */
	for (int j = 0; j < n; j++)
		if (m[row][j] == 'R')
			return 0;

	/**
	 * Directia diagonalei principale.
	 * Parcurgem elementele de pe diagonala pe care se afla (row, col).
	 */
	for (int i = 0; i < n; i++) {
		/* Ne asiguram ca nu iesim din matrice. */
		if (row + i < n && col + i < n)
			if (m[row + i][col + i] == 'R')
				return 0;

		if (row - i >= 0 && col - i >= 0)
			if (m[row - i][col - i] == 'R')
				return 0;
	}

	/**
	 * Directia diagonalei secundare.
	 * Parcurgem elementele de pe diagonala pe care se afla (row, col).
	 */
	for (int i = 0; i < n; i++) {
		if (row + i < n && col - i >= 0)
		 	if (m[row + i][col - i] == 'R')
				return 0;

		if (row - i >= 0 && col + i < n)
			if (m[row - i][col + i] == 'R')
				return 0;
	}

	return 1;
}

/**
 * TASK 4: Problema reginelor - backtracking
 *
 * Implementati functia printr-un algoritm Backtracking pentru generarea
 * tuturor solutiilor problemei reginelor.
 *
 */
void back_task4(char **m, int n, int k)
{
	/**
	 * TODO
	 *
	 * // Daca am construit o solutie, o afisez
	 * 1. if k >= n then
	 *     1.1. printati matricea m de dimensiune nxn
	 *
	 * // Daca mai am de construit
	 * 2. else
	 *     // Incerc sa pun regina k pe fiecare coloana i pe rand
	 *     2.1. for i = 0, n - 1
	 *         // Daca e safe sa pun regina pe linia k, coloana i
	 *         2.2. if is_ok_pos(m, n, k, i)
	 *             // Marchez cu R pozitia reginei k
	 *             2.3. m[k][i] = 'R';
	 *             // Merg in adancime - incerc sa pun regina k + 1
	 *             2.4. back_task4(m, n, k + 1);
	 *             // La intoarcere, sterg regina - o voi pune pe alta coloana
	 *             2.5. m[k][i] = '_';
	 */
}

/**
 * Task 5: John Snow
 *
 * Se da urmatoarea harta 2D, ca o matrice de caractere 6x6.
 *
 *     _ _ W _ _ B
 *     A _ W # W B
 *     W _ _ _ _ W
 *     _ _ A W _ _
 *     _ B W # # _
 *     _ _ _ _ _ _
 *
 * Casutele marcate cu '_' sunt libere.
 * Casutele marcate cu altceva sunt ocupate.
 *
 * Initial, John Snow se afla in coltul dreapta jos, la coordonatele (5, 5). El
 * doreste sa dea la Facultatea de Automatica si Calculatoare, care se afla in
 * coltul stanga-sus, la coordonatele (0, 0), insa pe traseu intalneste
 * White-Walkers (W), BAC-ul (B) si examenul de admitere (A).
 * Afisati toate solutiile pe unde John Snow o poate lua ca sa ajunga facultate.
 *
 * Marcati cu 'X' drumul pe unde o ia. John Snow nu se poate trece de mai multe
 * ori prin aceasi casuta.
 *
 * Ca exemplu, una din solutii arata asa:
 *
 *     X X W _ _ B
 *     A X W # W B
 *     W X _ _ _ W
 *     X X A W _ _
 *     X B W # # _
 *     X X X X X X
 *
 */
void back_task5(char **map, int n, int i, int j)
{
	/**
	 * Cele 4 directii (sus, jos, stanga, dreapta) pe care putem merge.
	 *
	 *  +--------------------------------------+
	 *  |            | (i - 1, j) |            |
	 *  +--------------------------------------+
	 *  | (i, j - 1) | (i,     j) | (i, j + 1) |
	 *  +--------------------------------------+
	 *  |            | (i + 1, j) |            |
	 *  +--------------------------------------+
	 *
	 */
	static int dirI[] = {-1, 1,  0, 0};
	static int dirJ[] = { 0, 0, -1, 1};

	/**
	 * TODO
	 *
	 * // Daca am ajuns la coordonatele (0, 0) - am construt o solutie
	 * 1. if i == 0 AND j == 0 then
	 *     1.1. printati matricea map de dimensiune nxn
	 *
	 * // Daca nu am ajuns inca pe pozitia finala
	 * 2. else
	 *     // Merg pe rand, pe cele patru directii ale casutei curente (i, j).
	 *     2.1. for d = 0, 3
	 *         // Calculez coordonatele casutei vecine
	 *         // Ma asigur ca coordonatele nu depasesc dimensiunea matricei.
	 *         2.1. newI = min(n - 1, max(i + dirI[d], 0))
	 *         2.2. newJ = min(n - 1, max(j + dirJ[d], 0))
	 *
	 *         // Daca noua directie este libera
	 *         2.3 if map[newI][newJ] == '_'
	 *             // O marchez ca ocupata.
	 *             2.4. map[newI][newJ] = 'X'
	 *             // Merg in adancime - ma mut pe casuta (newI, newJ).
	 *             2.5. back_task5(map, n, newI, newJ)
	 *             // La intoarcere eliberez casuta - voi incerca cu alta directie.
	 *             2.6. map[newI][newJ] = '_'
	 */

	if (i == 0 && j == 0) {
		/* Afisam matricea. */
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				printf("%c ", map[i][j]);
			printf("\n");
		}
		printf("\n");
	} else {
		/* Mergem pe rand pe cele 4 directii. */
		for (int d = 0; d < 4; d++) {
			int newI = min(n - 1, max(i + dirI[d], 0));
			int newJ = min(n - 1, max(j + dirJ[d], 0));

			/* TODO: vedeti algoritmul de mai sus. */

		}
	}
}

#define SECRET2 { \
	0x43, 0x61, 0x74, 0x73, 0x21, 0x20, 0x43, 0x61, 0x74, 0x73, 0x20, \
	0x65, 0x76, 0x65, 0x72, 0x79, 0x77, 0x68, 0x65, 0x72, 0x65, 0x21, 0x00 \
}

int main()
{
	/* TASK 1. */
	char sol1[MAX_LEN_TASK];
	memset(sol1, 0, sizeof(sol1));
	printf("Task 1: Toate sirurile formate din 'A' si 'B'\n");
	back_task1(sol1, 0, 3);
	printf("\n");

	/* TASK 2. */
	char *sir2 = "woem";
	char sol2[MAX_LEN_TASK];
	memset(sol2, 0, sizeof(sol2));
	printf("Task 2: Permutarile sirului '%s'\n", sir2);
	back_task2(sir2, strlen(sir2), sol2, 0);
	char x[] = SECRET2;
	if (sol2[3] == 'w' &&  sol2[1] == 'e' && sol2[0] == 'm' && sol2[2] == 'o')
		printf("%s\n", x);
	printf("\n");

	/* TASK 3. */
	printf("Task 3: Bruteforce\n");
	task3();
	printf("\n");

	/* TASK 4. */
	char **m;
	m = malloc(4 * sizeof(char*));
	for (int i = 0; i < 4; i++) {
		m[i] = malloc(4 * sizeof(char));
		memset(m[i], '_', sizeof(char) * 4);
	}
	printf("Task 4: Problema reginelor\n");
	back_task4(m, 4, 0);
	printf("\n");

	/* TASK 5. */
	char *cmap[] = {
		"__W__B",
		"A_W#WB",
		"W____W",
		"__AW__",
		"_BW##_",
		"______",
	};

	char **map;
	map = malloc(6 * sizeof(char*));
	for (int i = 0; i < 6; i++) {
		map[i] = malloc(6 * sizeof(char));
		memcpy(map[i], cmap[i], 6);
	}

	printf("Task 5: John Snow\n");
	back_task5(map, 6, 5, 5);
	printf("\n");

	return 0;
}

int pass_match(char *pass)
{
	char x[] = {
		0b11100110,
		0b11110110,
		0b11010110,
		0b11100110,
		0b11110110,
		0b11010110,
		0b11100110,
		0b11110110,
		0b11010110
	};

	char m[] = {
		0x43, 0x41, 0x54, 0x3a, 0x20, 0x4f, 0x4d, 0x47, 0x20, 0x48, 0x55, 0x4d,
		0x41, 0x4e, 0x2c, 0x20, 0x59, 0x4f, 0x55, 0x20, 0x46, 0x4f, 0x55, 0x4e,
		0x44, 0x20, 0x54, 0x48, 0x45, 0x20, 0x50, 0x41, 0x53, 0x53, 0x57, 0x4f,
		0x52, 0x44, 0x21, 0x00
	};

	char *p = pass;
	unsigned int i = 0;
	int match = 0;

	/* Obfuscated stuff is obfuscated. :P (go apply bruteforce). */
	while(*p && i < 9) {
		match += (((*p & 0xF0) >> 4) == (x[i] & 0x0F)) && (((*p & 0x0F) << 4) == (x[i] & 0xF0));
		p++;
		i++;
	}

	match = (match == ((0x80 >> 7) | (1 << 3))) && (!*p + (~i > 9)) >= (1 << 1);
	if (match)
		printf("%s\n", m);

	return match;
}
