#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "");

    wchar_t mod1[100], mod2[100], mod3[100];

    wprintf(L"Введите три модуля: ");
    wscanf(L"%ls %ls %ls", mod1, mod2, mod3);

    wprintf(L"%-15ls|%20ls|%.5ls\n", mod1, mod2, mod3);

}