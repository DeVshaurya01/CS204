#include <bits/stdc++.h> 
using namespace std;
bool check ( int start , vector<vector<int>> &vec , vector<int> &mark ){
    queue<int> q; 
    q.push(start);
    map <int, int> ma ;
    ma[start] = 1;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int u : vec[temp]){
            if(mark[u] == 0){
                mark[u]=1;
                q.push(u);
                if(ma[temp] ==1 ){
                    ma[u] = 2; 
                }else{
                    ma[u] = 1;
                }
            }
            else{
                if(ma[u] == ma[temp]){
                    return false;
                }
            }
        }
    }
    return true ; 
}
int main(){
    int v, e;
    cin>>v>>e; 
    vector<vector<int>> vec(v+1);
    for(int i = 0 ; i<e;i++){
        int x, y;
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    vector<int> mark(v+1,0);
    bool a = true ; 
    for(int i = 1; i<=v;i++){
        if(mark[i] == 0 ){
        if(!check(i,vec,mark)){
            a = false ; break;
        }
    }}
    if(a){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

}
