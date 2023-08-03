#include "binary_trees.h"

/**
 * binary_tree_size - size of a binary tree
 * @tree: tree to measure
 * Return: size of the tree node
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	while (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
