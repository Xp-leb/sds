#include <stdio.h>

int main(void) {
    int N, i;
    double sum;

    printf("Введите N: ");
    scanf("%d", &N);

    while (N > 0)
    {
        sum = 0.0;
        for (i = 1; i <= N; i++)
        {
            sum = sum + 1.0 / (1 << i);   /* 1 << i это 2 в степени i */
        }
        printf("SUM: %.6f\n", sum);

        printf("Введите N: ");
        scanf("%d", &N);
    }

}