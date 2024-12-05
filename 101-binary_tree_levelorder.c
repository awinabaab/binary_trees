#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: A pointer to the root node of the tree to measure
 *
 * Return: 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (!tree)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_levelorder - Binary tree trversal using level-order traversal
 *
 * @tree: A pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int level;
	int height;

	height = binary_tree_height(tree);

	if (tree && func)
		for (level = 0; level <= height; level++)
			_print(tree, func, level);
}

/**
 * _print - Prints all nodes at given level
 *
 * @tree: A pointer to the root node of the tree
 * @func: A pointer to the function to call for each node
 * @level: Level to print the nodes from
 */
void _print(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree)
	{
		if (level == 0)
			func(tree->n);
		else
		{
			_print(tree->left, func, level - 1);
			_print(tree->right, func, level - 1);
		}
	}
}
