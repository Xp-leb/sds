#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "myarrfunc.h"

static void print_menu(void)
{
    printf("\n--- МЕНЮ ---\n");
    printf("a  Задать размер массива\n");
    printf("b  Заполнить массив\n");
    printf("c  Представление массива (значения, адреса)\n");
    printf("d  Поиск значения последнего положительного элемента\n");
    printf("e  Количество элементов ниже введённого k\n");
    printf("f  Индексы элементов выше введённого k\n");
    printf("g  Выход\n");
    printf("Выберите пункт: ");
}

/* Чтение строки; 0 — успех, -1 — EOF или ошибка */
static int read_line(char *buf, size_t size)
{
    if (fgets(buf, (int)size, stdin) == NULL)
        return -1;
    /* убираем перевод строки */
    for (char *p = buf; *p; ++p)
        if (*p == '\n') { *p = '\0'; break; }
    return 0;
}

/* Разбор целого числа из строки: 0 — успех */
static int parse_int(const char *s, int *out)
{
    char *end = NULL;
    long v = strtol(s, &end, 10);
    if (end == s || *end != '\0' || v < INT_MIN || v > INT_MAX)
        return -1;
    *out = (int)v;
    return 0;
}

int main(void)
{
    int   *arr = NULL;
    size_t n   = 0;
    int    filled = 0;          /* массив заполнен? */
    int    size_set = 0;        /* размер задан? */
    char   line[128];

    for (;;) {
        print_menu();
        if (read_line(line, sizeof line) < 0) {
            printf("\nEOF. Завершение работы.\n");
            break;
        }
        if (line[0] == '\0')        /* пустой ввод — снова меню */
            continue;

        switch (line[0]) {
        case 'a': {
            printf("Введите размер массива (>0): ");
            if (read_line(line, sizeof line) < 0) { printf("\nEOF\n"); goto done; }
            int v;
            if (parse_int(line, &v) != 0 || v <= 0) {
                printf("Ошибка: нужно целое число > 0.\n");
                break;
            }
            int *tmp = realloc(arr, (size_t)v * sizeof *arr);
            if (!tmp) { printf("Ошибка выделения памяти.\n"); break; }
            arr = tmp;
            n = (size_t)v;
            size_set = 1;
            filled = 0;
            printf("Размер массива: %zu\n", n);
            break;
        }

        case 'b': {
            if (!size_set) { printf("Сначала задайте размер (пункт a).\n"); break; }
            printf("Введите %zu целых чисел через пробел/Enter:\n", n);
            size_t got = 0;
            while (got < n) {
                if (read_line(line, sizeof line) < 0) { printf("\nEOF\n"); goto done; }
                char *p = line;
                while (*p && got < n) {
                    while (*p == ' ' || *p == '\t') ++p;
                    if (!*p) break;
                    char *end = NULL;
                    long v = strtol(p, &end, 10);
                    if (end == p) { printf("Некорректный ввод, пропуск.\n"); p = end; continue; }
                    arr[got++] = (int)v;
                    p = end;
                }
            }
            filled = 1;
            printf("Массив заполнен (%zu элементов).\n", got);
            break;
        }

        case 'c': {
            if (!filled) { printf("Массив ещё не заполнен (пункт b).\n"); break; }
            printf("%-6s %-12s %s\n", "Индекс", "Значение", "Адрес");
            for (size_t i = 0; i < n; ++i)
                printf("%-6zu %-12d %p\n", i, *(arr + i), (void *)(arr + i));
            break;
        }

        case 'd': {
            if (!filled) { printf("Массив ещё не заполнен (пункт b).\n"); break; }
            int res;
            if (last_positive_value(arr, n, &res) == 0)
                printf("Последний положительный элемент: %d\n", res);
            else
                printf("Положительных элементов в массиве нет.\n");
            break;
        }

        case 'e': {
            if (!filled) { printf("Массив ещё не заполнен (пункт b).\n"); break; }
            printf("Введите k: ");
            if (read_line(line, sizeof line) < 0) { printf("\nEOF\n"); goto done; }
            int k;
            if (parse_int(line, &k) != 0) { printf("Некорректное k.\n"); break; }
            long cnt = count_below_k(arr, n, k);
            if (cnt < 0) printf("Ошибка аргументов.\n");
            else         printf("Элементов со значением ниже %d: %ld\n", k, cnt);
            break;
        }

        case 'f': {
            if (!filled) { printf("Массив ещё не заполнен (пункт b).\n"); break; }
            printf("Введите k: ");
            if (read_line(line, sizeof line) < 0) { printf("\nEOF\n"); goto done; }
            int k;
            if (parse_int(line, &k) != 0) { printf("Некорректное k.\n"); break; }

            size_t *idx = malloc(n * sizeof *idx);
            if (!idx) { printf("Ошибка памяти.\n"); break; }
            long cnt = indices_above_k(arr, n, k, idx, n);
            if (cnt < 0) {
                printf("Ошибка аргументов.\n");
            } else if (cnt == 0) {
                printf("Элементов со значением выше %d нет.\n", k);
            } else {
                printf("Элементов выше %d: %ld. Индексы: ", k, cnt);
                for (long j = 0; j < cnt; ++j)
                    printf("%zu ", idx[j]);
                printf("\n");
            }
            free(idx);
            break;
        }

        case 'g':
            printf("Выход.\n");
            goto done;

        default:
            printf("Неизвестный пункт меню: '%s'.\n", line);
            break;
        }
    }

done:
    free(arr);
    return 0;
}
