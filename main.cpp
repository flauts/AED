#include <iostream>
#include <string>

#include "tree/BST.cpp"



int main() {
    BSTree<int> tree;
    tree.insert(3);
    tree.insert(9);
    tree.insert(20);
    tree.insert(15);
    tree.insert(7);

    std::cout<<tree.is_equilibrated();


}