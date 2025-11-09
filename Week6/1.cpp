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
    int getMin()
    {
        if (TOP == -1)
            return -1; // Stack is empty
        int minVal = A[0];
        for (int i = 1; i <= TOP; i++)
        {
            if (A[i] < minVal)
                minVal = A[i];
        }
        return minVal;
    }
}; // End of ADT
main()
{
    int n;
    cin >> n;
    Stack S(100);
    // n denotes the no of operations to perform on the stack
    for (int i = 0; i < n; i++)
    {
        int op, ele;
        cin >> op;
        if (op == 1)
        {
            cin >> ele;
            S.PUSH(ele);
        }
        else if (op == 2)
        {
            int popped = S.POP();

        }
        else if (op == 3)
        {
            if (!S.isEmpty())
                cout << S.TopOfStack() << endl;
            else
                cout << "null" << endl;
        }
        else if (op == 4)
            {
                if (!S.isEmpty())
                    cout << S.getMin() << endl;
                else
                    cout << "null" << endl;
            }
            
        }
    }