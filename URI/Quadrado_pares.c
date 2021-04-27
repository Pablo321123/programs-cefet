#include <stdio.h>
#include <math.h>

int main()
{

    int n = 0, i;

    scanf(" %d", &n);

    for (i = 0; i <= n; i++)
    {
        if (i % 2 == 0 && i > 0)
        {
            printf("%d^2 =  %0.lf\n", i, (double)pow((i), 2));
        }
    }

    return 0;
}