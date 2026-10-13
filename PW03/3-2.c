#include <stdio.h>
#include <string.h>

int main(void) {
    char word1[15], word2[15];

    printf("Введите два слова: ");
    scanf("%s %s", word1, word2);

    printf("%s-%s\n", word1, word2);
    printf("TOTAL_LEN: %zu\n", strlen(word1) + strlen(word2));


}