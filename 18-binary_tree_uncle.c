#include "binary_trees.h"

/**
 * binary_tree_uncle - Get uncle of a node in binary tree
 * @node: pointer  to find the uncle
 * Return: pointer to the uncle node or NULL if not found
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	while (!node || !node->parent)
		return (NULL);

	return (binary_tree_sibling(node->parent));
}

/**
 * binary_tree_sibling - Get sibling of a node in binary tree
 * @node: pointer to the node to find the sibling
 * Return: pointer to the sibling node or NULL if not found
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}

