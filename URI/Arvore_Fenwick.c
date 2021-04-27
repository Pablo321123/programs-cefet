#include <stdio.h>
#include <string.h>

#define MAX 16

int ft[MAX]; //Vetor que guarda a soma na posicao do somatorio do bits menos significativos de cada indice;

void update(int k, int valor) // k -> Posicao
{
    while (k < MAX)
    {
        ft[k] += valor;

        k += (k & -k); //Soma do bit menos significativo, no qual controla a posicao da proxima soma.
    }
}

int rsq(int n /*Realiza a soma até o indice n*/) //Range sub Query -> Consulta de soma em intervalo
{
    int soma = 0;

    while (n > 0)
    {
        soma += ft[n];
        n -= (n & -n);
    }

    return soma;
}

int main()
{
    int a[] = {0, 1, 3, 2, 4, 1, 2, 5, 3, 6, 4, 7, 1, 9, 6, 5};
    memset(ft, 0, sizeof ft);

    for (int i = 1; i <= 15; i++)
    {
        update(i, a[i]);
    }

    // for (int i = 1; i <= 15; i++) // para descobrir quantos numeros sao MENORES ou MAIORES que um determinado numero
    // {
    //     update(a[i], 1);
    // }

     printf("A soma dos 2 primeiros elementos eh: %d\n", rsq(2));


    update(2, 20 - a[2]);

    printf("A soma dos 2 primeiros elementos eh: %d\n", rsq(2));

    // printf("Numeros maiores que 9: %d\n\n", rsq(15) - rsq(5)); //rsq(a) - rsq(n);  n == Termo, a == Todos os termos

    // printf("Numeros menores que 10: %d\n\n", rsq(9)); // rsq(n - 1)

     printf("Numeros iguais a 2: %d\n", rsq(2) - rsq(1)); // rsq(n) - rsq(n - 1);
    
    return 0;
}