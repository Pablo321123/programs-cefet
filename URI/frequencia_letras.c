#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define tam 202

int maiores_letras[tam][tam], cont = 0;

void ordena()
{

    /*
    
    strcmp: x < 0 <-> string1 é menor que string2.

            x = zero <-> ambas as strings são iguais.

            x > 0 -> string1 é maior que string2. 

    */

    char aux[tam];
    int i = 0, j = 0;

    for (i = 0; i <= cont; i++)
    {
        for (j = i + 1; j <= cont; j++)
        {
            int z = strcmp(maiores_letras[i], maiores_letras[j]);

            if (z > 0)
            {
                strcpy(aux, maiores_letras[i]);
                strcpy(maiores_letras[i], maiores_letras[j]);
                strcpy(maiores_letras[j], aux);
            }

            //printf("(string1: %s -> string2: %s) <-> %d\n", maiores_letras[i], maiores_letras[j], z);
        }
    }
}

int main()
{

    int op = 0, i, j, k = 0, m = 0, f = 0, lenght = 0, maior = 0, letras_repitidas[tam], indice = 0;
    char palavra[tam], c[2];

    scanf(" %d", &op);
    getchar(); //Captura o enter

    for (i = 0; i < op; i++)
    {
        fgets(palavra, tam, stdin);

        lenght = strlen(palavra) - 1;
        maior = 0;

        for (j = 0; j < lenght; j++)
        {
            letras_repitidas[j] = 0;

            for (k = 0; k < lenght; k++)
            {
                int ascII = palavra[k];
                if ((tolower(palavra[j]) == tolower(palavra[k])) && palavra[k] != ' ' && ((ascII >= 97 && ascII <= 122) || (ascII >= 65 && ascII <= 90)))
                {
                    letras_repitidas[j]++;
                    c[0] = tolower(palavra[k]);

                    if (k != j) //senao ele apagara a letra de comparacao
                    {
                        palavra[k] = ' ';
                    }
                }
            }

            if (letras_repitidas[j] > maior)
            {

                for (f = 0; f <= cont; f++)
                {
                    maiores_letras[f][0] = ' ';
                }

                cont = 0;
                indice = cont;
                strcpy(maiores_letras[cont], c);
                maior = letras_repitidas[j];
                m = indice;
            }
            else if (letras_repitidas[j] == maior)
            {
                cont++;
                strcpy(maiores_letras[cont], c);
                indice = cont;
                maior = letras_repitidas[j];
                m = indice;
            }
        }

        maiores_letras[m + 1][0] = '\0';

        if (cont > 0)
        {
            ordena(maiores_letras);
            for (m = 0; m <= cont; m++)
            {
                printf("%c", maiores_letras[m][0]);
                //int z = strcmp(maiores_letras[m], maiores_letras[m + 1]);
            }
        }
        else
        {
            printf("%c", maiores_letras[0][0]);
        }
        printf("\n");
    }

    return 0;
}