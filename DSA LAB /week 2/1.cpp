#include <bits/stdc++.h>

using namespace std;

// Custom comparison: first by length, then lexicographically
bool compare(const string &a, const string &b) {
    if (a.length() == b.length())
        return a < b;
    return a.length() < b.length();
}

void merge(string arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    string L[100], R[100]; // assuming n <= 1000

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compare(L[i], R[j])) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void merge_sort(string arr[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main(){
    int n;
    cin >> n;

    string arr[1000]; // assuming n <= 1000
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    merge_sort(arr, 0, n - 1);
    
// sort(arr, arr + n, [](const string &a, const string &b) {
//         if (a.length() == b.length())
//             return a < b;
//         return a.length() < b.length();
//     });



for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
}
cout << endl;
}