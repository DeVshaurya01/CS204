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

void MostRepeatedConsecutiveElement(node* head){
    if(head == NULL) return;
    int maxCount = 0;
    int mostRepeated = INT_MIN;
    node* current = head;
    while(current != NULL){
        int count = 1;
        node* runner = current->next;
        while(runner != NULL && runner->data == current->data){
            count++;
            runner = runner->next;
        }
        if(count > maxCount){
            maxCount = count;
            mostRepeated = current->data;
        } else if(count == maxCount && current->data > mostRepeated){
            mostRepeated = current->data;
        }
        current = runner;
    }
    cout << mostRepeated  << endl;
}
int main(){
 
while (true) {
    string input;
    cin >> input;
    if (input == "#") break;
    int val = stoi(input);
    createNode(val);
}


    MostRepeatedConsecutiveElement(head);
    return 0;
}