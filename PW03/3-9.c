#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "");

    wchar_t callsign[100];

    wprintf(L" ");
    wscanf(L"%ls", callsign);

    wprintf(L"Агент %ls авторизован в системе\n", callsign);

}