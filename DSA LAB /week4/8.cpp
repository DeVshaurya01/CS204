#include <iostream>
#include <string>
#include <sstream>

struct ListNode
{
int val;
ListNode *next;
ListNode(int x) : val(x), next(nullptr) {}
};

void printList(ListNode *head)
{
while (head != nullptr)
{
std::cout << head->val << (head->next ? " " : "");
head = head->next;
}
std::cout << std::endl;
}

void deleteList(ListNode *head)
{
while (head != nullptr)
{
ListNode *temp = head;
head = head->next;
delete temp;
}
}

ListNode *rotateLeft(ListNode *head, int k)
{
if (!head || !head->next || k == 0)
{
return head;
}

int len = 1;
ListNode *current = head;
while (current->next != nullptr)
{
current = current->next;
len++;
}

k = k % len;
if (k == 0)
{
return head;
}

current->next = head;

ListNode *new_tail = head;
for (int i = 0; i < k - 1; ++i)
{
new_tail = new_tail->next;
}

ListNode *new_head = new_tail->next;
new_tail->next = nullptr;

return new_head;
}

int main()
{
std::ios_base::sync_with_stdio(false);
std::cin.tie(NULL);

std::string line;
int num;

std::getline(std::cin, line);
std::stringstream ss(line);

ListNode *head = nullptr;
ListNode *tail = nullptr;

while (ss >> num)
{
ListNode *newNode = new ListNode(num);
if (head == nullptr)
{
head = tail = newNode;
}
else
{
tail->next = newNode;
tail = newNode;
}
}

int k;
std::cin >> k;

ListNode *rotated_head = rotateLeft(head, k);

printList(rotated_head);

deleteList(rotated_head);

return 0;
}