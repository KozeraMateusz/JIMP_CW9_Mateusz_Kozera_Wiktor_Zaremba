#include "gauss.h"
#include <stdio.h>
#include <math.h>

int eliminate(Matrix *mat, Matrix *b){
 
int i,j,k,p;
double temp;

for(i = 0; i < mat->r-1; i++) {

		double maxi=fabs(mat->data[i][i]);
		int maxi_i=i;
		for(p=i+1;p<=mat->r-1;p++)
		{
			if(fabs(mat->data[p][i])>maxi)
			{
				maxi=fabs(mat->data[p][i]);
				maxi_i=p;
			}
		}		
//petla przeszla po kolumnie i przeszukala za najwieksza wartoscia, teraz trzeba zmienic
		if(maxi_i!=i) {
			temp=b->data[i][0];
			b->data[i][0]=b->data[maxi_i][0];
			b->data[maxi_i][0]=temp;
//zmienilem wartosci w macierzy b, a teraz trzeba zrobic to w a macierzy

		for(p=0;p<=mat->r-1;p++) {
			temp=mat->data[i][p];
			mat->data[i][p]=mat->data[maxi_i][p];
			mat->data[maxi_i][p]=temp;
		}
				
		}
		
		for(k = i+1; k < mat->r; k++) {
			temp = mat->data[k][i] / mat->data[i][i];
			if(mat->data[i][i] == 0) {
				printf("Macierz osobliwa!\n");
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
