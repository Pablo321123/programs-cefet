#include <stdio.h>

int main()
{

    int j = 0, i = 0, min = 0, cont = 0;
    double M[12][12], valor = 0;

    char op;

    scanf(" %c", &op);

    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 12; j++)
        {
            scanf(" %lf", &M[i][j]);
        }
    }

    for (j = 11; j > 0; j--)
    {
        for (i = 0; i < 12; i++)
        {
            if (i > min && j)
            {
                valor += M[i][j];
                cont++;
            }
        }

        min++;
    }

    switch (op)
    {
    case 'S':

        printf("%.1lf\n", valor);

        break;

    case 'M':

        valor = valor / cont;

        printf("%.1lf\n", valor);

        break;
    }

    return 0;
}