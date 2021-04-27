#include <stdio.h>
 
int main() {
    
    int num = 0, maior = 0, posicao = 0, quant = 0;
    
    while(quant < 100){
        scanf(" %d", &num);
        
        if(num > maior){
            maior = num;
            posicao = quant + 1;
        }
        
        quant++;
    }
    
    
    return 0;
}