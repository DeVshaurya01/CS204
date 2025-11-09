#include <bits/stdc++.h>
using namespace std;

long long maxArea(vector<long long> &heights) {
    int n = heights.size();
    stack<int> st;
    long long max_area = 0;

    for (int i = 0; i <= n; i++) {
        long long h = (i == n ? 0 : heights[i]); // sentinel 0 at end
        while (!st.empty() && heights[st.top()] >= h) {
            int top = st.top(); st.pop();
            long long width = st.empty() ? i : i - st.top() - 1;
            max_area = max(max_area, heights[top] * width);
        }
        st.push(i);
    }
    return max_area;
}

int main() {
    int n;
    cin >> n;
    vector<long long> heights(n);
    for (int i = 0; i < n; i++)
        cin >> heights[i];

    cout << maxArea(heights) << "\n";
    return 0;
}
