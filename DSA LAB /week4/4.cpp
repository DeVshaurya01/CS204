#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    int twin_sum()
    {
        if (head == NULL)
            return -1;
        int n = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            n++;
            temp = temp->next;
        }
        if (n == 0)
            return -1;

        int max_sum = INT_MIN;
        Node *left = head;
        for (int i = 0; i < n / 2; ++i)
        {
            Node *right = head;
            for (int j = 0; j < n - 1 - i; ++j)
            {
                right = right->next;
            }
            int sum = left->data + right->data;
            if (sum > max_sum)
                max_sum = sum;
            left = left->next;
        }
        return max_sum;
    }
    void cycle(int k)
    {
        if (head == NULL || k <= 0)
            return;
        Node *temp = head;
        int count = 1;
        while (temp->next != NULL)
        {
            temp = temp->next;
            count++;
        }
        temp->next = head; // Make it circular

        // Move to the (k % count)th node
        k = k % count;
        Node *new_head = head;
        Node *new_tail = temp;
        for (int i = 0; i < k; i++)
        {
            new_tail = new_head;
            new_head = new_head->next;
        }

        // Break the cycle
        new_tail->next = NULL;
        head = new_head;
        // Update tail to the last node
        tail = head;
        while (tail && tail->next)
            tail = tail->next;
    }
    void printll()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    List ll;
    int val;
    while (cin >> val)
    {
        ll.push_back(val);
    }
    int result = ll.twin_sum();
    cout << result << endl;
    return 0;
}
