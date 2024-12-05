#include "binary_trees.h"

/**
 * binary_tree_is_full - Measures tha balance factor of a binary tree
 *
 * @tree: A pointer to the root node of the tree to measure the balance factor
 *
 * Return: 0 if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) &&
				binary_tree_is_full(tree->right));

	return (0);
}
