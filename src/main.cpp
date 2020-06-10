#include <iostream>
#include "tree.h"

int main(){
    BinarySearchTreeNode n;
    //std::cout << "test point 1" << std::endl;
    n.insert(Data(5, 12));
    n.insert(Data(7, 1));
    n.insert(Data(1, 1));
    std::cout << n << std::endl;
    BinarySearchTree T;
    T.insert(Data(1, 2));
    //T.insert(Data(2, 6));
    std::cout << T << std::endl;
    return 0;
}