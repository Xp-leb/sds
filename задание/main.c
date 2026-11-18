/*
 Моделирование архитектуры фон Неймана на языке Си.
 Уровень "хорошо", вариант 1,6.
 В памяти memory[256] хранятся и команды, и данные - это единое хранилище.
 Счётчик команд cpu_state[0] показывает, какую команду выполнять.
 Аккумулятор cpu_state[1] хранит результат.
 Команда 4 - это безусловный переход (JUMP).
*/

#include <stdio.h>

#define MEM_SIZE 256

int main()
{
    int cpu_state[8];
    int memory[MEM_SIZE];
    int i, n, code, operand;
    FILE *f;

    /* обнуляем память и состояние процессора */
    for (i = 0; i < MEM_SIZE; i++) {
        memory[i] = 0;
    }
    for (i = 0; i < 8; i++) {
        cpu_state[i] = 0;
    }

    /* читаем программу из файла program.txt */
    f = fopen("program.txt", "r");
    if (f == NULL) {
        printf("Не могу открыть файл program.txt\n");
        return 1;
    }

    n = 0;
    while (fscanf(f, "%d", &memory[n]) == 1) {
        n++;
        if (n >= MEM_SIZE) {
            break;
        }
    }
    fclose(f);

    printf("Прочитано чисел: %d\n", n);

    /* настраиваем процессор */
    cpu_state[3] = memory[0];  /* вектор прерываний */
    cpu_state[0] = 1;          /* pc начинается с 1, memory[0] - вектор */
    cpu_state[1] = 0;          /* acc = 0 */
    cpu_state[2] = 0;          /* ir = 0 */
    cpu_state[4] = 0;          /* не остановлен */
    cpu_state[5] = 0;          /* ошибок нет */

    printf("Вектор прерываний = %d\n", cpu_state[3]);
    printf("Начинаем с pc = %d\n\n", cpu_state[0]);

    /* главный цикл выполнения программы */
    while (cpu_state[4] == 0) {

        /* если pc вышел за границы памяти - прерывание */
        if (cpu_state[0] < 0 || cpu_state[0] >= MEM_SIZE) {
            printf("ОШИБКА: pc вышел за границы памяти\n");
            cpu_state[5] = 1;
            cpu_state[0] = cpu_state[3];
            if (cpu_state[0] == 0) {
                printf("Программа завершена с ошибкой.\n");
                break;
            }
            continue;
        }

        code = memory[cpu_state[0]];
        cpu_state[2] = code;

        if (code == 0) {
            /* стоп */
            printf("pc=%d: команда 0 (стоп), acc=%d\n",
                   cpu_state[0], cpu_state[1]);
            cpu_state[4] = 1;
        }
        else if (code == 1) {
            /* загрузить в аккумулятор значение из памяти */
            operand = memory[cpu_state[0] + 1];
            if (operand < 0 || operand >= MEM_SIZE) {
                printf("pc=%d: команда 1, operand=%d, ОШИБКА: адрес вне памяти\n",
                       cpu_state[0], operand);
                cpu_state[5] = 2;
                cpu_state[0] = cpu_state[3];
                if (cpu_state[0] == 0) {
                    printf("Программа завершена с ошибкой.\n");
                    break;
                }
                continue;
            }
            cpu_state[1] = memory[operand];
            printf("pc=%d: команда 1, operand=%d, acc=%d\n",
                   cpu_state[0], operand, cpu_state[1]);
            cpu_state[0] = cpu_state[0] + 2;
        }
        else if (code == 2) {
            /* умножить аккумулятор на значение из памяти */
            operand = memory[cpu_state[0] + 1];
            if (operand < 0 || operand >= MEM_SIZE) {
                printf("pc=%d: команда 2, operand=%d, ОШИБКА: адрес вне памяти\n",
                       cpu_state[0], operand);
                cpu_state[5] = 2;
                cpu_state[0] = cpu_state[3];
                if (cpu_state[0] == 0) {
                    printf("Программа завершена с ошибкой.\n");
                    break;
                }
                continue;
            }
            cpu_state[1] = cpu_state[1] * memory[operand];
            printf("pc=%d: команда 2, operand=%d, acc=%d\n",
                   cpu_state[0], operand, cpu_state[1]);
            cpu_state[0] = cpu_state[0] + 2;
        }
        else if (code == 3) {
            /* разделить аккумулятор на значение из памяти */
            operand = memory[cpu_state[0] + 1];
            if (operand < 0 || operand >= MEM_SIZE) {
                printf("pc=%d: команда 3, operand=%d, ОШИБКА: адрес вне памяти\n",
                       cpu_state[0], operand);
                cpu_state[5] = 2;
                cpu_state[0] = cpu_state[3];
                if (cpu_state[0] == 0) {
                    printf("Программа завершена с ошибкой.\n");
                    break;
                }
                continue;
            }
            if (memory[operand] == 0) {
                printf("pc=%d: команда 3, operand=%d, ОШИБКА: деление на 0\n",
                       cpu_state[0], operand);
                cpu_state[5] = 3;
                cpu_state[0] = cpu_state[3];
                if (cpu_state[0] == 0) {
                    printf("Программа завершена с ошибкой.\n");
                    break;
                }
                continue;
            }
            cpu_state[1] = cpu_state[1] / memory[operand];
            printf("pc=%d: команда 3, operand=%d, acc=%d\n",
                   cpu_state[0], operand, cpu_state[1]);
            cpu_state[0] = cpu_state[0] + 2;
        }
        else if (code == 4) {
            /* безусловный переход на адрес */
            operand = memory[cpu_state[0] + 1];
            if (operand < 0 || operand >= MEM_SIZE) {
                printf("pc=%d: команда 4, operand=%d, ОШИБКА: переход вне памяти\n",
                       cpu_state[0], operand);
                cpu_state[5] = 2;
                cpu_state[0] = cpu_state[3];
                if (cpu_state[0] == 0) {
                    printf("Программа завершена с ошибкой.\n");
                    break;
                }
                continue;
            }
            printf("pc=%d: команда 4 (переход), operand=%d, acc=%d\n",
                   cpu_state[0], operand, cpu_state[1]);
            cpu_state[0] = operand;
        }
        else {
            /* непонятная команда */
            printf("pc=%d: неизвестная команда %d\n", cpu_state[0], code);
            cpu_state[5] = 4;
            cpu_state[0] = cpu_state[3];
            if (cpu_state[0] == 0) {
                printf("Программа завершена с ошибкой.\n");
                break;
            }
            continue;
        }
    }

    if (cpu_state[4] == 1) {
        printf("Программа завершена.\n");
    }

    return 0;
}

/*  Моделирование архитектуры фон Неймана на языке Си.
 Уровень "хорошо", вариант 1,6.
 В памяти memory[256] хранятся и команды, и данные - это единое хранилище.
 Счётчик команд cpu_state[0] показывает, какую команду выполнять.
 Аккумулятор cpu_state[1] хранит результат.
 Команда 4 - это безусловный переход (JUMP).

 Отражение принципов фон Неймана:
 1. Единое хранилище: массив memory хранит и команды (опкоды), и данные (числа).
 2. Последовательное выполнение: счётчик команд (pc) увеличивается на 2 после 
    каждой команды с операндом.
 3. Наличие АЛУ и регистров: аккумулятор (acc) выполняет математические операции, 
    регистр команд (ir) хранит текущий опкод.
 4. Управление потоком: команда JUMP позволяет изменить естественный порядок 
    выполнения, перезаписывая счётчик команд.
*/