#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; // size of buffer
    cin >> N;
    queue<int> buffer;

    string op;
    while (cin >> op) {
        if (op == "E") break; // Exit

        if (op == "P") { // Producer
            int x;
            cin >> x;
            if (buffer.size() == N) {
                cout << "Buffer Full!\n";
            } else {
                buffer.push(x);
                cout << "Produced: " << x << "\n";
            }
        } else if (op == "C") { // Consumer
            if (buffer.empty()) {
                cout << "Buffer Empty!\n";
            } else {
                int x = buffer.front();
                buffer.pop();
                cout << "Consumed: " << x << "\n";
            }
        }

        // Print current queue contents
        cout << "Queue: [";
        queue<int> temp = buffer; // copy to print
        while (!temp.empty()) {
            cout << temp.front();
            temp.pop();
            if (!temp.empty()) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
