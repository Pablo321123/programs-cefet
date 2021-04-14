//Autores: Pablo Vasconcelos da Cruz e Vitor Godinho Rausch

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *pont_arq;
    char nome_arq[30];

    int matriz[5][5] = {{00, 15, 30, 05, 12}, {15, 00, 10, 17, 28}, {30, 10, 00, 03, 11}, {05, 17, 03, 00, 80}, {12, 28, 11, 80, 00}}; //Criação da matriz disponibilizada no enunciado da questao
    int i, j;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf(" %0.2d", matriz[i][j]); //Organização da visualização da matriz no prompt
        }
        printf("\n");
    }

    printf("\nDigite o nome do arquivo que queira copiar a matriz acima: (SEM O .txt)\n");
    gets(nome_arq);

    strcat(nome_arq, ".txt");

    pont_arq = fopen(nome_arq, "wb"); //Abertura do programa em modo escrita binaria

    system("cls");
    if (pont_arq == NULL) //Verificacao se o arquivo foi encontrado pelo fopen
    {
        printf("Erro na abertura do arquivo. ");
        system("pause");
        exit(1);
    }

    if (fwrite(matriz, sizeof(int), 25, pont_arq) != 25) //Teste para verificar se a matriz foi escrita com sucesso.
    {
        printf("Erro de gravação.");
        fclose(pont_arq);
        system("pause");
        exit(1);
    }
    else
    {
        printf("Arquivo gravado com sucesso!\n");
    }

    fclose(pont_arq); //Fechamento do arquivo
    system("pause");

    return 0;
}