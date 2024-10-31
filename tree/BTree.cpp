#include <iostream>
using namespace std;
// A BTree node
struct BTreeNode {
    int* keys;
    int t;
    BTreeNode** C;
    int n;
    bool leaf;
public:
    BTreeNode(int _t, bool _leaf);
    // A utility function to insert a new key in the subtree rooted with
    // this node. The assumption is, the node must be non-full when this
    // function is called
    void insertNonFull(int k);
    // A utility function to split the child y of this node. i is index of y in
    // child array C[].  The Child y must be full when this function is called
    void splitChild(int i, BTreeNode *y);
    // A function to traverse all nodes in a subtree rooted with this node
    void traverse();
    // A function to search a key in the subtree rooted with this node.
    BTreeNode *search(int k);   // returns NULL if k is not present.
    void print(int level);

    void remove();

    // Make BTree friend of this so that we can access private members of this
    // class in BTree functions
    friend class BTree;
};
// A BTree
struct  BTree {
    BTreeNode* root;
    int t; //order of btree
public:
    BTree(int _t)
    {
        root = NULL;
        t = _t;
    }
    void traverse()
    {  if (root != NULL) root->traverse(); }
    // function to search a key in this tree
    BTreeNode* search(int k)
    {  return (root == NULL)? NULL : root->search(k); }
    // The main function that inserts a new key in this B-Tree
    void insert(int k);
    void remove(int k);
    void print();
};
// Constructor for BTreeNode class
BTreeNode::BTreeNode(int _t, bool _leaf)
{
    t = _t;
    leaf = _leaf;
    keys = new int[2 * t - 1];
    C = new BTreeNode*[2 * t];
    n = 0;
}
void BTreeNode::traverse()
{
    int i;
    for (i = 0; i < n; i++) {
        if (leaf == false)
            C[i]->traverse();
        cout << " " << keys[i];
    }
    if (leaf == false)
        C[i]->traverse();
}
// Function to search key k in subtree rooted with this node
BTreeNode* BTreeNode::search(int k)
{
    int i = 0;
    while(i < n) {
        if(k == keys[i])
            return this;
        if(k > keys[i])
            i++; //aumentamos hasta q llegue al final
        else
            break; //si es menor es caso inicio o del medio
    }
    //cada key tiene como minimo
    if(leaf) return nullptr; //no hay mas child asi q no esta
    return C[i]->search(k); //apunta al hijo ya sea el del medio o el inicial
}


 // A BTree
 // The main function that inserts a new key in this B-Tree
 void BTree::insert(int k)
 { // TODO: !!!YOUR CODE
    if (root == NULL) { // Empty Tree
        root = new BTreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    }
    else {
        if (root->n == 2*t-1) { // Full Root
            BTreeNode *newRoot = new BTreeNode(t, false);
            newRoot->C[0] = root;
            newRoot->splitChild(0, root);
            int i = 0;
            if (newRoot->keys[0] < k)
                i++;
            newRoot->C[i]->insertNonFull(k);
            root = newRoot;
        }
        else
            root->insertNonFull(k);
    }
 }
 // A utility function to insert a new key in this node
 // The assumption is, the node must be non-full when this
 // function is called
 void BTreeNode::insertNonFull(int k)
 {
    int i = n-1;
    if (leaf == true)
    {
        while (i >= 0 && keys[i] > k)
        {
            keys[i+1] = keys[i];
            i--;
        }
        keys[i+1] = k;
        n = n+1;
    }
    else
    {
        while (i >= 0 && keys[i] > k)
            i--;
        if (C[i+1]->n == 2*t-1)
        {
            splitChild(i+1, C[i+1]);
            if (keys[i+1] < k)
                i++;
        }
    }
        C[i+1]->insertNonFull(k);
 }
 // A utility function to split the child y of this node
 // Note that y must be full when this function is called
 void BTreeNode::splitChild(int i, BTreeNode *y)
 {
    BTreeNode *z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;
    for (int j = 0; j < t-1; j++)
        z->keys[j] = y->keys[j+t];
    if (y->leaf == false)
    {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j+t];
    }
    y->n = t - 1;
    for (int j = n; j >= i+1; j--)
        C[j+1] = C[j];
    C[i+1] = z;
    for (int j = n-1; j >= i; j--)
        keys[j+1] = keys[j];
    keys[i] = y->keys[t-1];
    n = n + 1;
 }
 // A function to print all keys in this node with hierarchy
 void BTreeNode::print(int level)
 {
    // indent
    for (int i = 0; i < level; i++)
        cout << "    ";
    // print keys
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << keys[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
    // print children
    if (!leaf) {
        for (int i = 0; i <= n; i++) {
            C[i]->print(level + 1);
        }
    }
 }
void BTree::remove(int k) {
    auto n = search(k);
    if(n == nullptr) return;
}

void BTreeNode::remove() {

}
 // Add the following function in BTree class
 void BTree::print()
 {
    if (root != NULL)
        root->print(0);
 }
 void test() {
    BTree t(3);
    t.insert(10);
    t.insert(20);
    t.insert(30);
    t.insert(40);
    t.insert(50);
    t.insert(60);
    t.insert(70);
    t.insert(80);
    t.insert(90);
    t.print();
    t.traverse();
 }
 void test2() {
    BTree t(3);
    while(true) {
        int x;
        cin >> x;
        if (x == -5432) break;
        t.insert(x);
        t.print();
        t.traverse();
    }
 }
 // Driver program to test above functions
 int main()
 {
 //    test();
 //    test2();
 //    return 0;
    BTree t(2);
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);
    cout << "Traversal of the constructed tree is ";
    t.traverse();
    int k = 6;
    (t.search(k) != NULL)? cout << "\nPresent" : cout << "\nNot Present";
    k = 15;
    (t.search(k) != NULL)? cout << "\nPresent" : cout << "\nNot Present";
    return 0;
 }
