#include <stdio.h>
#include <string.h>

int inverte_numero(int numero, int *local_armazenamento)
{
    int i = 0, casas_decimais = 0;

    for (i = 0;; i++)
    {
        local_armazenamento[i] = (numero % 10);
        numero = numero / 10;
        casas_decimais++;

        if (numero == 0)
        {
            break;
        }
    }

    return casas_decimais;
}

int main()
{
    int op = 0, num_intervalo[2], i = 0, j = 0;
    int numeros_decimais = 0;

    scanf(" %d", &op);

    while (op--)
    {

        int num_invertido[5] = {0, 0, 0, 0, 0};

        scanf(" %d %d", &num_intervalo[0], &num_intervalo[1]);

        for (i = num_intervalo[0]; i <= num_intervalo[1]; i++)
        {
            printf("%d", i);
        }

        for (i = num_intervalo[1]; i >= num_intervalo[0]; i--)
        {
            numeros_decimais = inverte_numero(i, (int *)&num_invertido);

            j = 0;

            while (numeros_decimais--)
            {
                printf("%d", num_invertido[j++]);
            }
        }

        printf("\n");
    }

    return 0;
}