#include <stdio.h>

int main()
{

    //S = 1 + 1/2 + 1/3 + … + 1/100

    int divisor = 1, divendendo = 1;
    float s = 0;

    while (divendendo <= 39)
    {
        s += ((float)divendendo / (float)divisor);
        divendendo += 2;
        divisor *= 2;
    }

    printf("%.2f\n", s);

    return 0;
}