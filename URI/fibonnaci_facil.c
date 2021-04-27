#include <stdio.h>

int main()
{

    int n = 0, contador = 0, anterior = 0, proximo = 0, atual = 0;

    scanf(" %d", &n);

    while (contador < n)
    {
        if (contador == 0)
        {
            atual = 0;
        }
        else if (contador == 1)
        {
            atual = 1;
        }
        else
        {
            atual = proximo;
        }

        proximo = atual + anterior;
        anterior = atual;

        if (contador == n - 1)
        {
            printf("%d\n", atual);
        }
        else
        {
            printf("%d ", atual);
        }

        contador++;
    }

    return 0;
}