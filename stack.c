#include <string.h>
#include <stdio.h>

// определяем размер стека и тип хранимых данных
#define STACK_SIZE 6
#define STACK_TYPE int

// объявляем структуру "стек" для целых чисел
struct stack {
    STACK_TYPE data[STACK_SIZE]; // данные
    size_t head;                 // "голова" - верхний элемент стека
};

// вставка в стек - принимает два параметра:
// сам стек и значение для вставки
STACK_TYPE* push(struct stack* stack, const STACK_TYPE* value) {
    if (stack->head == STACK_SIZE)   // если текущий размер стека равен максимальному,
        return NULL;                 // то возвращаем нуль как значение ошибки

    return memcpy(                   // иначе копируем
        &stack->data[stack->head++], // в головной элемент и увеличиваем его индекс
        value,                       // значение, переданное в аргументе
        sizeof(STACK_TYPE)           // размером типа данных стека,
    );                               // возвращаем указатель на скопированное значение
}

STACK_TYPE* pop(struct stack* stack) {
    if (stack->head == 0) // если текущий размер стека равен нулю
        return NULL;      // возвращаем нуль как значение ошибки

    // иначе возвращаем указатель на головной элемент и уменьшем его индекс
    return &stack->data[--stack->head];
}

void main() {
    struct stack stack = {{}, 0}; // создаём пустой стек

    puts("заполняем стек числами от 0 до STACK_SIZE-1:");
    int num = 1;
    while (push(&stack, &num))
        printf("%i ", num++);

    puts("");

    puts("извлекаем числа из стека:");
    STACK_TYPE* i;
    while (i = pop(&stack))
        printf("%i ", *i);

    puts("");
}
