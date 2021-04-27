#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define tamanho 1002

int main()
{
    int op = 0, i = 0, j = 0, k = 0, inverso = 0, size_word = 0, metade = 0;
    char palavra[tamanho], palavra_criptografada[tamanho];

    scanf(" %d", &op);
    getchar();

    for (i = 0; i < op; i++)
    {
        fgets(palavra, tamanho, stdin);

        size_word = strlen(palavra) - 1;

        for (k = 0; k < 3; k++)
        {
            for (j = 0, inverso = size_word - 1, metade = (size_word / 2); j < size_word; j++, inverso--, metade++)
            {
                switch (k)
                {
                case 0:
                    if (isalpha(palavra[j]))
                    {
                        palavra[j] = palavra[j] + 3;
                    }
                    break;
                case 1:
                    palavra_criptografada[j] = palavra[inverso];
                    break;

                case 2:
                    palavra_criptografada[metade] = palavra_criptografada[metade] - 1;
                    break;

                default:
                    break;
                }
            }
        }
        palavra_criptografada[j] = '\0';
        printf("%s\n", palavra_criptografada);
    }
}
