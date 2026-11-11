#include <stdio.h>

/* Прототипы */
int sum_recursive(int n);
int sum_iterative(int n);

int main(void) {
    int n;
    int rec_result;
    int iter_result;

    printf("Введите N (целое положительное число): ");
    scanf("%d", &n);

    if (n < 1)
    {
        printf("N должно быть больше 0.\n");
        return 1;
    }

    rec_result = sum_recursive(n);
    iter_result = sum_iterative(n);

    printf("Рекурсивно: сумма от 1 до %d = %d\n", n, rec_result);
    printf("Итеративно: сумма от 1 до %d = %d\n", n, iter_result);

    return 0;
}

/* Рекурсивная версия — как в лекции 7, стр. 34 */
int sum_recursive(int n)
{
    if (n == 1)
    {
        return 1; /* базовый случай — условие окончания рекурсии */
    }
    else
    {
        return n + sum_recursive(n - 1);
    }
}

/* Итеративная версия — через цикл for (лекция 5, стр. 21) */
int sum_iterative(int n)
{
    int i;
    int sum = 0;

    for (i = 1; i <= n; i++)
    {
        sum = sum + i;
    }

    return sum;
}