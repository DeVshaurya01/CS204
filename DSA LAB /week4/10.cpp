#include <iostream>
#include <vector>
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
public:
Node *head;
Node *tail;
List()
{
head = tail = NULL;
}
void push_back(int val)
{
Node *newNode = new Node(val);
if (!head)
head = tail = newNode;
else
{
tail->next = newNode;
tail = newNode;
}
}
void removeDuplicates()
{
Node *curr = head;
while (curr && curr->next)
{
if (curr->data == curr->next->data)
{
Node *temp = curr->next;
curr->next = temp->next;
delete temp;
}
else
curr = curr->next;
}
}
void display()
{
Node *curr = head;
while (curr)
{
cout << curr->data << " ";
curr = curr->next;
}
}
};

int main()
{
List lst;
int x;
while (cin >> x)
{
if (cin.peek() == '#')
break;
lst.push_back(x);
}
lst.removeDuplicates();
lst.display();
}