#include <stdio.h>
#include <stdlib.h>
// o '(int *)' eh para o erro: invalid conversion from ‘void*’ to ‘int**

int **ft;

void testa_matriz()
{
    system("cls");
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            printf("[%d] ", ft[i][j]);
        }
        printf("\n");
    }
}

void update_linha(int indice, int max, int valor, int linha)
{
    while (indice <= max)
    {
        ft[linha][indice] += valor;
        indice += (indice & -indice); //Bit menos significativo para posicao
    }
}

void update_coluna(int indice, int max, int valor, int coluna)
{
    while (indice <= max)
    {
        ft[indice][coluna] += valor;
        indice += (indice & -indice); //Bit menos significativo para posicao
    }
}

int rsq_linha(int n, int tipo_op, int linha_ou_coluna)
{
    int soma = 0;

    if (tipo_op == 3)
    {
        for (int j = n; j > 0;)
        {
            soma += ft[linha_ou_coluna][j];
            j -= (j & -j); //Bit menos significativo para posicao
        }
    }
    else if (tipo_op == 4)
    {
        for (int i = n; i > 0;)
        {
            soma += ft[i - 1][linha_ou_coluna];
            i -= (i & -i); //Bit menos significativo para posicao
        }
    }

    testa_matriz();
    return soma;
}

int main()
{
    int **tabuleiro, N /*Tamanho do tabuleiro*/, Q /* Numero de operacoes*/, X /*Numero da coluna ou linha*/, R /*Valor a ser digitado nas linhas ou colunas*/, tipo_operacao = 0;
    int count_q = 0, numero, numero_frequencia;

    scanf(" %d %d", &N, &Q);

    tabuleiro = (int **)calloc(N, sizeof(int));
    ft = (int **)calloc(N + 1, sizeof(int));
    int frequencia[N]; // = (int *)calloc(N, sizeof(int)); // o '(int *)' eh para o erro: invalid conversion from ‘void*’ to ‘int** do URI

    for (int i = 0; i <= N; i++)
    {
        if (i < N)
        {
            tabuleiro[i] = (int *)calloc(N, sizeof(int));
        }

        ft[i] = (int *)calloc(N + 1, sizeof(int));
    }

    while (count_q < Q)
    {
        scanf(" %d", &tipo_operacao);

        switch (tipo_operacao)
        {
        case 1:

            scanf(" %d %d", &X, &R);

            // for (int j = 0; j < N; j++)
            // {
            //
            // }

            for (int j = 0; j < N; j++)
            {
                // if (R == tabuleiro[X - 1][j] || tabuleiro[X - 1][j] == 0)
                //{
                // update_linha((j + 1), N, R, X);
                //printf("[%d] ", tabuleiro[X - 1][j]);
                update_linha(j + 1, N, (R - tabuleiro[X - 1][j]), X);
                //update_coluna(1, N, (R - tabuleiro[X - 1][j]), X);
                tabuleiro[X - 1][j] = R;
                // }
                // else
                // {
                //update_linha(1, N, (R - tabuleiro[X - 1][j]), X);
                // update_linha((j + 1), N, (R - ft[X][j + 1] == 0 ? R : R - ft[X][j + 1]), X);
                // }
                //update_coluna(1, N, (R - tabuleiro[X - 1][j]), j);
            }

            break;

        case 2:

            scanf(" %d %d", &X, &R);

            // for (int j = 0; j < N; j++)
            // {
            //     tabuleiro[j][X - 1] = R;
            // }
            for (int j = 0; j < N; j++)
            {
                // if (R == tabuleiro[X - 1][j] || tabuleiro[X - 1][j] == 0)
                //{
                update_coluna(j + 1, N, (R - tabuleiro[j][X - 1]), X);
                tabuleiro[X - 1][j] = R;
                // }
                // else
                // {
                //update_linha(1, N, (R - tabuleiro[X - 1][j]), X);
                // update_linha((j + 1), N, (R - ft[X][j + 1] == 0 ? R : R - ft[X][j + 1]), X);
                // }
                //update_linha(j + 1, N, R - tabuleiro[X - 1][j], X);
            }

            break;

        case 3:
            scanf(" %d", &X);

            printf("A soma da linha %d eh %d\n", X, rsq_linha(N, 3, X));

            // numero = 0;

            // for (int j = 0; j < N; j++)
            // {
            //     numero = tabuleiro[X - 1][j];

            //     for (int l = 0; l < N; l++)
            //     {
            //         if (tabuleiro[X - 1][l] == numero)
            //         {
            //             frequencia[j]++;
            //         }
            //     }
            // }

            // numero_frequencia = 0;
            // numero = 0;

            // for (int f = 0; f < N; f++)
            // {
            //     numero_frequencia = frequencia[f];

            //     for (int l = 0; l < N; l++)
            //     {
            //         if (frequencia[l] >= numero_frequencia)
            //         {
            //             if (tabuleiro[X - 1][l] > numero)
            //             {
            //                 numero = tabuleiro[X - 1][l];
            //             }
            //         }
            //     }
            // }

            //printf("%d\n", numero);

            break;

        case 4:
            scanf(" %d", &X);

            printf("A soma da coluna %d eh %d\n", X, rsq_linha(N, 4, X));

            // numero = 0;

            // for (int j = 0; j < N; j++)
            // {
            //     numero = tabuleiro[j][X - 1];

            //     for (int l = 0; l < N; l++)
            //     {
            //         if (tabuleiro[l][X - 1] == numero)
            //         {
            //             frequencia[j]++;
            //         }
            //     }
            // }

            // numero_frequencia = 0;
            // numero = 0;

            // for (int f = 0; f < N; f++)
            // {
            //     numero_frequencia = frequencia[f];

            //     for (int l = 0; l < N; l++)
            //     {
            //         if (frequencia[l] >= numero_frequencia)
            //         {
            //             if (tabuleiro[l][X - 1] > numero)
            //             {
            //                 numero = tabuleiro[l][X - 1];
            //             }
            //         }
            //     }
            // }

            // printf("%d\n", numero);

            break;

        default:
            break;
        }

        count_q++;
    }

    free(tabuleiro);
    free(frequencia);

    tabuleiro = NULL;

    return 0;
}