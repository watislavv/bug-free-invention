#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sparse_list.h"
#include "sparse_list.c"

// Функции из sparse_list.c
void list_push_front(struct ListStruct *list, int value);
void list_push_back(struct ListStruct *list, int value);
void list_pop(struct ListStruct *list, struct ListNode *node);
int list_count(struct ListStruct *list);
struct ListNode *list_get_head(struct ListStruct *list);
struct ListNode *list_get_tail(struct ListStruct *list);
bool list_is_empty(struct ListStruct *list);

int main() {
    struct ListStruct my_list;
    my_list.head = NULL;
    my_list.tail = NULL;

    // Добавление элементов в список
    list_push_front(&my_list, 10);
    list_push_back(&my_list, 20);
    list_push_front(&my_list, 5);
    list_push_back(&my_list, 25);

    printf("Количество элементов: %d\n", list_count(&my_list));

    // Печать элементов списка
    struct ListNode *current = list_get_head(&my_list);
    printf("Элементы списка: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Проверка первого и последнего элемента
    struct ListNode *head = list_get_head(&my_list);
    struct ListNode *tail = list_get_tail(&my_list);

    if (head != NULL) {
        printf("Первый элемент: %d\n", head->data);
    }
    if (tail != NULL) {
        printf("Последний элемент: %d\n", tail->data);
    }

    // Удаление первого элемента
    if (head != NULL) {
        list_pop(&my_list, head);
        printf("Удален первый элемент. Новое количество элементов: %d\n", list_count(&my_list));
    }

    // Печать оставшихся элементов списка
    current = list_get_head(&my_list);
    printf("Оставшиеся элементы списка: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Освобождение памяти
    while (!list_is_empty(&my_list)) {
        list_pop(&my_list, list_get_head(&my_list));
    }

    return 0;
}
