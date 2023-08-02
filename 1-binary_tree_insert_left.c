#include "binary_trees.h"

/**
 * binary_tree_insert_left - assert new node
 * @parent: pointer to the node
 * @value: value to store in the node
 * Return: answer always
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *buff;

	if (!parent)
		return (NULL);

	buff = malloc(sizeof(binary_tree_t));
	if (!buff)
		return (NULL);

	buff->n = value;
	buff->parent = parent;
	buff->right = NULL;
	buff->left = parent->left;
	parent->left = buff;
	if (buff->left)
		buff->left->parent = buff;
	return (buff);
}

