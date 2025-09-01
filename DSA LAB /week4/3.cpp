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
void Reverse(node* head){
    node* prev = NULL;
    node* current = head;
    node* next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printList(head);
}
int main(){
 
while (true) {
    string input;
    cin >> input;
    if (input == "#") break;
    int val = stoi(input);
    createNode(val);
}


    Reverse(head);
    return 0;
}