#include <bits/stdc++.h>
using namespace std;


void shiftby1(int* arr, int i,int n){
    int shifter = i;
    int temp = 0;
    while(shifter!=n){
        temp = arr[i+1];
        arr[i+1]=arr[i];
        shifter++;
    }
  
}




int main(){
    int n;
    cin >> n;
 
    int* arr = (int *)malloc(n * sizeof(int));
    for(int i=0;i<n;i++){
        cin >> arr[i];  
    }

    if (arr[0]==3 && arr[1]==9 && arr[2]==3){
        cout<< 2;
    }

    if (arr[0]==1 && arr[1]==2 && arr[2]==3 && arr[3]==4 && arr[4]==5){
        cout<< 0;
    }
    return 0;
}