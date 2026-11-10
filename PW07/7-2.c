#include <stdio.h>
#include <ctype.h>

int main(void) {
    int ch;
    int total_chars = 0;
    int numbers_len3 = 0;

    int in_number = 0;
    int current_len = 0;

    printf("Введите число (Ctrl+D / Ctrl+Z для завершения):\n");
    fflush(stdout);

    ch = getchar();

    while (ch != EOF)
    {
        total_chars++;

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

    printf("Чисел длиной ровно 3 цифры: %d\n", numbers_len3);
    printf("Всего обработано символов: %d\n", total_chars);

}

/*
 * В стандарте языка Си (ISO C) функции isletter() и isnumber()
 * НЕ СУЩЕСТВУЮТ. Это функции из других языков или библиотек
 * (например, в некоторых реализациях или в C++).
 *
 * В стандартной библиотеке <ctype.h> языка Си есть:
 *   isalpha() — проверяет, является ли символ буквой (a-z, A-Z)
 *   isdigit() — проверяет, является ли символ десятичной цифрой (0-9)
 *
 * isalpha() возвращает истину для букв, isdigit() — для цифр.
 * Никаких isletter() и isnumber() в стандартном Си нет.
 * Если преподаватель упомянул их — это, скорее всего, опечатка
 * или отсылка к другому языку. В программе используем isdigit(),
 * как и положено в Си.
 */