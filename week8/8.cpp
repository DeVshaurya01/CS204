#include <iostream>
#include <cstring>
using namespace std;

const int HASH_SIZE = 131071;
const int MAX_NODES = 100005;
class Node {
public:
long key;
Node* next;
Node(long k) : key(k), next(nullptr) {}
};
class HashSet {
public:
Node* table[HASH_SIZE];
HashSet() { for(int i = 0; i < HASH_SIZE; ++i) table[i] = nullptr; }
~HashSet() {
for(int i = 0; i < HASH_SIZE; ++i) {
Node* curr = table[i];
while(curr) {
Node* temp = curr;
curr = curr->next;
delete temp;
}
}
}
unsigned long hash(long key) {
return ((unsigned long)key ^ (key >> 17)) % HASH_SIZE;
}
void insert(long key) {
int idx = hash(key);
Node* curr = table[idx];
while(curr) {
if(curr->key == key) return;
curr = curr->next;
}
Node* node = new Node(key);
node->next = table[idx];
table[idx] = node;
}
bool contains(long key) {
int idx = hash(key);
Node* curr = table[idx];
while(curr) {
if(curr->key == key) return true;
curr = curr->next;
}
return false;
}
};
struct ListNode {
long val;
ListNode* next;
ListNode(long v) : val(v), next(nullptr) {}
};

int main() {
long nodes[MAX_NODES];
int node_count = 0;
long x;
while(cin >> x && x != -1) nodes[node_count++] = x;
ListNode* list_nodes[MAX_NODES];
for(int i = 0; i < node_count; ++i)
list_nodes[i] = new ListNode(nodes[i]);
int n;
cin >> n;
long a, b;
for(int i = 0; i < n; ++i) {
cin >> a >> b;
int idx_a = -1, idx_b = -1;
for(int j = 0; j < node_count; ++j) {
if(list_nodes[j]->val == a) idx_a = j;
if(list_nodes[j]->val == b) idx_b = j;
}
if(idx_a != -1 && idx_b != -1)
list_nodes[idx_a]->next = list_nodes[idx_b];
}
HashSet visited;
ListNode* curr = list_nodes[0];
bool has_loop = false;
while(curr) {
if(visited.contains(curr->val)) {
has_loop = true;
break;
}
visited.insert(curr->val);
curr = curr->next;
}
cout << (has_loop ? "True" : "False") << endl;
for(int i = 0; i < node_count; ++i)
delete list_nodes[i];
}

