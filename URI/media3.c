#include <stdio.h>
#include <stdbool.h>

int main()
{

    float n1 = 0, n2 = 0, n3 = 0, n4 = 0, media = 0.0, nota_exame = 0.0;
    bool aluno_exame = false;

    scanf(" %f %f %f %f", &n1, &n2, &n3, &n4);

    do
    {
        if (aluno_exame)
        {
            scanf(" %f", &nota_exame);
            printf("Nota do exame: %.1f\n", nota_exame);

            nota_exame = (nota_exame + media) / 2;

            if (nota_exame >= 5.0)
            {
                printf("Aluno aprovado.\n");
            }
            else
            {
                printf("Aluno reprovado.\n");
            }

            printf("Media final: %.1f\n", nota_exame);
            aluno_exame = false;
        }
        else
        {
            media = ((n1 * 2) + (n2 * 3) + (n3 * 4) + n4) / 10;
            printf("Media: %.1f\n", media);

            if (media >= 7.0)
            {

                printf("Aluno aprovado.\n");
            }
            else if (media < 5.0)
            {

                printf("Aluno reprovado.\n");
            }
            else
            {
                printf("Aluno em exame.\n");
                aluno_exame = true;
            }
        }
    } while (aluno_exame);

    return 0;
}