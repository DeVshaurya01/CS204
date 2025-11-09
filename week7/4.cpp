#include <iostream>
#include <sstream>
#include <string>
#include <limits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int v) {
    Node* p = new Node;
    p->data = v;
    p->left = p->right = NULL;
    return p;
}

// Simple queue using raw array
struct Queue {
    Node* arr[20005];
    int f, r;
    Queue() { f = r = 0; }
    bool empty() { return f == r; }
    void push(Node* x) { arr[r++] = x; }
    Node* pop() { return arr[f++]; }
};

Node* buildTree(int vals[], int sz) {
    if (sz == 0 || vals[0] == -1) return NULL;
    Node* root = newNode(vals[0]);
    Queue q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < sz) {
        Node* cur = q.pop();
        // left
        if (i < sz && vals[i] != -1) {
            cur->left = newNode(vals[i]);
            q.push(cur->left);
        }
        i++;
        // right
        if (i < sz && vals[i] != -1) {
            cur->right = newNode(vals[i]);
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0; // no input
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // drop rest of line after n

    // Read all remaining lines from stdin and collect integers
    int vals[20005];
    int m = 0;
    string line;
    // Read at least one non-empty line (the level-order line)
    while (getline(cin, line)) {
        if (line.size() == 0) continue;
        istringstream iss(line);
        int x;
        while (iss >> x) {
            vals[m++] = x;
            if (m >= 20000) break;
        }
        // If we found integers, break (assume level-order is provided on one line).
        // If input uses multiple lines for the level-order, the next while-loop will collect more.
        break;
    }
    // Also collect any remaining integers (in case the level order was spread across lines)
    while (getline(cin, line)) {
        if (line.size() == 0) continue;
        istringstream iss(line);
        int x;
        while (iss >> x) {
            vals[m++] = x;
            if (m >= 20000) break;
        }
    }

    // Build tree from all tokens read (m tokens)
    Node* root = buildTree(vals, m);
    postorder(root);
    cout << "\n";
    return 0;
}
