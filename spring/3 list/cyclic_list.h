#ifndef CYCLIC_LIST_H
#define CYCLIC_LIST_H

#include <stdbool.h>

struct ListNode {
    struct ListNode *next;
    int data;
};

struct ListStruct {
    struct ListNode *head;
};

// API функций
void list_init(struct ListStruct *list);
void list_destroy(struct ListStruct *list);
void list_push_front(struct ListStruct *list, int value);
void list_push_back(struct ListStruct *list, int value);
void list_push(struct ListStruct *list, struct ListNode *prev_node, int value);
void list_pop(struct ListStruct *list, struct ListNode *node);
int list_count(struct ListStruct *list);
struct ListNode *list_get_head(struct ListStruct *list);
struct ListNode *list_get_tail(struct ListStruct *list);
bool list_is_empty(struct ListStruct *list);
void list_sort(struct ListStruct *list);

#endif // CYCLIC_LIST_H