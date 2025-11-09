#include <bits/stdc++.h>
using namespace std;

bool isBalanced(const string &s) {
    stack<char> st;
    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else { // closing bracket
            if (st.empty()) return false;
            char open = st.top(); st.pop();
            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '['))
                return false;
        }
    }
    return st.empty();
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (isBalanced(s))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
