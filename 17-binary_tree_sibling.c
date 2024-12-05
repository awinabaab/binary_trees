#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 *
 * @node: A pointer to the node to find the sibling
 *
 * Return: A pointer to the sibling node otherwise NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node && node->parent)
	{
		if (node == node->parent->left)
			return (node->parent->right);
		if (node == node->parent->right)
			return (node->parent->left);
	}

	return (NULL);
}
