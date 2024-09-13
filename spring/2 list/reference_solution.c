#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    struct ListNode *next;
    struct ListNode *prev;
    int data;
};

struct ListStruct {
    struct ListNode *head;
    struct ListNode *tail;
};

// Создание нового узла
struct ListNode* create_node(int value) {
    struct ListNode *new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Добавление элемента в начало списка
void list_push_front(struct ListStruct *list, int value) {
    struct ListNode *new_node = create_node(value);
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }
}

// Добавление элемента в конец списка
void list_push_back(struct ListStruct *list, int value) {
    struct ListNode *new_node = create_node(value);
    if (list->tail == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

// Добавление элемента после указанного узла
void list_push(struct ListStruct *list, struct ListNode *prev_node, int value) {
    if (prev_node == NULL) return; // Если предыдущий узел не существует
    struct ListNode *new_node = create_node(value);
    new_node->next = prev_node->next;
    new_node->prev = prev_node;

    if (prev_node->next != NULL) {
        prev_node->next->prev = new_node;
    } else {
        list->tail = new_node; // Если добавляем в конец
    }
    
    prev_node->next = new_node;
}

// Удаление указанного узла
void list_pop(struct ListStruct *list, struct ListNode *node) {
    if (node == NULL) return;

    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        list->head = node->next; // Если удаляем голову
    }

    if (node->next != NULL) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev; // Если удаляем хвост
    }

    free(node);
}

// Подсчет количества элементов в списке
int list_count(struct ListStruct *list) {
    int count = 0;
    struct ListNode *current = list->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Получение головы списка
struct ListNode *list_get_head(struct ListStruct *list) {
    return list->head;
}

// Получение хвоста списка
struct ListNode *list_get_tail(struct ListStruct *list) {
    return list->tail;
}

// Проверка, пуст ли список
bool list_is_empty(struct ListStruct *list) {
    return list->head == NULL;
}

// Сортировка списка (сортировка вставками)
void list_sort(struct ListStruct *list) {
    if (list_is_empty(list)) return;

    struct ListNode *current = list->head->next;
    
    while (current != NULL) {
        struct ListNode *key = current;
        current = current->next;

        struct ListNode *j = key->prev;

        while (j != NULL && j->data > key->data) {
            j = j->prev;
        }

        if (key != j && j != key->prev) {
            // Удаляем узел из текущего места
            if (key->prev != NULL) key->prev->next = key->next;
            if (key->next != NULL) key->next->prev = key->prev;

            // Вставляем узел на новое место
            if (j == NULL) {
                // Вставка в начало
                key->next = list->head;
                key->prev = NULL;
                if (list->head != NULL) list->head->prev = key;
                list->head = key;
            } else {
                key->next = j->next;
                key->prev = j;

                if (j->next != NULL) j->next->prev = key;
                j->next = key;
                if (j == list->tail) {
                    list->tail = key; // Обновляем хвост, если нужно
                }
            }
        }
    }
}

// Печать элементов списка для отладки
void list_print(struct ListStruct *list) {
    struct ListNode *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Пример использования
int main() {
    struct ListStruct list = {NULL, NULL};

    // Примеры операций
    list_push_back(&list, 10);
    list_push_back(&list, 20);
    list_push_front(&list, 5);
    
    printf("Содержимое списка: ");
    list_print(&list);

    printf("Количество элементов: %d\n", list_count(&list));
    
    struct ListNode *head = list_get_head(&list);
    printf("Головной элемент: %d\n", head ? head->data : -1);

    struct ListNode *tail = list_get_tail(&list);
    printf("Хвостовой элемент: %d\n", tail ? tail->data : -1);

    printf("Удаляем голову...\n");
    list_pop(&list, head);
    
    printf("Содержимое списка после удаления головы: ");
    list_print(&list);

    printf("Сортируем список...\n");
    list_push_back(&list, 15);
    list_push_back(&list, 25);
    
    printf("Содержимое списка до сортировки: ");
    list_print(&list);
    
    list_sort(&list);
    
    printf("Содержимое списка после сортировки: ");
    list_print(&list);

    return 0;
}
