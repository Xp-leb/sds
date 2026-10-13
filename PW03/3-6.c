#include <stdio.h>
#include <string.h>

int main(void) {
    char str[100];
    int width;

    printf("Введите строку и число: ");
    scanf("%99s %d", str, &width);

    printf("|%*s|\n", width, str);           // правое выравнивание
    printf("|%-*s|\n", width + 5, str);       // левое выравнивание, ширина + 5


}