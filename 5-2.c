#include <stdio.h>

#define HEIGHT 5
#define WIDTH 10

int main(void) {
    int i, j;

    for (i = 0; i < HEIGHT; i++)      /* строки */
    {
        for (j = 0; j < WIDTH; j++)   /* столбцы */
        {
            printf("-");
        }
        printf("\n");
    }

}