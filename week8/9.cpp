#include <iostream>
#include <cstring>
using namespace std;

class HashTable {
public:
struct Node {
char key;
int value;
Node* next;
Node(char k, int v) : key(k), value(v), next(nullptr) {}
};
static const int SIZE = 7;
Node* table[SIZE];
HashTable() {
for (int i = 0; i < SIZE; i++) table[i] = nullptr;
}
~HashTable() {
for (int i = 0; i < SIZE; i++) {
Node* curr = table[i];
while (curr) {
Node* tmp = curr;
curr = curr->next;
delete tmp;
}
}
}
int hash(char key) {
return (key - 'a') % SIZE;
}
int get(char key) {
int idx = hash(key);
Node* curr = table[idx];
while (curr) {
if (curr->key == key) return curr->value;
curr = curr->next;
}
return 0;
}
void set(char key, int value) {
int idx = hash(key);
Node* curr = table[idx];
while (curr) {
if (curr->key == key) {
curr->value = value;
return;
}
curr = curr->next;
}
Node* newNode = new Node(key, value);
newNode->next = table[idx];
table[idx] = newNode;
}
void inc(char key) {
set(key, get(key) + 1);
}
void dec(char key) {
int val = get(key);
if (val > 0) set(key, val - 1);
}
bool allPresent() {
return get('a') > 0 && get('b') > 0 && get('c') > 0;
}
};
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
string s;
cin >> s;
int n = s.size();
long long total = 0;
HashTable freq;
int left = 0;
for (int right = 0; right < n; ++right) {
freq.inc(s[right]);
while (freq.allPresent()) {
total += (n - right);
freq.dec(s[left]);
left++;
}
}
cout << total << "\n";
return 0;
}

