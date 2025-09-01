#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    node*next;
    node (int val){
        data = val;
        next = NULL;
    }
}node;

node* head = NULL;
node* tail = NULL;

node* createNode(int val){
    node* newNode = new node(val);
    if(head == NULL){
        head = tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
    return newNode;
}
void printList(node* head){
    if (head == NULL) return;
    node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head && temp != NULL);
    cout << endl;
}

void rotate_Circularll_k(node* &head, int k){
    if (head == NULL || k == 0) return;
    // Find length of the circular linked list
    node* current = head;
    int length = 1;
    while (current->next != head) {
        current = current->next;
        length++;
    }
    k = k % length;
    if (k == 0) {
        printList(head);
        return;
    }
    // Find new tail: (length - k)th node
    int steps = length - k;
    node* newTail = head;
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }
    node* newHead = newTail->next;
    current->next = head; // Ensure circularity
    newTail->next = newHead; // New tail points to new head
    head = newHead;
    printList(head);
}

int main(){
    int k;
    cin >> k;

    while (true) {
        int val;
        cin >> val;
        if (val == -1) break;
        createNode(val);
    }
    if (tail != NULL) {
        tail->next = head;
    }
    if (head == NULL) {
        cout << -1 << endl;
        return 0;
    }
    if (k == 0) {
        printList(head);
        return 0;
    }
    rotate_Circularll_k(head, k);

    return 0;
}

