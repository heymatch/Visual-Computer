/**
 * Tree
 * - Binary Tree (Linked List)
 * -- Binary Search Tree
 * --- AVL Tree
 * --- Red-Black Tree
 * - Binary Tree (Array)
 * - Heap
 * - Multi-Way Search Tree
 * -- B Tree
 * -- B+ Tree
 */

#ifndef TREE
#define TREE

#include "node.h"

class TreeNode : public Node{
public:
    TreeNode(int capacity = 0);
protected:
    Node *parent_;
    Node **&children_;
};

class BinaryTreeNode : public TreeNode{
public:
    BinaryTreeNode(int capacity = 0);
protected:
    Node *&left_;
    Node *&right_;
};

class BinarySearchTreeNode : public BinaryTreeNode{
public:
    BinarySearchTreeNode();
    void insert(Data data);
protected:
};

class Tree{
    friend std::ostream &operator<<(std::ostream &out, const Tree &right);
public:
    Tree();
    virtual void insert(Data data);
    virtual Node *find(int key);
    virtual void update(int key, int data);
    virtual void erase(int key);

    int getData();
protected:
    Node *root_;
private:
    size_t height_;
};

class BinaryTree : public Tree{
public:
    BinaryTree();
    void insert(Data data);
protected:

};

class BinarySearchTree : public BinaryTree{
public:
    BinarySearchTree();
    void insert(Data data);
protected:

};

#endif