#include <stdio.h>
#include <ctype.h>

int main(void) {
    int ch; 

    printf("Введите текст (Ctrl+D / Ctrl+Z для завершения):\n");

    ch = getchar();

    while (ch != EOF)
    {

        if (isupper(ch))
        {
            putchar(ch);
        }


        ch = getchar();
    }

    if (ch == EOF)
    {
        printf("\nВвод завершён (или не было данных).\n");
    }

}