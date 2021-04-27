#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define tam 5002

int main()
{

    int aliteracoes = 0, lenght = 0, i = 0;
    char palavra[tam], letra;
    bool sequencia = false;

    while (fgets(palavra, tam, stdin) != NULL)
    {
        aliteracoes = 0;
        lenght = strlen(palavra);
        letra = NULL;

        for (i = 0; i < lenght; i++)
        {
            if (i == 0 || palavra[i - 1] == ' ')
            {
                if (tolower(letra) == tolower(palavra[i]) && !sequencia)
                {
                    aliteracoes++;
                    sequencia = true;
                }
                else if (letra != tolower(palavra[i]))
                {
                    letra = tolower(palavra[i]);
                    sequencia = false;
                }
            }
        }

        printf("%d\n", aliteracoes);
    }

    return 0;
}