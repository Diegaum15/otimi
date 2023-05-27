#include <stdio.h>
#include <stdlib.h>
#define TAM_COL_MATRIZCL 2

int* alocaVetor(int size) 
{
    int* vetor = (int*)malloc(size * sizeof(int));
    if (vetor == NULL) 
    {
        printf("Falha na alocação de memória\n");
        return NULL;
    }
    
    return vetor;
}

float* alocaVetorFloat(float size) 
{
    float* vetor = (float*)malloc(size * sizeof(float));
    if (vetor == NULL) 
    {
        printf("Falha na alocação de memória\n");
        return NULL;
    }
    
    return vetor;
}

int** alocaMatrizInt(int linhas, int colunas) 
{
    int** matriz = (int**)malloc(linhas * sizeof(int*));
    if (matriz == NULL) {
        printf("Alocação de memória falhou.\n");
        return NULL;
    }
    
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*)malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Alocação de memória falhou.\n");
            return NULL;
        }
    }
    
    return matriz;
}

float** alocaMatrizFloat(int linhas, int colunas) 
{
    float** matriz = (float**)malloc(linhas * sizeof(float*));
    if (matriz == NULL) {
        printf("Alocação de memória falhou.\n");
        return NULL;
    }
    
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (float*)malloc(colunas * sizeof(float));
        if (matriz[i] == NULL) {
            printf("Alocação de memória falhou.\n");
            return NULL;
        }
    }
    
    return matriz;
}


void imprimeMatrizFloat(float** matriz, int linhas, int colunas) 
{
    for (int i = 0; i < linhas; i++) 
    {
        for (int j = 0; j < colunas; j++) 
        {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}


void imprimeMatrizInt(int** matriz, int linhas, int colunas) 
{
    for (int i = 0; i < linhas; i++) 
    {
        for (int j = 0; j < colunas; j++) 
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}


void liberaVetor(int* vetor) {
    if (vetor == NULL) {
        return;
    }
    
    free(vetor);
}

void liberaMatrizInt(int** matriz, int linhas) {
    if (matriz == NULL) {
        return;
    }
    
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    
    free(matriz);
}

void liberaMatrizFloat(float** matriz, int linhas) {
    if (matriz == NULL) {
        return;
    }
    
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    
    free(matriz);
}