#include "binary_trees.h"

/**
 * binary_tree_is_root - node is a root
 * @node: node to check the roots
 * Return: sucess
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return ((node == 0 || node->parent) ? 0 : 1);
}
