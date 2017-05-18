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
	if (k >= n) {
		/* Am gasit o solutie. */
		printf("%s\n", sol);

	} else {
		for (char c = 'A'; c <= 'B'; c++) {
			sol[k] = c;
			back_task1(sol, k + 1, n);
		}
	}
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
	if (k >= len) {
		/* Am gasit solutia. O afisez. */
		printf("%s\n", sol);
	} else {
		for (int i = 0; i < len; i++) {
			if (!used[i]) {
				/* Adaug la solutia in constructie pe sir[i]. */
				sol[k] = sir[i];

				/* Marchez sir[i] ca folosit. */
				used[i] = 1;

				/* Acum ca pe pozitia k il am pe sir[i], incerc sa pun ceva pe k + 1. */
				back_task2(sir, len, sol, k + 1);

				/* Marchez sir[i] ca nefolosit. */
				used[i] = 0;
			}
		}
	}
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
 * Bruteforce presupune generarea tuturor parolelor cu proprietatile de mai jos:
 *   - lungime fixa de 9 caractere
 *   - contine doar caracterele 'm', 'n' si 'o'
 *
 * Folositi functia pass_match() pentru a verifica daca solutia construita
 * este intr-adevar parola cautata.
 */
void back_task3(char *caractere, int len, int pass_len, char *sol, int k)
{
	if (k >= pass_len) {
		/* Am construit un sir - verific daca este o solutie. */
		if(pass_match(sol))
			printf("Pass: %s\n", sol);

	} else {
		for (int i = 0; i < len; i++) {
			/* Adaug la solutia in constructie pe sir[i]. */
			sol[k] = caractere[i];

			/* Acum ca pe pozitia k il am pe sir[i], incerc sa pun ceva pe k + 1. */
			back_task3(caractere, len, pass_len, sol, k + 1);
		}
	}
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
	 * Functia primeste multimea de caractere si numarul acestora.
	 * Mai primeste lungimea parolei care trebuie generata (pass_len = 9).
	 * Primeste un vector temporar unde se construiesc solutiile (sol).
	 * Ultimul parametru este nivelul de la care sa inceapa cautarea de parole
	 * (se porneste de la un sir vid, deci lungimea initiala este 0).
	 */
	back_task3(caractere, 3, 9, pass, 0);
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
 * Implementati functia is_ok_pos care primeste matricea 'm', dimensiunea ei 'n'
 * si verifica daca putem pune o regina pe pozitia (row, col).
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
	if (k >= n) {
		/* Am gasit o solutie. */
		printf("Solutia: \n");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%c ", m[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	} else {
		for (int i = 0; i < n; ++i) {
			if(is_ok_pos(m, n, k, i)) {
				m[k][i] = 'R';
				back_task4(m, n, k + 1);
				m[k][i] = '_';
			}
		}
	}
}

/**
 * Task 5: John Snow
 *
 * Se da urmatoarea harta 2D, ca o matrice de caractere 6x6.
 *
 *     _ _ W _ _ #
 *     # _ W # W #
 *     W _ _ _ _ w
 *     _ _ # W _ _
 *     _ # W # # _
 *     _ _ _ _ _ _
 *
 * Casutele marcate cu '_' sunt libere.
 * Casutele marcate cu 'W' = White Walker (obstacol).
 * Casutele marcate cu '#' = blocaj (alt obstacol)
 *
 * Initial, XXX se afla in coltul dreapta jos, la coordonatele (5, 5). El
 * doreste sa ajunga in coltul stanga-sus, la coordonatele (0, 0), insa pe traseu
 * intalneste YYY ca obstacole. Afisati toate solutiile pe unde XXX o poate lua
 * ca sa ajunga la final. Marcati cu 'X' drumul pe unde o ia.
 *
 * Ca exemplu, una din solutii arata asa:
 *
 *     X X W _ _ #
 *     # X W # W #
 *     W X _ _ _ W
 *     X X # W _ _
 *     X # W # # _
 *     X X X X X _
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
	 *  | (i, j - 1) |   (i, j)   | (i, j + 1) |
	 *  +--------------------------------------+
	 *  |            | (i + 1, j) |            |
	 *  +--------------------------------------+
	 *
	 */
	static int dirI[] = {-1, 1,  0, 0};
	static int dirJ[] = { 0, 0, -1, 1};

	if (i == 0 && j == 0) {
		/* Am ajuns la punctul final. */
		printf("Solutia: \n");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%c ", map[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	} else {
		for (int d = 0; d < 4; d++) {
			int newI = min(n - 1, max(i + dirI[d], 0));
			int newJ = min(n - 1, max(j + dirJ[d], 0));

			/* Daca noua directie este libera. */
			if (map[newI][newJ] == '_') {
				/* Marchez ca ocupata. */
				map[newI][newJ] = 'X';
				back_task5(map, n, newI, newJ);
				/* Eliberez casuta. */
				map[newI][newJ] = '_';
			}
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
		"__W__#",
		"#_W#W#",
		"W____W",
		"__#W__",
		"_#W##_",
		"______",
	};

	char **map;
	map = malloc(6 * sizeof(char*));
	for (int i = 0; i < 6; i++) {
		map[i] = malloc(6 * sizeof(char));
		memcpy(map[i], cmap[i], 6);
	}

	printf("Task 5: Help John Snow\n");
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
