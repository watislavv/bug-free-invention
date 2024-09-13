/* - Реализуйте следующие функции для работы со списком:
     - void list_push_front(struct ListStruct *, int value);
     - void list_push_back(struct ListStruct *, int value);
     - void list_push(struct ListStruct *, struct ListNode *, int value);
     - void list_pop(struct ListStruct *, struct ListNode *);
     - int list_count(struct ListStruct *);
     - struct ListNode *list_get_head(struct ListStruct *);
     - struct ListNode *list_get_tail(struct ListStruct *);
     - bool list_is_empty(struct ListStruct *);
     - void list_sort(struct ListStruct *); */
#include <stdlib.h>
#include "list.h"
#include <stdbool.h>

// Определение структур
struct ListNode {
    struct ListNode *prev;
    struct ListNode *next;
    int data;
};

struct ListStruct {
    struct ListNode *head;
    struct ListNode *tail;
};

// Реализация функций API
void list_push_front(struct ListStruct *list, int value) {
    // Реализация
}

void list_push_back(struct ListStruct *list, int value) {
    // Реализация
}

void list_pop(struct ListStruct *list, struct ListNode *node) {
    // Реализация
}

int list_count(struct ListStruct *list) {
    // Реализация
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

void list_sort(struct ListStruct *list) {
    // Реализация сортировки
}
