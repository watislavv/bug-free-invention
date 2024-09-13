// sparse_list.c
#include "sparse_list.h"
#include <stdlib.h>

void list_push_front(struct ListStruct *list, int value) {
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->data = value;
    new_node->next = list->head;
    new_node->prev = NULL;

    if (list->head != NULL) {
        list->head->prev = new_node;
    } else {
        list->tail = new_node; // Если список был пуст, новый узел становится хвостом
    }

    list->head = new_node; // Обновляем голову
}

void list_push_back(struct ListStruct *list, int value) {
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->data = value;
    new_node->next = NULL;

    if (list->tail != NULL) {
        list->tail->next = new_node;
        new_node->prev = list->tail;
    } else {
        new_node->prev = NULL; // Если список был пуст, новый узел становится головой
        list->head = new_node;
    }

    list->tail = new_node; // Обновляем хвост
}

void list_pop(struct ListStruct *list, struct ListNode *node) {
    if (node == NULL) return;

    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        list->head = node->next; // Удаляем голову
    }

    if (node->next != NULL) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev; // Удаляем хвост
    }

    free(node);
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

// Сортировка и другие функции могут быть добавлены по аналогии.