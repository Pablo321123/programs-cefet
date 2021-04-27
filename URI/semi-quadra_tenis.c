#include <stdio.h>
 
int main() {
 
    int x = 0, y = 0;
    
    scanf(" %d %d", &x, &y);
    
     if(x > 468 || x < 0 || y > 432 || y < 0){ // 0 pq eh uma semi quadra.
        
        printf("fora\n");
        
    }else{
         printf("dentro\n");
    }
 
    return 0;
}