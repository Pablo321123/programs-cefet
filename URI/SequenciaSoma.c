#include <stdio.h>

int main()
{

    int m, n, sum = 0;

    while (1)
    {
        scanf(" %d %d", &m, &n);
        sum = 0;

        if (m <= 0 || n <= 0)
        {
            break;
        }
        else
        {
            while (1)
            {
                if (m == n)
                {
                    sum += m;
                    printf("%d Sum=%d\n", m, sum);
                    break;
                }

                if (m > n)
                {
                    printf("%d ", n);
                    sum += n;
                    n++;
                }
                else
                {
                    printf("%d ", m);
                    sum += m;
                    m++;
                }
            }
        }
    }

    return 0;
}