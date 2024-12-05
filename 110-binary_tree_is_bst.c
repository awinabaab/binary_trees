#include "binary_trees.h"

/**
 * bst_check - Compares values of nodes to validate BST status
 * @tree: Pointer to the root node of the tree
 * @min: Lower limit of tree and right subtree
 * @max: Upper limit of tree and left subtree
 *
 * Return: 1 if valid BST, 0 otherwise
 */

static int bst_check(const binary_tree_t *tree, const binary_tree_t *min,
		const binary_tree_t *max)
{
	if (tree == NULL)
	{
		return (1);
	}
	if ((min != NULL && tree->n <= min->n) ||
			(max != NULL && tree->n >= max->n))
		return (0);
	return (bst_check(tree->left, min, tree) &&
			bst_check(tree->right, tree, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BInary Search Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if valid BST, 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (bst_check(tree, NULL, NULL));
}
