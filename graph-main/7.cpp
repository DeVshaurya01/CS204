#include <bits/stdc++.h>
using namespace std;
int bfs(int start, vector<vector<int>> &vec){
    queue<int> q; 
    q.push(start);
    vector<int> distance(vec.size() + 1,-1);
    
    distance[start] = 0 ;
    int maxa =0 ;

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int i = 0 ; i<vec[temp].size();i++){
            int a  = vec[temp][i];
            if(distance[a] == -1){
                q.push(vec[temp][i]);
            }
        }
        for(int u : vec[temp]){
            if(distance[u] == -1){ distance[u] = distance[temp] + 1;
            maxa = max(maxa,distance[u]);}
        }
    }
    return maxa; 
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

    int globalmaxa = 0 ; 
    for(int i = 1; i<=v;i++){
        globalmaxa = max(globalmaxa,bfs(i,vec));
    }
    cout<<globalmaxa <<endl;
}
