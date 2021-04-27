#include <stdio.h>
#include <math.h>
 
int main() {
 
    int n, tamanho, i, j;
    
    scanf(" %d", &tamanho);

    for(i = 0; i < tamanho; i++){
        
        for(j = 0; j < 3; j++){
            
            printf("%0.lf", (double) pow( (i+1) , (j + 1)));
            
            if(j != 2){
                printf(" ");
            }
            
        }
        printf("\n");
    }   
    
 
    return 0;
}