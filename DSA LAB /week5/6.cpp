#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
class circularlist{
public :
    Node* head;
    Node* tail;
    circularlist(){
        head = tail = NULL;
    }
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }
    int del_kth(int k, Node* &curr, Node* &prev){
        if (head == NULL) return -1; 
        for (int i = 1; i < k; i++) { 
            prev = curr;
            curr = curr->next;
        }
        int val = curr->data;
        prev->next = curr->next;
        if (curr == head) head = curr->next;
        if (curr == tail) tail = prev;
        Node* temp = curr;
        curr = curr->next;
        delete temp;
        return val;
    }
    int josephus(int k){
        if (!head) return -1;
        Node* curr = head;
        Node* prev = tail;
        while (head != tail){ 
            del_kth(k, curr, prev);
        }
        return head->data; 
    }
};

int main(){
    circularlist l1;
    int val ;
    while(cin >> val && val != -1){
        l1.push_back(val);
    }
    int k;
    cin >> k;
    cout << l1.josephus(k) << endl;
    return 0;
}