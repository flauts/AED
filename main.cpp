#include <iostream>
#include <queue>
#include <iomanip>

// Assuming the AVLTree class is in a header file named "avl_tree.h"
#include <cmath>

#include "tree/AVL.cpp"
void printTree(TreeNode* root) {
    if (root == nullptr) return;

    int height = root->height + 1;
    int width = (1 << height) - 1;
    std::vector<std::vector<std::string>> levels(height, std::vector<std::string>(width, " "));

    std::queue<std::pair<TreeNode*, std::pair<int, int>>> q;
    q.push({root, {0, width / 2}});

    while (!q.empty()) {
        auto node_info = q.front();
        q.pop();

        TreeNode* node = node_info.first;
        int level = node_info.second.first;
        int pos = node_info.second.second;

        levels[level][pos] = std::to_string(node->val) + "(" + std::to_string(node->height) + ")";

        if (node->left) {
            q.push({node->left, {level + 1, pos - std::pow(2, height - level - 2)}});
        }
        if (node->right) {
            q.push({node->right, {level + 1, pos + std::pow(2, height - level - 2)}});
        }
    }

    for (const auto& level : levels) {
        for (const auto& node : level) {
            std::cout << std::setw(5) << node;
        }
        std::cout << std::endl;
    }
}


void levelOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            std::cout << node->val << "(" << node->height << ") ";

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        std::cout << std::endl;
    }
}

int main() {
    AVLTree avl;

    // Test case 1: Inserting in ascending order
    std::cout << "Test case 1: Inserting in ascending order" << std::endl;
    for (int i = 1; i <= 7; i++) {
        avl.insert(i);
        std::cout << "After inserting " << i << ":" << std::endl;
        printTree(avl.getRoot());
        std::cout << "\nLevel order traversal:" << std::endl;
        levelOrderTraversal(avl.getRoot());
        std::cout << "\n------------------------" << std::endl;
    }

    // Test case 2: Inserting in descending order
    AVLTree avl2;
    std::cout << "Test case 2: Inserting in descending order" << std::endl;
    for (int i = 7; i >= 1; i--) {
        avl2.insert(i);
        std::cout << "After inserting " << i << ":" << std::endl;
        printTree(avl2.getRoot());
        std::cout << "\nLevel order traversal:" << std::endl;
        levelOrderTraversal(avl2.getRoot());
        std::cout << "\n------------------------" << std::endl;
    }

    // Test case 3: Mixed insertions
    AVLTree avl3;
    std::cout << "Test case 3: Mixed insertions" << std::endl;
    int mixed[] = {4, 2, 6, 1, 3, 5, 7};
    for (int i : mixed) {
        avl3.insert(i);
        std::cout << "After inserting " << i << ":" << std::endl;
        printTree(avl3.getRoot());
        std::cout << "\nLevel order traversal:" << std::endl;
        levelOrderTraversal(avl3.getRoot());
        std::cout << "\n------------------------" << std::endl;
    }

    return 0;
}