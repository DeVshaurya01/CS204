#include <bits/stdc++.h>
using namespace std;
class Stack
{
private:
    int TOP;
    int *A;
    int MAX;

public:
    Stack(int n)
    {
        TOP = -1;
        MAX = n;
        A = (int *)malloc(sizeof(int) * MAX);
    }
    int PUSH(int ele)
    {
        if (TOP < MAX - 1)
        {
            TOP++;
            A[TOP] = ele;
            return 1;
        }
        else
            return -1;
    }
    int POP()
    {
        if (TOP > -1)
        {
            int ele = A[TOP];
            TOP--;
            return ele;
        }
        else
            return -1;
    }
    void display()
    {
        int i;
        for (i = 0; i <= TOP; i++)
        {
            cout << A[i] << " ";
        }
    }
    
    int TopOfStack() { return A[TOP]; }
    int isEmpty()
    {
        if (TOP == -1)
            return 1;
        else
            return 0;
    }
    int isFull()
    {
        if (TOP < MAX - 1)
            return 0;
        else
            return 1;
    }
    
}; // End of ADT

int main()
{
    string infix;
    cin >> infix;
    //infix to postfix conversion
string postfix = "";
Stack s(infix.length());
unordered_map<char, int> prec = {
    {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}
};

for (char ch : infix) {
    if (isalnum(ch)) {
        postfix += ch;
    } else if (ch == '(') {
        s.PUSH(ch);
    } else if (ch == ')') {
        while (!s.isEmpty() && s.TopOfStack() != '(') {
            postfix += (char)s.POP();
        }
        if (!s.isEmpty() && s.TopOfStack() == '(')
            s.POP();
    } else { // operator
        while (!s.isEmpty() && s.TopOfStack() != '(' &&
               prec[(char)s.TopOfStack()] >= prec[ch]) {
            postfix += (char)s.POP();
        }
        s.PUSH(ch);
    }
}
while (!s.isEmpty()) {
    postfix += (char)s.POP();
}
cout << postfix << endl;
    



}