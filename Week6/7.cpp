#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr;  // stores all numbers in sorted order

    for (int i = 0; i < n; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int m;
            cin >> m;
            vector<int> nums(m);
            for (int j = 0; j < m; j++) cin >> nums[j];

            // insert each number into the sorted array
            for (int x : nums) {
                auto it = lower_bound(arr.begin(), arr.end(), x);
                arr.insert(it, x);
            }
        } 
        else if (op == 2) {
            int size = arr.size();
            int median_idx = (size - 1) / 2; // lower middle for even size
            cout << arr[median_idx] << "\n";
        }
    }

    return 0;
}
