#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
};

Node *findNode(Node *head, int val)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == val)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

int main()
{
    string line;
    getline(cin, line);
    stringstream ss(line);

    int num;
    Node *head = NULL;
    Node *tail = NULL;
    
    while (ss >> num)
    {
        Node *node = new Node(num);
        if (!head)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    int links;
    cin >> links;

    for (int i = 0; i < links; i++)
    {
        int u, v;
        cin >> u >> v;
        Node *from = findNode(head, u);
        Node *to = findNode(head, v);
        if (from && to)
        {
            from->next = to;
        }
    }

    if (!head) {
        cout << 0;
        return 0;
    }

    Node *slow = head;
    Node *fast = head;
    bool loopFound = false;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            loopFound = true;
            break;
        }
    }

    if (!loopFound)
    {
        cout << 0;
        return 0;
    }

    int length = 1;
    fast = fast->next;
    while (fast != slow)
    {
        fast = fast->next;
        length++;
    }
    cout << length;
    
    return 0;
}


