#include <bits/stdc++.h>
using namespace std;

void solve(int n);
int main(){
    int n;
    cin >> n;
    solve(n);
}

void solve(int n){
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int ans[n];
    for(int i=0; i<n; i++){
        ans[i] = arr[i] * arr[i];       
    }
    sort(ans, ans + n);

     for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }

}

