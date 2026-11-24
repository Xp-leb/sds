#ifndef MYARRFUNC_H
#define MYARRFUNC_H

#include <stddef.h>

/* Функция №6: значение последнего положительного элемента.
 * Возврат: 0 — найдено (значение записано в *result),
 *          -1 — положительных элементов нет / ошибка аргументов. */
int last_positive_value(const int *arrptr, size_t n, int *result);

/* Функция №19: количество элементов со значением ниже k.
 * Возврат: количество (>= 0), либо -1 при ошибке аргументов. */
long count_below_k(const int *arrptr, size_t n, int k);

/* Функция №24: индексы элементов со значением выше k.
 * Индексы записываются в idx[] (ёмкость idx_cap).
 * Возврат: количество записанных индексов, либо -1 при ошибке. */
long indices_above_k(const int *arrptr, size_t n, int k,
                     size_t *idx, size_t idx_cap);

#endif /* MYARRFUNC_H */