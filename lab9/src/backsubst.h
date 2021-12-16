#ifndef _BACKSUBST_H
#define _BACKSUBST_H

#include "mat_io.h"

/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - bĹ‚Ä…d dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - bĹ‚Ä…d nieprawidĹ‚owych rozmiarĂłw macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b);

#endif

