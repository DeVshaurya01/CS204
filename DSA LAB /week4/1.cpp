// middle of the linked list

// #include <bits/stdc++.h>
// using namespace std;
// struct Node
// {
//     int data;
//     Node *next;
//     Node(int val)
//     {
//         data = val;
//         next = NULL;
//     }
// };
// Node *middle(Node *head)
// {
//     Node *slow = head;
//     Node *fast = head;
//     while (fast != NULL && fast->next != NULL)
//     {
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     return slow;
// }

// Node *nodeNew(int val)
// {
//     Node *temp = new Node(val);
//     temp->next = NULL;
//     return temp;
// }

// // A sequence of integers representing the elements of the linked list.
// // The input is terminated by the symbol #.
// // print the element at the middle of the linked list.
// //  if two middle elements, print the second one.
// int main()
// {
//     Node *head = NULL;
//     Node *tail = NULL;
//     while (true)
//     {
//         string s;
//         cin >> s;
//         if (s == "#")
//         {
//             break;
//         }
//         try
//         {
//             int num = stoi(s);
//             Node *newNode = new Node(num);
//             if (head == NULL)
//             {
//                 head = newNode;
//                 tail = newNode;
//             }
//             else
//             {
//                 tail->next = newNode;
//                 tail = newNode;
//             }
//         }
//         catch (invalid_argument &e)
//         {
//             // Ignore invalid input that is not an integer
//             continue;
//         }
//     }
//     Node *mid = middle(head);
//     if (mid != NULL)
//     {
//         cout << mid->data << endl;
//     }
//     return 0;
// }
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

    // Corrected push_back to handle empty list correctly
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

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void pop_front()
    {
        if (head == NULL)
        {
            return;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void pop_back()
    {
        if (head == NULL)
        {
            return;
        }
        if (head == tail)
        { // Handle single node case
            delete head;
            head = tail = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void insert(int val, int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid position" << endl;
            return;
        }
        if (pos == 0)
        {
            push_front(val);
            return;
        }

        Node *newNode = new Node(val);
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            { // Handle out-of-bounds position
                cout << "Invalid position" << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Invalid position" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void middle()
    {
        if (head == NULL)
        {
            return;
        }
        Node *slow = head;
        Node *fast = head;
        // The condition fast->next->next != NULL would be a bit more robust
        // if we want to handle the first middle node on even lists.
        // But for the second middle node, this is correct.
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << slow->data << endl;
    }
};
int main()
{
    List ll;
    int val;
    // Reads input until a non-integer value (like '#') is entered
    while (cin >> val)
    {
        ll.push_back(val);
    }
    ll.middle();
    return 0;
}
