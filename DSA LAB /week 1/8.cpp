#include <iostream>
using namespace std;

int main(){
    int m,n;
    cin >>m;
    cin >> n;
    int arr[m][n];
    int k;
    cin >> k;

    for(int i =0; i<m;i++){
        for(int j=0; j<n; j++){
             arr[i][j]=0;
        }
    }
    for(int i=0; i< k; i++){
        int x, y, value;
        cin >> x >> y >> value;
        arr[x][y] = value;
    }
    for(int i=0; i< m; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
    
}