#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer  tree to check
 * Return: answwer
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t a = 0;
    size_t b = 0;
    size_t c = 0;

    if (!tree)
        return (0);

    if (!tree->right && !tree->left)
        return (1);

    a = binary_tree_height(tree);
    b = binary_tree_size(tree);

    c = (size_t)powrecur(2, a + 1);
    return (c - 1 == b);
}

/**
 * powrecur - returns the value of w raised to the power of q
 * @w: the value to exponentiate
 * @q: the power to raise w to
 * Return: w to the power of q, or -1 if q is negative
 */
int powrecur(int w, int q)
{
    if (q < 0)
        return (-1);
    if (q == 0)
        return (1);
    else
        return (w * powrecur(w, q - 1));
}

/**
 * binary_tree_size - the size of a binary tree
 * @tree: tree size
 * Return: size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_height - height of a binary tree
 * @tree: tree height
 * Return: height of the tree
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

