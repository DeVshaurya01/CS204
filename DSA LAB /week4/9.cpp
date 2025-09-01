#include <iostream>
#include <string>
#include <sstream>

struct ListNode
{
int val;
ListNode *next;
ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *reverseList(ListNode *head)
{
ListNode *prev = nullptr;
ListNode *curr = head;
ListNode *next = nullptr;
while (curr != nullptr)
{
next = curr->next;
curr->next = prev;
prev = curr;
curr = next;
}
return prev;
}

int findIntersectionValue(ListNode *headA, ListNode *headB)
{
if (!headA || !headB)
{
return -1;
}

ListNode *revA = reverseList(headA);
ListNode *revB = reverseList(headB);

ListNode *ptrA = revA;
ListNode *ptrB = revB;
int intersection_val = -1;

while (ptrA != nullptr && ptrB != nullptr)
{
if (ptrA->val == ptrB->val)
{
intersection_val = ptrA->val;
ptrA = ptrA->next;
ptrB = ptrB->next;
}
else
{
break;
}
}

reverseList(revA);
reverseList(revB);

return intersection_val;
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

int main()
{
std::ios_base::sync_with_stdio(false);
std::cin.tie(NULL);

std::string line;
int num;
char sharp;

ListNode *headA = nullptr;
ListNode *tailA = nullptr;
std::getline(std::cin, line);
std::stringstream ssA(line);
while (ssA >> num)
{
ListNode *newNode = new ListNode(num);
if (headA == nullptr)
{
headA = tailA = newNode;
}
else
{
tailA->next = newNode;
tailA = newNode;
}
}

ListNode *headB = nullptr;
ListNode *tailB = nullptr;
std::getline(std::cin, line);
std::stringstream ssB(line);
while (ssB >> num)
{
ListNode *newNode = new ListNode(num);
if (headB == nullptr)
{
headB = tailB = newNode;
}
else
{
tailB->next = newNode;
tailB = newNode;
}
}

int result = findIntersectionValue(headA, headB);
std::cout << result << std::endl;

deleteList(headA);
deleteList(headB);

return 0;
}