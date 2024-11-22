#include "binary_trees.h"
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * height - Calcule la hauteur d'un arbre binaire
 * @tree: Pointeur vers la racine de l'arbre
 *
 * Return: Hauteur de l'arbre ou -1 si NULL
 */
int height(const binary_tree_t *tree)
{
	if (!tree)
		return (-1);

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
/**
 * binary_tree_is_avl - Vérifie si un arbre est une AVL valide
 * @tree: Pointeur vers la racine de l'arbre
 *
 * Return: 1 si l'arbre est une AVL valide, 0 sinon
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);

	/* Validation BST intégrée */
	if ((tree->left && tree->left->n >= tree->n) ||
		(tree->right && tree->right->n <= tree->n))
		return (0);

	if (tree->left)
	{
		const binary_tree_t *left_max = tree->left;

		while (left_max->right)
			left_max = left_max->right;
		if (left_max->n >= tree->n)
			return (0);
	}

	if (tree->right)
	{
		const binary_tree_t *right_min = tree->right;

		while (right_min->left)
			right_min = right_min->left;
		if (right_min->n <= tree->n)
			return (0);
	}

	/* Calcul des hauteurs */
	left_height = height(tree->left);
	right_height = height(tree->right);

	/* Vérifie l'équilibre des hauteurs */
	if (abs(left_height - right_height) > 1)
		return (0);

	/* Vérifie récursivement les sous-arbres */
	return (binary_tree_is_avl(tree->left) &&
			binary_tree_is_avl(tree->right));
}

/**
 * binary_tree_node - Creates a new binary tree node
 * @parent: Pointer to the parent node
 * @value: Value to be stored in the new node
 *
 * Return: Pointer to the newly created node, or NULL on failure
 */
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
