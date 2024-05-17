#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *current;

    // Allocate memory for the new node
    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    // Initialize the new node
    new->n = number;
    new->next = NULL;

    // Handle the case where the list is empty or the new node should be the new head
    if (*head == NULL || (*head)->n >= number)
    {
        new->next = *head;
        *head = new;
        return (new);
    }

    // Traverse the list to find the insertion point
    current = *head;
    while (current->next != NULL && current->next->n < number)
    {
        current = current->next;
    }

    // Insert the new node at the correct position
    new->next = current->next;
    current->next = new;

    return (new);
}
