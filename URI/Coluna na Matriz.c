#include <stdio.h>

int main()
{

    int M[12][12], valor = 0, j = 0, i = 0, coluna;
    char op;

    scanf("%d %c", &coluna, &op);

    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 12; j++)
        {
            scanf(" %d", &M[i][j]);

            if (j == coluna)
            {
                valor += M[i][j];
            }
        }
    }

    switch (op)
    {
    case 'S':

        printf("%d\n", valor);

        break;

    case 'M':

        valor = valor / 12;

        printf("%d\n", valor);

        break;
    }
}