#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "xor_list.h"

// Функции реализации XOR списка

void list_push_front(struct ListStruct *list, int value) {
    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->data = value;
    new_node->xor_ptr = (struct ListNode *)((uintptr_t)list->head ^ 0); // XOR с NULL

    if (list->head) {
        list->head->xor_ptr = (struct ListNode *)((uintptr_t)new_node ^ (uintptr_t)list->head->xor_ptr);
    } else {
        list->tail = new_node; // Если список пуст, новый элемент также будет хвостом
    }
    
    list->head = new_node;
}

void list_push_back(struct ListStruct *list, int value) {
    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->data = value;
    new_node->xor_ptr = (struct ListNode *)((uintptr_t)list->tail ^ 0); // XOR с NULL

    if (list->tail) {
        list->tail->xor_ptr = (struct ListNode *)((uintptr_t)new_node ^ (uintptr_t)list->tail->xor_ptr);
    } else {
        list->head = new_node; // Если список пуст, новый элемент становится головой
    }
    
    list->tail = new_node;
}

void list_pop(struct ListStruct *list, struct ListNode *node) {
    if (!node || !list->head) return;

    // Обработка удаления узла из списка
    // ... (реализация удаления узла)
}

int list_count(struct ListStruct *list) {
    int count = 0;
    struct ListNode *current = list->head;
    struct ListNode *prev = NULL;

    while (current != NULL) {
        count++;
        struct ListNode *next = (struct ListNode *)((uintptr_t)current->xor_ptr ^ (uintptr_t)prev);
        prev = current;
        current = next;
    }
    
    return count;
}

struct ListNode *list_get_head(struct ListStruct *list) {
    return list->head;
}

struct ListNode *list_get_tail(struct ListStruct *list) {
    return list->tail;
}

bool list_is_empty(struct ListStruct *list) {
    return list->head == NULL;
}

void print_list(struct ListStruct *list) {
    struct ListNode *current = list_get_head(list);
    struct ListNode *prev = NULL;

    while (current != NULL) {
        printf("%d ", current->data);
        struct ListNode *next = (struct ListNode *)((uintptr_t)current->xor_ptr ^ (uintptr_t)prev);
        prev = current;
        current = next;
    }
    printf("\n");
}

// Основная функция для тестирования
int main() {
    struct ListStruct my_list;
    my_list.head = NULL;
    my_list.tail = NULL;

    // Пример использования функций списка
    list_push_back(&my_list, 5);
    list_push_back(&my_list, 10);
    list_push_front(&my_list, 1);
    
    printf("Список: ");
    print_list(&my_list);

    printf("Количество элементов: %d\n", list_count(&my_list));

    return 0;
}
