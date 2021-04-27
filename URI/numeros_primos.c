#include <stdio.h>

int main()
{
    int num, divisores = 0, casos = 0;

    scanf(" %d", &casos);

    while (casos) // casos > 0
    {

        scanf("%d", &num);
        divisores = 0;

        for (int i = 1; i <= num; i++)
        {
            if (num % i == 0)
            {
                divisores++;
            }
        }

        if (divisores == 2)
        {
            printf("%d eh primo\n", num);
        }
        else
        {
            printf("%d nao eh primo\n", num);
        }

        casos--;
    }
}