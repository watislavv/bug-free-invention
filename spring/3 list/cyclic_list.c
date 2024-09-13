#include <stdlib.h>
#include "cyclic_list.h"

// Инициализация списка
void list_init(struct ListStruct *list) {
    list->head = NULL;
}

// Освобождение памяти
void list_destroy(struct ListStruct *list) {
    if (list_is_empty(list)) return;

    struct ListNode *current = list->head;
    struct ListNode *temp;

    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != list->head);

    list->head = NULL;
}

// Добавление в начало
void list_push_front(struct ListStruct *list, int value) {
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->data = value;

    if (list_is_empty(list)) {
        new_node->next = new_node; // Циклический указатель на самого себя
        list->head = new_node;
    } else {
        struct ListNode *tail = list->head;
        while (tail->next != list->head) {
            tail = tail->next; // Находим хвост
        }
        new_node->next = list->head; // Новый узел указывает на голову
        tail->next = new_node; // Хвост указывает на новый узел
        list->head = new_node; // Обновляем голову
    }
}

// Добавление в конец
void list_push_back(struct ListStruct *list, int value) {
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->data = value;

    if (list_is_empty(list)) {
        new_node->next = new_node; // Циклический указатель на самого себя
        list->head = new_node;
    } else {
        struct ListNode *tail = list->head;
        while (tail->next != list->head) {
            tail = tail->next; // Находим хвост
        }
        tail->next = new_node; // Хвост указывает на новый узел
        new_node->next = list->head; // Новый узел указывает на голову
    }
}

// Удаление указанного узла
void list_pop(struct ListStruct *list, struct ListNode *node) {
    if (node == NULL || list_is_empty(list)) return;

    if (node == list->head && node->next == node) { // Если единственный элемент
        free(node);
        list->head = NULL;
        return;
    }

    struct ListNode *current = list->head;
    while (current->next != node) {
        current = current->next; // Находим узел перед удаляемым
    }

    current->next = node->next; // Удаляем узел из списка

    if (node == list->head) { // Если удаляем голову, обновляем её
        list->head = node->next;
    }

    free(node);
}

// Подсчет узлов
int list_count(struct ListStruct *list) {
    if (list_is_empty(list)) return 0;

    int count = 0;
    struct ListNode *current = list->head;

    do {
        count++;
        current = current->next;
    } while (current != list->head);

    return count;
}

// Получение первого узла
struct ListNode *list_get_head(struct ListStruct *list) {
    return list->head;
}

// Получение последнего узла
struct ListNode *list_get_tail(struct ListStruct *list) {
    if (list_is_empty(list)) return NULL;

    struct ListNode *current = list->head;

    while (current->next != list->head) {
        current = current->next; // Находим хвост
    }

    return current;
}

// Проверка на пустоту
bool list_is_empty(struct ListStruct *list) {
    return list->head == NULL;
}

// Сортировка (например, пузырьком)
void list_sort(struct ListStruct *list) {
    if (list_is_empty(list)) return;

    bool swapped;
    do {
        swapped = false;
        struct ListNode *current = list->head;

        do {
            if (current->data > current->next->data) {
                // Меняем местами данные
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;

                swapped = true;
            }
            current = current->next;
        } while (current != list->head);

    } while (swapped);
}
