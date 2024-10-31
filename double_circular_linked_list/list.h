#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <string.h>

/**
 * struct List - A double circular linked list node
 * @str: The string data stored in the node
 * @prev: Pointer to the previous node
 * @next: Pointer to the next node
 */
typedef struct List
{
    char *str;
    struct List *prev;
    struct List *next;
} List;

List *add_node_end(List **list, char *str);
List *add_node_begin(List **list, char *str);

#endif /* LIST_H */
