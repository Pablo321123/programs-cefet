#include <stdio.h>
#include <stdbool.h>

int i = 0, j = 0;

int main()
{
    int qtd_coluna = 0, qtd_linha = 0, k = 0, cont = 0;
    bool escalonada = true;

    scanf(" %d %d", &qtd_linha, &qtd_coluna);

    int matriz[qtd_linha][qtd_coluna], soma_linha[qtd_linha], soma_coluna[qtd_coluna];

    for (i = 0; i < qtd_linha; i++)
    {
        soma_linha[i] = 0;

        for (j = 0; j < qtd_coluna; j++)
        {
            scanf(" %d", &matriz[i][j]);

            soma_linha[i] += matriz[i][j];
        }
    }

    for (i = 0; i < qtd_linha; i++)
    {
        for (j = 0; j < qtd_coluna; j++)
        {
            if (i > 0 && soma_linha[i - 1] == 0)
            {
                if (matriz[i][j] != 0)
                {
                    escalonada = false;
                    printf("N\n");
                    return 0;
                    break;
                }
            }
            else
            {
                if ((i + cont + 1 < qtd_linha) && matriz[i + cont][j] != 0)
                {
                    for (k = i + cont + 1; k < qtd_linha - cont; k++)
                    {
                        if (matriz[k][j] != 0)
                        {
                            escalonada = false;
                            break;
                        }
                    }

                    cont++;
                }
            }
        }
        if (!escalonada)
        {
            break;
        }
    }

    printf("%c\n", escalonada ? 'S' : 'N');

    return 0;
}