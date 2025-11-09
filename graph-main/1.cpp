#include <bits/stdc++.h> 
using namespace std;
void dfs(int start ,vector<vector<int>> &vec ,vector<int> &mark){
    int n = mark.size();
    stack<int> s ;
    s.push(start);
    while(s.empty() == false){
        int temp = s.top();
        if(mark[temp]!=1){
        cout<<temp<<" ";
        mark[temp] =1;
    }
        s.pop();
        for(int i = n-1 ; i>=0;i--){
            if(vec[temp][i] == 1){
                if(mark[i]==0){
                    s.push(i);
                }
            }
        }
        }
    
}
int main (){
    int n ; cin>>n;
    vector<vector<int>> vec(n, vector<int> (n)) ;
    for(int i = 0 ; i<n;i++){
        for(int j = 0 ; j<n;j++){
            cin>>vec[i][j];
        }
    }
    vector<int> mark(n,0);
    dfs(0,vec,mark); 
    for (int i = 1; i < n; i++) {
        if (mark[i] == 0) {
            dfs(i, vec, mark);
        }
    }


}