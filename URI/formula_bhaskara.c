#include <stdio.h>
#include <math.h>
 
int main() {
 
    double a = 0.0, b = 0.0, c = 0.0, r1 = 0.0, r2 = 0.0, delta = 0.0;
    
    scanf(" %lf %lf %lf", &a, &b, &c);
    
    delta = pow(b, 2) - (4 * a * c);
    
    if(2 * a == 0 ||  delta < 0){
        
        printf("Impossivel calcular\n");
        
    }else{
        
        r1 =  ((b * -1) + sqrt(delta)) / (2 * a);
        r2 =  ((b * -1) - sqrt(delta)) / (2 * a);
        
        printf("R1 = %1.5lf\nR2 = %.5lf\n", r1, r2);
    }
 
    return 0;
}