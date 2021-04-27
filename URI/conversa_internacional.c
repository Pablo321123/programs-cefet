#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int op = 0, tam_grupo = 0, cont = 0, n, i = 0;
    char idioma[22], aux[22];
    bool ingles = false;

    scanf(" %d", &op);

    while (cont++ < op)
    {
        scanf(" %d", &n, idioma);

        ingles = false;

        for (i = 0; i < n; i++)
        {
            scanf(" %s", idioma);

            if (strcmp(idioma, aux) && i > 0)
            {
                ingles = true;
            }

            strcpy(aux, idioma);
        }

        printf("%s\n", ingles ? "ingles" : idioma);
    }

    return 0;
}