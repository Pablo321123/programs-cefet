#include <stdio.h>

#define tamanho 1000

int main()
{
    int t = 0, vetor[tamanho], posicao = 0, valor = 0;

    scanf(" %d", &t);

    do
    {
        if (valor <= (t - 1))
        {
            vetor[posicao] = valor;
            valor++;
        }
        else
        {
            valor = 0;
            continue;
        }

        printf("N[%d] = %d\n", posicao, vetor[posicao]);
        posicao++;
    } while (posicao < 1000);

    return 0;
}