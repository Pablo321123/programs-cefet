#include <stdio.h>

int main()
{

    if(1)
    {
        printf("Entrei aqui :D\n");
        goto aqui_else;
    }
    else
    {
        aqui_else: 
        printf("Aqui tambem >:D\n");
    }
}