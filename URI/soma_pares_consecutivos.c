#include <stdio.h>

int main()
{

    int p, sum = 0, contador = 0;

    while (1)
    {
        scanf(" %d", &p);
        contador = 0;
        sum = 0;

        if (p == 0)
        {
            break;
        }

        while (contador < 5)
        {
            if (p % 2 != 0)
            {
                p++;
            }
            else
            {
                sum += p;
                contador++;
                p += 2;
            }
        }

        printf("%d\n", sum);
    }

    return 0;
}