#include <stdio.h>

/* Прототип функции — как в лекции 7, стр. 32 */
double average(double a, double b);

int main(void) {
    double a, b, result;

    printf("Введите пары чисел (Ctrl+D / Ctrl+Z для завершения):\n");

    /* scanf возвращает количество успешно считанных элементов.
       Если считано 2 — ввод корректен, продолжаем. */
    while (scanf("%lf %lf", &a, &b) == 2)
    {
        result = average(a, b);
        printf("Среднее арифметическое: %.4f\n", result);
        printf("Введите следующую пару: ");
    }

    printf("Ввод завершён.\n");

}

/* Определение функции — как в лекции 7, стр. 30 */
double average(double a, double b)
{
    double sum;
    sum = a + b;
    return sum / 2.0;
}