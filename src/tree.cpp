#include "tree.h"

TreeNode::TreeNode(int capacity) : Node(capacity), children_(next_){
    parent_ = nullptr;
}

BinaryTreeNode::BinaryTreeNode(int capacity) : TreeNode(capacity), left_(children_[0]), right_(children_[1]){
    addEdge();
    addEdge();
}

BinarySearchTreeNode::BinarySearchTreeNode() : BinaryTreeNode(1){
    
}

void BinarySearchTreeNode::insert(Data data){
    if(isEmpty()){
        Node::insert(data);
        return;
    }
    if(data < getData()){
        if(left_ != nullptr){
            left_->insert(data);
            return;
        }
        left_ = new BinarySearchTreeNode;
        left_->Node::insert(data);
    }
    else{
        if(right_ != nullptr){
            right_->insert(data);
            return;
        }
        right_ = new BinarySearchTreeNode;
        right_->Node::insert(data);
    }
}

std::ostream &operator<<(std::ostream &out, const Tree &right){
    out << "[\n";
    out << *right.root_;
    out << "\n]";

    return out;
}

Tree::Tree(){
    root_ = nullptr;
    height_ = 0;
}

void Tree::insert(Data data){
    if(root_ == nullptr){
        root_ = new TreeNode();
        root_->Node::insert(data);
        return;
    }
}

Node *Tree::find(int key){
    
}

void Tree::update(int key, int data){

}

void Tree::erase(int key){

}

void Tree::setDepth(){
    root_->setDepth(0);
}

BinaryTree::BinaryTree() : Tree(){

}

void BinaryTree::insert(Data data){

}

BinarySearchTree::BinarySearchTree() : BinaryTree(){

}

void BinarySearchTree::insert(Data data){
    if(root_ == nullptr){
        root_ = new BinarySearchTreeNode();
        root_->Node::insert(data);
        return;
    }
    root_->insert(data);
    setDepth();
}