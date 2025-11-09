#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int key;
    Node* next;
    Node(int k) : key(k), next(nullptr) {}
};

// Insert key into the hash table
void insert(Node* hash_table[], int TABLE_SIZE, int key) {
    int index = key % TABLE_SIZE;
    Node* newNode = new Node(key);

    // Insert at the beginning of the linked list
    newNode->next = hash_table[index];
    hash_table[index] = newNode;
}

// Delete key from the hash table
void deleteKey(Node* hash_table[], int TABLE_SIZE, int key) {
    int index = key % TABLE_SIZE;
    Node* curr = hash_table[index];
    Node* prev = nullptr;

    while (curr != nullptr) {
        if (curr->key == key) {
            if (prev == nullptr) {
                hash_table[index] = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

// Search key in the hash table
void search(Node* hash_table[], int TABLE_SIZE, int key) {
    int index = key % TABLE_SIZE;
    Node* curr = hash_table[index];

    while (curr != nullptr) {
        if (curr->key == key) {
            cout << "Found" << endl;
            return;
        }
        curr = curr->next;
    }

    cout << "NotFound" << endl;
}

int main() {
    int TABLE_SIZE;
    cin >> TABLE_SIZE;

    // Initialize hash table with nullptr
    Node* hash_table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = nullptr;
    }

    while (true) {
        char cmd;
        int key;
        cin >> cmd >> key;

        if (cmd == 'I') {
            insert(hash_table, TABLE_SIZE, key);
        } else if (cmd == 'D') {
            deleteKey(hash_table, TABLE_SIZE, key);
        } else if (cmd == 'S') {
            search(hash_table, TABLE_SIZE, key);
            break; // stop after search
        }
    }

    return 0;
}
