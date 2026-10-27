#include <stdio.h>

#define SIZE 8

int main(void) {
    double arr[SIZE];
    int i, j;
    int chislo = 0;
    int num = 2; 
    int proverka;
    double sum = 0.0;

    while (chislo < SIZE)
    {
        proverka = 1;
        for (i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                proverka = 0;
        
            }
        }
        if (proverka)
        {
            arr[chislo] = num;
            chislo++;
        }
        num++;
    }

    printf("Массив: ");
    for (j = 0; j < SIZE; j++)
    {
        printf("%.2f ", arr[j]);
    }
    printf("\n");

    for (j = 1; j < SIZE; j++)
    {
        sum = sum + arr[j];
    }
    printf("Сумма: %.2f\n", sum);

}