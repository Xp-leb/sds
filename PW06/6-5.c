#include <stdio.h>

int main(void) {
    int choice;
    double value;
    double result;

    /* Бесконечный цикл, выход через break */
    while (1)
    {
        printf("\n--- Конвертер данных ---\n");
        printf("1. Байты -> Килобайты\n");
        printf("2. Килобайты -> Мегабайты\n");
        printf("3. Мегабайты -> Гигабайты\n");
        printf("4. Биты -> Байты\n");
        printf("5. Выход\n");
        printf("Выберите пункт (1-5): ");

        /* Защита: проверяем, что ввод — число */
        if (scanf("%d", &choice) != 1)
        {
            printf("Ошибка: введено не число. Завершение.\n");
            return 1;
        }

        /* Проверка на некорректный ввод — используем continue */
        if (choice < 1 || choice > 5)
        {
            printf("Ошибка: неверный номер пункта. Попробуйте снова.\n");
            continue; /* пропускаем остаток итерации, возвращаемся к меню */
        }

        /* Выход из программы */
        if (choice == 5)
        {
            printf("Выход из программы.\n");
            break; /* выходим из цикла while */
        }

        /* Если дошли сюда — choice от 1 до 4, спрашиваем значение */
        printf("Введите значение: ");

        /* Защита: проверяем, что ввод — число */
        if (scanf("%lf", &value) != 1)
        {
            printf("Ошибка: введено не число. Завершение.\n");
            return 1;
        }

        /* Множественный выбор с помощью switch */
        switch (choice)
        {
            case 1:
                result = value / 1024.0;
                printf("%.2f Б = %.4f КБ\n", value, result);
                break; /* без break выполнился бы case 2 */
            case 2:
                result = value / 1024.0;
                printf("%.2f КБ = %.4f МБ\n", value, result);
                break;
            case 3:
                result = value / 1024.0;
                printf("%.2f МБ = %.4f ГБ\n", value, result);
                break;
            case 4:
                result = value / 8.0;
                printf("%.2f бит = %.2f байт\n", value, result);
                break;
            default:
                printf("Неизвестная ошибка.\n");
                break;
        }
    }

}