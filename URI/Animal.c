#include <stdio.h>
#include <string.h>

int main()
{

    char tipo_vertebra[30], classe[30], tipo_de_comida[30];

    scanf(" %s %s %s", tipo_vertebra, classe, tipo_de_comida);

    if (!strcmp(tipo_vertebra, "vertebrado"))
    {
        if (!strcmp(classe, "ave"))
        {
            if (!strcmp(tipo_de_comida, "carnivoro"))
            {
                printf("aguia\n");
            }
            else if (!strcmp(tipo_de_comida, "onivoro"))
            {
                printf("pomba\n");
            }
        }
        else if (!strcmp(classe, "mamifero"))
        {
            if (!strcmp(tipo_de_comida, "onivoro"))
            {
                printf("homem\n");
            }
            else if (!strcmp(tipo_de_comida, "herbivoro"))
            {
                printf("vaca\n");
            }
        }
    }
    else if (!strcmp(tipo_vertebra, "invertebrado"))
    {
        if (!strcmp(classe, "inseto"))
        {
            if (!strcmp(tipo_de_comida, "hematofago"))
            {
                printf("pulga\n");
            }
            else if (!strcmp(tipo_de_comida, "herbivoro"))
            {
                printf("lagarta\n");
            }
        }
        else if (!strcmp(classe, "anelideo"))
        {
            if (!strcmp(tipo_de_comida, "hematofago"))
            {
                printf("sanguessuga\n");
            }
            else if (!strcmp(tipo_de_comida, "onivoro"))
            {
                printf("minhoca\n");
            }
        }
    }

    return 0;
}