#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int height;
    Node *left, *right;
    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

// Utility: height of a node
int h(Node* n) { return n ? n->height : 0; }

// Utility: update height from children
void updateHeight(Node* n) {
    if (!n) return;
    n->height = 1 + max(h(n->left), h(n->right));
}

// Utility: balance factor (left height - right height)
int balanceFactor(Node* n) { return n ? h(n->left) - h(n->right) : 0; }

// Right rotate (for LL and part of LR)
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    return x; // new root
}

// Left rotate (for RR and part of RL)
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    return y; // new root
}

// Insert a key and rebalance using LL, RR, LR, RL
Node* insert(Node* root, int key) {
    // 1) BST insert
    if (!root) return new Node(key);
    if (key < root->key) root->left  = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    else return root; // duplicates not inserted

    // 2) Update height
    updateHeight(root);

    // 3) Get balance
    int bf = balanceFactor(root);

    // 4) Rebalance cases

    // LL: left-left
    if (bf > 1 && key < root->left->key)
        return rotateRight(root);

    // RR: right-right
    if (bf < -1 && key > root->right->key)
        return rotateLeft(root);

    // LR: left-right
    if (bf > 1 && key > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // RL: right-left
    if (bf < -1 && key < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root; // unchanged
}

// Optional: min value node (useful if you add deletion later)
Node* minValueNode(Node* n) {
    while (n && n->left) n = n->left;
    return n;
}

// Traversals to verify structure
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* root = nullptr;

    // Example: insert values that will trigger different rotations
    vector<int> vals = { 30, 20, 40, 10, 25, 50, 5, 35, 45, 42 }; 
    // You can try sequences like {30, 20, 10} -> LL, {10, 20, 30} -> RR
    // {30, 10, 20} -> LR, {10, 30, 20} -> RL

    for (int x : vals) root = insert(root, x);

    cout << "Inorder  (sorted): ";
    inorder(root);
   
    
    cout << "\n";

    return 0;
}
