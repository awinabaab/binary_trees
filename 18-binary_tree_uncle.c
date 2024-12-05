#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle of
 *
 * Return: Pointer to the uncle node
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grandparent;

	if (node == NULL ||
			node->parent == NULL ||
			node->parent->parent == NULL)
	{
		return (NULL);
	}
	grandparent = node->parent->parent;
	if (grandparent->left != NULL && grandparent->right != NULL)
	{
		if (node->parent == grandparent->left)
		{
			return (grandparent->right);
		}
		else
		{
			return (grandparent->left);
		}
	}

	return (NULL);
}
