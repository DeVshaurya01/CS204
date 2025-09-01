#include <bits/stdc++.h>
using namespace std;

struct Node
{
long long data;
Node *next;
Node(long long val) : data(val), next(NULL) {}
};

int main()
{
long long num;
Node *head = NULL;
Node *tail = NULL;

while (cin >> num)
{
if (cin.peek() == '#')
{
char c;
cin >> c;
break;
}
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

if (!head || !head->next)
{
Node *temp = head;
while (temp)
{
cout << temp->data << " ";
temp = temp->next;
}
return 0;
}

Node *odd = head;
Node *even = head->next;
Node *evenHead = even;

while (even && even->next)
{
odd->next = even->next;
odd = odd->next;
even->next = odd->next;
even = even->next;
}

odd->next = evenHead;

Node *temp = head;
while (temp)
{
cout << temp->data << " ";
temp = temp->next;
}

return 0;
}