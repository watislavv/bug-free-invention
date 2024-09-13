#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "singly_linked_list.h"

// Реализация функций для односвязного списка

void list_push_front(struct ListStruct *list, int value) {
    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->data = value;
    new_node->next = list->head;
    list->head = new_node;

    if (list->tail == NULL) {
        list->tail = new_node; // Если список пуст, новый элемент также будет хвостом
    }
}

void list_push_back(struct ListStruct *list, int value) {
    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->data = value;
    new_node->next = NULL;

    if (list->tail) {
        list->tail->next = new_node;
    } else {
        list->head = new_node; // Если список пуст, новый элемент становится головой
    }
    
    list->tail = new_node;
}

void list_pop(struct ListStruct *list, struct ListNode *node) {
    // Реализация удаления узла из списка
}

int list_count(struct ListStruct *list) {
    int count = 0;
    struct ListNode *current = list->head;

    while (current != NULL) {
        count++;
        current = current->next;
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

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Основная функция для тестирования
int main() {
    struct ListStruct my_list = {NULL, NULL};

    // Пример использования функций списка
    list_push_back(&my_list, 5);
    list_push_back(&my_list, 10);
    list_push_front(&my_list, 1);
    
    printf("List: ");
    print_list(&my_list);

    printf("Count numbers in list: %d\n", list_count(&my_list));

    return 0;
}
