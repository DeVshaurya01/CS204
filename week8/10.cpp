#include <bits/stdc++.h>
using namespace std;

int main() {
// Fast I/O
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int m, n;
cin >> m >> n;

// The total number of ranges is (m*n)/2 based on the problem description.
int num_ranges = (m * n) / 2;
int ranges[num_ranges][2]; // Using a VLA, like in your previous code.

// Read the m*n integers as pairs into our ranges array.
for (int i = 0; i < num_ranges; ++i) {
cin >> ranges[i][0] >> ranges[i][1];
}

int left, right;
cin >> left >> right;

bool isCovered[51] = {false}; // Initializes all elements to false.

// --- 1. Marking Phase ---
for (int i = 0; i < num_ranges; ++i) {
int start = ranges[i][0];
int end = ranges[i][1];

for (int k = start; k <= end; ++k) {
if (k <= 50) { // Stay within the bounds of our checklist.
isCovered[k] = true;
}
}
}

bool all_covered = true;
for (int j = left; j <= right; ++j) {
if (j > 50 || !isCovered[j]) {
all_covered = false;
break; // No need to check further.
}
}

// --- 3. Print the Result ---
if (all_covered) {
cout << "True" << endl;
} else {
cout << "False" << endl;
}

return 0;
}

