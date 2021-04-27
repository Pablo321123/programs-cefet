#include <stdio.h>
#define N 10002
#include <string.h>
#include <stdbool.h>

// int main(void)
// {
//   int qtd = 0, i = 0;
//   char nome1[N], nome2[N], decifrado[N];
//   bool qual_nome = false; // false -> nome1 V true -> nome2

//   scanf(" %d", &qtd);
//   getchar();

//   for (i = 0; i < qtd; i++)
//   {
//     int k = 0, j = 0, cont = 0, indice_decifrado = 0;

//     fgets(nome1, N, stdin);
//     fgets(nome2, N, stdin);

//     int tamanho = strlen(nome1) + strlen(nome2) - 2;

//     qual_nome = false;

//     while (indice_decifrado < tamanho)
//     {
//       if (!qual_nome)
//       {
//         if (nome1[k] != '\n')
//         {
//           decifrado[indice_decifrado++] = nome1[k];

//           cont++;

//           if (cont == 2)
//           {
//             cont = 0;
//             qual_nome = true;
//           }
//         }
//         k++;
//       }
//       else
//       {
//         if (nome2[j] != '\n')
//         {

//           decifrado[indice_decifrado++] = nome2[j];
//           cont++;

//           if (cont == 2)
//           {
//             cont = 0;
//             qual_nome = false;
//           }
//         }
//         j++;
//       }
//     }

//     decifrado[indice_decifrado] = '\0';

//     printf("%s\n", decifrado);
//   }

//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *input(char *string, int tamanho)
{
  if (fgets(string, tamanho, stdin) != NULL)
  {
    /* Remove a nova linha (\n), caso ela tenha sido lida pelo fgets */
    int indiceUltimoCaractere = strlen(string) - 1;

    if (string[indiceUltimoCaractere] == '\n')
    {
      string[indiceUltimoCaractere] = '\0';
    }

    return string;
  }

  return NULL;
}

int main(int argc, char const *argv[])
{
  int N, i, j = 0, z = 0, indice = 0;
  char name[204], name2[204], palavra_decifrada[408];

  scanf("%d\n", &N);

  for (i = 0; i < N; ++i)
  {
    input(name, 204);
    input(name2, 204);

    int tam = (strlen(name) - 1) + (strlen(name2) - 1);

    while (indice < tam)
    {
      palavra_decifrada[indice++] = name[j];
      palavra_decifrada[indice++] = name[++j];
      palavra_decifrada[indice++] = name2[z];
      palavra_decifrada[indice++] = name2[++z];

      // printf("%c", name[j]);
      // printf("%c", name[++j]);
      // printf("%c", name2[z]);
      // printf("%c", name2[++z]);

      ++j;
      ++z;
    }
    palavra_decifrada[indice] = '\0';
    printf("%s\n", palavra_decifrada);
    j = 0;
    z = 0;
    tam = 0;
    indice = 0;
  }

  return 0;
}