#include <stdio.h>
#include <math.h>

int main()
{

    float valor = 0.00, m[6] = {1, 0.50, 0.25, 0.10, 0.05, 0.01}, n[6] = {100, 50, 20, 10, 5, 2}, notas[6] = {0, 0, 0, 0, 0, 0}, moedas[6] = {0, 0, 0, 0, 0, 0};
    int j = 0;

    scanf(" %f", &valor);

    printf("NOTAS:\n");

    for (j = 0; j < 6; j++)
    {
        notas[j] = (int)(valor / n[j]);
        printf("%.0f nota(s) de R$ %.2f\n", notas[j], n[j]);

        if (valor >= 2)
        {
            valor -= notas[j] * n[j];
        }
    }

    printf("MOEDAS:\n");

    for (j = 0; j < 6; j++)
    {
        float valor_arrendodado = ceilf((valor / m[j]) * 100) / 100;
        moedas[j] = (int)valor_arrendodado;
        printf("%.0f moeda(s) de R$ %.2f\n", moedas[j], m[j]);

        valor -= moedas[j] * m[j];
    }

    return 0;
}