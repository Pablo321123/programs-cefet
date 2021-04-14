//Autores: Pablo Vasconcelos da Cruz e Vitor Godinho Rausch

#include <stdio.h>
#include <string.h>

typedef struct dadosArquivo
{
    FILE *arquivo;
    char nomeArquivo[31];
    int tamanhoArquivo;

} arq;

int matriz[5][5];

int travelledDistance(int cidades[10], int qtd_cidades)
{
    int soma = 0;
    for (int i = 0; i < qtd_cidades - 1; i++)       //ADAPTAÇÃO: É preciso retirar uma unidade da quantidade total de cidades, porque precisamos considerar que so existe trajeto se existe duplas,
    {                                               //logo como a cidade inicial (sozinha) nao gera um trajeto, precisamos desconsiderar uma unidade que representa essa situação,
        soma += matriz[cidades[i]][cidades[i + 1]]; // por que caso o contrario o programa iria somar uma caso a mais não previsto (errado).
    }

    return soma;
}

int main()
{
    arq arq;
    int cidades[10], distanciaTotal = 0, n_cidades = 0;

    printf("Digite o nome do arquivo que contenha a matriz distancias a ser aberto: (SEM O .txt)\n");
    scanf(" %s", arq.nomeArquivo);
    strcat(arq.nomeArquivo, ".txt");

    arq.arquivo = fopen(arq.nomeArquivo, "rb");

    if (arq.arquivo == NULL)
    {
        system("cls");
        printf("Impossivel abrir o arquivo no momento!!\nO nome pode estar incorreto.\n");
    }
    else
    {
        fread(matriz, sizeof(int), 25, arq.arquivo);

        system("cls");

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                printf(" %0.2d", matriz[i][j]);
            }
            printf("\n");
        }

        printf("\nDigite o trajeto do usuario, entre as cidades 1, 2, 3, 4 e 5. (Digite 0 para encerrar a gravacao)\n");

        while (n_cidades < 10)
        {
            scanf(" %d", &cidades[n_cidades]);

            cidades[n_cidades] -= 1; //ADAPTAÇÃO: é preciso tirar uma unidade das cidades para que fique de acordo com os indices dos vetores nos quais iniciam suas contagem em 0;

            if (cidades[n_cidades] < 0)
            {
                break;
            }

            n_cidades++;
        }

        distanciaTotal = travelledDistance(cidades, n_cidades);

        system("cls");

        printf("O viajante andou um total de %d Km\n", distanciaTotal);
    }

    system("pause");

    return 0;
}
