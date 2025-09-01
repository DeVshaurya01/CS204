#include <iostream>
using namespace std;

void reverse(int* arr, int begin, int end){
    while(end>begin){
    swap(arr[begin], arr[end]);
    begin++;
    end--;
    }
}

void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int k=0;
    cin >> k;
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    reverse(arr,0,n-1);
    
    for(int i=0; i<n; i++){
        cout << arr[i]<<" ";
    }

}

int main(){
    solve();
    return 0;
}