#include <stdio.h>

int main(void) {
    int num;
    int kratno3 = 0;
    int kratno5 = 0;
    int sum3 = 0;
    int sum5 = 0;
    double avg3;
    double avg5;

    printf("Введите целые числа (0 для завершения):\n");

    /* Читаем первое число */
    if (scanf("%d", &num) != 1)
    {
        printf("Ошибка: введено не целое число. Завершение.\n");
        return 1;
    }

    while (num != 0)
    {
        /* Проверяем, кратно ли число 3 */
        if (num % 3 == 0)
        {
            kratno3 = kratno3 + 1;
            sum3 = sum3 + num;
        }

        /* Проверяем, кратно ли число 5 */
        if (num % 5 == 0)
        {
            kratno5 = kratno5 + 1;
            sum5 = sum5 + num;
        }

        /* Читаем следующее число */
        if (scanf("%d", &num) != 1)
        {
            printf("\nОшибка ввода (не число или конец ввода). Завершение.\n");
            break;
        }
    }

    /* Выводим результаты для кратных 3 */
    printf("Чисел, кратных 3: %d\n", kratno3);
    if (kratno3 > 0)
    {
        avg3 = (double)sum3 / kratno3;
        printf("Среднее арифметическое для кратных 3: %.2f\n", avg3);
    }
    else
    {
        printf("Среднее арифметическое для кратных 3: нет чисел\n");
    }

    /* Выводим результаты для кратных 5 */
    printf("Чисел, кратных 5: %d\n", kratno5);
    if (kratno5 > 0)
    {
        avg5 = (double)sum5 / kratno5;
        printf("Среднее арифметическое для кратных 5: %.2f\n", avg5);
    }
    else
    {
        printf("Среднее арифметическое для кратных 5: нет чисел\n");
    }

}