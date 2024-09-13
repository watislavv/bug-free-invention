#include <stdio.h>
#include <stdlib.h>

// Определение структуры узла для двусвязного списка
struct DoublyListNode {
    struct DoublyListNode *prev;
    struct DoublyListNode *next;
    int data;
};

// Определение структуры списка для двусвязного списка
struct DoublyListStruct {
    struct DoublyListNode *head;
    struct DoublyListNode *tail;
};

// Функции для двусвязного списка
void doubly_list_init(struct DoublyListStruct *list) {
    list->head = NULL;
    list->tail = NULL;
}

void doubly_list_destroy(struct DoublyListStruct *list) {
    struct DoublyListNode *current = list->head;
    struct DoublyListNode *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    list->head = NULL;
    list->tail = NULL;
}void doubly_list_push_front(struct DoublyListStruct *list, int value) {
    struct DoublyListNode *new_node = (struct DoublyListNode *)malloc(sizeof(struct DoublyListNode));
    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = list->head;

    if (list->head != NULL) {
        list->head->prev = new_node;
    } else {
        list->tail = new_node; // Если список был пуст, новый узел становится хвостом
    }

    list->head = new_node; // Обновляем голову
}

void doubly_list_push_back(struct DoublyListStruct *list, int value) {
    struct DoublyListNode *new_node = (struct DoublyListNode *)malloc(sizeof(struct DoublyListNode));
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

int doubly_list_count(struct DoublyListStruct *list) {
    int count = 0;
    struct DoublyListNode *current = list->head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

// Основная функция для проверки работы двусвязного списка
int main() {
    struct DoublyListStruct doubly_list;
    doubly_list_init(&doubly_list);
    
    doubly_list_push_front(&doubly_list, 3);
    doubly_list_push_back(&doubly_list, 4);
    
    printf("Двусвязный список: ");
    
    struct DoublyListNode* current_doubly = doubly_list.head;

    while (current_doubly != NULL) {
        printf("%d ", current_doubly->data);
        current_doubly = current_doubly->next;
    }
    
    printf("\n");
    
    doubly_list_destroy(&doubly_list);
    
    return 0;
}
