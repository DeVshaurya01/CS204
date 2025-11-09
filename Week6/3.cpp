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
    int size() const
    {
        return TOP + 1;
    }

}; // End of ADT

int main()
{
    string postfix;
    cin >> postfix;
    Stack s(postfix.length());
    int maxsize = 0;
    for (char ch : postfix)
    {
        if (isdigit(ch))
        {
            s.PUSH(ch - '0');
            maxsize= max(maxsize, s.size());
        }
        else
        {
            int val2 = s.POP();
            int val1 = s.POP();
            int res = 0;
            switch (ch)
            {
            case '+':
                res = val1 + val2;
                break;
            case '-':
                res = val1 - val2;
                break;
            case '*':
                res = val1 * val2;
                break;
            case '/':
                res = val1 / val2;
                break;
            }
            s.PUSH(res);
        }
          maxsize= max(maxsize, s.size());
    }
    cout << s.POP() << endl;
    cout << maxsize << endl;
    return 0;
}