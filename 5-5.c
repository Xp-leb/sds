#include <stdio.h>

double calc(double a, double b) {
    return (a*a*a - b*b*b) / (a*a - b*b);
}

int main(void) {
    double a, b;
    double res;
    
    printf("Введите a и b: ");
    while (scanf("%lf %lf", &a, &b) == 2) 
    {
        res = calc(a, b);
        
        printf("(%.1f, %.1f) = %.4f\n", a, b, res);
        
        printf("Введите a и b: ");
    }

}

