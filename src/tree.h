/**
 * Tree
 * - Binary Tree
 * -- Binary Search Tree
 * --- AVL Tree
 * --- Red Black Tree
 * - Heap
*/

#ifndef BINARY_TREE
#define BINART_TREE

#include <cstdlib>
#include <ostream>

class BinaryTreeNode{
public:
    BinaryTreeNode();
private:
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    int key;
};

class BinaryTree{
public:
    BinaryTree();
private:
    BinaryTreeNode *root;
};

#endif