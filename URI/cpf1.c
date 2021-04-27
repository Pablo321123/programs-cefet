#include <stdio.h>
#include <ctype.h>

#define tam 15

int main()
{

    int multiplos[2] = {0, 0}, i[3] = {0, 0, 0};

    char cpf[16], resto[3];

    while (scanf(" %s", cpf) != EOF)
    {        

        multiplos[0] = multiplos[1] = 0;
        i[1] = 0;
        i[2] = 9;

        for (i[0] = 0; i[0] < tam - 3; i[0]++)
        {
            if (isdigit(cpf[i[0]]))
            {
                int ascII = cpf[i[0]] - 48;
                multiplos[0] += ascII * ++i[1];
                multiplos[1] += ascII * i[2]--;
            }
        }

        int aux = (int)(multiplos[0] % 11);
        resto[0] = aux == 10 ? '0' : aux + 48;

        aux = multiplos[1] % 11;
        resto[1] = aux == 10 ? '0' : aux + 48;

        printf("CPF %s\n", (resto[0] != cpf[12]) || (resto[1] != cpf[13]) ? "invalido" : "valido");
    }

    return 0;
}