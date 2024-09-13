#include <stdio.h>
#include <stdlib.h>

// Определение структуры узла для односвязного списка
struct SinglyListNode {
    struct SinglyListNode *next;
    int data;
};

// Определение структуры списка для односвязного списка
struct SinglyListStruct {
    struct SinglyListNode *head;
};

// Функции для односвязного списка
void singly_list_init(struct SinglyListStruct *list) {
    list->head = NULL;
}

void singly_list_destroy(struct SinglyListStruct *list) {
    struct SinglyListNode *current = list->head;
    struct SinglyListNode *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    list->head = NULL;
}

void singly_list_push_front(struct SinglyListStruct *list, int value) {
    struct SinglyListNode *new_node = (struct SinglyListNode *)malloc(sizeof(struct SinglyListNode));
    new_node->data = value;

    new_node->next = list->head; // Новый узел указывает на текущую голову
    list->head = new_node; // Обновляем голову
}

void singly_list_push_back(struct SinglyListStruct *list, int value) {
    struct SinglyListNode *new_node = (struct SinglyListNode *)malloc(sizeof(struct SinglyListNode));
    new_node->data = value;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node; // Если список пуст, новый узел становится головой
    } else {
        struct SinglyListNode *current = list->head;
        while (current->next != NULL) {
            current = current->next; // Находим хвост
        }
        current->next = new_node; // Хвост указывает на новый узел
    }
}

int singly_list_count(struct SinglyListStruct *list) {
    int count = 0;
    struct SinglyListNode *current = list->head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

// Основная функция для проверки работы односвязного списка
int main() {
   struct SinglyListStruct singly_list;
   singly_list_init(&singly_list);
   
   singly_list_push_front(&singly_list, 5);
   singly_list_push_back(&singly_list, 6);
   
   printf("Односвязный список: ");
   
   struct SinglyListNode* current_singly = singly_list.head;

   while (current_singly != NULL) {
       printf("%d ", current_singly->data);
       current_singly = current_singly->next;
   }
   
   printf("\n");
   
   singly_list_destroy(&singly_list);

   return 0;
}
