#include <stdio.h>

int main()
{

    int j = 0, i = 0, ordem = 0, cont = 0, reverso = 0;

    while (1)
    {
        scanf(" %d", &ordem);

        i = j = cont = reverso = 0;

        //int matriz[ordem][ordem];

        if (ordem == 0)
        {
            break;
        }

        cont = i + 1;

        // printf("  ");

        while (i < ordem)
        {
            if (j < ordem)
            {
                printf("%3d", cont);

                if (cont <= 1)
                {
                    cont++;
                    reverso = 0;
                }
                else if (cont >= ordem)
                {
                    cont--;
                    reverso = 1;
                }
                else
                {
                    cont = reverso ? --cont : ++cont;
                }

                j++;
            }

            if (j >= ordem)
            {
                printf("\n");
                j = 0;
                i++;

                // if (i < ordem)

                // {
                //     printf("  ");
                // }

                cont = i + 1;
                reverso = 1;
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }
    return 0;
}