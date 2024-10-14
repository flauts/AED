// #include "parcial/Graph.cpp"
#include <iostream>
#include <vector>
using namespace std;
// int main() {
//     int edges[10][3] = {{1,2,1},{2,3,2},{3,4,1},{4,5,1},
//     {5,6,4},{6,7,2},{7,8,1},{8,9,2},{1,9,1},{0,8,1}};
//     Graph graph(10,edges);
//     int edge[3] = {2,9,2};
//     graph.addEdge(edge);
//     int edge1[3] = {1,5,1};
//     graph.addEdge(edge1);
//     cout<<graph.shortestPath(2,5);
//
// }

struct Node {
    int val;
    Node* next;
    Node(int val):val(val),next(nullptr){}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val):val(val),left(nullptr),right(nullptr){}
};

TreeNode* binaryInsert(vector<int>arr) {
    if(arr.empty()) return nullptr;
    int mid = arr.size()/2;
    auto node = new TreeNode(arr[mid]);
    if(arr.size() == 1) return node;
    vector arr_left(arr.begin(),arr.begin()+mid);
    node->left = binaryInsert(arr_left);
    vector arr_right(arr.begin()+mid+1,arr.end());
    node->right = binaryInsert(arr_right);
    return node;
}

TreeNode* toBSL(Node* head) {
    auto current = head;
    vector<int> arr;
    while(current!=nullptr) {
        arr.push_back(current->val);
        current = current->next;
    }
    return binaryInsert(arr);
}


int main() {
    auto head = new Node(-10);
    auto current = head;
    for(int i = -9; i < 3;i++) {
        auto n = new Node(i);
        current->next = n;
        current = n;
    }

    TreeNode* balanced = toBSL(head);
    cout<<balanced->val;
}