#include <stdio.h>
#include <ctype.h>

int main(void) {
    int ch; /* getchar() возвращает int, чтобы можно было сравнить с EOF */

    printf("Введите текст (Ctrl+D / Ctrl+Z для завершения):\n");

    ch = getchar();

    while (ch != EOF)
    {
        /* isupper() из <ctype.h> проверяет, заглавная ли буква */
        if (isupper(ch))
        {
            putchar(ch);
        }
        /* остальные символы игнорируем — ничего не выводим */

        ch = getchar();
    }

}