#include <bits/stdc++.h>
using namespace std;

class QueueUsingStacks {
    stack<long long> s1, s2;

    void moveS1toS2() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

public:
    void enqueue(long long x) {
        s1.push(x);
    }

    long long dequeue() {
        if (s2.empty()) moveS1toS2();
        if (s2.empty()) return -1; // queue is empty
        long long val = s2.top();
        s2.pop();
        return val;
    }
};

int main() {
    int n;
    cin >> n;
    QueueUsingStacks q;

    for (int i = 0; i < n; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            long long m;
            cin >> m;
            q.enqueue(m);
        } else if (op == 2) {
            cout << q.dequeue() << "\n";
        }
    }
    return 0;
}
