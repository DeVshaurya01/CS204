#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create new node
Node* newNode(int val) {
    Node* node = new Node;
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
Node* insert(Node* root, int val) {
    if (!root) return newNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// In-order traversal (prints sorted order)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int n;
    cin >> n;

    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    inorder(root);
    cout << endl;

    return 0;
}
