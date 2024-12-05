#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: The number of elements in the array
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree;
	size_t i;

	tree = NULL;
	if (array == NULL || size == 0)
	{
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		bst_insert(&tree, *array);
		array++;
		i++;
	}

	return (tree);
}
