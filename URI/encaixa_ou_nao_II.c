#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define tam 1001

int main()
{

    int n = 0, cont = 0, i = 0, j = 0;
    char A[tam], B[tam];
    bool encaixa = true;

    scanf(" %d", &n);

    while (cont++ < n)
    {

        scanf(" %s %s", A, B);
        encaixa = true;

        for (i = strlen(B), j = strlen(A); i >= 0; i--, j--)
        {
            if (A[j] != B[i])
            {
                encaixa = false;
                break;
            }
        }

        if (encaixa)
        {
            puts("encaixa");
        }
        else
        {
            puts("nao encaixa");
        }
    }

    return 0;
}