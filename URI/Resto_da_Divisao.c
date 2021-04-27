#include <stdio.h>
#include <math.h>

int main()
{
    int x = 0, y = 0, operacoes = 0, menor = 0;

    scanf(" %d %d", &x, &y);

    while (1)
    {
        if (x > y)
        {
            y++;
            menor = y;
        }
        else if (x < y)
        {
            x++;
            menor = x;
        }

        if(x == y)
        {
            break;
        }

        if (menor % 5 == 2 || menor % 5 == 3)
        {
            printf("%d\n", menor);
        }
    }

    return 0;
}