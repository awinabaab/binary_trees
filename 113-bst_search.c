#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree
 * @tree: Pointer to the root node of the BST to search
 * @value: Value to serach in the tree
 *
 * Return: Pointer to the node containing the value being searched
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
	{
		return (NULL);
	}

	if (value == tree->n)
	{
		return ((bst_t *)tree);
	}
	if (value < tree->n)
	{
		if (tree->left != NULL)
		{
			return (bst_search(tree->left, value));
		}
	}
	if (value > tree->n)
	{
		if (tree->right != NULL)
		{
			return (bst_search(tree->right, value));
		}
	}

	return (NULL);
}
