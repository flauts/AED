#include <algorithm>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    int bf;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val):val(val),left(nullptr),right(nullptr),bf(0){};
};

class AVL{
    TreeNode* root;

    int height(TreeNode* root) {
        if(root == nullptr) return -1;
        return 1 + max(height(root->left),height(root->right));
    }
    TreeNode* leftRotation(TreeNode* root) {
        pair<TreeNode*,TreeNode*> third_pair = pair(root->right->left,root->right->right);
        auto old_root = root;
        root = root->right;
        root->left = old_root;
        root->left->right = third_pair.first;
        return root;
    }

    TreeNode* rightRotation(TreeNode* root) {
        pair<TreeNode*,TreeNode*> third_pair = pair(root->left->left,root->left->right);
        auto old_root = root;
        root = root->left;
        root->right = old_root;
        root->right->left = third_pair.second;
        return root;
    }

    TreeNode* rightLeftRotation(TreeNode* root) {
       root->right = rightRotation(root->right);
       root =  leftRotation(root);
        return root;
    }

    TreeNode* leftRightRotation(TreeNode* root) {
        // auto old_root = root;
        // root = root->left->right;
        // root->left = old_root->left;
        // root->right = old_root;
        // old_root->left = nullptr;
        root->left = leftRotation(root->left);
        root = rightRotation(root);
        return root;
    }

    TreeNode* balance(TreeNode* root) {
        if(root->bf < 0) {
            if(root->right->bf < 0) {
                root = leftRotation(root);
            }
            else {
             root = rightLeftRotation(root);
                //right left rotation
            }
        }
        else {
            if(root->left->bf > 0) {
               root = rightRotation(root);
            }
            else {
              root =  leftRightRotation(root);
            }
        }
    return root;
    }

    TreeNode* insert(TreeNode* root, const int& val) {
        if (root == nullptr) return new TreeNode(val);
        if(root->val > val) root->left = insert(root->left,val);
        else if (root->val < val) root->right = insert(root->right, val);
        else return root;
        int height_left = height(root->left) + 1;
        int height_right = height(root->right) + 1;

        root->bf = height_left - height_right;

        if(abs(root->bf) > 1) {
           root =  balance(root);
        }
        return root;
    }


    void print(TreeNode* root) {
        if(root == nullptr) return;
        for(int i = 0; i < height(root)+1;i++) {
            cout<<" ";
        }
        if (root->left != nullptr) cout<<root->left->val;
        for(int i = 0; i < height(root)+1;i++) {
            cout<<" ";
        }
        if(root->right != nullptr) cout<<root->right->val;
        cout<<endl;
        print(root->left);
        print(root->right);
    }
public:
    AVL():root(nullptr){}
    void insert(const int& val) {
        if(root == nullptr) root = new TreeNode(val);
        else root = insert(root,val);
    }

    void print() {
        for(int i = 0; i < 2*height(root)+1;i++) {
            cout<<" ";
        }
        cout<<root->val;
        for(int i = 0; i < 2*height(root)+1;i++) {
            cout<<" ";
        }
        cout<<endl;
        print(root);
    }

};