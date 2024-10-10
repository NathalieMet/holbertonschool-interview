#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the head of the list
 *
 * Return: The address of the node where the loop starts, or NULL if no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *slow = head, *fast = head;

    if (!head)
        return (NULL);

    /* Detect if there is a loop using the slow and fast pointer approach */
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        /* If slow and fast meet, there's a loop */
        if (slow == fast)
        {
            /* Reset slow to head, and move both one step at a time */
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return (slow); /* This is the start of the loop */
        }
    }

    return (NULL); /* No loop found */
}
