#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * print_tree - Stores level in an array of
 * @tree: Pointer to the node 
 * @offset: ...
 * @depth: Depth of the node
 * @s: ...
 *
 * Return: length of printed tree after process
 */
static int print_tree(const binary_tree_t *tr, int off, int depth, char **strs)
{
    char buff[6];
    int w, l, r, is_l, i;

    if (!tr)
        return (0);
    is_l = (tr->parent && tr->parent->left == tr);
    w = sprintf(buff, "(%03d)", tr->n);
    l = print_tree(tr->left, off, depth + 1, strs);
    r = print_tree(tr->right, off + l + w, depth + 1, strs);
    for (i = 0; i < w; i++)
        strs[depth][off + l + i] = buff[i];
    if (depth && is_l)
    {
        for (i = 0; i < w + r; i++)
            strs[depth - 1][off + l + w / 2 + i] = '-';
        strs[depth - 1][off + l + w / 2] = '.';
    }
    else if (depth && !is_l)
    {
        for (i = 0; i < l + w; i++)
            strs[depth - 1][off - w / 2 + i] = '-';
        strs[depth - 1][off + l + w / 2] = '.';
    }
    return (l + w + r);
}

/**
 * _height - display height
 * @tree: Pointer to the node to heigh
 * Return: The answer on height
 */
static size_t _height(const binary_tree_t *t)
{
    size_t hl, hr;

    hl = t->left ? 1 + _height(t->left) : 0;
    hr = t->right ? 1 + _height(t->right) : 0;
    return (hl > hr ? hl : hr);
}

/**
 * binary_tree_print - Display  a binary tree
 * @tree: Pointer to the root node
 */
void binary_tree_print(const binary_tree_t *t)
{
    char **s;
    size_t h, i, j;

    if (!t)
        return;
    h = _height(t);
    s = malloc(sizeof(*s) * (h + 1));
    if (!s)
        return;
    for (i = 0; i < h + 1; i++)
    {
        s[i] = malloc(sizeof(**s) * 255);
        if (!s[i])
            return;
        memset(s[i], 32, 255);
    }
    print_tree(t, 0, 0, s);
    for (i = 0; i < h + 1; i++)
    {
        for (j = 254; j > 1; --j)
        {
            if (s[i][j] != ' ')
                break;
            s[i][j] = '\0';
        }
        printf("%s\n", s[i]);
        free(s[i]);
    }
    free(s);
}

