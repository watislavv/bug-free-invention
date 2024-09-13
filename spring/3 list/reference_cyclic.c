#include <stdio.h>
#include <stdlib.h>

// Определение структуры узла для циклического списка
struct CyclicListNode {
    struct CyclicListNode *next;
    int data;
};

// Определение структуры списка для циклического списка
struct CyclicListStruct {
    struct CyclicListNode *head;
};

// Функции для циклического списка
void cyclic_list_init(struct CyclicListStruct *list) {
    list->head = NULL;
}

void cyclic_list_destroy(struct CyclicListStruct *list) {
    if (list->head == NULL) return;

    struct CyclicListNode *current = list->head;
    struct CyclicListNode *temp;

    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != list->head);

    list->head = NULL;
}

void cyclic_list_push_front(struct CyclicListStruct *list, int value) {
    struct CyclicListNode *new_node = (struct CyclicListNode *)malloc(sizeof(struct CyclicListNode));
    new_node->data = value;

    if (list->head == NULL) {
        new_node->next = new_node; // Циклический указатель на самого себя
        list->head = new_node;
    } else {
        struct CyclicListNode *tail = list->head;
        while (tail->next != list->head) {
            tail = tail->next; // Находим хвост
        }
        new_node->next = list->head; // Новый узел указывает на голову
        tail->next = new_node; // Хвост указывает на новый узел
        list->head = new_node; // Обновляем голову
    }
}

void cyclic_list_push_back(struct CyclicListStruct *list, int value) {
    struct CyclicListNode *new_node = (struct CyclicListNode *)malloc(sizeof(struct CyclicListNode));
    new_node->data = value;

    if (list->head == NULL) {
        new_node->next = new_node; // Циклический указатель на самого себя
        list->head = new_node;
    } else {
        struct CyclicListNode *tail = list->head;
        while (tail->next != list->head) {
            tail = tail->next; // Находим хвост
        }
        tail->next = new_node; // Хвост указывает на новый узел
        new_node->next = list->head; // Новый узел указывает на голову
    }
}

int cyclic_list_count(struct CyclicListStruct *list) {
    if (list->head == NULL) return 0;

    int count = 0;
    struct CyclicListNode *current = list->head;

    do {
        count++;
        current = current->next;
    } while (current != list->head);

    return count;
}

// Основная функция для проверки работы циклического списка
int main() {
    struct CyclicListStruct cyclic_list;
    cyclic_list_init(&cyclic_list);
    
    cyclic_list_push_front(&cyclic_list, 1);
    cyclic_list_push_back(&cyclic_list, 2);
    
    printf("Циклический список: ");
    
    struct CyclicListNode* current_cyclic = cyclic_list.head;
    
    if (current_cyclic != NULL) {
        do {
            printf("%d ", current_cyclic->data);
            current_cyclic = current_cyclic->next;
        } while (current_cyclic != cyclic_list.head);
        
        printf("\n");
    }

    cyclic_list_destroy(&cyclic_list);
    
    return 0;
}
