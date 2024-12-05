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
		return (0);
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
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise, or if tree is NULL
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_height;
	int right_height;

	if (tree == NULL)
	{
		return (0);
	}
	left_height = _binary_tree_height(tree->left);
	right_height = _binary_tree_height(tree->right);

	if (left_height == right_height)
	{
		if (tree->left == NULL && tree->right == NULL)
		{
			return (1);
		}
		if (tree->left != NULL && tree->right != NULL)
		{
			return (binary_tree_is_perfect(tree->left) &&
					binary_tree_is_perfect(tree->right));
		}
	}

	return (0);
}
