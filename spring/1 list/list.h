/*1. Односвязный список;
Реализовать односвязный список с;
- добавлением элемента в начало списка*/ 
#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

struct ListNode {
    struct ListNode *next;
    // Дополнительные поля для реализации заданного вида
    int value; // Пример поля для данных
};

struct ListStruct {
    struct ListNode *head;
};

// Прототипы функций
void list_push_front(struct ListStruct *, int);
void list_push_back(struct ListStruct *, int);
void list_push(struct ListStruct *, struct ListNode *, int);
void list_pop(struct ListStruct *);
int list_count(struct ListStruct *);
struct ListNode *list_get_head(struct ListStruct *);
struct ListNode *list_get_tail(struct ListStruct *);
bool list_is_empty(struct ListStruct *);
void list_sort(struct ListStruct *);

#endif // LIST_H