#include "binary_trees.h"
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * height - Computes the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree or 0 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int left_height = height(tree->left);
	int right_height = height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree
 * @min: Minimum allowable value for the current node
 * @max: Maximum allowable value for the current node
 *
 * Return: 1 if the tree is a valid BST, otherwise 0
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (is_bst(tree->left, min, tree->n) &&
			is_bst(tree->right, tree->n, max));
}

/**
 * is_balanced - Checks if a binary tree is balanced
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is balanced, otherwise 0
 */
int is_balanced(const binary_tree_t *tree)
{
	int lh, rh;

	if (!tree)
		return (1);

	lh = height(tree->left);
	rh = height(tree->right);

	if (abs(lh - rh) > 1)
		return (0);

	return (is_balanced(tree->left) && is_balanced(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid AVL tree, otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	int balance_factor;
	int left_is_avl;
	int right_is_avl;

	int left_height = height(tree->left);
	int right_height = height(tree->right);

	balance_factor = left_height - right_height;
	if (balance_factor < -1 || balance_factor > 1)
		return (0);

	left_is_avl = binary_tree_is_avl(tree->left);
	right_is_avl = binary_tree_is_avl(tree->right);

	return (left_is_avl && right_is_avl);
}

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
