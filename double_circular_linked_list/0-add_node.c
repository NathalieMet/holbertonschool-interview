#include "list.h"
#include <stdio.h>

/**
 * add_node_end - Adds a new node at the end of a double circular linked list
 * @list: Double pointer to the list head
 * @str: String to be copied into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
    List *new_node, *tail;

    /* Allocate and initialize new node */
    new_node = malloc(sizeof(List));
    if (!new_node)
        return (NULL);
    new_node->str = strdup(str);
    if (!new_node->str)
    {
        free(new_node);
        return (NULL);
    }

    /* If the list is empty */
    if (*list == NULL)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        *list = new_node;
    }
    else
    {
        /* Locate the last node */
        tail = (*list)->prev;

        /* Update pointers to include new node */
        tail->next = new_node;
        new_node->prev = tail;
        new_node->next = *list;
        (*list)->prev = new_node;
    }
    return (new_node);
}

/**
 * add_node_begin - Adds a new node at the beginning of a double circular linked list
 * @list: Double pointer to the list head
 * @str: String to be copied into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
    List *new_node = add_node_end(list, str);

    if (new_node)
        *list = new_node;

    return (new_node);
}
