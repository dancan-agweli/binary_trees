#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes child in a binary tree.
 * @tree: A pointer to the root node
 * Return: sucess
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
    size_t alx = 0;

    if (tree)
    {
        alx += (tree->left || tree->right) ? 1 : 0;
        alx += binary_tree_nodes(tree->left);
        alx += binary_tree_nodes(tree->right);
    }
    return (alx);
}

