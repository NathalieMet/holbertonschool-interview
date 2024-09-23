#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * heapify_down - Restores the Max-Heap property from root down
 * @root: double pointer to the root of the heap
 */
void heapify_down(heap_t *root)
{
	heap_t *largest;
	int temp;

	while (root)
	{
		largest = root;
		if (root->left && root->left->n > largest->n)
			largest = root->left;
		if (root->right && root->right->n > largest->n)
			largest = root->right;

		if (largest == root)
			break;

		temp = root->n;
		root->n = largest->n;
		largest->n = temp;

		root = largest;
	}
}

/**
 * enqueue - Helper function to add a node to the queue
 * @queue: double pointer to the queue array
 * @node: node to add
 * @rear: pointer to the current rear of the queue
 */
void enqueue(heap_t **queue, heap_t *node, int *rear)
{
	queue[*rear] = node;
	(*rear)++;
}

/**
 * dequeue - Helper function to remove a node from the queue
 * @queue: double pointer to the queue array
 * @front: pointer to the current front of the queue
 * Return: The node at the front of the queue
 */
heap_t *dequeue(heap_t **queue, int *front)
{
	(*front)++;
	return (queue[*front - 1]);
}

/**
 * get_last_node - Gets the last node in a complete binary tree in level order
 * @root: pointer to the root of the heap
 * Return: pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
	if (root == NULL)
		return (NULL);

	int front = 0, rear = 0;
	heap_t *node = NULL;
	heap_t **queue = malloc(1024 * sizeof(heap_t *));
	/* Dynamically allocate a queue */

	if (!queue)
		return (NULL);

	enqueue(queue, root, &rear);

	/* Perform level-order traversal */
	while (front < rear)
	{
		node = dequeue(queue, &front);

		if (node->left)
			enqueue(queue, node->left, &rear);

		if (node->right)
			enqueue(queue, node->right, &rear);
	}

	free(queue);
	return (node);
	/* The last node encountered is the last node in level-order */
}


/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: The value of the root node
 */
int heap_extract(heap_t **root)
{
	if (!root || !*root)
		return (0);

	int extracted_value = (*root)->n;
	heap_t *last_node = get_last_node(*root);

	if (last_node == *root)
	{
		free(*root);
		*root = NULL;
		return (extracted_value);
	}

	(*root)->n = last_node->n;

	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	free(last_node);

	heapify_down(*root);

	return (extracted_value);
}
