#include <stdio.h>
#define k 60

int main(void) {
    int total_min;

    printf("Ввод:\n");

    while (scanf("%d", &total_min) == 1 && total_min > 0) {
    
        int hours = total_min / k; 
        int minutes = total_min % k; 
        
        printf("%d мин = %d ч %d мин\n", total_min, hours, minutes);
    }

    // При целочисленном делении int на int дробная часть отбрасывается, 
    // потому что тип int предназначен только для хранения целых чисел.

}