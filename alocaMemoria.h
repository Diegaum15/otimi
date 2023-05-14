#ifndef _LIB_ALOCA_H_
#define _LIB_ALOCA_H_
#include "alocaMemoria.h"

int* alocaVetor(int size);

int** alocaMatrizInt(int linhas, int colunas);

float** alocaMatrizFloat(int linhas, int colunas);

void imprimeMatrizFloat(float** matriz, int linhas, int colunas);

void imprimeMatrizInt(int** matriz, int linhas, int colunas);

void liberaVetor(int* vetor);

void liberaMatrizInt(int** matriz, int rows);

void liberaMatrizFloat(float** matriz, int linhas);

#endif