#include <bits/stdc++.h>

using namespace std;

int main(){
int n;
cin >> n ;

string arr[n][2];
for(int i = 0; i < n; i++) {
    cin >> arr[i][0];
    cin >> arr[i][1];
}


sort(arr, arr + n, [](const string a[2], const string b[2]) {
    if (a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
});

for(int i = 0; i < n; i++) {
    cout << arr[i][0] << " ";
    cout << arr[i][1] << " ";
    cout << endl;
}
cout << endl;
}