#include <stdio.h>

int main()
{

    int a = 0, b = 0, c = 0, d = 0;

    float tt = 1.5;

    scanf(" %d %d %d %d", &a, &b, &c, &d);

    if (b > c && d > a && (c + d) > (a + b) && c > 0 && d > 0 && a % 2 == 0)
    {
        printf("Valores aceitos\n");
    }
    else
    {
        printf("Valores nao aceitos\n");
    }

    switch (tt)
    {
    case 1.5:
        print("Dentro do caso\n");
        break;

    default:
        print("Fora do caso\n");
        break;
    }

    return 0;
}