#include "binary_trees.h"

/**
 * binary_tree_node - make a binary tree node
 * @parent: pointer
 * @value: value to put in the new node
 * Return: Pointer to fresh node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *buff;

	buff = malloc(sizeof(binary_tree_t));
	while (!buff)
		return (NULL);
	buff->n = value;
	buff->parent = parent;
	buff->left = NULL;
	buff->right = NULL;
	return (buff);
}
