#include <stdio.h>
#include <string.h>

int main(void) {
    char name[50];

    if (scanf("%49s", name) != 1) {
        
    }

    int len = (int)strlen(name) + 5;

    printf("\"%s\"\n",    name);                 // 1. в кавычках
    printf("\"%20s\"\n",  name);                 // 2. вправо, ширина 20
    printf("\"%-20s\"\n", name);                 // 3. влево, ширина 20
    printf("\"%*s\"\n",   len, name);    // 4. ширина = длина + 5

}