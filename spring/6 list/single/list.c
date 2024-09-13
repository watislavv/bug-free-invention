// list.c
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"

void list_push_front(struct ListStruct *list, int value) {
    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->data = value;
    new_node->next = list->head;
    list->head = new_node;
    if (list->tail == NULL) {
        list->tail = new_node;
    }
}

void list_push_back(struct ListStruct *list, int value) {
    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->data = value;
    new_node->next = NULL;
    if (list->tail) {
        list->tail->next = new_node;
    } else {
        list->head = new_node;
    }
    list->tail = new_node;
}


