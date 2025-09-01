#include <bits/stdc++.h>
using namespace std;
void solve(int m, int n);
void mergesort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
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
int main(){
    int m,n;
    cin >> m >> n;
    solve(m,n);
}

void solve(int m,int n){
int arr1[m+n];
for(int i=0; i<m+n; i++){
    cin >> arr1[i];
}
int arr2[n];
for(int i=0; i<n; i++){
    cin >> arr2[i];
}


for (int i = 0; i < n; ++i) {
    arr1[m + i] = arr2[i];
}
merge(arr1, 0, m - 1, m + n - 1);
for(int i=0; i<m+n; i++){
    cout << arr1[i] << " ";
}




}

void mergesort(int arr[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergesort(arr, left, mid);
    mergesort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}