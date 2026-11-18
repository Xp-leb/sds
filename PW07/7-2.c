#include <stdio.h>
#include <ctype.h>

int main(void) {
    int ch;
    int total_simvols = 0;
    int numbers_len3 = 0;

    int in_number = 0;
    int current_len = 0;

    printf("Введите число (Ctrl+D / Ctrl+Z для завершения):\n");
    fflush(stdout);

    ch = getchar();

    while (ch != EOF)
    {
        total_simvols++;

        if (isdigit(ch))
        {
            if (in_number == 0)
            {
                in_number = 1;
                current_len = 1;
            }
            else
            {
                current_len++;
            }
        }
        else
        {
            if (in_number == 1)
            {
                if (current_len == 3)
                {
                    numbers_len3++;
                }
                in_number = 0;
                current_len = 0;
            }
        }

        ch = getchar();
    }

    /* Обработка последнего числа, если оно не было закрыто */
    if (in_number == 1 && current_len == 3)
    {
        numbers_len3++;
    }

    /* Защита: пустой ввод — считать нечего */
    if (total_simvols == 0)
    {
        printf("Вы не ввели ни одного символа. Нечего считать.\n");
        return 1;
    }

    printf("Чисел длиной ровно 3 цифры: %d\n", numbers_len3);
    printf("Всего обработано символов: %d\n", total_simvols);

}