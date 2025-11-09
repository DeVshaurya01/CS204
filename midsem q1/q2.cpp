#include <bits/stdc++.h>
using namespace std;



struct Node {
 string id; string data[3];
 Node* prev=NULL; Node* next=NULL;
 Node(string s, string arr[3]) {
 id=s; for(int i=0;i<5;i++) data[i]=arr[i];
 }
};

void printList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
int n;
cin >> n;
node* head;

printList(head);
return 0;
}
