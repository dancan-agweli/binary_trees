#include "binary_trees.h"

/**
 * binary_tree_is_leaf - finds out node is a leaf
 * @node: node to check the tree leaf
 * Return: a true value
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	return ((!node || node->left || node->right) ? 0 : 1);
}
