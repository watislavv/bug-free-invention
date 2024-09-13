// list.h
#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

struct ListNode {
    struct ListNode *next;
    // Дополнительные поля для реализации заданного вида
    // Например, для двусвязного списка:
    struct ListNode *prev; // Для двусвязного списка
    int data; // Пример для целочисленного списка
};

struct ListStruct {
    struct ListNode *head;
    struct ListNode *tail;
};

#endif // LIST_H
