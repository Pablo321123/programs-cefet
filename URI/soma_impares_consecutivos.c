#include <stdio.h>
#include <math.h>

int main()
{

    int x = 0, y = 0, soma = 0, menor = 0;

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

        if (x == y)
        {
            break;
        }

        if (menor % 2 != 0)
        {
            soma += menor;
        }
    }
    printf("%d\n", abs(soma));

    return 0;
}