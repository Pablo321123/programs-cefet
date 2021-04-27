#include <stdio.h>

int main()
{

    int j = 0, i = 0, min = 0, max = 11;
    double M[12][12], valor = 0;
    
    char op;

    scanf(" %c", &op);

    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 12; j++)
        {
            scanf(" %lf", &M[i][j]);

            if ((j > min && j < max) && (i < 5))
            {
                valor += M[i][j];
            }
        }

        min++;
        max--;
    }

    switch (op)
    {
    case 'S':

        printf("%.1lf\n", valor);

        break;

    case 'M':

        valor = valor / 30;

        printf("%.1lf\n", valor);

        break;
    }

    return 0;
}