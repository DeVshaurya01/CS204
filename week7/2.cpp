#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create a new node
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

// Find LCA in BST
int findLCA(Node* root, int v1, int v2) {
    while (root) {
        if (v1 < root->data && v2 < root->data) {
            root = root->left;
        }
        else if (v1 > root->data && v2 > root->data) {
            root = root->right;
        }
        else {
            return root->data; // Found the split point
        }
    }
    return -1; // should not happen if v1 and v2 are present
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

    int v1, v2;
    cin >> v1 >> v2;

    cout << findLCA(root, v1, v2) << endl;

    return 0;
}
