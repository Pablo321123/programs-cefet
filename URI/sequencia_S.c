#include <stdio.h>

int main()
{

    //S = 1 + 1/2 + 1/3 + … + 1/100

    int divisor = 1;
    float s = 0;

    while (divisor <= 100)
    {
        s += ((float)1 / (float)divisor);
        divisor++;
    }

    printf("%.2f\n", s);

    return 0;
}