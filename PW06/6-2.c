#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void) {
    wchar_t current;
    wchar_t previous;
    int sledom = 0;
    int first = 1;

    setlocale(LC_ALL, "");

    wprintf(L"Введите текст (для завершения введите L'#'):\n");

    current = getwchar();

    while (current != L'#')
    {
        if (current == WEOF)
        {
            wprintf(L"\nДостигнут конец ввода без символа '#'.\n");
            break;
        }

        if (first == 1)
        {
            previous = current;
            first = 0;
        }
        else
        {
            if (current == previous)
            {
                sledom = sledom + 1;
            }
            previous = current;
        }

        current = getwchar();
    }

    /* защита: если ни один символ не был обработан, first так и остался 1 */
    if (first == 1)
    {
        wprintf(L"Нечего считать.\n");
        return 1;
    }

    wprintf(L"Количество пар одинаковых соседних символов: %d\n", sledom);

}