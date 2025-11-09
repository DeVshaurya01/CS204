#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int longestSubstring(string s) {
    int n = s.length();
    int hash[256]; // To store last index of characters
    fill(hash, hash + 256, -1); // Initialize all values to -1

    int maxLength = 0;
    int start = 0; // Start of current window

    for (int i = 0; i < n; i++) {
        if (hash[s[i]] >= start) {
            // Character repeated inside the window
            start = hash[s[i]] + 1; // Move start right after last occurrence
        }
        hash[s[i]] = i; // Update last index
        maxLength = max(maxLength, i - start + 1); // Update max length
    }

    return maxLength;
}

int main() {
    string s;
    getline(cin, s); // Read the input string
    cout << longestSubstring(s) << endl;
    return 0;
}
