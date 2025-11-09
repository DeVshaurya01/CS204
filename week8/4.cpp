#include <iostream>
#include <string>
using namespace std;

int romanToInt(string s) {
    int hash[256] = {0}; // hash array for ASCII chars

    // Mapping Roman numerals to integer values
    hash['I'] = 1;
    hash['V'] = 5;
    hash['X'] = 10;
    hash['L'] = 50;
    hash['C'] = 100;
    hash['D'] = 500;
    hash['M'] = 1000;

    int result = 0;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        // If current character is smaller than next one -> subtract
        if (i + 1 < n && hash[s[i]] < hash[s[i + 1]]) {
            result -= hash[s[i]];
        } else {
            result += hash[s[i]];
        }
    }

    return result;
}

int main() {
    string s;
    cin >> s;
    cout << romanToInt(s) << endl;
    return 0;
}
