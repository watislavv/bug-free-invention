// main.c для односвязного списка

// main.c
#include <stdio.h>
#include "list.h"

int main() {
    struct ListStruct list = {NULL, NULL};
    char command[256];
    
    while (fgets(command, sizeof(command), stdin)) {
        // Разбор команды и вызов соответствующей функции
        // Например:
        if (strncmp(command, "push_front", 10) == 0) {
            int value;
            sscanf(command + 11, "%d", &value);
            list_push_front(&list, value);
        }
        // Другие команды...
        
        // Вывод состояния списка
        // ...
    }
    
    return 0;
}

