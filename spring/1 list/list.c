/*1. Односвязный список;
Реализовать односвязный список с;
- добавлением элемента в начало списка*/ 
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Реализация функций

void list_push_front(struct ListStruct *list, int value) {
    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->value = value;
    new_node->next = list->head;
    list->head = new_node;
}

void list_push_back(struct ListStruct *list, int value) {
    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->value = value;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        struct ListNode *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}