#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
void printCircularList(Node* start) {
    if (start == nullptr) return;
    Node* temp = start;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != start);
    cout << endl;
}

int main() {
    int val;
    Node *head = nullptr, *tail = nullptr;
    int n = 0;
    while (cin >> val && val != -1) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        n++;
    }
    if (head != nullptr) {
        tail->next = head;
    }
    if (n == 0) {
        cout << -1 << endl;
        return 0;
    }
    if (n == 1) {
        cout << head->data << endl;
        return 0;
    }
    Node *head1, *head2;
    Node *tail1, *tail2;
    int len1 = (n + 1) / 2;
    head1 = head;
    tail1 = head;
    for (int i = 0; i < len1 - 1; i++) {
        tail1 = tail1->next;
    }
    head2 = tail1->next;
    tail2 = tail;
    tail1->next = head1;
    tail2->next = head2;
    printCircularList(head1);
    printCircularList(head2);
    return 0;
}