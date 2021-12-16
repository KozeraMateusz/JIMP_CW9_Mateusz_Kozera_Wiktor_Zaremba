#include "gauss.h"
#include <stdio.h>
#include <math.h>

int eliminate(Matrix *mat, Matrix *b){
 
int i,j,k,p;
double temp;

for(i = 0; i < mat->r-1; i++) {
	double max=fabs(mat->data[i][i]);
		int maxi=i;
		for(p=i+1;p<=mat->r-1;p++)
		{
			if(fabs(mat->data[i][p])>max)
			{
				max=fabs(mat->data[i][p]);
				maxi=i;
			}
		}		

		if(maxi!=i) {
			temp=b->data[0][i];
			b->data[0][i]=b->data[0][maxi];
			b->data[0][maxi]=temp;
		for(p=0;p<=mat->r-1;p++) {
			temp=mat->data[p][i];
			mat->data[p][i]=mat->data[p][maxi];
			mat->data[p][maxi]=temp;
		}
				
		}
		
		for(k = i+1; k < mat->r; k++) {
			temp = mat->data[i][k] / mat->data[i][i];
			if(mat->data[i][i] == 0) {
				printf("Niedobra macierz!\n");
				return NULL;
			}
		}
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
