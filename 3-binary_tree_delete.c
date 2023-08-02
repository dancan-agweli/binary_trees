#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: delete the tree
 */
void binary_tree_delete(binary_tree_t *tree)
{
	while (!tree)
		return;
	binary_tree_delete(tree->right);
	binary_tree_delete(tree->left);
	free(tree);
}
