// main.c
#include <stdio.h>
#include "sparse_list.h"

int main() {
    struct ListStruct my_list;
    my_list.head = NULL;
    my_list.tail = NULL;

    // Пример использования API
    list_push_front(&my_list, 10);
    list_push_back(&my_list, 20);

    printf("Количество элементов: %d\n", list_count(&my_list));

    struct ListNode *head = list_get_head(&my_list);
    printf("Первый элемент: %d\n", head->data);

    struct ListNode *tail = list_get_tail(&my_list);
    printf("Последний элемент: %d\n", tail->data);

    // Здесь могут быть дополнительные проверки и операции

    return 0;
}