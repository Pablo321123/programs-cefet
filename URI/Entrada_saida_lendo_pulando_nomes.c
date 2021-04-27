#include <stdio.h>
#include <string.h>

int main()
{

    char nome[10][31];
    int cont = 0;

    while (cont < 10)
    {
        scanf(" %s", nome[cont++]);

        if (cont == 3 || cont == 7 || cont == 9)
        {
            printf("%s\n", nome[cont - 1]);
        }
    }

    return 0;
}