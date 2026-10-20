#include <stdio.h>
#include <stdint.h>

int main(void) {

    uint16_t m, v;

    printf("Введите массу m: ");
    // %hu - формат для unsigned short (uint16_t)
    if (scanf("%hu", &m) != 1) {
        return 1;
    }

    printf("Введите скорость v: ");
    if (scanf("%hu", &v) != 1) {
        return 1;
    }
     /* Приводим m к float. Теперь все выражение вычисляется в вещественных числах.
     *  Если бы мы не привели тип, выражение (m * v * v) могло бы вызвать переполнение 
     *  типа uint16_t (например, при v=300, v*v=90000 > 65535), и результат был бы 
     *  полностью неверным. Кроме того, деление на 2 без float отбросило бы дробную часть.
     */
    float result = (float)m * v * v / 2;

    printf("\nРезультат: (float)m * v * v / 2 = %f\n", result);

    printf("sizeof(uint16_t) = %llu\n", (unsigned long long)sizeof(uint16_t));
    printf("sizeof(float)    = %llu\n", (unsigned long long)sizeof(float));
    printf("sizeof(double)   = %llu\n", (unsigned long long)sizeof(double));
    printf("sizeof(m)        = %llu\n", (unsigned long long)sizeof(m));
    printf("sizeof(v)        = %llu\n", (unsigned long long)sizeof(v));
    printf("sizeof(result)   = %llu\n", (unsigned long long)sizeof(result));

}