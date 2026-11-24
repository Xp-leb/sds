#include "myarrfunc.h"

/* ---------- Функция №6 ---------- */
int last_positive_value(const int *arrptr, size_t n, int *result)
{
    if (arrptr == NULL || result == NULL)
        return -1;

    const int *p = arrptr + n;   /* указатель за последним элементом */
    while (p != arrptr) {
        --p;                     /* шаг назад: p указывает на элемент */
        if (*p > 0) {
            *result = *p;
            return 0;            /* найдено */
        }
    }
    return -1;                   /* положительных нет */
}

/* ---------- Функция №19 ---------- */
long count_below_k(const int *arrptr, size_t n, int k)
{
    if (arrptr == NULL)
        return -1;

    long count = 0;
    const int *end = arrptr + n;
    for (const int *p = arrptr; p != end; ++p)
        if (*p < k)
            ++count;
    return count;
}

/* ---------- Функция №24 ---------- */
long indices_above_k(const int *arrptr, size_t n, int k,
                     size_t *idx, size_t idx_cap)
{
    if (arrptr == NULL || idx == NULL)
        return -1;

    long count = 0;
    const int *end = arrptr + n;
    size_t i = 0;

    for (const int *p = arrptr; p != end; ++p, ++i) {
        if (*p > k) {
            if ((size_t)count < idx_cap)   /* не переполняем буфер */
                idx[count] = i;
            ++count;                        /* считаем все совпадения */
        }
    }
    return count;
}