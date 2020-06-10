#include <iostream>
#include "tree.h"

int main(){
    std::cout << "test point 1" << std::endl;
    BinarySearchTree T;
    while(1){
        int key, data;
        std::cin >> key >> data;
        T.insert(Data(key, data));
        std::cout << T << std::endl;
    }
    
    return 0;
}
