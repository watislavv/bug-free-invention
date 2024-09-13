#include <stdio.h>
#include "cyclic_list.h"

int main() {
    struct ListStruct myList;
    list_init(&myList);

    char command[256];
    
    while (true) {
        printf("Введите команду: ");
        scanf("%s", command);

        if (strcmp(command, "push_front") == 0) {
            int value;
            scanf("%d", &value);
            list_push_front(&myList, value);
        } else if (strcmp(command, "push_back") == 0) {
            int value;
            scanf("%d", &value);
            list_push_back(&myList, value);
        } else if (strcmp(command, "count") == 0) {
            printf("Количество элементов: %d\n", list_count(&myList));
        } else if (strcmp(command, "get_head") == 0) {
            struct ListNode* head = list_get_head(&myList);
            if (head) printf("Первый элемент: %d\n", head->data);
            else printf("Список пуст.\n");
        } else if (strcmp(command, "get_tail") == 0) {
            struct ListNode* tail = list_get_tail(&myList);
            if (tail) printf("Последний элемент: %d\n", tail->data);
            else printf("Список пуст.\n");
        } else if (strcmp(command, "is_empty") == 0) {
            printf("Список %s\n", list_is_empty(&myList) ? "пуст" : "не пуст");
        } else if (strcmp(command, "sort") == 0) {
            list_sort(&myList);
            printf("Список отсортирован.\n");
        } else if (strcmp(command, "exit") == 0) {
            break;
        }
        
        // Вывод списка для проверки корректности
        printf("Текущий список: ");
        struct ListNode* current = myList.head;
        if (current != NULL) {
            do {
                printf("%d ", current->data);
                current = current->next;
            } while (current != myList.head);
            printf("\n");
        } else {
            printf("пуст\n");
        }
    }

    list_destroy(&myList);
    
    return 0;
}
