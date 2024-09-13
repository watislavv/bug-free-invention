#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct ListNode {
    struct ListNode *next;
    struct ListNode *prev;
    int data;
};

struct ListStruct {
    struct ListNode *head;
    struct ListNode *tail;
};

// Прототипы функций
void list_push_front(struct ListStruct *list, int value);
void list_push_back(struct ListStruct *list, int value);
void list_push(struct ListStruct *list, struct ListNode *prev_node, int value);
void list_pop(struct ListStruct *list, struct ListNode *node);
int list_count(struct ListStruct *list);
struct ListNode *list_get_head(struct ListStruct *list);
struct ListNode *list_get_tail(struct ListStruct *list);
bool list_is_empty(struct ListStruct *list);
void list_sort(struct ListStruct *list);
void list_print(struct ListStruct *list);

int main() {
    struct ListStruct list = {NULL, NULL};
    char command[256];

    while (fgets(command, sizeof(command), stdin)) {
        if (strncmp(command, "push_front", 10) == 0) {
            int value;
            sscanf(command + 11, "%d", &value);
            list_push_front(&list, value);
        } else if (strncmp(command, "push_back", 9) == 0) {
            int value;
            sscanf(command + 10, "%d", &value);
            list_push_back(&list, value);
        } else if (strncmp(command, "push", 4) == 0) {
            int value;
            sscanf(command + 5, "%d", &value);
            // Предполагаем, что указатель на узел передается правильно
            struct ListNode *prev_node = list_get_tail(&list); // Пример
            list_push(&list, prev_node, value);
        } else if (strncmp(command, "pop", 3) == 0) {
            struct ListNode *node_to_remove = list_get_head(&list);
            if (node_to_remove) {
                list_pop(&list, node_to_remove);
            }
        } else if (strncmp(command, "count", 5) == 0) {
            printf("%d\n", list_count(&list));
        } else if (strncmp(command, "is_empty", 8) == 0) {
            printf("%s\n", list_is_empty(&list) ? "true" : "false");
        } else if (strncmp(command, "get_head", 8) == 0) {
            struct ListNode *head = list_get_head(&list);
            printf("%d\n", head ? head->data : -1);
        } else if (strncmp(command, "get_tail", 8) == 0) {
            struct ListNode *tail = list_get_tail(&list);
            printf("%d\n", tail ? tail->data : -1);
        } else if (strncmp(command, "sort", 4) == 0) {
            list_sort(&list);
        } else if (strncmp(command, "print", 5) == 0) {
            list_print(&list);
        }
    }

    return 0;
}
