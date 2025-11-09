#include <iostream>
#include <climits>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* newNode(int val) {
    Node* node = new Node;
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Queue implementation using raw arrays
struct Queue {
    Node* arr[100005];
    int front, rear;
    Queue() { front = rear = 0; }

    bool empty() { return front == rear; }
    void push(Node* x) { arr[rear++] = x; }
    Node* pop() { return arr[front++]; }
};

// Function to build tree from level order
Node* buildTree(int level[], int n) {
    if (n == 0 || level[0] == -1) return NULL;

    Node* root = newNode(level[0]);
    Queue q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < n) {
        Node* curr = q.pop();

        // Left child
        if (i < n && level[i] != -1) {
            curr->left = newNode(level[i]);
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < n && level[i] != -1) {
            curr->right = newNode(level[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// Check BST recursively with min/max range
bool isBST(Node* root, long long minVal, long long maxVal) {
    if (!root) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}

int main() {
    int n;
    cin >> n;
    int arr[100005];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* root = buildTree(arr, n);

    if (isBST(root, LLONG_MIN, LLONG_MAX)) cout << "T\n";
    else cout << "F\n";

    return 0;
}