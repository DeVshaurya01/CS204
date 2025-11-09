#include <bits/stdc++.h> 
using namespace std;
void bfs(int start, vector<vector<int>> &vec ,vector<int> &visited){
    queue<int> q; 
    q.push(start);

    while(!q.empty()){
        int temp = q.front();
        if(visited[temp] == 0){
            cout<<temp<<" ";
            visited[temp] = 1;
        }
        q.pop();
        for(int i = 0 ; i<vec[temp].size();i++){
            int a  = vec[temp][i];
            if(visited[a] == 0){
                q.push(vec[temp][i]);
            }
        }
    }
}
int main(){
    int v, e;
    cin>>v>>e; 
    vector<vector<int>> vec(v);
    for(int i = 0 ; i<e;i++){
        int x, y;
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    for(int i = 0 ; i<v;i++){
        sort(vec[i].begin(),vec[i].end());
    }
    vector<int> visited(v,0);
    bfs(0,vec,visited);
    for(int i = 1 ; i<v;i++){
        if(visited[i]==0 ){
            bfs(i,vec,visited);
        }
    }
}