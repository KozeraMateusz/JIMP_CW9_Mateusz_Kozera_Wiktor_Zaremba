#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(Matrix *x, Matrix *mat, Matrix *b)
{ //zakladamy tutaj juz ze r =c bo inaczej nie ma konkretnej macierzy rozwiazan, bo trzeba parametry robic
int i;
int j=1;
int temp;
        if(mat->data[mat->c-1][mat->c-1] == 0) {
                //printf("Macierz osobliwa!");
                return NULL;
        }
        x->data[(x->r)-1][0]=(b->data[(b->r)-1][0])/(mat->data[(mat->c)-1][(mat->r)-1]);

        temp=x->data[0][(x->c)-1];

               for(i=(mat->r)-2; i>=0; i--)
                {
                        x->data[i][0]=b->data[i][0];
                for(j=i+1; j<mat->r; j++)
                {
                        x->data[i][0]=x->data[i][0]-mat->data[i][j]*x->data[j][0];
                }
                        x->data[i][0]=x->data[i][0]/mat->data[i][i];
                }

       return 1;


}

