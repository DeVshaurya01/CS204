#include <iostream>
using namespace std;

void solve(){
    int m, n;
    cin >>m;
    cin >> n;
    int arr[m][n];
    
    
    for(int i=0; i<m;i++){
        for(int j=0; j<n;j++){
            cin >> arr[i][j];
        }
    }

    for(int k=0; k<m*n;k++){
        cout << arr[k/n][k%n] << " ";
    }
    cout << endl;

}

int main(){
    solve();
    return 0;
}