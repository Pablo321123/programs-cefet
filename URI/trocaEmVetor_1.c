#include <stdio.h>

#define tamanho 21

int vetor[tamanho];

void update(int posicao, int valor)
{
    while (posicao < tamanho)
    {
        vetor[posicao] += valor;
        posicao += (posicao & -posicao);
    }
}

int rsq(int indice) //Range sub Query -> Consulta de soma em intervalo
{
    int resultado = 0;

    while (indice > 0)
    {
        resultado += vetor[indice];
        indice -= (indice & -indice);
    }

    return resultado;
}

int main()
{
    int n[tamanho];
    int aux;

    for (int i = 1; i < tamanho; i++)
    {
        scanf(" %d", &n[i]);
        getchar();

        update(i, n[i]);

        //printf("%d\n\n", rsq(i));
    }

    int indice = 0;

    for (int i = 1, j = 20, z = 19; i < 11; i++, j--, z--)
    {
        aux = n[i];

        n[i] = rsq(j) - rsq(z);
        n[j] = aux;

        printf("N[%d] = %d\n", (i - 1), n[i]);
    }

    return 0;
}