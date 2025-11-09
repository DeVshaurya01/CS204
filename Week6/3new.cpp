#include <bits/stdc++.h>
using namespace std;

class Stack {
    int TOP;
    vector<int> A;
public:
    Stack(int n) : TOP(-1), A(n) {}
    bool push(int x) {
        if (TOP + 1 >= (int)A.size()) return false;
        A[++TOP] = x;
        return true;
    }
    bool pop(int &out) {
        if (TOP < 0) return false;
        out = A[TOP--];
        return true;
    }
    int size() const { return TOP + 1; }
};

int main() {
    string postfix;
    cin >> postfix;

    Stack s(postfix.size());
    int maxsize = 0;
    bool invalid = false;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0');
            maxsize = max(maxsize, s.size());
        } 
        else if (ch=='+' || ch=='-' || ch=='*' || ch=='/') {
            int a,b;
            if (!s.pop(b) || !s.pop(a)) {   // need 2 operands
                invalid = true;
                break;
            }
            if (ch=='/' && b==0) {          // division by zero
                invalid = true;
                break;
            }
            int res = 0;
            switch (ch) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }
            s.push(res);
            maxsize = max(maxsize, s.size());
        } 
        else {                              // unknown character
            invalid = true;
            break;
        }
    }

    int result;
    if (invalid || s.size() != 1 || !s.pop(result)) {
        cout << "invalid\n";
    } else {
        cout << result << "\n";   // evaluated value
        cout << maxsize << "\n";  // max stack size
    }
    return 0;
}
