#include <stdio.h>
#include <ctype.h>

int main(void) {
    char ch;
    int glasnia = 0;
    int soglasnia = 0;
    int drygie = 0;

    printf("Введите текст (для завершения введите '#'):\n");

    ch = getchar();

    while (ch != '#')
    {
        /* isalpha() из <ctype.h> проверяет, является ли символ буквой */
        if (isalpha(ch))
        {
            /* Это буква. Но нам нужна только латиница.
               Проверяем диапазон вручную, чтобы отсечь кириллицу */
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            {
                /* Латинская буква. Проверяем, гласная ли она */
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                    ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
                {
                    glasnia = glasnia + 1;
                }
                else
                {
                    soglasnia = soglasnia + 1;
                }
            }
            else
            {
                /* Буква, но не латинская (например, кириллица) — считаем остальной */
                drygie = drygie + 1;
            }
        }
        else
        {
            /* Не буква — остальной символ */
            drygie = drygie + 1;
        }

        ch = getchar();
    }

    printf("Гласных латинских букв: %d\n", glasnia);
    printf("Согласных латинских букв: %d\n", soglasnia);
    printf("Остальных символов: %d\n", drygie);

}