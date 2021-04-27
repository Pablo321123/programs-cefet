#include <stdio.h>

void update(int posicao, int valor, int tamanho, int vetor_soma[])
{
    while (posicao < tamanho)
    {
        vetor_soma[posicao] += valor;
        posicao += (posicao & -posicao);
    }
}

int rsq(int indice, int vetor_soma[])
{

    int resultado = 0;

    while (indice > 0)
    {

        resultado += vetor_soma[indice];
        indice -= (indice & -indice);
    }

    return resultado;
}

int main()
{
    int n = 0, menor = 99999, menor_pos = 99999;

    scanf(" %d", &n);

    int *somas_bit_bit, X[n + 1];

    somas_bit_bit = (int *)calloc(n + 1, sizeof(int));

    X[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        scanf(" %d", &X[i]);

        update(i, X[i], (n + 1), somas_bit_bit);

        //Ja daria pra capturar o menor caracter e sua posicao aqui, porém o meu objetivo é de aperfeiçoar a aplicação da arvore de fenwick.
    }

    int valor_atual = 0;

    for (int i = 1; i <= n; i++)
    {

        valor_atual = rsq(i, somas_bit_bit) - rsq((i - 1), somas_bit_bit);

        if (valor_atual < menor)
        {
            menor = valor_atual;
            menor_pos = i - 1;
        }
    }

    printf("Menor valor: %d\nPosicao: %d", menor, menor_pos);
}