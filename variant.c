#include <stdio.h>

int main(void) {
    
    unsigned long long n_zks = 111260251; 

    int var_4_1 = (n_zks % 30) + 1;
    int var_4_2 = ((n_zks + 7) % 30) + 1;
    int var_4_3 = ((n_zks + 13) % 30) + 1;
    int var_4_4 = ((n_zks + 19) % 30) + 1;
    int var_4_5 = ((n_zks + 23) % 30) + 1;

    printf("Задание 4.1: Вариант %d\n", var_4_1);
    printf("Задание 4.2: Вариант %d\n", var_4_2);
    printf("Задание 4.3: Вариант %d\n", var_4_3);
    printf("Задание 4.4: Вариант %d\n", var_4_4);
    printf("Задание 4.5: Вариант %d\n", var_4_5);

}