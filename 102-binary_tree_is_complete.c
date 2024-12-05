#include "binary_trees.h"

/**
 * create_queue - Allocates memory for a queue
 *
 * Return: Pointer to a queue
 */

queue_t *create_queue(void)
{
	queue_t *queue;

	queue = malloc(sizeof(queue_t));
	if (queue == NULL)
	{
		return (NULL);
	}
	queue->front = NULL;
	queue->back = NULL;

	return (queue);
}

/**
 * enqueue - Adds a node to a queue
 * @queue: Pointer to queue
 * @node: Pointer to binary tree node
 *
 * Return: 0 if successful
 */

int enqueue(queue_t *queue, const binary_tree_t *node)
{
	q_node_t *new;

	if (queue == NULL || node == NULL)
	{
		return (-1);
	}
	new = malloc(sizeof(q_node_t));
	if (new == NULL)
	{
		return (-1);
	}
	new->node = node;
	new->next = NULL;

	if (queue->back == NULL)
	{
		queue->front = new;
		queue->back = new;
	}
	else
	{
		queue->back->next = new;
		queue->back = new;
	}

	return (0);
}

/**
 * dequeue - Removes a node from a queue
 * @queue: Pointer to queue
 *
 * Return: Pointer to binary tree node
 */

binary_tree_t *dequeue(queue_t *queue)
{
	q_node_t *temp;
	const binary_tree_t *node;

	if (queue == NULL || queue->front == NULL)
	{
		return (NULL);
	}
	temp = queue->front;
	node = temp->node;
	queue->front = queue->front->next;

	if (queue->front == NULL)
	{
		queue->back = NULL;
	}
	free(temp);

	return ((binary_tree_t *)node);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if complete, 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_t *queue;
	const binary_tree_t *temp;
	int leaf_node_flag;

	leaf_node_flag = 0;
	if (tree == NULL)
		return (0);
	queue = create_queue();
	if (queue == NULL)
		return (0);
	if (enqueue(queue, tree) == -1)
	{
		free(queue);
		return (0);
	}

	while (queue->front != NULL)
	{
		temp = dequeue(queue);
		if (temp == NULL)
			continue;
		if (temp->right && !temp->left)
		{
			while (queue->front != NULL)
				dequeue(queue);
			free(queue);
			return (0);
		}
		if (leaf_node_flag && (temp->left || temp->right))
		{
			while (queue->front != NULL)
				dequeue(queue);
			free(queue);
			return (0);
		}
		if (!temp->left || !temp->right)
			leaf_node_flag = 1;
		if (temp->left && enqueue(queue, temp->left) == -1)
		{
			while (queue->front != NULL)
				dequeue(queue);
			free(queue);
			return (0);
		}
		if (temp->right && enqueue(queue, temp->right) == -1)
		{
			while (queue->front != NULL)
				dequeue(queue);
			free(queue);
			return (0);
		}
	}
	while (queue->front != NULL)
		dequeue(queue);
	free(queue);

	return (1);
}
