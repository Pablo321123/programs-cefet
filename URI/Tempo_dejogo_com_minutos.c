#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int h_0 = 0, m_0 = 0, h = 0, m = 0, duracao_h = 0, duracao_m = 0, coeficiente_horas = 0, segundos_inicial = 0, segundos_final = 0;
    bool uma_hora = true;

    scanf(" %d %d %d %d", &h_0, &m_0, &h, &m);

    if (h_0 == h && m_0 == m)
    {
        duracao_h = 24;
    }
    else
    {
        segundos_inicial = (h_0 * 3600) + (m_0 * 60);
        segundos_final = (h * 3600) + (m * 60);

        if (segundos_inicial > segundos_final)
        {

            duracao_h = (86400 - (segundos_inicial - segundos_final)) / 3600;
            duracao_m = ((86400 - (segundos_inicial - segundos_final)) % 3600) / 60;
        }
        else
        {

            duracao_h = ((segundos_final - segundos_inicial) / 3600);
            duracao_m = ((segundos_final - segundos_inicial) % 3600) / 60;
        }
    }

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", duracao_h, duracao_m);

    return 0;
}