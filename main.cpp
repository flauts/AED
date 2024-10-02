#include <iostream>
#include <cassert>
#include "tree/AVL.cpp"
int main() {
    AVLTree tree;

    // Insert nodes into the AVL tree
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(10);
    tree.insert(25);
    tree.insert(35);
    tree.insert(50);

    // Check heights
    assert(tree.getHeight() == 2); // The height of the root should be 2

    // Check heights of specific nodes
    std::cout << "Root Height: " << tree.height(tree.root) << std::endl; // Should print 2
    std::cout << "Node 20 Height: " << tree.height(tree.root->left) << std::endl; // Should print 1
    std::cout << "Node 40 Height: " << tree.height(tree.root->right) << std::endl; // Should print 1
    std::cout << "Node 10 Height: " << tree.height(tree.root->left->left) << std::endl; // Should print 0
    std::cout << "Node 25 Height: " << tree.height(tree.root->left->right) << std::endl; // Should print 0
    std::cout << "Node 35 Height: " << tree.height(tree.root->right->left) << std::endl; // Should print 0
    std::cout << "Node 50 Height: " << tree.height(tree.root->right->right) << std::endl; // Should print 0

    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}
