#include <iostream>
#include "../queue/Queue.cpp"

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class MaxHeap {
    TreeNode* root;
    int size;

    void heapifyDown(TreeNode* node) {
        if (!node) return;
        TreeNode* largest = node;
        if (node->left && node->left->val > largest->val)
            largest = node->left;
        if (node->right && node->right->val > largest->val)
            largest = node->right;
        if (largest != node) {
            std::swap(node->val, largest->val);
            heapifyDown(largest);
        }
    }

    TreeNode* getLastNode() {
        if (!root) return nullptr;
        Queue<TreeNode*> q;
        q.enqueue(root);
        TreeNode* last = nullptr;
        while (!q.isempty()) {
            last = q.get_front();
            q.dequeue();
            if (last->left) q.enqueue(last->left);
            if (last->right) q.enqueue(last->right);
        }
        return last;
    }

public:
    MaxHeap() : root(nullptr), size(0) {}

    void update(int new_val) {
        root->val = new_val;
        heapifyDown(root);
    }

    void insert(int value) {
        TreeNode* newNode = new TreeNode(value);
        if (!root) {
            root = newNode;
        } else {
            Queue<TreeNode*> q;
            q.enqueue(root);
            while (!q.isempty()) {
                TreeNode* current = q.get_front();
                q.dequeue();
                if (!current->left) {
                    current->left = newNode;
                    break;
                } else if (!current->right) {
                    current->right = newNode;
                    break;
                }
                q.enqueue(current->left);
                q.enqueue(current->right);
            }
        }
        size++;

        TreeNode* current = newNode;
        while (current != root) {
            TreeNode* parent = nullptr;
            Queue<TreeNode*> q;
            q.enqueue(root);
            while (!q.isempty()) {
                TreeNode* node = q.get_front();
                q.dequeue();
                if (node->left == current || node->right == current) {
                    parent = node;
                    break;
                }
                if (node->left) q.enqueue(node->left);
                if (node->right) q.enqueue(node->right);
            }
            if (parent && parent->val < current->val) {
                std::swap(parent->val, current->val);
                current = parent;
            } else {
                break;
            }
        }
    }

    int pop() {
        if (!root) return -1;
        int maxVal = root->val;
        TreeNode* last = getLastNode();
        root->val = last->val;
        TreeNode* parent = nullptr;
        Queue<TreeNode*> q;
        q.enqueue(root);
        while (!q.isempty()) {
            TreeNode* node = q.get_front();
            q.dequeue();
            if (node->left == last) {
                parent = node;
                parent->left = nullptr;
                break;
            }
            if (node->right == last) {
                parent = node;
                parent->right = nullptr;
                break;
            }
            if (node->left) q.enqueue(node->left);
            if (node->right) q.enqueue(node->right);
        }
        delete last;
        size--;
        if (size == 0) root = nullptr;
        else heapifyDown(root);
        return maxVal;
    }

    int getMax() {
        if (!root) return -1;
        return root->val;
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }
};
