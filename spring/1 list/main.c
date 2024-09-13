/*1. Односвязный список;
Реализовать односвязный список с;
- добавлением элемента в начало списка*/ 
#include <stdio.h>
#include "list.h"

int main() {
    struct ListStruct list = {NULL};
    char command[100];
    
    while (fgets(command, sizeof(command), stdin)) {
        int value;
        if (sscanf(command, "push_front %d", &value) == 1) {
            list_push_front(&list, value);
        } else if (sscanf(command, "push_back %d", &value) == 1) {
            list_push_back(&list, value);
        } else if (strcmp(command, "count\n") == 0) {
            printf("Count: %d\n", list_count(&list));
        } else if (strcmp(command, "is_empty\n") == 0) {
            printf("Is empty: %s\n", list_is_empty(&list) ? "true" : "false");
        }
        // Другие команды...
    }
    
    return 0;
}