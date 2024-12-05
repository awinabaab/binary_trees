#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 *
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor, otherwise NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *first_node;
	const binary_tree_t *second_node;

	if (first && second)
	{
		first_node = first;
		while (first_node)
		{
			second_node = second;
			while (second_node)
			{
				if (first_node == second_node)
					return ((binary_tree_t *)first_node);
				second_node = second_node->parent;
			}
			first_node = first_node->parent;
		}
	}

	return (NULL);
}
