#include <stdio.h>

int main()
{

    int n = 0, x = 0, in = 0, out = 0, i;

    scanf(" %d", &n);

    for (i = 0; i < n; i++)
    {
        scanf(" %d", &x);

        if (x >= 10 && x <= 20)
        {
            in++;
        }
        else
        {
            out++;
        }
    }

    printf("%d in\n%d out", in, out);

    return 0;
}