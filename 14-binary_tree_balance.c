#include "binary_trees.h"

/**
 * _binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height of
 *
 * Return: Height, 0 if tree is NULL
 */

static int _binary_tree_height(const binary_tree_t *tree)
{
	int left_height;
	int right_height;

	if (tree == NULL)
	{
		return (-1);
	}
	left_height = _binary_tree_height(tree->left);
	right_height = _binary_tree_height(tree->right);

	if (left_height > right_height)
	{
		return (left_height + 1);
	}
	else
	{
		return (right_height + 1);
	}
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance
 * factor of
 *
 * Return: Balance factor, 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height;
	int right_height;

	if (tree == NULL)
	{
		return (0);
	}
	left_height = _binary_tree_height(tree->left);
	right_height = _binary_tree_height(tree->right);

	return (left_height - right_height);
}
