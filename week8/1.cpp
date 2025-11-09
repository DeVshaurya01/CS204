#include <iostream>
using namespace std;

// Insert a key into the hash table
void insert(int hash_table[], int TABLE_SIZE, int key) {
    int index = key % TABLE_SIZE;
    int original_index = index;

    while (hash_table[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
        if (index == original_index) return; // Table full
    }
    hash_table[index] = key;
}

// Delete a key from the hash table
void deleteKey(int hash_table[], int TABLE_SIZE, int key) {
    int index = key % TABLE_SIZE;
    int original_index = index;

    while (hash_table[index] != -1) {
        if (hash_table[index] == key) {
            hash_table[index] = -2; // mark as deleted
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == original_index) return; // key not found
    }
}

// Search for a key and print result
void search(int hash_table[], int TABLE_SIZE, int key) {
    int index = key % TABLE_SIZE;
    int original_index = index;
    int probes = 1;

    while (hash_table[index] != -1) { // stop only at empty slot
        if (hash_table[index] == key) {
            cout << "Found " << probes << endl;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        probes++;
        if (index == original_index) break; // circled back
    }

    cout << "NotFound " << probes << endl;
}

int main() {
    int TABLE_SIZE;
    cin >> TABLE_SIZE;

    int hash_table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = -1; // initialize as empty
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
