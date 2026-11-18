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
        if (ch == EOF)
        {
            printf("\nДостигнут конец ввода без символа '#'.\n");
            break;
        }

        if (isalpha(ch))
        {
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            {
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                    ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
                {
                    glasnia++;
                }
                else
                {
                    soglasnia++;
                }
            }
            else
            {
                drygie++;
            }
        }
        else
        {
            drygie++;
        }

    }

    /* Защита: пользователь сразу ввёл '#' — нечего считать */
    if (vsego == 0)
    {
        printf("Нечего считать.\n");
        return 1;
    }

    printf("\nГласных латинских букв: %d\n", glasnia);
    printf("Согласных латинских букв: %d\n", soglasnia);
    printf("Остальных символов: %d\n", drygie);

}