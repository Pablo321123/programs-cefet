#include <stdio.h>
#define N 20

int main()
{
    int vetor[N],i,aux;
    
    for(i=0;i<N;i++)
    {
    scanf("%d",&vetor[i]);
    }
    
    for(i=0;i<10;i++)
    {
        aux=vetor[i];
        vetor[i]=vetor[19-i]; // vetor[i]=vetor[10-i] -> 10 - 0 -> o vetor nao possui o elemento na posicao vetor[10]
        vetor[19-i]=aux;  // vetor[i]=vetor[10-i] -> 10 - 0 -> o vetor nao possui o elemento na posicao vetor[10]
        
    }
    for(i=0;i<N;i++)
    {
       printf("N[%d] = %d\n",i,vetor[i]);
    }
    
       
    return 0;
}