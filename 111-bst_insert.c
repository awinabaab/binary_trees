#include "binary_trees.h"

/**
 * bst_insert - Inserts a vlaue in a Binary Search Tree
 * @tree: A pointer to a pointer to the root node of the
 * BST to insert the value in
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the created node, NULL on failure
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new;

	if (tree == NULL)
	{
		return (NULL);
	}
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	if (value < (*tree)->n)
	{
		if ((*tree)->left != NULL)
		{
			return (bst_insert(&(*tree)->left, value));
		}
		new = binary_tree_node(*tree, value);
		return ((*tree)->left = new);
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right != NULL)
		{
			return (bst_insert(&(*tree)->right, value));
		}
		new = binary_tree_node(*tree, value);
		return ((*tree)->right = new);
	}

	return (NULL);
}
