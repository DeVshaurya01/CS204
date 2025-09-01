#include <bits/stdc++.h>
using namespace std;    

void bubbleSort(int arr[], int n, int &swaps) { 
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                ++swaps;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}    

int main() {
    int n;
    int k;
    cin >> n;
    cin >> k;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int swaps = 0;
    bubbleSort(arr, k,swaps);
    cout << swaps << endl;
    bubbleSort(arr, n, swaps);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
