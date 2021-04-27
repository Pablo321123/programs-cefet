#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int min = 0, max = 0;
    char numero_picado[5];
    bool numero_ivalido = false;

    while (scanf(" %d %d", &min, &max) != EOF)
    {
        int num_livres = 0, i = 0, k = 0, coluna = 0, casa_decimais = 0;

        for (i = min; i <= max; i++)
        {
            snprintf(numero_picado, 5, "%d", i);

            casa_decimais = strlen(numero_picado);

            for (k = 0; k < casa_decimais; k++)
            {
                for (coluna = k + 1; coluna < casa_decimais; coluna++)
                {
                    if (numero_picado[k] == numero_picado[coluna])
                    {
                        numero_ivalido = true;
                    }
                }
            }
            if (numero_ivalido)
            {
                numero_ivalido = false;
            }
            else
            {
                num_livres++;
            }
        }
        printf("%d\n", num_livres);
    }
    return 0;
}

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int split_de_inteiro(int numero_para_separar, int *local_para_ser_gravado)
{
    int i, casas_decimais = 0;

    for (i = 0;; i++)
    {
        local_para_ser_gravado[i] = numero_para_separar % 10;
        numero_para_separar = numero_para_separar / 10;

        casas_decimais++;

        if (numero_para_separar == 0)
        {
            break;
        }
    }

    return casas_decimais;
}

int diferenca_digitos(int num_ini, int num_fim, int *digitos)
{
    int cont, i, j, casas_decimais = 0;

    for (i = num_ini; i <= num_fim; i++)
    {
        casas_decimais = split_de_inteiro(i, digitos);

        j = 0;

        switch (casas_decimais)
        {
        case 1:
            cont++;
            break;
        case 2:
            if (digitos[0] != digitos[1])
            {
                cont++;
            }
            break;
        case 3:
            if (digitos[0] != digitos[1])
            {
                if (digitos[0] != digitos[2])
                {
                    if (digitos[1] != digitos[2])
                    {
                        cont++;
                    }
                }
            }

            break;
        case 4:
            if (digitos[0] != digitos[1])
            {
                if (digitos[0] != digitos[2])
                {
                    if (digitos[0] != digitos[3])
                    {
                        if (digitos[1] != digitos[2])
                        {
                            if (digitos[1] != digitos[3])
                            {
                                if (digitos[2] != digitos[3])
                                {
                                    cont++;
                                }
                            }
                        }
                    }
                }
            }
            break;
        default:
            break;
        }
    }

    return cont;
}

int main()
{
    int min = 0, max = 0, *digitos_separados;

    while (scanf(" %d %d", &min, &max) != EOF)
    {
        digitos_separados = calloc(4, sizeof(int));

        int num_livres = diferenca_digitos(min, max, digitos_separados);
        printf("%d\n", num_livres);

        free(digitos_separados);
        digitos_separados = NULL;
    }

    return 0;
}

*/

// #pragma region Raciocinio
// /*
// 10 a 99 ->   9 digitos iguais
// 100 a 109 -> 1 digitos iguais
// 110 a 119 -> 10 digitos iguais
// 120 a 129 -> 2 digitos iguais
// 130 a 139 -> 2 digitos iguais
// 140 a 149 -> 2 digitos iguais
// 150 a 159 -> 2 digitos iguais
// 160 a 169 -> 2 digitos iguais
// 170 a 179 -> 2 digitos iguais
// 180 a 189 -> 2 digitos iguais
// 190 a 199 -> 2 digitos iguais
// ...
// 1000 a 1009 -> 10 digitos iguais
// 1010 a 1019 -> 10 digitos iguais
// 1020 a 1029 -> 3 digitos iguais
// ...
// 1100 a 1109 ->
// #pragma endregion

/* Codigo sem ponteiro ACEITO PELO URI

int main()
{
  int min = 0, max = 0, digitos_separados[4] = {0, 0, 0, 0};

  while (scanf(" %d %d", &min, &max) != EOF)
  {
    int num_livres = 0;

    int i, j, casas_decimais = 0;

    for (i = min; i <= max; i++)
    {

      int k, casas_decimais = 0, numero_para_separar = i;

      for (k = 0;; k++)
      {
        digitos_separados[k] = numero_para_separar % 10;
        numero_para_separar = numero_para_separar / 10;

        casas_decimais++;

        if (numero_para_separar == 0)
        {
          break;
        }
      }

      j = 0;

      switch (casas_decimais)
      {
      case 1:
        num_livres++;
        break;
      case 2:
        if (digitos_separados[0] != digitos_separados[1])
        {
          num_livres++;
        }
        break;
      case 3:
        if (digitos_separados[0] != digitos_separados[1])
        {
          if (digitos_separados[0] != digitos_separados[2])
          {
            if (digitos_separados[1] != digitos_separados[2])
            {
              num_livres++;
            }
          }
        }

        break;
      case 4:
        if (digitos_separados[0] != digitos_separados[1])
        {
          if (digitos_separados[0] != digitos_separados[2])
          {
            if (digitos_separados[0] != digitos_separados[3])
            {
              if (digitos_separados[1] != digitos_separados[2])
              {
                if (digitos_separados[1] != digitos_separados[3])
                {
                  if (digitos_separados[2] != digitos_separados[3])
                  {
                    num_livres++;
                  }
                }
              }
            }
          }
        }
        break;
      default:
        break;
      }
    }

    printf("%d\n", num_livres);
  }

  return 0;
}

*/