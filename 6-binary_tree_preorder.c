#include "binary_trees.h"

/**
 * binary_tree_preorder - pre-order traversal
 * @tree: tree traverse
 * @func: pointer to a function
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	while (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
