#include <iostream>
#include "../queue/Queue.cpp"
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class MaxHeap {
private:
    TreeNode* root;
    int size;

    void heapifyUp(TreeNode* node, TreeNode* parent) {
        if (!parent || node->val <= parent->val) return;
        std::swap(node->val, parent->val);
        heapifyUp(parent, getParent(parent));
    }

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

    TreeNode* getParent(TreeNode* node) {
        Queue<TreeNode*> q;
        if (!root) return nullptr;
        q.enqueue(root);
        while (!q.isempty()) {
            TreeNode* current = q.get_front();
            q.dequeue();
            if (current->left == node || current->right == node) return current;
            if (current->left) q.enqueue(current->left);
            if (current->right) q.enqueue(current->right);
        }
        return nullptr;
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
        heapifyUp(newNode, getParent(newNode));
    }

    int extractMax() {
        if (!root) throw std::out_of_range("Heap is empty");
        int maxVal = root->val;
        TreeNode* last = getLastNode();
        root->val = last->val;
        TreeNode* parent = getParent(last);
        if (parent && parent->left == last) parent->left = nullptr;
        else if (parent) parent->right = nullptr;
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
