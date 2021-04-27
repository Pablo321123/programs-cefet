#include <stdio.h>
#include <stdlib.h>
// o '(int *)' eh para o erro: invalid conversion from ‘void*’ to ‘int**

int main()
{
    int **tabuleiro, N /*Tamanho do tabuleiro*/, Q /* Numero de operacoes*/, X /*Numero da coluna ou linha*/, R /*Valor a ser digitado nas linhas ou colunas*/, tipo_operacao = 0;
    int count_q = 0, numero, numero_frequencia;

    scanf(" %d %d", &N, &Q);

    tabuleiro = (int **)calloc(N, sizeof(int));
    int frequencia[N]; // = (int *)calloc(N, sizeof(int)); // o '(int *)' eh para o erro: invalid conversion from ‘void*’ to ‘int** do URI

    for (int i = 0; i < N; i++)
    {
        tabuleiro[i] = (int *)calloc(N, sizeof(int));
    }

    while (count_q < Q)
    {
        scanf(" %d", &tipo_operacao);

        switch (tipo_operacao)
        {
        case 1:

            scanf(" %d %d", &X, &R);

            for (int j = 0; j < N; j++)
            {
                tabuleiro[X - 1][j] = R;
            }

            break;

        case 2:

            scanf(" %d %d", &X, &R);

            for (int j = 0; j < N; j++)
            {
                tabuleiro[j][X - 1] = R;
            }

            break;

        case 3:
            scanf(" %d", &X);

            numero = 0;

            for (int j = 0; j < N; j++)
            {
                numero = tabuleiro[X - 1][j];

                for (int l = 0; l < N; l++)
                {
                    if (tabuleiro[X - 1][l] == numero)
                    {
                        frequencia[j]++;
                    }
                }
            }

            numero_frequencia = 0;
            numero = 0;

            for (int f = 0; f < N; f++)
            {
                numero_frequencia = frequencia[f];

                for (int l = 0; l < N; l++)
                {
                    if (frequencia[l] >= numero_frequencia)
                    {
                        if (tabuleiro[X - 1][l] > numero)
                        {
                            numero = tabuleiro[X - 1][l];
                        }
                    }
                }
            }

            printf("%d\n", numero);

            break;

        case 4:
            scanf(" %d", &X);

            numero = 0;

            for (int j = 0; j < N; j++)
            {
                numero = tabuleiro[j][X - 1];

                for (int l = 0; l < N; l++)
                {
                    if (tabuleiro[l][X - 1] == numero)
                    {
                        frequencia[j]++;
                    }
                }
            }

            numero_frequencia = 0;
            numero = 0;

            for (int f = 0; f < N; f++)
            {
                numero_frequencia = frequencia[f];

                for (int l = 0; l < N; l++)
                {
                    if (frequencia[l] >= numero_frequencia)
                    {
                        if (tabuleiro[l][X - 1] > numero)
                        {
                            numero = tabuleiro[l][X - 1];
                        }
                    }
                }
            }

            printf("%d\n", numero);

            break;

        default:
            break;
        }

        count_q++;
    }

    free(tabuleiro);
    free(frequencia);

    return 0;
}