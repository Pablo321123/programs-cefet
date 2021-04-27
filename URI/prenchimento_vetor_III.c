#include <stdio.h>

void exibe_vetor(int vetor[], int par /*par != 0, impar == 0*/, int maximo)
{
    int i;
    for (i = 0; i < maximo; i++)
    {
        if (par)
        {
            printf("par[%d] = %d\n", i, vetor[i]);
        }
        else
        {
            printf("impar[%d] = %d\n", i, vetor[i]);
        }
    }
}

int main()
{

    int quant = 0, par[5], impar[5], num = 0, q_par = 0, q_impar = 0;

    while (1)
    {
        scanf(" %d", &num);

        if (num % 2 == 0)
        {
            par[q_par] = num;
            q_par++;
        }
        else
        {
            impar[q_impar] = num;
            q_impar++;
        }

        if (q_par == 5)
        {
            exibe_vetor(par, 1, 5);
            q_par = 0;
        }
        else if (q_impar == 5)
        {
            exibe_vetor(impar, 0, 5);
            q_impar = 0;
        }

        quant++;

        if (quant == 15)
        {
            if (q_impar > 0)
            {
                exibe_vetor(impar, 0, q_impar);
            }
            if (q_par > 0)
            {
                exibe_vetor(par, 1, q_par);
            }

            break;
        }
    }

    return 0;
}