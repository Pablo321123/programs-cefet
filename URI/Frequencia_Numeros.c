#include <stdio.h>
#include <stdlib.h>

#define tamanho 2001

int main()
{
    int op = 0, i = 0, j = 0, indice, **numeros, maximo = 0;

    scanf(" %d", &op);

    numeros = (int **)calloc(tamanho, sizeof(int));

    for (int i = 0; i < tamanho; i++)
    {
        numeros[i] = (int *)calloc(2, sizeof(int));
    }

    while (op--)
    {
        scanf(" %d", &indice);

        if (numeros[indice][0] != indice)
        {
            numeros[indice][0] = indice;
        }

        if (indice > maximo)
        {
            maximo = indice;
        }

        numeros[indice][1]++;
    }

    for (i = 0, j = 0; i <= maximo; i++, j++)
    {
        if (numeros[i][0] != 0)
        {
            printf("%d aparece %d vez(es)\n", numeros[i][0], numeros[i][1]);
        }
    }

    return 0;
}