#include "binary_trees.h"

/**
 * binary_tree_balance - the balance a binary tree
 * @tree: pointer to the root node
 * Return: the success on balance
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int a, c;

	if (!tree)

		return (0);

	a = tree->left ? (int)binary_tree_height(tree->left) : -1;
	c = tree->right ? (int)binary_tree_height(tree->right) : -1;

	return (a - c);
}

/**
 * binary_tree_height - the height of a binary tree
 * @tree: tree to scale
 * Return: height of tree to be answer
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t a = 0;
	size_t b = 0;

	if (!tree)
		return (0);

	a = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	b = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (a > b ? a : b);
}
