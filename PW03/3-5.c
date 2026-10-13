#include <stdio.h>

int main(void) {
    char c;
    printf("Введите строчную латинскую букву: ");
    scanf(" %c", &c);   // пробел перед %c игнорирует whitespace

    printf("CODE_DEC: %d\n", c);
    printf("CODE_HEX: %x\n", c);
    printf("CODE_OCT: %o\n", c);

    // Преобразование в верхний регистр: 'a'..'z' -> 'A'..'Z'
    char upper = (c >= 'a' && c <= 'z') ? (char)(c - 'a' + 'A') : c;
    printf("UPPER: %c\n", upper);

    // Следующий и предыдущий символы
    printf("NEXT: %c\n", c + 1);
    printf("PREV: %c\n", c - 1);

}