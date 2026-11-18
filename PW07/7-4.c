#include <stdio.h>

/* Прототип: функция принимает два указателя на double */
void set_average(double *pa, double *pb);

int main(void) {
    double x = 4.0;
    double y = 10.0;

    printf("До вызова функции:\n");
    printf("x = %.2f, y = %.2f\n", x, y);

    /* Передаём адреса переменных с помощью & */
    set_average(&x, &y);

    printf("После вызова функции:\n");
    printf("x = %.2f, y = %.2f\n", x, y);

    return 0;
}

void set_average(double *pa, double *pb)
{
    double sum;
    double avg;

    /* Защита: проверяем, что указатели не NULL */
    if (pa == NULL || pb == NULL)
    {
        return;
    }

    /* Разыменовываем указатели, чтобы получить значения */
    sum = *pa + *pb;
    avg = sum / 2.0;

    /* Присваиваем обеим переменным среднее арифметическое */
    *pa = avg;
    *pb = avg;
}