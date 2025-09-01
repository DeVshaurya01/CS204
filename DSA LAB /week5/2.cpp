#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    node*next;
    node*prev;
    node (int val){
        data = val;
        next = NULL;
        prev = NULL;
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
        newNode->prev = tail;
        tail = newNode;
    }
    return newNode;
}
void printList(node* head){
    if (head == NULL) return;
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
node* RemoveX_DLL(node* head, int x) {
    if (head == NULL) return NULL;

    node* current = head;
    node* newHead = head; // To track the new head in case the original head is removed

    while(current!=NULL){
        if(current->data == x){
            if(current->prev != NULL){
                current->prev->next = current->next;
            } else {
                newHead = current->next; // Update head if the first node is removed
            }
            if(current->next != NULL){
                current->next->prev = current->prev;
            } else {
                // If current is tail, update global tail
                tail = current->prev;
            }
            node* temp = current;
            current = current->next; // Move to next node before deleting
            delete temp; // Free memory
        } else {
            current = current->next;
        }
    }
    return newHead; // Return the possibly new head of the list
}


int main(){
    int x;
    cin >> x;

    while (true) {
        int val;
        cin >> val;
        if (val == -1) break;
        createNode(val);
    }
    head = RemoveX_DLL(head,x);
    printList(head);
    if(head == NULL) {
        cout << "-1"<< endl;
    }
    

    return 0;
}