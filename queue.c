#include <stdio.h>
#include <stdlib.h>

// пусть очередь хранит значения целочисленного типа
struct node {
    int value;          // значение
    struct node* next;  // указатель на следующий элемент очереди
};

struct queue {
    struct node* head; // указатель на головной в очереди элемент
    struct node* tail; // указатель на последний элемент очереди
};


int push(struct queue* q, int value) {
    q->tail->value = value;        // присваиваем значение новому элементу
    q->tail->next = malloc(sizeof(struct node)); // выделяем память под новый элемент очереди
    q->tail->next->next = NULL;   // указываем, что элемент, следующий после нового пуст
    q->tail = q->tail->next;      // указываем что последний элемент - новый элемент

    return value;
}

int pop(struct queue* q) {
    if (q->head->next == NULL) // если очередь пуста
        return 0;              // возвращаем нуль

    int value = q->head->value;        // извлекаем значение "головы" - первого элемента
    struct node* next = q->head->next; // сохраняем указатель на этот элемент

    free(q->head);                     // удаляем первый элемент
    q->head = next;                    // теперь второй элемент является первым

    return value;
}

void main() {
    struct queue queue; // создаём пустую очередь
    queue.head = malloc(sizeof(struct node));
    queue.head->next = NULL;
    queue.tail = queue.head;

    puts("Вносим значения в очередь");
    for (int i = 0; i < 10; i++)
        printf("%i ", push(&queue, i));

    puts("");

    puts("Извлекаем значения из очереди");
    while (queue.head->next)
        printf("%i ", pop(&queue));

    puts("");

}
