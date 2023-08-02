#include "binary_trees.h"

/**
 * binary_tree_insert_right - the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the node
 * Return: Pointer to success
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *buff;

	while (!parent)
		return (NULL);

	buff = malloc(sizeof(binary_tree_t));
	if (!buff)
		return (NULL);

	buff->n = value;
	buff->parent = parent;
	buff->left = NULL;
	buff->right = parent->right;
	parent->right = buff;
	if (buff->right)
		buff->right->parent = buff;
	return (buff);
}

