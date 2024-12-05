#include "binary_trees.h"

/**
 * _bst_search - Searches for a value in a Binary Search Tree
 * @tree: Pointer to the root node of the BST to search
 * @value: Value to serach in the tree
 *
 * Return: Pointer to the node containing the value being searched
 */

static bst_t *_bst_search(bst_t *tree, int value)
{
	if (tree == NULL || tree->n == value)
	{
		return (tree);
	}

	if (value < tree->n)
	{
		return (_bst_search(tree->left, value));
	}
	return (_bst_search(tree->right, value));
}

/**
 * remove_node_successor - Removes a node from a Binary Search Tree
 * @node: Pointer to the node to be removed
 *
 * Return: Void
 */

static void remove_node_successor(bst_t *node)
{
	bst_t *successor;
	bst_t *temp;

	successor = node->right;

	while (successor->left)
	{
		successor = successor->left;
	}
	node->n = successor->n;
	if (successor->right)
	{
		temp = successor->right;
		if (successor->parent->left == successor)
			successor->parent->left = temp;
		else
			successor->parent->right = temp;
		temp->parent = successor->parent;
	}
	else
	{
		if (successor->parent->left == successor)
			successor->parent->left = NULL;
		else
			successor->parent->right = NULL;
	}
	free(successor);
}

/**
 * remove_node_predecessor - Removes a node from a Binary Search Tree
 * @node: Pointer to the node to be removed
 *
 * Return: Void
 */

static void remove_node_predecessor(bst_t *node)
{
	bst_t *successor;
	bst_t *temp;

	successor = node->left;

	while (successor->right)
	{
		successor = successor->right;
	}
	node->n = successor->n;
	if (successor->left)
	{
		temp = successor->left;
		if (successor->parent->right == successor)
			successor->parent->right = temp;
		else
			successor->parent->left = temp;
		temp->parent = successor->parent;
	}
	else
	{
		if (successor->parent->right == successor)
			successor->parent->right = NULL;
		else
			successor->parent->left = NULL;
	}
	free(successor);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree from which
 * to remove a node
 * @value: The value to remove from the tree
 *
 * Return: Pointer to the new root node of the tree
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *search_node;

	if (root == NULL)
	{
		return (NULL);
	}

	search_node = _bst_search(root, value);
	if (search_node == NULL)
	{
		return (root);
	}
	if (search_node->right)
	{
		remove_node_successor(search_node);
	}
	else if (search_node->left)
	{
		remove_node_predecessor(search_node);
	}
	else
	{
		if (search_node->parent)
		{
			if (search_node->parent->left == search_node)
				search_node->parent->left = NULL;
			else
				search_node->parent->right = NULL;
		}
		else
		{
			root = NULL;
		}
		free(search_node);
	}

	return (root);
}
