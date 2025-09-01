#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Node {
public:
    string word;
    Node* prev;
    Node* next;

    Node(const string& w) {
        word = w;
        prev = nullptr;
        next = nullptr;
    }
};
Node* head = nullptr;
Node* currentNode = nullptr;
void insertAction(const string& text) {
    Node* newNode = new Node(text);
    if (head == nullptr) {
        head = newNode;
        currentNode = newNode;
    } else {
        currentNode->next = newNode;
        newNode->prev = currentNode;
        currentNode = newNode;
    }
}
void undo() {
    if (currentNode != nullptr && currentNode->prev != nullptr) {
        currentNode = currentNode->prev;
    }
}
void redo() {
    if (currentNode != nullptr && currentNode->next != nullptr) {
        currentNode = currentNode->next;
    }
}
void displayHistory() {
    if (head == nullptr) {
        cout << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->word;
        if (temp == currentNode) break;
        if (temp->next != nullptr) cout << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    string line;
    while (getline(cin, line)) {
        if (line.rfind("INSERT", 0) == 0) {
            string word = line.substr(7);
            insertAction(word);
        } else if (line.rfind("UNDO", 0) == 0) {
            undo();
        } else if (line.rfind("REDO", 0) == 0) {
            redo();
        } else if (line.rfind("DISPLAY", 0) == 0) {
            displayHistory();
            break;
        }
    }
    return 0;
}