#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] <= heap[index]) break;
            swap(heap[parent], heap[index]);
            index = parent;
        }
    }

    void heapifyDown(int index) {
        int n = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < n && heap[left] < heap[smallest]) smallest = left;
            if (right < n && heap[right] < heap[smallest]) smallest = right;

            if (smallest == index) break;
            swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }

public:
    void insert(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    int getMin() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    void removeMin() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
    }
};

int main() {
    int n;
    cin >> n;
    MinHeap mh;

    for (int i = 0; i < n; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int m;
            cin >> m;
            mh.insert(m);
        } else if (op == 2) {
            cout << mh.getMin() << "\n";
        } else if (op == 3) {
            mh.removeMin();
        }
    }

    return 0;
}
