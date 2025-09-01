#include <iostream>
#include <sstream>
#include <string>
using namespace std;

typedef struct Node {
    int o1, o2, o3, o4;
    Node* prev;
    Node* next;
    Node(int a, int b, int c, int d) {
        o1 = a; o2 = b; o3 = c; o4 = d;
        prev = next = NULL;
    }
} Node;
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    DoublyLinkedList() {
        head = tail = NULL;
    }
    void insert(int a, int b, int c, int d) {
        Node* newNode = new Node(a, b, c, d);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    static bool greaterIP(Node* a, Node* b) {
        if (a->o1 != b->o1) return a->o1 > b->o1;
        if (a->o2 != b->o2) return a->o2 > b->o2;
        if (a->o3 != b->o3) return a->o3 > b->o3;
        return a->o4 > b->o4;
    }
    void insertionSort() {
        if (!head || !head->next) return;
        Node* sorted = head; 
        Node* current = head->next;
        sorted->next = NULL; 
        while (current) {
            Node* next = current->next;
            if (!greaterIP(sorted, current)) {
                Node* temp = sorted;
                while (temp->next && greaterIP(temp->next, current) == false)
                    temp = temp->next;
                current->next = temp->next;
                if (temp->next) temp->next->prev = current;
                temp->next = current;
                current->prev = temp;
            } else {
                current->next = sorted;
                sorted->prev = current;
                current->prev = NULL;
                sorted = current;
            }
            current = next;
        }
        head = sorted;
        Node* t = head;
        while (t->next) t = t->next;
        tail = t;
    }
    void print() {
        if (!head) {
            cout << -1 << endl;
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->o1 << "." << temp->o2 << "." 
                 << temp->o3 << "." << temp->o4;
            if (temp->next) cout << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    string input;
    getline(cin, input);

    stringstream ss(input);
    string ip;

    while (ss >> ip && ip != "-1") {
        int a, b, c, d;
        char dot;
        stringstream ipStream(ip);
        ipStream >> a >> dot >> b >> dot >> c >> dot >> d;
        dll.insert(a, b, c, d);
    }

    if (!dll.head) {
        cout << -1 << endl;
        return 0;
    }

    dll.insertionSort();
    dll.print();

    return 0;
}