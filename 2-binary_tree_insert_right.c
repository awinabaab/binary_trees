#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: Pointer to the node to insert the right-child in
 * @value: Value to store in the new node
 *
 * Return: Return pointer to created node, or NULL if failure of parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right;

	if (parent == NULL)
	{
		return (NULL);
	}
	right = binary_tree_node(parent, value);
	if (right == NULL)
	{
		return (NULL);
	}
	if (parent->right != NULL)
	{
		right->right = parent->right;
		parent->right->parent = right;
	}
	parent->right = right;

	return (right);
}
