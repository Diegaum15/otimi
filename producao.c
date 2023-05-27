#include <stdio.h>
#include <stdlib.h>
#include "alocaMemoria.h"
#define TAM_COL_MATRIZCL 2



int main() 
{
    int num_produtos, num_compostos; 
    float *valores;
    float **matriz_cl;
    float **matriz_qc, **matrizT;
    float *funcao_objetiva;
    float soma, lucro;
    int i, j, cont;

    printf("\nEntre com o numero de produtos e compostos\n");
    scanf("%d %d", &num_produtos, &num_compostos);
    
    // aloca um vetor para inserção dos valores de cada produto
    valores = alocaVetorFloat(num_produtos);

    // aloca um vetor de num_produtos ponteiros para num_produtos
    printf("\nEntre com o valor de cada produto:\n");
    for (i = 0; i < num_produtos; i++)
    {
        scanf("%f", &valores[i]);
    }

    matriz_cl = alocaMatrizFloat(num_compostos, TAM_COL_MATRIZCL);
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
        scanf("%f", &matriz_cl[i][j]);
        scanf("%f", &matriz_cl[i][j+1]);
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

    // Alocação de memória para funcao_objetiva
    funcao_objetiva = alocaVetorFloat(num_compostos);

    /* Calcular funcao objetiva */
    printf("\nVamos calcular funcao objetiva :\n");

    soma = 0;
    cont = 0; 
    for (i = 0; i < num_produtos; i++)
    {
        for (j = 0; j < num_compostos; j++)
        {
            soma += matriz_qc[i][j] * matriz_cl[j][0];
            if( j == num_compostos - 1)
            {
                printf("Valor vetor - Valor custo: %f - %.2f\n", valores[cont], soma);
                lucro = valores[cont] - soma;
                funcao_objetiva[cont] = lucro;
                printf("Lucro: %.2f\n", lucro);
                cont++;  
                soma = 0;
            }
        }
    }

    printf("Funcao objetiva: ");
    for(i = 0; i < num_produtos; i++)
    {
        printf("%.2f ", funcao_objetiva[i]);
    }


    printf("\n");

    matrizT = alocaMatrizFloat(num_compostos, num_produtos);
    if(matriz_qc == NULL)
    {
        return 1;
    }

    for(i = 0; i < num_produtos; i++)
    {
        for(j = 0; j < num_compostos; j++)
        {
            matrizT[j][i] = matriz_qc[i][j];
        }    
    }

    //Imprime matriz_qc
    imprimeMatrizFloat(matriz_qc, num_produtos, num_compostos);
    printf("\n");

    // Imprime a matriz transposta
    imprimeMatrizFloat(matrizT, num_compostos, num_produtos);

    FILE *file = fopen("input.lp", "w");
    
    if (file == NULL) 
    {
        printf("Erro ao criar o arquivo de entrada.\n");
        return 1;
    }

    fprintf(file, "max: ");
    for (i = 0; i < num_produtos; i++)
    {
        // Testa para ver se o lucro eh positivo        
        //if(funcao_objetiva[i] < 0)
          //  funcao_objetiva[i] = 0;
    
        fprintf(file, "%.2f x%d", funcao_objetiva[i], i+1);
        if (i < num_produtos - 1)
        {
            fprintf(file, " + ");
        }
    }
    fprintf(file, ";\n");

    fprintf(file, "\n");

    for (i = 0; i < num_compostos; i++)
    {
        for (j = 0; j < num_produtos; j++)
        {
            fprintf(file, "%.2f x%d", matrizT[i][j], j+1);
            if (j < num_produtos - 1)
            {
                fprintf(file, " + ");
            }
        }
        fprintf(file, " <= %f;\n", matriz_cl[i][1]);
    }

    fprintf(file, "\n");

    for (i = 0; i < num_produtos; i++)
    {
        fprintf(file, "x%d >= 0;\n", i+1);
    }

    fclose(file);

    // Libera memoria alocada
    liberaMatrizFloat(matriz_cl, num_compostos);
    liberaMatrizFloat(matriz_qc, num_produtos);

    liberaVetorFloat(valores);
    
    return 0;
}
