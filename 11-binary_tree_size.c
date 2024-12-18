#include "binary_trees.h"

/**
 * binary_tree_size - Measures the depth of a node in a binary tree
 *
 * @tree: A pointer to the node to measure the depth
 *
 * Return: 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) +
			binary_tree_size(tree->right));
}
