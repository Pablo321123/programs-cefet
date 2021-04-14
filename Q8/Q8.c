//Autores: Pablo Vasconcelos da Cruz e Vitor Godinho Rausch

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <stdbool.h>

#define tamamnho 48
typedef struct estrutura_arquivo //Struct para facilitar o obtenção de dados do arquivo
{
    FILE *arquivo;
    char nome_aquivo[31];
    char texto[tamamnho]; // Porque a maior palavra do dicionario brasileiro tem 46 palavras
    int contador;

} variaveis;

void ignoreCase(char *palavra, char *palavra_procurada) //Funcao criada para retirar um possivel caracter de pontuação como ',', '.', ':' dentre varios outros.
{                                                       //Deste modo, é possível contar corretamente uma palavra que venha acompanhada de ','. Por exemplo, o usuario digita 'canivete' e no texto aparece 'canivete,'.

    bool pontuacao = false;

    for (int i = 0; i < strlen(palavra_procurada); i++)
    {
        if (ispunct(palavra_procurada[i]))
        {
            pontuacao = true; //Verifica se a palavra procurada possui alguma pontuacao
            break;
        }
    }

    if (!pontuacao)
    {
        for (int i = 0; i < strlen(palavra); i++) // loop para verificar se a palavra esta entre algum sinal de pontuacao.
        {
            if (ispunct(palavra[0]))
            {
                int j = 0;
                for (j = 0; !ispunct(palavra[j + 1]); j++)
                {
                    palavra[j] = palavra[j + 1];
                }

                palavra[j] = '\0';
            }

            if (ispunct(palavra[i]))
            {
                palavra[i] = '\0';
            }
        }
    }
}

int main()
{
    variaveis var;
    char palavra_procurada[tamamnho];

    setlocale(LC_ALL, "");

    puts("Digite o nome do arquivo texto (NAO DIGITE '.TXT'): ");
    scanf(" %s", var.nome_aquivo);
    strcat(var.nome_aquivo, ".txt");

    var.arquivo = fopen(var.nome_aquivo, "r");

    if (var.arquivo == NULL)
    {
        puts("Impossivel abrir o arquivo!");
        system("pause");
        return 0;
    }
    else
    {
        system("cls");

        printf("Digite a palavra que voce deseja saber a frequencia na qual ela aparece dentro do %s: \n", var.nome_aquivo);
        var.contador = 0;

        scanf(" %s", palavra_procurada);

        for (; fscanf(var.arquivo, " %s", var.texto) != EOF;)
        {
            ignoreCase(var.texto, palavra_procurada);

            if (!strcmp(var.texto, palavra_procurada))
            {
                var.contador++;
            }
        }

        system("cls");

        printf("A palavra %s aparece %d vez(es).\n", palavra_procurada, var.contador);

        fclose(var.arquivo);
    }

    system("pause");

    return 0;
}
