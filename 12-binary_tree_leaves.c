#include "binary_trees.h"

/**
 * binary_tree_leaves - the leaves in a binary tree.
 * @tree: A pointer to the root node
 * Return: leaves in the tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf = 0;

	if (tree)
	{
		leaf += (!tree->left && !tree->right) ? 1 : 0;
		leaf += binary_tree_leaves(tree->left);
		leaf += binary_tree_leaves(tree->right);
	}
	return (leaf);
}
