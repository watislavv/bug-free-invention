#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdbool.h>

struct ListNode {
    struct ListNode *next;
    int data; // Поле для данных
};

struct ListStruct {
    struct ListNode *head;
    struct ListNode *tail;
};

// API функций
void list_push_front(struct ListStruct *, int);
void list_push_back(struct ListStruct *, int);
void list_push(struct ListStruct *, struct ListNode *, int);
void list_pop(struct ListStruct *, struct ListNode *);
int list_count(struct ListStruct *);
struct ListNode *list_get_head(struct ListStruct *);
struct ListNode *list_get_tail(struct ListStruct *);
bool list_is_empty(struct ListStruct *);
void list_sort(struct ListStruct *);
void print_list(struct ListStruct *);

#endif // SINGLY_LINKED_LIST_H
