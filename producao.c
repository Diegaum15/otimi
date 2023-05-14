#include <stdio.h>
#include <stdlib.h>
#include "alocaMemoria.h"
#define TAM_COL_MATRIZCL 2

int main() 
{
    int num_produtos, num_compostos; 
    int *valores;
    int **matriz_cl;
    float **matriz_qc;
    int i, j;

    printf("\nEntre com o numero de produtos e compostos\n");
    scanf("%d %d", &num_produtos, &num_compostos);
    
    // aloca um vetor para inserção dos valores de cada produto
    valores = alocaVetor(num_produtos);

    // aloca um vetor de num_produtos ponteiros para num_produtos
    printf("\nEntre com o valor de cada produto:\n");
    for (i = 0; i < num_produtos; i++)
    {
        scanf("%d", &valores[i]);
    }

    matriz_cl = alocaMatrizInt(num_compostos, TAM_COL_MATRIZCL);
    if (matriz_cl == NULL) 
    {
        return 1;
    }

    /* Entre com o custo e limite de cada produto*/
    printf("\nEntre com o custo e limite de produção de cada composto:\n");
    
    // coluna 0, linha i -> teremos os custos
    // coluna 1, linha i -> teremos os limites
    j = 0;    
    for (i = 0; i < num_compostos; i++)
    {
        scanf("%d", &matriz_cl[i][j]);
        scanf("%d", &matriz_cl[i][j+1]);
    } 

    // Alocação de memória para matriz_qc
    matriz_qc = alocaMatrizFloat(num_produtos, num_compostos);
    if (matriz_qc == NULL) 
    {
        return 1;
    }

    /* Entre com o composto de cada coluna*/
    printf("\nEntre com o composto de cada coluna\n");
    for (i = 0; i < num_produtos; i++)
    {
        for (j = 0; j < num_compostos; j++)
        {
            scanf("%f", &matriz_qc[i][j]);
        }
    }
    
    /* aloca um vetor de num_produtos ponteiros para num_produtos 8 
    matriz_qc = malloc (num_produtos * sizeof (float*)) ;
    // aloca um vetor com todos os elementos da matriz_qc
    matriz_qc[0] = malloc (num_produtos * num_compostos * sizeof (float)) ;
    // ajusta os demais ponteiros de num_produtos (i > 0)
    for (i=1; i < num_produtos; i++)
        matriz_qc[i] = matriz_qc[0] + i * num_compostos ;*/

    FILE *file = fopen("input.lp", "w");
    
    if (file == NULL) 
    {
        printf("Erro ao criar o arquivo de entrada.\n");
        return 1;
    }

    
    //Imprime matriz_qc
    imprimeMatrizFloat(matriz_qc, num_produtos, num_compostos);

    // Imprime matriz_cl
    imprimeMatrizInt(matriz_cl, num_compostos, TAM_COL_MATRIZCL);

    liberaMatrizInt(matriz_cl, num_compostos);
    liberaMatrizFloat(matriz_qc, num_produtos);

    liberaVetor(valores);
    
    return 0;
}
