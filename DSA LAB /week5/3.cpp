#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
    node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

node* createList() {
    node* head = NULL;
    node* tail = NULL;
    while (true) {
        int val;
        cin >> val;
        if (val == -1) break;
        node* newNode = new node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    return head;
}

void printList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void merge_ll(node* head1, node* head2) {
    node* dummy = new node(0); // Dummy node to simplify merging
    node* tail = dummy;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            tail->next = head1;
            head1->prev = tail;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2->prev = tail;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    // Attach the remaining nodes, if any
    if (head1 != NULL) {
        tail->next = head1;
        head1->prev = tail;
    } else if (head2 != NULL) {
        tail->next = head2;
        head2->prev = tail;
    }

    // Print the merged list
    printList(dummy->next);
    delete dummy; // Free the dummy node
}

int main() {
    node* head1 = createList();
    node* head2 = createList();
    if (head1 == NULL && head2 == NULL) {
        cout << "-1" << endl;
    } else {
        merge_ll(head1, head2);
    }
    return 0;
}