#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    struct ListNode *next;
    int data; // Поле для данных
};

struct ListStruct {
    struct ListNode *head;
    struct ListNode *tail;
};

// Функция для добавления элемента в начало списка
void list_push_front(struct ListStruct *list, int value) {
    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->data = value;
    new_node->next = list->head;
    list->head = new_node;

    if (list->tail == NULL) {
        list->tail = new_node; // Если список был пуст, новый элемент также будет хвостом
    }
}

// Функция для добавления элемента в конец списка
void list_push_back(struct ListStruct *list, int value) {
    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->data = value;
    new_node->next = NULL;

    if (list->tail) {
        list->tail->next = new_node;
    } else {
        list->head = new_node; // Если список был пуст, новый элемент становится головой
    }
    list->tail = new_node;
}

// Функция для добавления элемента перед заданным узлом
void list_push(struct ListStruct *list, struct ListNode *node, int value) {
    if (node == NULL) return; // Если узел NULL, ничего не делаем

    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->data = value;

    // Если узел - голова списка
    if (node == list->head) {
        new_node->next = list->head;
        list->head = new_node;
        return;
    }

    // Найдем узел перед данным
    struct ListNode *current = list->head;
    while (current && current->next != node) {
        current = current->next;
    }

    if (current) {
        new_node->next = node;
        current->next = new_node;
    }
}

// Функция для удаления узла из списка
void list_pop(struct ListStruct *list, struct ListNode *node) {
    if (node == NULL || list->head == NULL) return;

    // Если узел - голова списка
    if (node == list->head) {
        list->head = node->next;
        free(node);
        if (list->head == NULL) {
            list->tail = NULL; // Если список стал пустым
        }
        return;
    }

    // Найдем узел перед данным
    struct ListNode *current = list->head;
    while (current && current->next != node) {
        current = current->next;
    }

    if (current) {
        current->next = node->next;
        if (node == list->tail) {
            list->tail = current; // Обновляем хвост, если удаляем его
        }
        free(node);
    }
}

// Функция для подсчета элементов в списке
int list_count(struct ListStruct *list) {
    int count = 0;
    struct ListNode *current = list->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Функция для получения первого элемента списка
struct ListNode *list_get_head(struct ListStruct *list) {
    return list->head;
}

// Функция для получения последнего элемента списка
struct ListNode *list_get_tail(struct ListStruct *list) {
    return list->tail;
}

// Функция для проверки, пуст ли список
bool list_is_empty(struct ListStruct *list) {
    return list->head == NULL;
}

// Функция для сортировки списка (простой алгоритм сортировки вставками)
void list_sort(struct ListStruct *list) {
    if (list_is_empty(list)) return;

    struct ListNode *sorted = NULL; // Начинаем с пустого отсортированного списка
    struct ListNode *current = list->head;

    while (current != NULL) {
        struct ListNode *next = current->next; // Сохраняем следующий узел

        // Вставляем текущий узел в отсортированный список
        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            struct ListNode *temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next; // Переходим к следующему узлу
    }

    list->head = sorted; // Обновляем голову списка
}

// Функция для печати элементов списка
void print_list(struct ListStruct *list) {
    struct ListNode *current = list_get_head(list);
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Основная функция для тестирования
int main() {
    struct ListStruct my_list;
    my_list.head = NULL;
    my_list.tail = NULL;

    // Пример использования функций списка
    list_push_back(&my_list, 5);
    list_push_back(&my_list, 10);
    list_push_front(&my_list, 1);
    
    printf("Список: ");
    print_list(&my_list);

    printf("Количество элементов: %d\n", list_count(&my_list));

    struct ListNode *head = list_get_head(&my_list);
    printf("Первый элемент: %d\n", head ? head->data : -1);

    struct ListNode *tail = list_get_tail(&my_list);
    printf("Последний элемент: %d\n", tail ? tail->data : -1);

    printf("Сортируем список...\n");
    list_sort(&my_list);
    
    printf("Отсортированный список: ");
    print_list(&my_list);

    // Удаляем первый элемент и выводим оставшиеся элементы
    if (head != NULL) {
        printf("Удаляем первый элемент: %d\n", head->data);
        list_pop(&my_list, head);
        printf("Список после удаления: ");
        print_list(&my_list);
    }

    // Освобождение памяти
    while (!list_is_empty(&my_list)) {
        list_pop(&my_list, list_get_head(&my_list));
    }

    return 0;
}