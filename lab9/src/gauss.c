#include "gauss.h"
#include <stdio.h>
#include <math.h>

int eliminate(Matrix *mat, Matrix *b){
 
int i,j,k,p;
double temp;

for(i = 0; i < mat->r-1; i++) {
	for(k = i+1; k < mat->r; k++) {
		temp = mat->data[k][i] / mat->data[i][i];

			if(mat->data[i][i] == 0) {
				printf("Macierz osobliwa!\n");
				return NULL; 
			}
		for(j = 0; j < mat->c; j++) {
			mat->data[k][j] = mat->data[k][j] - temp * mat->data[i][j];
			b->data[k][0] = b->data[k][0] - temp * b->data[i][j];
		}
		}
 	}
		return 1;
}
