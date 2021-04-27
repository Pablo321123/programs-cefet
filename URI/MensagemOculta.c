#include <stdio.h>
#include <string.h>

int main()
{

    int op = 0, cont = 0, i = 0, j = 0, numero_pra_guardar_op = 0;
    char palavra[52], palavra_oculta[52];

    scanf(" %d", &op);
    numero_pra_guardar_op = op;

    getchar();

    while (cont < op)
    {
        fflush(stdin);
        gets(palavra);

        op = numero_pra_guardar_op;

        j = 0;

        for (i = 0; palavra[i] != '\0'; i++)
        {
            if (i == 50)
            {
                break;
            }

            if (palavra[i] == ' ')
            {
                continue;
            }
            else
            {
                if (i == 0)
                {
                    palavra_oculta[j] = palavra[i];
                    j++;
                }
                else if (i > 0 && palavra[i - 1] == ' ')
                {
                    palavra_oculta[j] = palavra[i];
                    j++;
                }
            }
        }

            palavra_oculta[j] = '\0';
            puts(palavra_oculta);
        
        cont++;
    }

    return 0;
}