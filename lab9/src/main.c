#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	if(A->c != A->r) {
		printf("Macierz nie jest kwadratowa, nie mozna rozwiazac bez uzycia parametrow!\n");
		return -1;
	}
	if(b->r != A->c) {
		printf(" Nie mozna wymnozyc macierzy A i b o podanych wymiarach!\n");
		return 1;
	}
	if(b->c != 1) { 
		printf("Podany zly wymiar macierzy - za duzo kolumn!\n");
		return 1;
	}
	
	if (A == NULL) return -1;
	if (b == NULL) return -2;
	printToScreen(A);
	printToScreen(b);

	if(eliminate(A,b) == NULL) {
		printf("Macierz osobliwa!1");
		return EXIT_FAILURE;
	}

	res = eliminate(A,b);
	x = createMatrix(b->r, 1);
	
	if (x != NULL) {
		if(backsubst(x,A,b) == 0) {
			printf("Macierz osobliwa!2");
			return EXIT_FAILURE;
		}
		res = backsubst(x,A,b);
		
		printToScreen(x);
	  freeMatrix(x);
	} else {
					fprintf(stderr,"BĹ‚Ä…d! Nie mogĹ‚em utworzyÄ‡ wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
	
}

