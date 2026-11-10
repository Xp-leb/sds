#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void) {
    wchar_t current;
    wchar_t previous;
    int pairs = 0;
    int first = 1;

    setlocale(LC_ALL, "");

    wprintf(L"Введите текст (для завершения введите '#'):\n");

    current = getwchar();

    while (current != L'#')
    {
        if (first == 1)
        {
            previous = current;
            first = 0;
        }
        else
        {
            if (current == previous)
            {
                pairs = pairs + 1;
            }
            previous = current;
        }

        current = getwchar();
    }

    wprintf(L"Количество пар одинаковых соседних символов: %d\n", pairs);

}

/*
 * Комментарий к коду (как требует задание):
 *
 * Разница между getchar() и getwchar():
 *
 * getchar() читает ОДИН БАЙТ и возвращает int.
 * В многобайтовых кодировках (например, UTF-8) один символ
 * может занимать 2, 3 или 4 байта. Поэтому getchar() вернёт
 * только первый байт символа, и сравнение с другими символами
 * будет некорректным — мы будем сравнивать части байтов, а не
 * целые символы.
 *
 * getwchar() читает ШИРОКИЙ СИМВОЛ (тип wchar_t) и возвращает
 * его код в текущей локали. Один вызов getwchar() соответствует
 * одному символу, даже если в файле он занимает несколько байт.
 * Это позволяет корректно сравнивать символы между собой.
 *
 * Для работы getwchar() нужно подключить <wchar.h> и <locale.h>,
 * а также вызвать setlocale(LC_ALL, "") — иначе локаль будет "C"
 * и широкие символы кириллицы могут не читаться.
 */