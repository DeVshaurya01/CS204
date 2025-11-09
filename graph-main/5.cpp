#include <bits/stdc++.h> 
using namespace std;
bool hasCycleDFS(int u, vector<vector<int>>& vec, vector<bool>& visited, vector<bool>& path) {
    visited[u] = true;
    path[u] = true;
    for( auto v :vec[u]){
        if(!visited[v]){
           if(hasCycleDFS(v , vec, visited , path)){
            return true;
           }
        }
        else if (path[v]){
            return true ;
        }
        
    }
    path[u] =false;
    return false;
}
int main(){
    int v, e;
    cin>>v>>e; 
    vector<vector<int>> vec(v+1);
    for(int i = 0 ; i<e;i++){
        int x, y;
        cin>>x>>y;
        vec[x].push_back(y);
    }
    vector<bool> visited(v+1,false);
    vector<bool> path(v+1,false);
    bool cycleFound = false;
    for (int i = 1; i <= v; ++i) {
        if (!visited[i]) {
            if (hasCycleDFS(i, vec, visited, path)) {
                cycleFound = true;
                break;
            }
        }
    }

    if (cycleFound) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
