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
    node* temp = head;
    while(temp != NULL){
        cout << temp->data<< " ";
        temp = temp->next;
    };
}
//rotate the linked list to right by k places
void K_rotate(node* head, int k){
    if (head == NULL || k <= 0) {
        printList(head);
        return;
    }
    // Find length and tail
    node* temp = head;
    int len = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        len++;
    }
    // Make it circular
    temp->next = head;
    k = k % len;
    if (k == 0) {
        temp->next = NULL;
        printList(head);
        return;
    }
    // Find new tail (len - k)th node
    node* newTail = head;
    for (int i = 0; i < len - k - 1; i++) {
        newTail = newTail->next;
    }
    node* newHead = newTail->next;
    newTail->next = NULL;
    printList(newHead);
}

int main(){
   while (true) {
    string input;
    cin >> input;
    if (input == "#") break;
    int val = stoi(input);
    createNode(val);
}
    int k;
    cin >> k;   
    K_rotate(head,k);
    return 0;
}