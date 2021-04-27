#include <stdio.h>
#define N 10002
#include <string.h>
#include <stdbool.h>


int main(void)
{
    char valor[N], D, valor_convertido[N];

    while (1)
    {
        bool pivo = false;

        scanf(" %c", &D);
        scanf(" %s", valor);

        int tam2 = strlen(valor), x = 0, i = 0;

        if (D == '0' && valor[0] == '0')
        {
            break;
        }
        else
        {
            for (i = 0, x = 0; i < tam2; i++)
            {
                if (valor[i] != D)
                {
                    if (valor[i] != '0')
                    {
                        pivo = true;
                    }
                    if (pivo)
                    {
                        valor_convertido[x] = valor[i];
                        x++;
                    }
                }
            }

            valor_convertido[x] = '\0';

            printf("%s\n", pivo ? valor_convertido : "0");
        }
    }
    
    return 0;
}

//Codigo v1

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <math.h>

// int main(void)
// {

//     int i = 0, indice = 0, zeros;
//     char n_quebrado, num_original[1002], num_convertido[1002];
//     bool pivo = false;

//     while (1)
//     {
//         scanf(" %c %s", &n_quebrado, &num_original);

//         zeros = indice = 0;
//         pivo = false;

//         if (n_quebrado == '0' && num_original[0] == '0')
//         {
//             break;
//         }

//         for (i = 0; i < strlen(num_original); i++)
//         {
//             if (num_original[i] != n_quebrado)
//             {
//                 num_convertido[indice++] = num_original[i];
//             }
//         }

//         num_convertido[indice] = '\0';

//         //Tirar os zeros

//         for (i = 0; i < strlen(num_convertido); i++)
//         {

//             if (num_convertido[i] != '0' && !pivo)
//             {
//                 pivo = true;
//                 break;
//             }
//             else if (!pivo)
//             {
//                 zeros++;
//             }
//         }

//         int tamanho = strlen(num_convertido);

//         if (tamanho == zeros)
//         {
//             printf("0\n");
//         }
//         else
//         {
//             for (i = 0; i < tamanho && zeros > 1; i++)
//             {
//                 num_convertido[i] = num_convertido[zeros + i];
//                 num_convertido[i + 1] = '\0';
//             }

//             printf("%s\n", num_convertido);
//         }

//         strcpy(num_convertido, " ");
//     }

//     return 0;
// }

// codigo v2

// #include <stdio.h>
// #include <string.h>

// int main()
// {
//   char string[1001];
//   char string_convertido[1001];
//   char N;

//   while (1)
//   {

//     scanf(" %c", &N);     //numero que esta com defeito.
//     scanf(" %s", string); //valor oficial negociado

//     int pivo = 0,
//         indice = 0;

//     if (N == '0' && string[0] == '0')
//     {
//       break;
//     }
//     else
//     {
//       int tamanho, i;

//       tamanho = strlen(string);

//       for (i = 0; i <= tamanho; i++)
//       {
//         if (string[i] != N)
//         {

//           if (string[i] != '0')
//           {
//             pivo = 1;
//           }

//           if (pivo)
//           {
//             string_convertido[indice++] = string[i];
//           }
//         }
//       }

//       string_convertido[indice] = '\0';

//       printf("%s\n", pivo == 1 ? string_convertido : "0");
//     }
//   }

//   return 0;
// }