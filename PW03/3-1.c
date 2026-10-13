#include <stdio.h>
#include <string.h>

int main(void) {
    char str1[20] = "SibSUTIS";
    char str2[20]   = "СибГУТИ";

    printf("SIZEOF: %zu\n", sizeof(str1));
    printf("STRLEN: %zu\n", strlen(str1));
    printf("FREE_BYTES: %zu\n", sizeof(str1) - strlen(str1) - 1);

    printf("\n");

    printf("SIZEOF: %zu\n", sizeof(str2));
    printf("STRLEN: %zu\n", strlen(str2));
    printf("FREE_BYTES: %zu\n", sizeof(str2) - strlen(str2) - 1);

}